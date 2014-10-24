/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat May 17 18:33:30 2014
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_info;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_login;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_help;
    QLabel *title_label;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *user_label;
    QLineEdit *lineEdit_user;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password_label;
    QLineEdit *lineEdit_psd;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 272);
        MainWindow->setMinimumSize(QSize(480, 272));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_info = new QPushButton(centralwidget);
        pushButton_info->setObjectName(QString::fromUtf8("pushButton_info"));
        pushButton_info->setGeometry(QRect(370, 80, 50, 30));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(88, 152, 271, 28));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_login = new QPushButton(widget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        horizontalLayout_3->addWidget(pushButton_login);

        pushButton_exit = new QPushButton(widget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        horizontalLayout_3->addWidget(pushButton_exit);

        pushButton_help = new QPushButton(widget);
        pushButton_help->setObjectName(QString::fromUtf8("pushButton_help"));

        horizontalLayout_3->addWidget(pushButton_help);

        title_label = new QLabel(centralwidget);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setGeometry(QRect(92, 52, 259, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        title_label->setFont(font);
        title_label->setTextFormat(Qt::AutoText);
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(94, 81, 261, 29));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        user_label = new QLabel(widget1);
        user_label->setObjectName(QString::fromUtf8("user_label"));

        horizontalLayout->addWidget(user_label);

        lineEdit_user = new QLineEdit(widget1);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));

        horizontalLayout->addWidget(lineEdit_user);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(94, 114, 261, 29));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        password_label = new QLabel(widget2);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        horizontalLayout_2->addWidget(password_label);

        lineEdit_psd = new QLineEdit(widget2);
        lineEdit_psd->setObjectName(QString::fromUtf8("lineEdit_psd"));
        lineEdit_psd->setAutoFillBackground(false);
        lineEdit_psd->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_psd);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton_info->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        pushButton_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton_help->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        title_label->setText(QApplication::translate("MainWindow", "         \350\277\234\347\250\213\347\233\221\346\216\247\347\263\273\347\273\237\347\231\273\345\275\225\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        user_label->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        password_label->setText(QApplication::translate("MainWindow", " \345\257\206\347\240\201: ", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
