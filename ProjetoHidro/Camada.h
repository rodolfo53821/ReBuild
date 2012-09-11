#ifndef CAMADA_H
#define CAMADA_H

#include<QList>
#include<QColor>



class Point{
private:
    int i,j;

public:
    Point(){
        i = j = 0;
    }

    Point(int iN, int jN){
        i = iN; j = jN;
    }
    Point(const Point &p){
        i = p.i;
        j = p.j;
    }

    int getI() const{return i;}
    int getJ()const{return j;}

   bool operator==(const Point&p) const{
      if(this->i == p.i && this->j == p.j)
      return true;
  else
          return false;
    }


};




class Camada{

public:


    //====Construtores e destrutores
    Camada();//default
    Camada(QString,double,QColor,int nLinha,int nColun);
    Camada(Camada const &);//de copia
    ~Camada();//destrutor



    //====atributos
    bool **pontos;//define quais os pontos sao importantes(criticos)
    QList<Point> listaDePontos; //utilizada para guarda os pontos e ao pintar nao precisar percorrer toda a matriz
    int nLinhas;
    int nColunas;
    //TODO
    bool estaIncluidoNoAlgoritmo;//variavel que permite a camada estar no algoritmo ou nao
    bool estaVisivel;//é visível



    //=====metodos
    QString getNome();
    void setNome(QString);
    double getPeso();
    void setPeso(double);
    QColor getCorCamada();
    void setCorCamada(QColor);
    bool getEstaIncluidoNoAlgoritmo();
    void setEstaIncluidoNoAlgoritmo(bool);
    void alteraPonto(Point p,bool add);



    //====sobrecarga de operadores
    Camada&  operator=(Camada  const&);//de atribuicao
    bool operator==(Camada const&) const;//de igualdade



private:


//=====atributos
    QString nome;
    double peso;
    QColor corCamada;






};

#endif // CAMADA_H
