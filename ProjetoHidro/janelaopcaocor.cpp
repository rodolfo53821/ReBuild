#include "janelaopcaocor.h"
#include "ui_janelaopcaocor.h"

/*!
  \class janelaOpcaoCor


     \previouspage janelaCamadas

     \contentspage

     \nextpage janelaopcaofb

     \startpage All Classes


  \brief Class to create the window color option

  */

janelaOpcaoCor::janelaOpcaoCor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelaOpcaoCor)
{
    ui->setupUi(this);



    //inserir elementos na lista
    QStringList nomeDasCores = QColor::colorNames();

    for (int i = 0; i < nomeDasCores.size(); ++i) {
        QColor color(nomeDasCores[i]);

        if(color.alpha() != 255 ) continue;
        ui->caixaCorAlagamento->insertItem(i, nomeDasCores[i]);
        ui->caixaCorAlagamento->setItemData(i, color, Qt::DecorationRole);
    }


    for (int i = 0; i < nomeDasCores.size(); ++i) {
        QColor color(nomeDasCores[i]);

        ui->caixaCorBarragem->insertItem(i, nomeDasCores[i]);
        ui->caixaCorBarragem->setItemData(i, color, Qt::DecorationRole);
    }



    for (int i = 0; i < nomeDasCores.size(); ++i) {
        QColor color(nomeDasCores[i]);

        ui->caixaCorMenorElevacao->insertItem(i, nomeDasCores[i]);
        ui->caixaCorMenorElevacao->setItemData(i, color, Qt::DecorationRole);
    }

    for (int i = 0; i < nomeDasCores.size(); ++i) {
        QColor color(nomeDasCores[i]);

        ui->caixaCorMaiorElevacao->insertItem(i, nomeDasCores[i]);
        ui->caixaCorMaiorElevacao->setItemData(i, color, Qt::DecorationRole);
    }



    for (int i = 0; i < nomeDasCores.size(); ++i) {
        QColor color(nomeDasCores[i]);

        ui->caixaCorRedeDeDrenagem->insertItem(i, nomeDasCores[i]);
        ui->caixaCorRedeDeDrenagem->setItemData(i, color, Qt::DecorationRole);
    }

}

janelaOpcaoCor::~janelaOpcaoCor()
{
    delete ui;
}


QStringList janelaOpcaoCor::getValores(bool &ok){



    //exec espera por uma acao do usuario
    int botaoApertado = exec();

    QStringList parametrosResposta;


    if(botaoApertado == QDialog::Accepted){
        ok = true;

        //artificio utilizado para setar cores default
        if(ui->corPadraoCaixa->isChecked())
            return  parametrosResposta;

        //obtendo a cor selecionada para alagamento
        QVariant corVariant = ui->caixaCorAlagamento->itemData(ui->caixaCorAlagamento->currentIndex(),Qt::DecorationRole);
        QColor cor = corVariant.value<QColor>();

        parametrosResposta.push_back(cor.name());


        //obtendo a cor selecionada para alagamento
        corVariant = ui->caixaCorBarragem->itemData(ui->caixaCorBarragem->currentIndex(),Qt::DecorationRole);
        cor = corVariant.value<QColor>();

        parametrosResposta.push_back(cor.name());



        //obtendo a cor selecionada para alagamento
        corVariant = ui->caixaCorMaiorElevacao->itemData(ui->caixaCorMaiorElevacao->currentIndex(),Qt::DecorationRole);
        cor = corVariant.value<QColor>();

        parametrosResposta.push_back(cor.name());


        //obtendo a cor selecionada para alagamento
        corVariant = ui->caixaCorMenorElevacao->itemData(ui->caixaCorMenorElevacao->currentIndex(),Qt::DecorationRole);
        cor = corVariant.value<QColor>();

        parametrosResposta.push_back(cor.name());


        //obtendo a cor selecionada para alagamento
        corVariant = ui->caixaCorRedeDeDrenagem->itemData(ui->caixaCorRedeDeDrenagem->currentIndex(),Qt::DecorationRole);
        cor = corVariant.value<QColor>();

        parametrosResposta.push_back(cor.name());

        ok = true;
    }else

    {

        if(botaoApertado == QDialog::Rejected)
             ok = false;
        else
            ok = true;
    }

    return parametrosResposta;


}
