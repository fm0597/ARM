/********************************************************************************
** Form generated from reading ui file 'capture.ui'
**
** Created: Wed May 21 16:34:11 2014
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CAPTURE_H
#define UI_CAPTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Capture
{
public:
    QLabel *video_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *open_pushButton;
    QPushButton *close_pushButton;
    QPushButton *take_photo_pushButton;
    QPushButton *image_open_pushButton;
    QPushButton *image_close_pushButton;
    QPushButton *serial_btn;
    QLabel *label;

    void setupUi(QWidget *Capture)
    {
        if (Capture->objectName().isEmpty())
            Capture->setObjectName(QString::fromUtf8("Capture"));
        Capture->resize(480, 272);
        Capture->setMinimumSize(QSize(480, 272));
        Capture->setMaximumSize(QSize(480, 272));
        video_label = new QLabel(Capture);
        video_label->setObjectName(QString::fromUtf8("video_label"));
        video_label->setGeometry(QRect(12, 11, 321, 241));
        video_label->setMinimumSize(QSize(321, 220));
        video_label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));
        layoutWidget = new QWidget(Capture);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(350, 10, 122, 211));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        open_pushButton = new QPushButton(layoutWidget);
        open_pushButton->setObjectName(QString::fromUtf8("open_pushButton"));
        open_pushButton->setMinimumSize(QSize(80, 30));

        verticalLayout->addWidget(open_pushButton);

        close_pushButton = new QPushButton(layoutWidget);
        close_pushButton->setObjectName(QString::fromUtf8("close_pushButton"));
        close_pushButton->setMinimumSize(QSize(80, 30));

        verticalLayout->addWidget(close_pushButton);

        take_photo_pushButton = new QPushButton(layoutWidget);
        take_photo_pushButton->setObjectName(QString::fromUtf8("take_photo_pushButton"));
        take_photo_pushButton->setMinimumSize(QSize(80, 30));

        verticalLayout->addWidget(take_photo_pushButton);

        image_open_pushButton = new QPushButton(layoutWidget);
        image_open_pushButton->setObjectName(QString::fromUtf8("image_open_pushButton"));
        image_open_pushButton->setMinimumSize(QSize(80, 30));

        verticalLayout->addWidget(image_open_pushButton);

        image_close_pushButton = new QPushButton(layoutWidget);
        image_close_pushButton->setObjectName(QString::fromUtf8("image_close_pushButton"));
        image_close_pushButton->setMinimumSize(QSize(80, 30));

        verticalLayout->addWidget(image_close_pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        serial_btn = new QPushButton(layoutWidget);
        serial_btn->setObjectName(QString::fromUtf8("serial_btn"));

        verticalLayout_2->addWidget(serial_btn);

        label = new QLabel(Capture);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 230, 111, 17));

        retranslateUi(Capture);

        QMetaObject::connectSlotsByName(Capture);
    } // setupUi

    void retranslateUi(QWidget *Capture)
    {
        Capture->setWindowTitle(QApplication::translate("Capture", "Capture", 0, QApplication::UnicodeUTF8));
        video_label->setText(QString());
        open_pushButton->setText(QApplication::translate("Capture", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", 0, QApplication::UnicodeUTF8));
        close_pushButton->setText(QApplication::translate("Capture", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", 0, QApplication::UnicodeUTF8));
        take_photo_pushButton->setText(QApplication::translate("Capture", "\346\210\252\345\233\276", 0, QApplication::UnicodeUTF8));
        image_open_pushButton->setText(QApplication::translate("Capture", "\346\265\217\350\247\210\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        image_close_pushButton->setText(QApplication::translate("Capture", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        serial_btn->setText(QApplication::translate("Capture", "Open Serial", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        Q_UNUSED(Capture);
    } // retranslateUi

};

namespace Ui {
    class Capture: public Ui_Capture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURE_H
