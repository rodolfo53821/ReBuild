/********************************************************************************
** Form generated from reading UI file 'janelacamada.ui'
**
** Created: Tue 20. Mar 12:39:38 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELACAMADA_H
#define UI_JANELACAMADA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *caixaNomeDaCamada;
    QLabel *label;
    QLineEdit *caixaPesoDaCamada;
    QLabel *label_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(371, 171);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        caixaNomeDaCamada = new QLineEdit(Dialog);
        caixaNomeDaCamada->setObjectName(QString::fromUtf8("caixaNomeDaCamada"));
        caixaNomeDaCamada->setGeometry(QRect(90, 10, 113, 20));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 46, 13));
        caixaPesoDaCamada = new QLineEdit(Dialog);
        caixaPesoDaCamada->setObjectName(QString::fromUtf8("caixaPesoDaCamada"));
        caixaPesoDaCamada->setGeometry(QRect(90, 50, 113, 20));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 46, 13));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Nome", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Peso", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELACAMADA_H
