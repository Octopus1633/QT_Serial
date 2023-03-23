# QT_Serial
用QT制作一个串口调试助手
# STM32MP157串口调试助手

## widget.ui

设计的ui界面如下图所示：

![1679365896371](https://user-images.githubusercontent.com/97655921/227108828-29ec933b-564d-48c1-923e-733a6b88d4f6.png)

该界面可分为**发送区**（上半部分）和**接收区** （下半部分），整体为垂直布局。

发送区

- 左边为文本框，用于显示串口接收的数据。
- 右边为串口的配置和打开、关闭串口、清空接收区的按钮。
- 端口等文字描述使用`QLabel`控件，下拉框使用`QComboBox`控件，按钮使用`QPushButton`控件。
- **发送区整体为水平布局，右半部分整体为垂直布局，局部为水平布局**。

接收区

- 左边为文本框，用于输入要发送的数据。
- 右边为发送、清空按钮以及发送的相关配置。
- 按钮使用`QPushButton`控件，自动发送周期编辑框使用`QLineEdit`控件，发送新行、自动发送单选框使用`QCheckBox`控件。
- **接收区整体为水平布局，右半部分整体为垂直布局，局部为水平布局**。

## pro文件

```c++
QT       += core gui serialport
```

这行代码是在使用Qt框架中的pro项目文件中使用的，它指定了在构建这个项目时需要链接哪些Qt模块。具体来说，它指定了需要链接`core`、`gui`和`serialport`三个模块。

- `core`：Qt核心模块，提供了Qt基础库和一些基本的非GUI功能，如信号槽机制、容器、文件操作等。
- `gui`：Qt图形用户界面模块，提供了Qt图形库和一些GUI相关的类，如窗口、按钮、标签、列表框等。
- `serialport`：Qt串口通信模块，提供了串口通信相关的类。

在编写Qt程序时，我们需要使用这些模块提供的类和函数，而在构建程序时，需要链接这些模块才能使程序正确运行。因此，在.pro文件中使用QT关键字来指定需要链接的模块是很重要的一步。

## widget.h

### 头文件

```c++
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
```

- `<QSerialPort>`：Qt提供的串口通信相关的头文件，包含了`QSerialPort`类的定义。`QSerialPort`类提供了与串口进行通信的功能，如**打开、关闭串口**、**读取、写入数据**等。
- `<QSerialPortInfo>`：Qt提供的串口信息相关的头文件，包含了`QSerialPortInfo`类的定义。`QSerialPortInfo`类提供了获取串口信息的功能，如**获取当前系统上所有可用的串口列表**、**获取每个串口的名称**、描述、制造商、产品ID等信息。
- `<QTimer>`：Qt提供的定时器相关的头文件，包含了`QTimer`类的定义。`QTimer`类提供了在一定时间间隔后触发某些事件的功能，如一定时间后执行一段代码、周期性地执行一段代码等。通过使用`QTimer`，可以方便地实现定时执行某些操作的功能，如**定时发送串口数据**、定时检测串口状态等。

### 槽函数

在Qt框架中，**信号**（`signal`）和**槽**（`slot`）是一种重要的机制，用于在对象之间进行通信。信号是在对象中定义的特殊函数，用于通知其他对象发生了某个事件。而槽是另一个对象中定义的特殊函数，用于响应信号并执行相应的操作。

**QT槽函数就是被信号连接的特殊函数，它会在接收到信号时被自动调用**。通过将信号与槽函数相关联，可以实现对象之间的通信和交互。在Qt中，可以使用**connect函数**将信号和槽函数连接起来。connect函数有两种方式：

1.使用函数指针连接信号和槽函数
```c
函数原型：
connect(sender, &Sender::signal, receiver, &Receiver::slot);

参数：
sender -- 发送信号的对象
signal -- 表示Sender类中名为signal的信号函数的指针
receiver -- 接收信号的对象
slot -- 表示Receiver类中名为slot的槽函数的指针  
```


2.使用信号和槽函数的字符串连接信号和槽函数

```c
函数原型：
connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));

参数：
sender -- 发送信号的对象
signal -- 表示信号函数的名称
receiver -- 接收信号的对象
slot -- 表示槽函数的名称  
```

无论使用哪种方式连接信号和槽函数，都必须保证信号和槽函数的参数类型和参数个数一致。当发送信号时，所有连接的槽函数都会被自动调用，并按照连接的顺序执行。
总之，QT槽函数是一种特殊函数，用于响应与之连接的信号并执行相应的操作。通过将信号与槽函数相关联，可以实现对象之间的通信和交互。

```c++
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
```

### 成员声明

```c++
/*成员变量*/
private:
    Ui::Widget *ui;
    QSerialPort *serialPort;//指向QSerialPort类的指针
    QTimer *auto_Timer;//定时器
    bool cb_new_select = 0;//发送新行标志位
    bool cb_auto_select = 0;//自动发送标志位
```

## widget.cpp

### 头文件

```c++
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
```

- `<QDebug>`: 这是Qt框架中的一个调试工具，允许程序员在代码中插入打印调试信息的语句，以帮助调试程序。
- `<QMessageBox>`: 这也是Qt框架中的一个类，用于创建弹出对话框，通常用于提示用户或请求用户进行操作。
- `<QTimer>`: 这是Qt框架中的一个类，用于创建定时器，可以在指定时间间隔内执行某些操作，例如更新UI界面或执行后台任务等。

这些头文件是在Qt应用程序中使用的，可能会在类的定义或者实现中包含这些头文件。例如，可以使用 `qDebug()` 函数打印调试信息，使用 `QMessageBox` 类创建一个消息对话框，使用 `QTimer` 类创建一个定时器来执行某些操作。

### 扫描串口并添加到下拉列表

```c++
/*扫描本机的串口并且添加到下拉列表*/
foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
    ui->cmb_port->addItem(info.portName());
}
```

`foreach`是一个关键字，可以起到循环作用，这里用于遍历当前计算机可用的串口。QSerialPortInfo::availablePorts()是一个静态函数，返回一个列表，包含计算机上可用的所有串口信息。该循环在每次中将可用串口的信息保存在info变量中。 

`ui->cmb_port`是一个指向下拉列表控件的指针。`addItem()`函数用于将串口的名称添加到下拉列表控件中，结合以上即可循环将可用的串口名称添加到下拉控件中。 

### 串口配置

#### 参数获取

在串口配置时，需要获取用户在串口调试助手选择的参数。调用控件的`currentText()`方法即可获取控件的文本内容。例：

```c++
ui->cmb_port->currentText()
```

该行代码可以获取控件当前的文本内容。

如**波特率**、**数据位**、**停止位**则还可以将文本转为数字再进行判断。例：

```c++
ui->cmb_rate->currentText().toInt()
```

该行代码可以获取控件的波特率并将其转换为数字。

#### 配置参数

函数：

```c++
/*配置串口名称*/
函数原型：
void QSerialPort::setPortName(const QString &name);
参数：
name -- 串口名称

/*配置波特率*/
函数原型：
void QSerialPort::setBaudRate(qint32 baudRate, QSerialPort::Directions directions = QSerialPort::AllDirections);    
参数：
baudRate -- 波特率
directions -- 不传入默认为QSerialPort::AllDirections，即双向通讯

/*配置数据位*/
函数原型：
void QSerialPort::setDataBits(QSerialPort::DataBits dataBits);
参数：
dataBits -- 数据位数

/*配置停止位*/
函数原型：
void QSerialPort::setStopBits(QSerialPort::StopBits stopBits);
参数：
stopBits -- 停止位数

/*配置奇偶校验位*/
函数原型：
void QSerialPort::setParity(QSerialPort::Parity parity);
参数：
parity -- 奇偶校验位

/*配置流控制*/
函数原型：
void QSerialPort::setFlowControl(QSerialPort::FlowControl flowControl);
参数：
flowControl -- 是否设置流控制
```

代码：

```c++
/*串口名、波特率配置*/
serialPort->setPortName(ui->cmb_port->currentText());
serialPort->setBaudRate(ui->cmb_rate->currentText().toInt());

/*数据位配置*/
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

/*停止位配置*/
switch (ui->cmb_stop->currentText().toInt()) {
    case 1:
        serialPort->setStopBits(QSerialPort::OneStop);
        break;
    case 2:
        serialPort->setStopBits(QSerialPort::TwoStop);
        break;
}

/*校验位配置*/
if(ui->cmb_check->currentText()=="无")
    serialPort->setParity(QSerialPort::NoParity);
else if(ui->cmb_check->currentText()=="奇")
    serialPort->setParity(QSerialPort::OddParity);
else if(ui->cmb_check->currentText()=="偶")
    serialPort->setParity(QSerialPort::EvenParity);

/*关闭流控制*/
serialPort->setFlowControl(QSerialPort::NoFlowControl);
```

### 打开、关闭串口

使用**open()**、**close()** 函数实现串口的打开和关闭。

```c++
/*打开串口*/
函数原型：
bool open(QIODevice::OpenMode mode = QIODevice::ReadWrite);
参数：
mode -- 串口打开模式,不传入默认为QIODevice::ReadWrite，即读写模式

/*关闭串口*/
serialPort->close();
```

### 读取数据

#### 信号

当串口接收到数据时，会触发 `serialPort` 对象的 `readyRead` 信号，当该信号被触发时，表示串口已准备好接收数据，接下来可以进行数据的读取操作。

#### 读数据函数

```c++
函数原型：
QByteArray readAll();

使用：
void Widget::read_Data()
{
    /*读取串口所有数据并显示到文本框*/
    ui->text_receive->insertPlainText(serialPort->readAll());
}
```

#### 代码

```c++
/*检测到有数据可读时自动执行数据读取*/
connect(serialPort, SIGNAL(readyRead()), this, SLOT(read_Data()));
```

### 发送数据

当点击发送按键或自动发送时，槽函数**on_btn_send_clicked**被执行，函数调用 **write()** 函数，实现通过当前打开的串口发送发送区的数据。

```c++
函数原型：
qint64 write(const QByteArray &data);
参数：
data -- 要发送的数据

/*发送数据串口数据*/
void Widget::on_btn_send_clicked()
{
    serialPort->write(ui->text_send->toPlainText().toUtf8());
}
```

### 清空接收、发送区

当点击清空接收、发送区按键时，槽函数**on_btn_cleanR_clicked**（清空接收区）、**on_btn_cleanS_clicked**（清空发送区）被执行，函数中调用文本框的 **clear()** 函数清空文本框数据。

```c++
/*清空接收区数据*/
void Widget::on_btn_cleanR_clicked()
{
    ui->text_receive->clear();
}

/*清空发送区数据*/
void Widget::on_btn_cleanS_clicked()
{
    ui->text_send->clear();
}
```

### 发送新行

勾选或取消勾选发送新行单选框时，槽函数**on_cb_newLine_stateChanged**被执行，若当前为勾选状态（参数**arg1**为2）则将发送新行标志位**cb_new_select**置1，否则将发送新行标志位**cb_new_select**清零，在数据发送函数**on_btn_send_clicked**中判断当前是否为自动换行，若是则在数据末尾添加换行符。

```c++
/*发送新行单选框状态改变*/
void Widget::on_cb_newLine_stateChanged(int arg1)
{
    if(arg1 == 2)//选中
    {
        cb_new_select = 1;//发送新行标志位置1
    }
    else if(arg1 == 0)//未选中
    {
        cb_new_select = 0;//发送新行标志位清零
    }
}

/*串口数据发送*/
void Widget::on_btn_send_clicked()
{
    if(cb_new_select)//勾选发送新行
        serialPort->write((ui->text_send->toPlainText()+"\n").toUtf8());
    else//未勾选发送新行
        serialPort->write(ui->text_send->toPlainText().toUtf8());
}
```

### 定时发送

勾选或取消勾选定时发送单选框时，槽函数**on_cb_auto_stateChanged**被执行，若当前为勾选状态（参数**arg1**为2）则开启定时器，否则关闭定时器。定时结束时（用户自己设定时长）自动执行数据发送函数**on_btn_send_clicked**。

```c++
/*创建定时器对象*/
auto_Timer = new QTimer();
/*设置定时器为精确地定时，毫秒级精度*/
auto_Timer->setTimerType(Qt::PreciseTimer);
/*定时结束自动执行发送数据*/
connect(auto_Timer,SIGNAL(timeout()),this,SLOT(on_btn_send_clicked()));

/*自动发送单选框状态改变*/
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

/*串口数据发送*/
void Widget::on_btn_send_clicked()
{
    if(cb_new_select)//勾选发送新行
        serialPort->write((ui->text_send->toPlainText()+"\n").toUtf8());
    else//未勾选发送新行
        serialPort->write(ui->text_send->toPlainText().toUtf8());
}
```

## 移植

### 安装含编译 Qt 应用程序的交叉编译工具链 

在虚拟机上成功运行该项目后，接下来开始进行交叉编译，将该串口调试助手移植到开发板上。首先，需要安装含编译Qt应用程序的交叉编译工具链。

![1679541468264](https://user-images.githubusercontent.com/97655921/227108947-cff41efb-7730-454a-aa7f-25a71ce8b4e2.png)


图片源于文档 **【正点原子】STM32MP157快速体验**。该项目使用正点原子提供的交叉编译器，详情请看该文档6.2章节安装含编译 Qt 应用程序的交叉编译工具链相关内容。

### 编译及运行 Qt 应用程序 

安装完后，使能交叉编译工具链的环境变量

```shell
source /opt/st/stm32mp1/3.1-snapshot/environment-setup-cortexa7t2hf-neon-vfpv4-ostl-linux-gnueabi
```

然后，使用终端进入该项目目录执行如下命令

```shell
将之前用Qt编译的档案清除：
make clean

使用qmake生成Makefile文件：
qmake

编译工程：
make
```

编译完成后会生成一个可执行文件Serial，可以用file命令查看该可执行文件的详细信息

![1679543588811](https://user-images.githubusercontent.com/97655921/227108967-f0805aa1-30c8-46a5-bf8d-8f296025fa43.png)

### 文件传输

可选择使用scp方式传输，格式：scp 文件名 用户名@ip地址:存储路径

```shell
scp Serial root@192.168.128.128:/home/root/
```

## 运行效果

### 虚拟机运行效果

![1679547323879](https://user-images.githubusercontent.com/97655921/227109001-25ba524f-450a-4bfb-959f-2afc652c015b.png)

### 开发板运行效果

![8ddb8eb759dd3c9da8070203804df77](https://user-images.githubusercontent.com/97655921/227109050-1572479d-00bd-4647-843e-401ee20d127e.jpg)

![1679547712249](https://user-images.githubusercontent.com/97655921/227109018-d786511e-0039-4bac-9906-f1cab68ce406.png)
