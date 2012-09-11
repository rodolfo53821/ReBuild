#ifndef JANELASOBRE_H
#define JANELASOBRE_H

#include <QDialog>

namespace Ui {
    class janelasobre;
}

class janelasobre : public QDialog
{
    Q_OBJECT

public:
    explicit janelasobre(QWidget *parent = 0);
    ~janelasobre();

private:
    Ui::janelasobre *ui;
};

#endif // JANELASOBRE_H
