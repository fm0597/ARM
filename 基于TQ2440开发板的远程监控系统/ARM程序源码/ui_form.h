/********************************************************************************
** Form generated from reading ui file 'form.ui'
**
** Created: Sat May 17 07:32:59 2014
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(480, 272);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 50, 121, 17));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 90, 121, 17));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 120, 321, 21));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(340, 200, 81, 21));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 230, 112, 26));
        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 150, 321, 21));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "\350\277\234\347\250\213\347\233\221\346\216\247\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "\346\214\207\345\257\274\350\200\201\345\270\210\357\274\232\347\216\213\351\234\207", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "\345\260\217\347\273\204\346\210\220\345\221\230\357\274\232\346\242\201\345\242\236\345\233\275 \345\224\220\345\256\217\346\226\214 \345\220\264\344\277\212\346\235\260 \346\233\276\344\276\235\345\251\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "2014/05/17", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form", "\347\217\255\347\272\247\357\274\232   11\347\272\247\350\256\241\347\256\227\346\234\272", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
