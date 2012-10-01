/********************************************************************************
** Form generated from reading UI file 'janelaopcaofb.ui'
**
** Created: Mon 1. Oct 11:20:29 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAOPCAOFB_H
#define UI_JANELAOPCAOFB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_janelaopcaofb
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *caixaEntradaPesoEB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *caixaEntradaPesoHB;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *caixaEntradaPesoAB;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *caixaEntradaPesoC;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *caixaEntradaPesoAA;
    QLabel *label_7;
    QCheckBox *checkBoxPadrao;

    void setupUi(QDialog *janelaopcaofb)
    {
        if (janelaopcaofb->objectName().isEmpty())
            janelaopcaofb->setObjectName(QString::fromUtf8("janelaopcaofb"));
        janelaopcaofb->resize(286, 236);
        janelaopcaofb->setMinimumSize(QSize(286, 236));
        janelaopcaofb->setMaximumSize(QSize(286, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../imagens/logo3.png"), QSize(), QIcon::Normal, QIcon::Off);
        janelaopcaofb->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(janelaopcaofb);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(64, 200, 157, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(janelaopcaofb);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(6, 74, 133, 119));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(14, 24, 113, 80));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        caixaEntradaPesoEB = new QLineEdit(layoutWidget);
        caixaEntradaPesoEB->setObjectName(QString::fromUtf8("caixaEntradaPesoEB"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(caixaEntradaPesoEB->sizePolicy().hasHeightForWidth());
        caixaEntradaPesoEB->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(caixaEntradaPesoEB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(22);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        caixaEntradaPesoHB = new QLineEdit(layoutWidget);
        caixaEntradaPesoHB->setObjectName(QString::fromUtf8("caixaEntradaPesoHB"));
        sizePolicy.setHeightForWidth(caixaEntradaPesoHB->sizePolicy().hasHeightForWidth());
        caixaEntradaPesoHB->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(caixaEntradaPesoHB);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(28);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        caixaEntradaPesoAB = new QLineEdit(layoutWidget);
        caixaEntradaPesoAB->setObjectName(QString::fromUtf8("caixaEntradaPesoAB"));
        sizePolicy.setHeightForWidth(caixaEntradaPesoAB->sizePolicy().hasHeightForWidth());
        caixaEntradaPesoAB->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(caixaEntradaPesoAB);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_2 = new QGroupBox(janelaopcaofb);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(148, 74, 131, 119));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 38, 107, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        caixaEntradaPesoC = new QLineEdit(layoutWidget1);
        caixaEntradaPesoC->setObjectName(QString::fromUtf8("caixaEntradaPesoC"));

        horizontalLayout_4->addWidget(caixaEntradaPesoC);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(23);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        caixaEntradaPesoAA = new QLineEdit(layoutWidget1);
        caixaEntradaPesoAA->setObjectName(QString::fromUtf8("caixaEntradaPesoAA"));

        horizontalLayout_5->addWidget(caixaEntradaPesoAA);


        verticalLayout_2->addLayout(horizontalLayout_5);

        label_7 = new QLabel(janelaopcaofb);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 12, 233, 57));
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);
        checkBoxPadrao = new QCheckBox(janelaopcaofb);
        checkBoxPadrao->setObjectName(QString::fromUtf8("checkBoxPadrao"));
        checkBoxPadrao->setGeometry(QRect(226, 206, 70, 17));

        retranslateUi(janelaopcaofb);
        QObject::connect(buttonBox, SIGNAL(accepted()), janelaopcaofb, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), janelaopcaofb, SLOT(reject()));

        QMetaObject::connectSlotsByName(janelaopcaofb);
    } // setupUi

    void retranslateUi(QDialog *janelaopcaofb)
    {
        janelaopcaofb->setWindowTitle(QApplication::translate("janelaopcaofb", "Peso das caracter\303\255sticas", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("janelaopcaofb", "Barragem", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("janelaopcaofb", "Extens\303\243o", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("janelaopcaofb", "Altura", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("janelaopcaofb", "\303\201rea", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("janelaopcaofb", "Reservat\303\263rio", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("janelaopcaofb", "Volume", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("janelaopcaofb", "\303\201rea ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("janelaopcaofb", "Dica: quanto maior o peso mais cr\303\255tica \303\251 a caracter\303\255stica. I.e. \303\251 mais importante (necess\303\241rio) que ap\303\263s gerar o reservat\303\263rio esta caracter\303\255stica tenha o seu valor mais baixo", 0, QApplication::UnicodeUTF8));
        checkBoxPadrao->setText(QApplication::translate("janelaopcaofb", "Padr\303\243o", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class janelaopcaofb: public Ui_janelaopcaofb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAOPCAOFB_H
