/********************************************************************************
** Form generated from reading UI file 'janelaopcaocor.ui'
**
** Created: Mon 6. Aug 16:12:18 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAOPCAOCOR_H
#define UI_JANELAOPCAOCOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_janelaOpcaoCor
{
public:
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *caixaCorMaiorElevacao;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *caixaCorMenorElevacao;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *caixaCorRedeDeDrenagem;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *caixaCorAlagamento;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *caixaCorBarragem;
    QCheckBox *corPadraoCaixa;

    void setupUi(QDialog *janelaOpcaoCor)
    {
        if (janelaOpcaoCor->objectName().isEmpty())
            janelaOpcaoCor->setObjectName(QString::fromUtf8("janelaOpcaoCor"));
        janelaOpcaoCor->resize(292, 230);
        janelaOpcaoCor->setMinimumSize(QSize(292, 230));
        janelaOpcaoCor->setMaximumSize(QSize(292, 230));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../imagens/logo3.png"), QSize(), QIcon::Normal, QIcon::Off);
        janelaOpcaoCor->setWindowIcon(icon);
        groupBox = new QGroupBox(janelaOpcaoCor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 271, 211));
        groupBox->setMinimumSize(QSize(271, 211));
        buttonBox_2 = new QDialogButtonBox(groupBox);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(10, 170, 161, 32));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 231, 136));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        caixaCorMaiorElevacao = new QComboBox(layoutWidget);
        caixaCorMaiorElevacao->setObjectName(QString::fromUtf8("caixaCorMaiorElevacao"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(caixaCorMaiorElevacao->sizePolicy().hasHeightForWidth());
        caixaCorMaiorElevacao->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(caixaCorMaiorElevacao);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        caixaCorMenorElevacao = new QComboBox(layoutWidget);
        caixaCorMenorElevacao->setObjectName(QString::fromUtf8("caixaCorMenorElevacao"));
        sizePolicy.setHeightForWidth(caixaCorMenorElevacao->sizePolicy().hasHeightForWidth());
        caixaCorMenorElevacao->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(caixaCorMenorElevacao);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        caixaCorRedeDeDrenagem = new QComboBox(layoutWidget);
        caixaCorRedeDeDrenagem->setObjectName(QString::fromUtf8("caixaCorRedeDeDrenagem"));
        sizePolicy.setHeightForWidth(caixaCorRedeDeDrenagem->sizePolicy().hasHeightForWidth());
        caixaCorRedeDeDrenagem->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(caixaCorRedeDeDrenagem);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        caixaCorAlagamento = new QComboBox(layoutWidget);
        caixaCorAlagamento->setObjectName(QString::fromUtf8("caixaCorAlagamento"));
        sizePolicy.setHeightForWidth(caixaCorAlagamento->sizePolicy().hasHeightForWidth());
        caixaCorAlagamento->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(caixaCorAlagamento);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        caixaCorBarragem = new QComboBox(layoutWidget);
        caixaCorBarragem->setObjectName(QString::fromUtf8("caixaCorBarragem"));
        sizePolicy.setHeightForWidth(caixaCorBarragem->sizePolicy().hasHeightForWidth());
        caixaCorBarragem->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(caixaCorBarragem);


        verticalLayout->addLayout(horizontalLayout_5);

        corPadraoCaixa = new QCheckBox(groupBox);
        corPadraoCaixa->setObjectName(QString::fromUtf8("corPadraoCaixa"));
        corPadraoCaixa->setGeometry(QRect(180, 178, 91, 17));

        retranslateUi(janelaOpcaoCor);
        QObject::connect(buttonBox_2, SIGNAL(accepted()), janelaOpcaoCor, SLOT(accept()));
        QObject::connect(buttonBox_2, SIGNAL(rejected()), janelaOpcaoCor, SLOT(reject()));

        QMetaObject::connectSlotsByName(janelaOpcaoCor);
    } // setupUi

    void retranslateUi(QDialog *janelaOpcaoCor)
    {
        janelaOpcaoCor->setWindowTitle(QApplication::translate("janelaOpcaoCor", "Mude as cores", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("janelaOpcaoCor", "Cores", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("janelaOpcaoCor", "Maior Eleva\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("janelaOpcaoCor", "Menor Eleva\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("janelaOpcaoCor", "Rede de drenagem", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("janelaOpcaoCor", "Alagamento", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("janelaOpcaoCor", "Barragem", 0, QApplication::UnicodeUTF8));
        corPadraoCaixa->setText(QApplication::translate("janelaOpcaoCor", "Cores Padr\303\243o", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class janelaOpcaoCor: public Ui_janelaOpcaoCor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAOPCAOCOR_H
