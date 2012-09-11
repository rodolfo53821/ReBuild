#ifndef JANELACAMADAS_H
#define JANELACAMADAS_H

#include <QInputDialog>

namespace Ui {
class janelaCamadas;
}

class janelaCamadas : public QDialog
{
    Q_OBJECT

public:


    explicit janelaCamadas(QWidget *parent = 0);
    ~janelaCamadas();

    //===metodo
    QStringList getValores(bool&);//sobescrito usado para obter os valores da janela

private slots:


private:

    //====atributos
    Ui::janelaCamadas *ui;
};

#endif // JANELACAMADAS_H
