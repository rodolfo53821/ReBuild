#include "janelaopcaofb.h"
#include "ui_janelaopcaofb.h"
#include <QMessageBox>



/*!
  \class janelaopcaofb

     \previouspage janelaOpcaoCor

     \contentspage

     \nextpage JanelaPrincipal

     \startpage All Classes


  \brief Class to create the window objective function option

  */


janelaopcaofb::janelaopcaofb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelaopcaofb)
{
    ui->setupUi(this);
}

janelaopcaofb::~janelaopcaofb()
{
    delete ui;
}


QStringList janelaopcaofb::getValores(bool &ok){


    QStringList resp;
    int botaoApertado = exec();

    if(botaoApertado == QDialog::Accepted){


        ok = true;

        if(ui->checkBoxPadrao->isChecked())
            return resp;

        bool conv1,conv2,conv3,conv4,conv5;
        QString a;

        ui->caixaEntradaPesoAA->text().toInt(&conv1,10);
        ui->caixaEntradaPesoAB->text().toInt(&conv2,10);
        ui->caixaEntradaPesoC->text().toInt(&conv3,10);
        ui->caixaEntradaPesoEB->text().toInt(&conv4,10);
        ui->caixaEntradaPesoHB->text().toInt(&conv5,10);

        if(!conv1 || !conv2 || !conv3 || !conv4 ||!conv5){
            QMessageBox a;
            a.setText("Erro nos parâmetros");
            a.exec();
            ok = false;
            return resp;




        }


        resp.append(ui->caixaEntradaPesoAA->text());
        resp.append(ui->caixaEntradaPesoAB->text());
        resp.append(ui->caixaEntradaPesoC->text());
        resp.append(ui->caixaEntradaPesoEB->text());
        resp.append(ui->caixaEntradaPesoHB->text());





    }else
        ok = false;


    return resp;



}
