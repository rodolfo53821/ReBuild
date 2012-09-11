/********************************************************************************
** Form generated from reading UI file 'janelabarragem.ui'
**
** Created: Thu 16. Aug 23:00:50 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELABARRAGEM_H
#define UI_JANELABARRAGEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QSpinBox>
#include "painelvisualizacaobarragemopengl.h"

QT_BEGIN_NAMESPACE

class Ui_janelabarragem
{
public:
    PainelVisualizacaoBarragemOpenGL *widget;
    QSpinBox *spinBoxPosicaoX;
    QSpinBox *spinBoxPosicaoY;
    QSpinBox *spinBoxPosicaoZ;
    QSpinBox *spinBoxDirecaoY;
    QSpinBox *spinBoxDirecaoX;
    QSpinBox *spinBoxDirecaoZ;
    QSpinBox *spinBoxNormalZ;
    QSpinBox *spinBoxNormalX;
    QSpinBox *spinBoxNormalY;

    void setupUi(QDialog *janelabarragem)
    {
        if (janelabarragem->objectName().isEmpty())
            janelabarragem->setObjectName(QString::fromUtf8("janelabarragem"));
        janelabarragem->setEnabled(true);
        janelabarragem->resize(399, 426);
        janelabarragem->setModal(false);
        widget = new PainelVisualizacaoBarragemOpenGL(janelabarragem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 351, 311));
        widget->setMouseTracking(true);
        widget->setFocusPolicy(Qt::ClickFocus);
        widget->setAutoFillBackground(true);
        spinBoxPosicaoX = new QSpinBox(janelabarragem);
        spinBoxPosicaoX->setObjectName(QString::fromUtf8("spinBoxPosicaoX"));
        spinBoxPosicaoX->setGeometry(QRect(340, 350, 42, 22));
        spinBoxPosicaoY = new QSpinBox(janelabarragem);
        spinBoxPosicaoY->setObjectName(QString::fromUtf8("spinBoxPosicaoY"));
        spinBoxPosicaoY->setGeometry(QRect(300, 330, 42, 22));
        spinBoxPosicaoZ = new QSpinBox(janelabarragem);
        spinBoxPosicaoZ->setObjectName(QString::fromUtf8("spinBoxPosicaoZ"));
        spinBoxPosicaoZ->setGeometry(QRect(300, 370, 42, 22));
        spinBoxPosicaoZ->setMaximum(1000);
        spinBoxDirecaoY = new QSpinBox(janelabarragem);
        spinBoxDirecaoY->setObjectName(QString::fromUtf8("spinBoxDirecaoY"));
        spinBoxDirecaoY->setGeometry(QRect(160, 330, 42, 22));
        spinBoxDirecaoX = new QSpinBox(janelabarragem);
        spinBoxDirecaoX->setObjectName(QString::fromUtf8("spinBoxDirecaoX"));
        spinBoxDirecaoX->setGeometry(QRect(200, 350, 42, 22));
        spinBoxDirecaoZ = new QSpinBox(janelabarragem);
        spinBoxDirecaoZ->setObjectName(QString::fromUtf8("spinBoxDirecaoZ"));
        spinBoxDirecaoZ->setGeometry(QRect(160, 370, 42, 22));
        spinBoxNormalZ = new QSpinBox(janelabarragem);
        spinBoxNormalZ->setObjectName(QString::fromUtf8("spinBoxNormalZ"));
        spinBoxNormalZ->setGeometry(QRect(40, 370, 42, 22));
        spinBoxNormalX = new QSpinBox(janelabarragem);
        spinBoxNormalX->setObjectName(QString::fromUtf8("spinBoxNormalX"));
        spinBoxNormalX->setGeometry(QRect(80, 350, 42, 22));
        spinBoxNormalY = new QSpinBox(janelabarragem);
        spinBoxNormalY->setObjectName(QString::fromUtf8("spinBoxNormalY"));
        spinBoxNormalY->setGeometry(QRect(40, 330, 42, 22));

        retranslateUi(janelabarragem);

        QMetaObject::connectSlotsByName(janelabarragem);
    } // setupUi

    void retranslateUi(QDialog *janelabarragem)
    {
        janelabarragem->setWindowTitle(QApplication::translate("janelabarragem", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class janelabarragem: public Ui_janelabarragem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELABARRAGEM_H
