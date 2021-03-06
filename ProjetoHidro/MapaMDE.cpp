//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : MapaMDE.cpp
//  @ Date : 29/08/2011
//  @ Author : Rodolfo da Costa Ladeira
//
//


#include "MapaMDE.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <QString>
#include <QDate>
#include<janelaprincipal.h>

using namespace std;


/*!
  \class MapaMDE

     \previouspage janelasobre



     \nextpage painelvisualizacaobarragem2dopengl

     \startpage All Classes


 \indexpage All Classes
     \startpage All Classes


  \brief Class for create the MDE of terrain

  */


/*!
  \variable MapaMDE::matrizDeElevacoes
  \brief a pointer to pointer, representing a matrix of status of the cell. If it is dam, drainage network, flooded or nothing
*/

/*!
  \variable MapaMDE::maxElev
  \brief the maximum cell's elevation


*/

/*!
  \variable MapaMDE::minElev
  \brief the minimun cell's elevation

*/


/*!
  \fn MapaMDE::MapaMDE()
  \brief Constructor. Default Constructor. Do nothing

  */
MapaMDE::MapaMDE(){

}


/*!
  \fn MapaMDE::~MapaMDE()
  \brief Destructor.

  */
MapaMDE::~MapaMDE(){

    try{
        //liberando memoria apontada pelos ponteiros
        for(int i = 0; i < nLinhas;i++)
            delete matrizDeElevacoes[i];

        delete []matrizDeElevacoes;


        //previnindo que o ponteiro acesse memoria invalida
        matrizDeElevacoes = NULL;


        delete []caminhoArquivo;
        caminhoArquivo = NULL;
        delete [] nomeArquivo;
        nomeArquivo = NULL;

    }catch(exception e){
        QString erroMsg="Erro no destrutor da classe MapaMDE";
        ofstream erro(JanelaPrincipal::urllog.toStdString().data());


        erro<<"Erro ocorrido em: ";
        erro<< QDate::currentDate().toString("dd.MM.yyyy").toStdString();
        erro<<endl;
        erro<<erroMsg.toStdString()<<endl;
        erro<<e.what()<<endl;
        erro.close();



    }

}


/*!
    \fn MapaMDE::MapaMDE(MapaMDE const &mapaCopia)
    \brief Copy Constructor.
    Creates an object receiving attributes from mapaCopia




  */

MapaMDE::MapaMDE(MapaMDE const &mapaCopia){

    nColunas = mapaCopia.nColunas;
    nLinhas = mapaCopia.nLinhas;
    dadoInvalido = mapaCopia.dadoInvalido;
    xllcorner = mapaCopia.xllcorner;
    yllcorner = mapaCopia.yllcorner;

    matrizDeElevacoes = new short int *[nLinhas];


    for(int i = 0; i < nLinhas;i++)
        matrizDeElevacoes[i] = new short int[nColunas];


    for(int i=0; i<nLinhas; i++)
        for(int j=0; j<nColunas; j++)
            matrizDeElevacoes[i][j] = mapaCopia.matrizDeElevacoes[i][j];

    nomeArquivo =  new char [30];
    strcpy(nomeArquivo, mapaCopia.nomeArquivo);



    caminhoArquivo = new char[256];
    strcpy(caminhoArquivo, mapaCopia.caminhoArquivo);


    maxElev = mapaCopia.maxElev;
    minElev = mapaCopia.minElev;


}




/*!
  \fn MapaMDE::MapaMDE(const char * caminhoArquivo )
  \brief Constructor. Creates a object (MDE) for especified caminhoArquivo path

  */
MapaMDE::MapaMDE(const char * caminhoArquivo ) {
    //posteriormente pode-se ter como entrada
    //diversos outros formatos, porem por hora apenas
    //o asscii padrao do arcgis
    maxElev = 0;
    minElev = 999999;


    try {
        scannerAscii(caminhoArquivo);

    } catch (exception e) {
        QString erroMsg="Erro no m�todo scannerAscii classe MapaMDE";
        ofstream erro(JanelaPrincipal::urllog.toStdString().data());


        erro<<"Erro ocorrido em: ";
        erro<< QDate::currentDate().toString("dd.MM.yyyy").toStdString();
        erro<<endl;
        erro<<erroMsg.toStdString()<<endl;
        erro<<e.what()<<endl;
        erro.close();

    }


}

/*!
  \fn MapaMDE::getNColunas()
  \brief Returns the number of columns

  */

int MapaMDE::getNColunas() {
    return nColunas;

}

