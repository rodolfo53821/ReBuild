#ifndef JANELAOPCAOFB_H
#define JANELAOPCAOFB_H

#include <QDialog>

namespace Ui {
    class janelaopcaofb;
}

class janelaopcaofb : public QDialog
{
    Q_OBJECT

public:
    explicit janelaopcaofb(QWidget *parent = 0);
    ~janelaopcaofb();


    //metodos sobescrito
    QStringList getValores(bool &ok);

private:
    Ui::janelaopcaofb *ui;
};

#endif // JANELAOPCAOFB_H
