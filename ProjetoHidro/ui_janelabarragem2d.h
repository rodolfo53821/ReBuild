/********************************************************************************
** Form generated from reading UI file 'janelabarragem2d.ui'
**
** Created: Mon 1. Oct 21:22:54 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELABARRAGEM2D_H
#define UI_JANELABARRAGEM2D_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include "painelvisualizacaobarragem2dopengl.h"

QT_BEGIN_NAMESPACE

class Ui_janelaBarragem2D
{
public:
    painelvisualizacaobarragem2dopengl *widget;
    QTextEdit *textEdit1;
    QTextEdit *textEdit2;
    QTextEdit *textEdit3;

    void setupUi(QDialog *janelaBarragem2D)
    {
        if (janelaBarragem2D->objectName().isEmpty())
            janelaBarragem2D->setObjectName(QString::fromUtf8("janelaBarragem2D"));
        janelaBarragem2D->resize(528, 479);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../imagens/logo3.png"), QSize(), QIcon::Normal, QIcon::Off);
        janelaBarragem2D->setWindowIcon(icon);
        widget = new painelvisualizacaobarragem2dopengl(janelaBarragem2D);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 501, 361));
        textEdit1 = new QTextEdit(janelaBarragem2D);
        textEdit1->setObjectName(QString::fromUtf8("textEdit1"));
        textEdit1->setGeometry(QRect(20, 380, 151, 91));
        textEdit2 = new QTextEdit(janelaBarragem2D);
        textEdit2->setObjectName(QString::fromUtf8("textEdit2"));
        textEdit2->setGeometry(QRect(190, 380, 151, 91));
        textEdit3 = new QTextEdit(janelaBarragem2D);
        textEdit3->setObjectName(QString::fromUtf8("textEdit3"));
        textEdit3->setGeometry(QRect(360, 380, 151, 91));

        retranslateUi(janelaBarragem2D);

        QMetaObject::connectSlotsByName(janelaBarragem2D);
    } // setupUi

    void retranslateUi(QDialog *janelaBarragem2D)
    {
        janelaBarragem2D->setWindowTitle(QApplication::translate("janelaBarragem2D", "Visualiza\303\247\303\243o 2D", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class janelaBarragem2D: public Ui_janelaBarragem2D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELABARRAGEM2D_H