/*!
  \fn MapaMDE::getNLinhas()
   Returns the number of lines

  */
int MapaMDE::getNLinhas() {
    return nLinhas;
}


/*!
  \fn MapaMDE::getResolucao()
  Returns the resolution of the cell

  */

short int MapaMDE::getResolucao() {
    return tamanhoCelula;
}

/*!
  \fn MapaMDE::getDadoInvalido()
  Returns the value of invalid data

  */
short int MapaMDE::getDadoInvalido() {
    return dadoInvalido;
}

/*!
  \fn MapaMDE::getCaminhoArquivo()
  Returns the full path of file contain the MDE

  */
char * MapaMDE::getCaminhoArquivo() {
    return caminhoArquivo;
}

/*!
  \fn MapaMDE::getNomeArquivo()
  Returns the name of the file MDE
  */

char * MapaMDE::getNomeArquivo() {
    return nomeArquivo;
}


/**este metodo se encarrega de fazer a leitura do arquivo ascii
  e atribui as os valores as variaveis

  **/
void MapaMDE::scannerAscii(const char  * caminhoArquivo ) {

    ifstream entrada;
    entrada.open(caminhoArquivo,ifstream::in);

    //setando o nome e caminho do arquivo
    QString fileName (caminhoArquivo);

    this->caminhoArquivo = new char[262];
    nomeArquivo = new char[30];

    fileName = fileName.section("/",-1,-1);

    strcpy(nomeArquivo, fileName.toAscii().data());
    strcpy(this->caminhoArquivo,caminhoArquivo);




    /*padrao de leitura

    ncols
    nrows
    xllcorner
    yllcorner
    cellsize
    NODATA_value

      */
    //ignorando a leitura do escrito n cols
    entrada.ignore(256, ' ');
    entrada>>nColunas;

    //ignorando a leitura do escrito n linhas
    entrada.ignore(256, ' ');
    entrada>>nLinhas;


    //ignorando a leitura do escrito xllcorner
    entrada.ignore(256, ' ');
    entrada>>xllcorner;


    //ignorando a leitura do escrito yllcorner
    entrada.ignore(256, ' ');
    entrada>>yllcorner;

    //ignorando a leitura do escrito cellsize
    entrada.ignore(256, ' ');
    entrada>>tamanhoCelula;

    //ignorando a leitura do escrito noData
    entrada.ignore(256, ' ');
    entrada>>dadoInvalido;


    matrizDeElevacoes = new short int *[nLinhas];


    for(int i = 0; i < nLinhas;i++)
        matrizDeElevacoes[i] = new short int[nColunas];



    //ind i para linha j para coluna
    int i,j;
    i=j=0;

    while(i < nLinhas){//entrada.eof nao esta fazendo como o esperado
        //esquema para pular linhas


        if(j >= nColunas){
            i++;
            j = 0;

            if(i>=nLinhas)
                break;
        }

        double auxLeitura;
        string auxTrocaVirgulaPonto;
        entrada>>auxTrocaVirgulaPonto;


        //trocando virgula por ponto
        unsigned int localVirgula = auxTrocaVirgulaPonto.find(",");

        if(localVirgula != string::npos){
            auxTrocaVirgulaPonto = auxTrocaVirgulaPonto.replace(auxTrocaVirgulaPonto.find(","),0,".");
            auxTrocaVirgulaPonto = auxTrocaVirgulaPonto.erase(auxTrocaVirgulaPonto.find(","),1);
        }


        auxLeitura = atof(auxTrocaVirgulaPonto.data());



        //entrada>>auxLeitura;
        matrizDeElevacoes[i][j]=auxLeitura;

        if(auxLeitura <0)
            cout<<"teste";

        if(matrizDeElevacoes[i][j] != dadoInvalido && matrizDeElevacoes[i][j]>0){
            if(matrizDeElevacoes[i][j]>maxElev)
                maxElev = matrizDeElevacoes[i][j];

            if(matrizDeElevacoes[i][j]<minElev)
                minElev = matrizDeElevacoes[i][j];

        }
        j++;

    }

    entrada.close();



    //    ofstream saida("testandoEntrada.txt");

    //    for(int i = 0; i < nLinhas; i++){
    //        for(int j = 0; j< nColunas; j++)
    //            saida<<matrizDeElevacoes[i][j]<<"-";
    //    saida<<endl;
    //    }
    //    saida.close();

}


void MapaMDE::substituindoVirgurlaPonto(const char * caminhoArquivo){


    // StreamReader ms = new StreamReader(caminhoArquivo);



}
