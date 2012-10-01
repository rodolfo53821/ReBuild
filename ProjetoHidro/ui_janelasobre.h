/********************************************************************************
** Form generated from reading UI file 'janelasobre.ui'
**
** Created: Mon 1. Oct 11:20:29 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELASOBRE_H
#define UI_JANELASOBRE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_janelasobre
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;

    void setupUi(QDialog *janelasobre)
    {
        if (janelasobre->objectName().isEmpty())
            janelasobre->setObjectName(QString::fromUtf8("janelasobre"));
        janelasobre->resize(325, 273);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(janelasobre->sizePolicy().hasHeightForWidth());
        janelasobre->setSizePolicy(sizePolicy);
        janelasobre->setMinimumSize(QSize(325, 273));
        janelasobre->setMaximumSize(QSize(325, 273));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../imagens/logo3.png"), QSize(), QIcon::Normal, QIcon::Off);
        janelasobre->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(janelasobre);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(250, 170, 71, 21));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        line = new QFrame(janelasobre);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(5, 193, 311, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(janelasobre);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 210, 46, 13));
        label_2 = new QLabel(janelasobre);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 210, 81, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../imagens/brasaoUFVPequeno.png")));
        label_3 = new QLabel(janelasobre);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 210, 81, 61));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../imagens/brasaoDPI.png")));
        label_4 = new QLabel(janelasobre);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 50, 231, 41));
        label_4->setWordWrap(true);
        label_5 = new QLabel(janelasobre);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(168, 76, 171, 16));
        label_6 = new QLabel(janelasobre);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 110, 46, 13));
        label_7 = new QLabel(janelasobre);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 100, 201, 16));
        label_8 = new QLabel(janelasobre);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 170, 211, 16));
        label_9 = new QLabel(janelasobre);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(250, 190, 111, 91));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../imagens/logoCapes.png")));
        label_10 = new QLabel(janelasobre);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 120, 221, 31));
        label_10->setWordWrap(true);
        label_11 = new QLabel(janelasobre);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(150, 150, 121, 16));
        label_12 = new QLabel(janelasobre);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(60, -10, 211, 81));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../imagens/nomeLogoGrande.png")));
        label_13 = new QLabel(janelasobre);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(150, 130, 131, 16));
        label_14 = new QLabel(janelasobre);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(250, 30, 46, 13));

        retranslateUi(janelasobre);
        QObject::connect(buttonBox, SIGNAL(accepted()), janelasobre, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), janelasobre, SLOT(reject()));

        QMetaObject::connectSlotsByName(janelasobre);
    } // setupUi

    void retranslateUi(QDialog *janelasobre)
    {
        janelasobre->setWindowTitle(QApplication::translate("janelasobre", "Sobre", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("janelasobre", "Apoio:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("janelasobre", "Reservoir Building - Sistema de posicionamento de barragens para cria\303\247\303\243o de reservat\303\263rios h\303\255dricos.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("janelasobre", "Vers\303\243o Beta 1.0/2012", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("janelasobre", "Laborat\303\263rio de pesquisa TARG/DPI-UFV", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("janelasobre", "Contato: rodolfo53821@hotmail.com", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("janelasobre", "Desenvolvedores:                 ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("janelasobre", "Maur\303\255cio Gouv\303\252a Gruppi", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        label_13->setText(QApplication::translate("janelasobre", "Rodolfo da Costa Ladeira", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("janelasobre", "v.b.1.0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class janelasobre: public Ui_janelasobre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELASOBRE_H
