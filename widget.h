#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

/*槽函数*/
private slots:
    /*按键点击*/
    void on_btn_open_clicked();//开关串口
    void on_btn_cleanR_clicked();//清空读取区数据
    void on_btn_send_clicked();//发送数据
    void on_btn_cleanS_clicked();//清空发送区数据
    /*串口数据读取*/
    void read_Data();//读取串口数据
    /*单选框状态改变*/
    void on_cb_newLine_stateChanged(int arg1);//发送新行
    void on_cb_auto_stateChanged(int arg1);//自动发送

/*成员变量*/
private:
    Ui::Widget *ui;
    QSerialPort *serialPort;//指向QSerialPort类的指针
    QTimer *auto_Timer;//定时器
    bool cb_new_select = 0;//发送新行标志位
    bool cb_auto_select = 0;//自动发送标志位
};
#endif // WIDGET_H
