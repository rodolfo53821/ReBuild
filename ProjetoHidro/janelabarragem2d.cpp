#include "janelabarragem2d.h"
#include "ui_janelabarragem2d.h"

/*!
  \class janelaBarragem2D

     \previouspage janelabarragem

     \contentspage

     \nextpage janelaCamadas

     \startpage All Classes


  \brief Class to create a window 2D view of the reservoir
  */


janelaBarragem2D::janelaBarragem2D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelaBarragem2D)
{

    ui->setupUi(this);
    //  setWindowFlags(Qt::WindowStaysOnTopHint);

}



void janelaBarragem2D::recarregandoMapa(VisualizacaoMapa *viMapa){
    ui->widget->makeCurrent();

    //CARREGANDO INFO DA BARRAGEM

    //ATUALIZA A LISTA
    ui->textEdit3->setText(ui->textEdit2->toPlainText());
    ui->textEdit2->setText(ui->textEdit1->toPlainText());


    QString infoBarragem = " Info Barragem ";
    QString altBarragem = "AlturaBarragem-";
    QString areaAlagada = "Area Alagada-";
    QString tamanhoBarragem = "Extensao Barragem-";
    altBarragem += QString::number(viMapa->inundacao->nivelAgua);
    areaAlagada +=QString::number(viMapa->inundacao->areaLaminaAgua);
    tamanhoBarragem +=QString::number(viMapa->inundacao->comprimentoBarragemTocada);

    infoBarragem += "\n";
    infoBarragem+=altBarragem +"\n"+ areaAlagada +"\n"+ tamanhoBarragem;

    ui->textEdit1->setText(infoBarragem);




    ui->widget->carregandoInformacoes(viMapa);

}



janelaBarragem2D::~janelaBarragem2D()
{
    delete ui;
}
