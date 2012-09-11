#include "janelacamadas.h"
#include "ui_janelacamadas.h"


/*!
  \class janelaCamadas



     \previouspage janelaBarragem2D

     \contentspage

     \nextpage janelaOpcaoCor

     \startpage All Classes


  \brief Class to create a window for inserting new camadas
  */

janelaCamadas::janelaCamadas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelaCamadas)
{
    ui->setupUi(this);

    //inserir elementos na lista
    QStringList nomeDasCores = QColor::colorNames();

    for (int i = 0; i < nomeDasCores.size(); ++i) {
        QColor color(nomeDasCores[i]);

        ui->caixaBoxCor->insertItem(i, nomeDasCores[i]);
        ui->caixaBoxCor->setItemData(i, color, Qt::DecorationRole);
    }





}

janelaCamadas::~janelaCamadas()
{
    delete ui;
}


QStringList janelaCamadas::getValores(bool &ok){



    //exec espera por uma acao do usuario
    int botaoApertado = exec();

    QStringList parametrosResposta;


    if(botaoApertado == QDialog::Accepted){
        ok = true;
        //inserindo os elementos da entrada
        parametrosResposta.push_back(ui->caixaEntradaNomeDaCamada->text());
        parametrosResposta.push_back(ui->caixaEntradaPesoDaCamada->text());

        //obtendo a cor selecionada
        QVariant corVariant = ui->caixaBoxCor->itemData(ui->caixaBoxCor->currentIndex(),Qt::DecorationRole);
        QColor cor = corVariant.value<QColor>();

        parametrosResposta.push_back(cor.name());

        ok = true;
    }else {
        ok = false;
    }

    return parametrosResposta;


}



