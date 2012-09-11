#include <QtGui/QApplication>
#include "janelaprincipal.h"
#include <iostream>

using namespace std;





/*!
     \page classes.html
     \title All Classes
     \previouspage VisualizacaoMapa


     \nextpage Camada




The classes of the project are listed below.

     \generatelist classes

 */





int main(int argc, char *argv[])
{

    QList<Point> listaDePontos;

    for(int i = 0;i<6;i++){
        Point aux(1,0);
          listaDePontos.append(aux);
    }

    QApplication a(argc, argv);
    JanelaPrincipal w;
    w.show();

    return a.exec();
}
