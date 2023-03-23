#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    serialPort = new QSerialPort(this);

    //扫描本机的串口并且添加到下拉列表
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->cmb_port->addItem(info.portName());
    }

    //检测到有数据可读时执行数据读取
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(read_Data()));

    ui->text_send->setText("www.baidu.com");

    /*创建定时器对象*/
    auto_Timer = new QTimer();
    /*设置定时器为精确地定时，毫秒级精度*/
    auto_Timer->setTimerType(Qt::PreciseTimer);
    /*定时器触发执行发送数据*/
    connect(auto_Timer,SIGNAL(timeout()),this,SLOT(on_btn_send_clicked()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_open_clicked()
{
    if(ui->btn_open->text()=="打开串口")
    {
        serialPort->setPortName(ui->cmb_port->currentText());
        serialPort->setBaudRate(ui->cmb_rate->currentText().toInt());

        //数据位配置
        switch (ui->cmb_data->currentText().toInt()) {
            case 5:
                serialPort->setDataBits(QSerialPort::Data5);
                break;
            case 6:
                serialPort->setDataBits(QSerialPort::Data6);
                break;
            case 7:
                serialPort->setDataBits(QSerialPort::Data7);
                break;
            case 8:
                serialPort->setDataBits(QSerialPort::Data8);
                break;
        }

        //停止位配置
        switch (ui->cmb_stop->currentText().toInt()) {
            case 1:
                serialPort->setStopBits(QSerialPort::OneStop);
                break;
            case 2:
                serialPort->setStopBits(QSerialPort::TwoStop);
                break;
        }

        //校验位配置
        if(ui->cmb_check->currentText()=="无")
            serialPort->setParity(QSerialPort::NoParity);
        else if(ui->cmb_check->currentText()=="奇")
            serialPort->setParity(QSerialPort::OddParity);
        else if(ui->cmb_check->currentText()=="偶")
            serialPort->setParity(QSerialPort::EvenParity);

        //关闭流控制
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        //打开串口
        if(!serialPort->open(QIODevice::ReadWrite))
        {
            QMessageBox::about(this,"错误","串口打开失败，请检查串口是否已被占用");
            return;
        }

        //更改界面
        ui->btn_open->setText("关闭串口");
        ui->cmb_port->setEnabled(false);
        ui->cmb_data->setEnabled(false);
        ui->cmb_rate->setEnabled(false);
        ui->cmb_stop->setEnabled(false);
        ui->cmb_check->setEnabled(false);
    }
    else
    {
        ui->btn_open->setText("打开串口");
        ui->cmb_port->setEnabled(true);
        ui->cmb_data->setEnabled(true);
        ui->cmb_rate->setEnabled(true);
        ui->cmb_stop->setEnabled(true);
        ui->cmb_check->setEnabled(true);
        serialPort->close();
    }
}

void Widget::on_btn_cleanR_clicked()
{
    ui->text_receive->clear();
}

void Widget::on_btn_send_clicked()
{
    if(cb_new_select)
        serialPort->write((ui->text_send->toPlainText()+"\n").toUtf8());
    else
        serialPort->write(ui->text_send->toPlainText().toUtf8());
}

void Widget::on_btn_cleanS_clicked()
{
    ui->text_send->clear();
}

void Widget::read_Data()
{
    /*读取串口所有数据并显示到文本框*/
    ui->text_receive->insertPlainText(serialPort->readAll());
}

void Widget::on_cb_newLine_stateChanged(int arg1)
{
    if(arg1 == 2)//选中
    {
        cb_new_select = 1;
    }
    else if(arg1 == 0)//未选中
    {
        cb_new_select = 0;
    }
}

void Widget::on_cb_auto_stateChanged(int arg1)
{
    if(arg1 == 2)//选中
    {
        cb_auto_select = 1;//自动发送标志位置1
        auto_Timer->start(ui->text_ms->text().toInt());//定时器启动
    }
    else if(arg1 == 0)//未选中
    {
        cb_auto_select = 0;//自动发送标志位清零
        auto_Timer->stop();//定时器停止
    }
}


