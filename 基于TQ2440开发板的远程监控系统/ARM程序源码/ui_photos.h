/********************************************************************************
** Form generated from reading ui file 'photos.ui'
**
** Created: Sat May 17 20:00:14 2014
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PHOTOS_H
#define UI_PHOTOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Photos
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *expand_pushButton;
    QPushButton *narrow_pushButton;
    QPushButton *previous_pushButton;
    QPushButton *next_pushButton;
    QPushButton *open_pushButton;
    QPushButton *delete_pushButton;
    QPushButton *adjust_pushButton;
    QLabel *label;

    void setupUi(QWidget *Photos)
    {
        if (Photos->objectName().isEmpty())
            Photos->setObjectName(QString::fromUtf8("Photos"));
        Photos->resize(480, 272);
        Photos->setMinimumSize(QSize(480, 272));
        Photos->setMaximumSize(QSize(480, 272));
        layoutWidget = new QWidget(Photos);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 240, 458, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        expand_pushButton = new QPushButton(layoutWidget);
        expand_pushButton->setObjectName(QString::fromUtf8("expand_pushButton"));
        expand_pushButton->setMinimumSize(QSize(35, 30));
        expand_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(expand_pushButton);

        narrow_pushButton = new QPushButton(layoutWidget);
        narrow_pushButton->setObjectName(QString::fromUtf8("narrow_pushButton"));
        narrow_pushButton->setMinimumSize(QSize(35, 30));
        narrow_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(narrow_pushButton);

        previous_pushButton = new QPushButton(layoutWidget);
        previous_pushButton->setObjectName(QString::fromUtf8("previous_pushButton"));
        previous_pushButton->setMinimumSize(QSize(60, 30));
        previous_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(previous_pushButton);

        next_pushButton = new QPushButton(layoutWidget);
        next_pushButton->setObjectName(QString::fromUtf8("next_pushButton"));
        next_pushButton->setMinimumSize(QSize(60, 30));
        next_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(next_pushButton);

        open_pushButton = new QPushButton(layoutWidget);
        open_pushButton->setObjectName(QString::fromUtf8("open_pushButton"));
        open_pushButton->setMinimumSize(QSize(35, 30));
        open_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(open_pushButton);

        delete_pushButton = new QPushButton(layoutWidget);
        delete_pushButton->setObjectName(QString::fromUtf8("delete_pushButton"));
        delete_pushButton->setMinimumSize(QSize(35, 30));
        delete_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(delete_pushButton);

        adjust_pushButton = new QPushButton(layoutWidget);
        adjust_pushButton->setObjectName(QString::fromUtf8("adjust_pushButton"));
        adjust_pushButton->setMinimumSize(QSize(35, 30));
        adjust_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(adjust_pushButton);

        label = new QLabel(Photos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 120, 101, 17));

        retranslateUi(Photos);

        QMetaObject::connectSlotsByName(Photos);
    } // setupUi

    void retranslateUi(QWidget *Photos)
    {
        Photos->setWindowTitle(QApplication::translate("Photos", "Photos", 0, QApplication::UnicodeUTF8));
        expand_pushButton->setText(QApplication::translate("Photos", "\346\224\276\345\244\247", 0, QApplication::UnicodeUTF8));
        narrow_pushButton->setText(QApplication::translate("Photos", "\347\274\251\345\260\217", 0, QApplication::UnicodeUTF8));
        previous_pushButton->setText(QApplication::translate("Photos", "\344\270\212\344\270\200\345\274\240", 0, QApplication::UnicodeUTF8));
        next_pushButton->setText(QApplication::translate("Photos", "\344\270\213\344\270\200\345\274\240", 0, QApplication::UnicodeUTF8));
        open_pushButton->setText(QApplication::translate("Photos", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        delete_pushButton->setText(QApplication::translate("Photos", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        adjust_pushButton->setText(QApplication::translate("Photos", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Photos", "\350\257\267\347\202\271\345\207\273\346\265\217\350\247\210\346\214\211\351\222\256\357\274\201", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Photos);
    } // retranslateUi

};

namespace Ui {
    class Photos: public Ui_Photos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOS_H
