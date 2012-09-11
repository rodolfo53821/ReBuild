#include"Camada.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <QString>


/*!
  \class Camada


     \previouspage All Classes

     \contentspage

     \nextpage Fluxo
\startpage All Classes


  \brief Class for creating critical points.

When calculating the best position of the dam, the algorithm can use
these points to define regions where it is disadvantageous to have a reservoir.



  */


/*!
    \variable Camada::pontos
    \brief the a pointer to pointer, representing the matrix of critical points (I.e. the reservoir being at these points is (peso) disadvantageous  )
 */
/*!
    \variable Camada::nColunas
    \brief the number of lines in matrix
 */
/*!
    \variable Camada::nLinhas
    \brief the number of colluns in matrix
 */
/*!
    \variable Camada::estaIncluidoNoAlgoritmo
    \brief the value if this Camada is insert into algorithm dam positioning
 */
/*!
    \variable Camada::estaVisivel
    \brief the value if this Camada is actual showing to user
  */

/*!
    \variable Camada::listaDePontos
    \brief the list of critical points
  */






/*!
    \fn Camada::Camada()
    \brief Default constructor.

Set default values to attributes

  */
Camada::Camada(){

    nome = " ";
    peso = 1.0;
    pontos = NULL;

    corCamada.setRgb(1,0,0);
    nLinhas = nColunas = 0;

    estaVisivel = true;


}

/*!

   \overload Camada::operator=(Camada  const& c)
    The current object camada receive the attributes from c

  */

Camada& Camada::operator=(Camada  const& c){



    nome = c.nome;
    corCamada = c.corCamada;
    peso = c.peso;




    nLinhas = c.nLinhas;
    nColunas = c.nColunas;

    pontos =  new bool *[nLinhas];


    for(int i = 0; i < nLinhas; i++){
        pontos[i] = new bool[nColunas];
        for(int j = 0; j<nColunas; j++)
            pontos[i][j] = c.pontos[i][j];

    }


    estaVisivel = c.estaVisivel;
    estaIncluidoNoAlgoritmo = c.estaIncluidoNoAlgoritmo;

    for(int i = 0; i < c.listaDePontos.size(); i++)
        listaDePontos.append(c.listaDePontos.at(i));



    return *this;


}





/*!
    \fn Camada::Camada(QString n, double p,QColor c,int nLinha,int nColun)

     Constructor.

    Construct an object (Camada) tha will have:

    nome = n

    peso = p

    cor = c




  */

Camada::Camada(QString n, double p,QColor c,int nLinha,int nColun){




    nome = n;
    peso = p;
    corCamada = c;



    nLinhas = nLinha;
    nColunas = nColun;

    pontos =  new bool *[nLinhas];


    for(int i = 0; i < nLinhas; i++){
        pontos[i] = new bool[nColunas];
        for(int j = 0; j<nColunas; j++)
            pontos[i][j] = false;

    }

    estaVisivel = true;

}


/*!
    \fn Camada::Camada(Camada const &c)

    \brief Copy Constructor.
    Creates an object receiving attributes from c

  */
Camada::Camada(Camada const &c){
    nome = c.nome;
    corCamada = c.corCamada;
    peso = c.peso;


    nLinhas = c.nLinhas;
    nColunas = c.nColunas;

    pontos =  new bool *[nLinhas];


    for(int i = 0; i < nLinhas; i++){
        pontos[i] = new bool[nColunas];
        for(int j = 0; j<nColunas; j++)
            pontos[i][j] = c.pontos[i][j];

    }



    estaVisivel = c.estaVisivel;
    estaIncluidoNoAlgoritmo = c.estaIncluidoNoAlgoritmo;

    for(int i = 0; i < c.listaDePontos.size(); i++)
        listaDePontos.append(c.listaDePontos.at(i));


}

/*!
    \fn Camada::~Camada()

    \brief Destructor

  */
Camada::~Camada(){






        for(int i = 0; i < nLinhas; i++)
            delete [] pontos[i] ;

        delete pontos;





}
/*!
    \fn QString Camada::getNome()

    \brief Returns nome
  */


QString Camada::getNome(){


    return nome;
}


/*!
    \fn void Camada::setNome(QString n)

    \brief Set n to nome
  */
void Camada::setNome(QString n){
    nome = n;
}


/*!
    \fn double Camada::getPeso()

    \brief Returns peso
  */
double Camada::getPeso(){
    return peso;
}

/*!
    \fn void Camada::setPeso(double p)

    \brief Set p to peso
  */
void Camada::setPeso(double p){
    peso = p;

}
/*!

  \overload Camada::operator==(Camada const& c) const

    Return if two objects Camada are equal
  */

bool Camada::operator==(Camada const& c) const{


    return (QString::compare(nome,c.nome,Qt::CaseInsensitive) == 0);

}
/*!
    \fn QColor Camada::getCorCamada()

    \brief Return cor
  */

QColor Camada::getCorCamada(){
    return corCamada;
}

/*!
    \fn void Camada::setCorCamada(QColor c)

    \brief Set c to cor
  */
void Camada::setCorCamada(QColor c){
    corCamada = c;

}
/*!
    \fn bool Camada::getEstaIncluidoNoAlgoritmo()

    \brief Return estaIncluidoNoAlgoritmo
  */
bool Camada::getEstaIncluidoNoAlgoritmo(){
    return estaIncluidoNoAlgoritmo;

}

/*!
    \fn bool Camada::alteraPonto(Point p,bool add)

     \brief Change status of point p using add. Printed(add==true) or not
  */
void Camada::alteraPonto(Point p,bool add){

    if(p.getI()<0||p.getI()<0||p.getI()>=nLinhas||p.getJ()>=nColunas)
        return;


    try{


    if(add)
        listaDePontos.append(p);
    else
        listaDePontos.removeAt(listaDePontos.indexOf(p,0));


    pontos[p.getI()][p.getJ()] = add;

    }catch(...){

        int teste = 3;
        teste++;
    }



}

/*!
    \fn voi Camada::setEstaIncluidoNoAlgoritmo(bool op)

    \brief Set op to estaIncluidoNoAlgoritmo
  */
void Camada::setEstaIncluidoNoAlgoritmo(bool op){
    estaIncluidoNoAlgoritmo = op;
}
