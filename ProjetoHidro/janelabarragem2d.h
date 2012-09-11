#ifndef JANELABARRAGEM2D_H
#define JANELABARRAGEM2D_H

#include <QDialog>
#include<VisualizacaoMapa.h>

namespace Ui {
class janelaBarragem2D;
}

class janelaBarragem2D : public QDialog
{
    Q_OBJECT

public:

    //==construtor e destrutor
    explicit janelaBarragem2D(QWidget *parent = 0);
    ~janelaBarragem2D();



    //====metodos
    void recarregandoMapa(VisualizacaoMapa *viMapa);


private:
    //===atributo
    Ui::janelaBarragem2D *ui;
};

#endif // JANELABARRAGEM2D_H
