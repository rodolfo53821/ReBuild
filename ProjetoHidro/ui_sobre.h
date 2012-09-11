/********************************************************************************
** Form generated from reading UI file 'sobre.ui'
**
** Created: Fri 6. Jul 14:27:54 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOBRE_H
#define UI_SOBRE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(277, 238);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 0, 131, 121));
        label->setWordWrap(true);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 80, 131, 16));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 140, 101, 16));
        line = new QFrame(Dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 160, 241, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 100, 121, 16));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 180, 46, 13));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 180, 71, 61));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../imagens/brasaoUFVPequeno.png")));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Sistema de posicionamento de barragens", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Desenvolvido em 2012", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Vers\303\243o Beta 1.0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "TARG-Terrain", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "Apoio:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOBRE_H
