#ifndef JANELAOPCAOCOR_H
#define JANELAOPCAOCOR_H

#include <QDialog>

namespace Ui {
    class janelaOpcaoCor;
}

class janelaOpcaoCor : public QDialog
{
    Q_OBJECT

public:

    //====construtor e destrutor
    explicit janelaOpcaoCor(QWidget *parent = 0);
    ~janelaOpcaoCor();

    //====metodo
    QStringList getValores(bool &ok);//sobescrito usado para obter os valores da janela

private:

    //===atributo
    Ui::janelaOpcaoCor *ui;
};

#endif // JANELAOPCAOCOR_H
