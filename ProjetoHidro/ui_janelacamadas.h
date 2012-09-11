/********************************************************************************
** Form generated from reading UI file 'janelacamadas.ui'
**
** Created: Mon 6. Aug 11:20:49 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELACAMADAS_H
#define UI_JANELACAMADAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_janelaCamadas
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *caixaEntradaNomeDaCamada;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *caixaEntradaPesoDaCamada;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *caixaBoxCor;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *janelaCamadas)
    {
        if (janelaCamadas->objectName().isEmpty())
            janelaCamadas->setObjectName(QString::fromUtf8("janelaCamadas"));
        janelaCamadas->setWindowModality(Qt::ApplicationModal);
        janelaCamadas->resize(189, 130);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(janelaCamadas->sizePolicy().hasHeightForWidth());
        janelaCamadas->setSizePolicy(sizePolicy);
        janelaCamadas->setMinimumSize(QSize(189, 130));
        janelaCamadas->setMaximumSize(QSize(189, 130));
        janelaCamadas->setAutoFillBackground(false);
        layoutWidget = new QWidget(janelaCamadas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 172, 111));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        caixaEntradaNomeDaCamada = new QLineEdit(layoutWidget);
        caixaEntradaNomeDaCamada->setObjectName(QString::fromUtf8("caixaEntradaNomeDaCamada"));

        horizontalLayout->addWidget(caixaEntradaNomeDaCamada);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        caixaEntradaPesoDaCamada = new QLineEdit(layoutWidget);
        caixaEntradaPesoDaCamada->setObjectName(QString::fromUtf8("caixaEntradaPesoDaCamada"));

        horizontalLayout_2->addWidget(caixaEntradaPesoDaCamada);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        caixaBoxCor = new QComboBox(layoutWidget);
        caixaBoxCor->setObjectName(QString::fromUtf8("caixaBoxCor"));

        horizontalLayout_3->addWidget(caixaBoxCor);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(janelaCamadas);
        QObject::connect(buttonBox, SIGNAL(accepted()), janelaCamadas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), janelaCamadas, SLOT(reject()));

        QMetaObject::connectSlotsByName(janelaCamadas);
    } // setupUi

    void retranslateUi(QDialog *janelaCamadas)
    {
        janelaCamadas->setWindowTitle(QApplication::translate("janelaCamadas", "Camada", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("janelaCamadas", "Nome", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("janelaCamadas", "Peso", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("janelaCamadas", "Cor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class janelaCamadas: public Ui_janelaCamadas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELACAMADAS_H
