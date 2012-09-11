#include "janelasobre.h"
#include "ui_janelasobre.h"


/*!
  \class janelasobre

     \previouspage JanelaPrincipal

     \contentspage

     \nextpage MapaMDE

     \startpage All Classes



  \brief Class to create the about window

  */

/*!
  \fn janelasobre::janelasobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelasobre)
  \brief Constructor

  */

janelasobre::janelasobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelasobre)
{
    ui->setupUi(this);
}

/*!
  \fn janelasobre::~janelasobre()
  \brief Destructor

  */

janelasobre::~janelasobre()
{
    delete ui;
}
