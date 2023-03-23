/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QTextBrowser *text_receive;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cmb_port;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *cmb_rate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *cmb_data;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *cmb_stop;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *cmb_check;
    QPushButton *btn_open;
    QPushButton *btn_cleanR;
    QHBoxLayout *horizontalLayout_9;
    QTextEdit *text_send;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_send;
    QPushButton *btn_cleanS;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *text_ms;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *cb_newLine;
    QCheckBox *cb_auto;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 480);
        Widget->setMinimumSize(QSize(800, 480));
        Widget->setMaximumSize(QSize(800, 480));
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        text_receive = new QTextBrowser(Widget);
        text_receive->setObjectName(QString::fromUtf8("text_receive"));

        horizontalLayout_6->addWidget(text_receive);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cmb_port = new QComboBox(Widget);
        cmb_port->setObjectName(QString::fromUtf8("cmb_port"));

        horizontalLayout->addWidget(cmb_port);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        cmb_rate = new QComboBox(Widget);
        cmb_rate->addItem(QString());
        cmb_rate->addItem(QString());
        cmb_rate->addItem(QString());
        cmb_rate->addItem(QString());
        cmb_rate->addItem(QString());
        cmb_rate->setObjectName(QString::fromUtf8("cmb_rate"));

        horizontalLayout_2->addWidget(cmb_rate);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        cmb_data = new QComboBox(Widget);
        cmb_data->addItem(QString());
        cmb_data->addItem(QString());
        cmb_data->addItem(QString());
        cmb_data->addItem(QString());
        cmb_data->setObjectName(QString::fromUtf8("cmb_data"));

        horizontalLayout_3->addWidget(cmb_data);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        cmb_stop = new QComboBox(Widget);
        cmb_stop->addItem(QString());
        cmb_stop->addItem(QString());
        cmb_stop->setObjectName(QString::fromUtf8("cmb_stop"));

        horizontalLayout_4->addWidget(cmb_stop);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        cmb_check = new QComboBox(Widget);
        cmb_check->addItem(QString());
        cmb_check->addItem(QString());
        cmb_check->addItem(QString());
        cmb_check->setObjectName(QString::fromUtf8("cmb_check"));

        horizontalLayout_5->addWidget(cmb_check);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_5);

        btn_open = new QPushButton(Widget);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));
        btn_open->setMinimumSize(QSize(0, 35));
        btn_open->setCheckable(true);
        btn_open->setChecked(false);

        verticalLayout->addWidget(btn_open);

        btn_cleanR = new QPushButton(Widget);
        btn_cleanR->setObjectName(QString::fromUtf8("btn_cleanR"));
        btn_cleanR->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(btn_cleanR);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalLayout_6->setStretch(0, 6);
        horizontalLayout_6->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        text_send = new QTextEdit(Widget);
        text_send->setObjectName(QString::fromUtf8("text_send"));

        horizontalLayout_9->addWidget(text_send);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_send = new QPushButton(Widget);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        btn_send->setMinimumSize(QSize(0, 35));

        verticalLayout_2->addWidget(btn_send);

        btn_cleanS = new QPushButton(Widget);
        btn_cleanS->setObjectName(QString::fromUtf8("btn_cleanS"));
        btn_cleanS->setMinimumSize(QSize(0, 35));

        verticalLayout_2->addWidget(btn_cleanS);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_8->addWidget(label_6);

        text_ms = new QLineEdit(Widget);
        text_ms->setObjectName(QString::fromUtf8("text_ms"));

        horizontalLayout_8->addWidget(text_ms);

        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        cb_newLine = new QCheckBox(Widget);
        cb_newLine->setObjectName(QString::fromUtf8("cb_newLine"));
        cb_newLine->setEnabled(true);
        cb_newLine->setChecked(false);
        cb_newLine->setTristate(false);

        horizontalLayout_7->addWidget(cb_newLine);

        cb_auto = new QCheckBox(Widget);
        cb_auto->setObjectName(QString::fromUtf8("cb_auto"));

        horizontalLayout_7->addWidget(cb_auto);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);

        horizontalLayout_9->addLayout(verticalLayout_2);

        horizontalLayout_9->setStretch(0, 6);
        horizontalLayout_9->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalLayout_3->setStretch(0, 6);
        verticalLayout_3->setStretch(1, 4);

        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213", nullptr));
        label->setText(QApplication::translate("Widget", "\347\253\257\345\217\243", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        cmb_rate->setItemText(0, QApplication::translate("Widget", "115200", nullptr));
        cmb_rate->setItemText(1, QApplication::translate("Widget", "9600", nullptr));
        cmb_rate->setItemText(2, QApplication::translate("Widget", "19200", nullptr));
        cmb_rate->setItemText(3, QApplication::translate("Widget", "38400", nullptr));
        cmb_rate->setItemText(4, QApplication::translate("Widget", "57600", nullptr));

        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        cmb_data->setItemText(0, QApplication::translate("Widget", "8", nullptr));
        cmb_data->setItemText(1, QApplication::translate("Widget", "5", nullptr));
        cmb_data->setItemText(2, QApplication::translate("Widget", "6", nullptr));
        cmb_data->setItemText(3, QApplication::translate("Widget", "7", nullptr));

        label_4->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        cmb_stop->setItemText(0, QApplication::translate("Widget", "1", nullptr));
        cmb_stop->setItemText(1, QApplication::translate("Widget", "2", nullptr));

        label_5->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", nullptr));
        cmb_check->setItemText(0, QApplication::translate("Widget", "\346\227\240", nullptr));
        cmb_check->setItemText(1, QApplication::translate("Widget", "\345\245\207", nullptr));
        cmb_check->setItemText(2, QApplication::translate("Widget", "\345\201\266", nullptr));

        btn_open->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        btn_cleanR->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        btn_send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        btn_cleanS->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        label_6->setText(QApplication::translate("Widget", "\350\207\252\345\212\250\345\217\221\351\200\201\345\221\250\346\234\237", nullptr));
        text_ms->setText(QApplication::translate("Widget", "1000", nullptr));
        label_7->setText(QApplication::translate("Widget", "ms", nullptr));
        cb_newLine->setText(QApplication::translate("Widget", "    \345\217\221\351\200\201\346\226\260\350\241\214", nullptr));
        cb_auto->setText(QApplication::translate("Widget", "\350\207\252\345\212\250\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
