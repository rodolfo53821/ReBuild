#ifndef INUNDACAO_H
#define INUNDACAO_H

#include <QQueue>
#include <Fluxo.h>

#define proximoY(y,x) (y+ Fluxo::direcaoDeFluxo[ matrizDeDirecoes[y][x] ][0])
#define proximoX(y,x) (x+ Fluxo::direcaoDeFluxo[ matrizDeDirecoes[y][x] ][1])
//====Constantes====
#define BARRAGEM 2;
#define AFLUENTE 1;
#define ACIMA_BARRAGEM 3;
#define AGUA_BORDA_BARRAGEM 4;
#define AGUA 5;


class PontoZ {
public:
    int x,y;
    short int z;


    PontoZ(const short int y1, const short int x1,const short int z1) :
        x(x1),y(y1),z(z1) {}

    PontoZ(){x=-1; y=-1; z=-1;}

    // void operator=(PontoZ& outro) {this->x = outro.x; this->y = outro.y; this->z = outro.z;}


    bool operator<(const PontoZ &p1) const {


        return  this->z > p1.z;
    }

};


class Inundacao {


public:

    //=====construtores
    Inundacao();
    Inundacao(int , int );
    Inundacao(Inundacao const&);
    ~Inundacao();



    //=======atributos
    short int** matrizEstados;
    PontoZ posicaoBarragem;
    PontoZ posicaoAcimaBarragem;
    PontoZ vetorNormalABarragem;
    int nLinhas;
    int nColunas;
    int tamanhoMaximoDaBarragem;
    int volumeAgua;
    int volumeAlvo;
    int nivelAgua;
    int areaLaminaAgua;
    int areaBarragemTocada;
    int comprimentoBarragemTocada;





    //====Metodos====
    bool permiteInundacaoEAumentaBarragem(PontoZ p3);//define se um ponto p3 deve ser inundado, barragem ou extravasou barragem
    void inicializaBarragem(int x, int y, int xAcima, int yAcima, short int** elevacoes,bool **rio,unsigned char**matrizDeDirecoes, int opVetorNormal,int valorVetorNormal,int valEp);
    void marcaMontante(int xi, int yi, short int** matrizDeEstados, unsigned char** matrizDeDirecoes, short int** elevacoes,bool **rio,int opVetorNormal,int valorVetorNormal,int valEp);
    void sobeNivelDeAgua(short int** matrizDeEstados, short int** elevacoes);
    void inunda(int posX, int posY, unsigned char** matrizDeDirecoes, short int** elevacoes,bool **rio,int opVetorNormal, int valorVetorNormal,int valEp);
    void defineVetorNormalABarragem(int op,int val,short int **elevacoes,bool **rio,unsigned char**matrizDeDirecoes,int valEp);
    void vetorNormalPorVizinhanca(int viz,short int **elevacoes,bool**rio,unsigned char**matrizDeDirecoes);
    void vetorNormalPorMediaDasDirecoes(int viz,short int **elevacoes,bool**rio,unsigned char**matrizDeDirecoes);
    void vetorNormalPorDouglasPeucker(int numElementos,int epsilon,short int **elevacoes,bool**rio,unsigned char**matrizDeDirecoes);
    void criaListaParaDouglasPeucker(int numElementos,QList<PontoZ> &listaASerSimplificada,short int **elevacoes,bool**rio,unsigned char**matrizDeDirecoes);
    QList<PontoZ> algoritmoDouglasPeucker(QList<PontoZ> & ,int,QList<PontoZ> &);
    void marcaBarragem(short int **matrizDeEstados);//marca os elementos que serao barragem de acordo com sua direcao
    void acertaTamanhoBarragem(short int **matrizDeEstados);//acerta a barragem com elementos apenas adjacente a inundacao
    PontoZ getPosicaoBarragem();



private:


    //====Atributos====
    bool** visitado;
    priority_queue<PontoZ> filaProximosPontos; //fila contendo os proximos elementos a serem alagados




};

#endif // INUNDACAO_H
