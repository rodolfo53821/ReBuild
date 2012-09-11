#include "janelabarragem.h"
#include "ui_janelabarragem.h"





/*!
  \class janelabarragem

     \previouspage Inundacao

     \contentspage All Classes

     \nextpage janelaBarragem2D

     \indexpage Fluxo

     \startpage All Classes




  \brief Class to create a window 3D view of reservoir and terrain

  */


/*!
  \fn janelabarragem::janelabarragem(VisualizacaoMapa *viMapa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelabarragem)
  \brief Constructor the painel with 3D view of reservoir
  */
janelabarragem::janelabarragem(VisualizacaoMapa *viMapa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelabarragem)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window);
    //posicionado sempre no cantinho superior direito da tela do programa

    this->setGeometry((parent->x()+ parent->width())- this->width(),parent->y(),this->width(),this->height());

    ui->widget->makeCurrent();
    ui->widget->carregandoInformacoes(viMapa);

    ui->widget->updateGL();

}

/*!
  \fn janelabarragem::~janelabarragem()
  \brief Destructor
  */

janelabarragem::~janelabarragem()
{
    delete ui;
}

void janelabarragem::on_pushButton_clicked()
{



}

void janelabarragem::on_pushButton_2_clicked()
{



}

void janelabarragem::on_novoDireCamX_valueChanged(int arg1)
{

}

void janelabarragem::on_spinBoxPosicaoX_valueChanged(int arg1)
{


    ui->widget->posicaoCamera[0] = arg1;


    ui->widget->updateGL();

}

void janelabarragem::on_spinBoxPosicaoZ_valueChanged(int arg1)
{
    ui->widget->posicaoCamera[2] = arg1;


    ui->widget->updateGL();

}

void janelabarragem::on_spinBoxPosicaoY_valueChanged(int arg1)
{
    ui->widget->posicaoCamera[1] = arg1;


    ui->widget->updateGL();
}

void janelabarragem::on_spinBoxDirecaoX_valueChanged(int arg1)
{
    ui->widget->direcaoCamera[0] = arg1;


    ui->widget->updateGL();

}

void janelabarragem::on_spinBoxDirecaoY_valueChanged(int arg1)
{
    ui->widget->direcaoCamera[1] = arg1;


    ui->widget->updateGL();
}

void janelabarragem::on_spinBoxDirecaoZ_valueChanged(int arg1)
{
    ui->widget->direcaoCamera[2] = arg1;


    ui->widget->updateGL();
}

void janelabarragem::on_spinBoxNormalY_valueChanged(int arg1)
{
    ui->widget->normalCamera[1] = arg1;


    ui->widget->updateGL();
}

void janelabarragem::on_spinBoxNormalX_valueChanged(int arg1)
{
    ui->widget->normalCamera[0] = arg1;


    ui->widget->updateGL();
}


void janelabarragem::on_spinBoxNormalZ_valueChanged(int arg1)
{
    ui->widget->normalCamera[2] = arg1;


    ui->widget->updateGL();
}
