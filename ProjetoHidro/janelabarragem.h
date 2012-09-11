#ifndef JANELABARRAGEM_H
#define JANELABARRAGEM_H

#include <QDialog>
#include "VisualizacaoMapa.h"

namespace Ui {
    class janelabarragem;
}

class janelabarragem : public QDialog
{
    Q_OBJECT

public:

   explicit janelabarragem(VisualizacaoMapa*,QWidget *parent = 0);
     ~janelabarragem();

private slots:

    //slots para os botoes...
    void on_pushButton_clicked();//botao ok
    void on_pushButton_2_clicked();//botao cancel
    void on_novoDireCamX_valueChanged(int arg1);
    void on_spinBoxPosicaoX_valueChanged(int arg1);
    void on_spinBoxPosicaoZ_valueChanged(int arg1);
    void on_spinBoxPosicaoY_valueChanged(int arg1);
    void on_spinBoxDirecaoX_valueChanged(int arg1);
    void on_spinBoxDirecaoY_valueChanged(int arg1);
    void on_spinBoxDirecaoZ_valueChanged(int arg1);
    void on_spinBoxNormalY_valueChanged(int arg1);
    void on_spinBoxNormalX_valueChanged(int arg1);
    void on_spinBoxNormalZ_valueChanged(int arg1);

private:

    Ui::janelabarragem *ui;
};

#endif // JANELABARRAGEM_H
