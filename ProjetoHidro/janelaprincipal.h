#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include <string>
#include <VisualizacaoMapa.h>
#include<janelacamadas.h>
#include <fstream>
#include<Camada.h>
#include <janelabarragem.h>
#include <janelabarragem2d.h>
#include <QKeyEvent>
#include <QTableWidgetItem>

namespace Ui {
class JanelaPrincipal;
}





class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:


    //===construtor e destrutor
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();


    //===atributos
    map<string,VisualizacaoMapa> mapeamentoAreaProjeto; //usado para expor elementos na area de projeto
    QStringList stringAreaProjeto;//usado como auxiliar do map para armazenar o nome dos elementos
    //posicao para os botoes de zoom isto permite que os mesmos andem ao mexer no slider
    int posXBotaoZoomMais;
    int posYBotaoZoomMais;
    int posXBotaoZoomMenos;
    int posYBotaoZoomMenos;
    int posXBarraZoom;
    int posYBarraZoom;
    //atrr flag
    bool escolhendoPontosCamada;//variavel que define se o botao do mouse esta segurado
    bool selecaoPontos;//define se o usuario esta adicionando ou subtraindo elementos da camada
    bool selecaoPontoBarragem;//define se o click deve ir para os metodos de adicionar pontos a camada ou seta posicao da barragem
    QList<Point> listaDePosicoesMouse;//lista utilizada para se criar os pontos continuos usa o ultimo(clicado) e o anterior
    bool pontosContinuos; //define se os pontos deve ser continuos


   const static QString urllog;



    //======Metodos
    void setaTelaPadrao();//reseta os campos
    void setaTamanhoBarraDeZoom();//define o tamanho da barragem cada mapa pode ter a sua
    void habilitandoBotoes();//habilita todos os botoes
    void desAbilitandoBotoes();//desabilita botoes que nao podem ser apertados sem o mapa estar carregado
    void atualizaCamposSaida();//atualiza o campo de saida apos os calculos
    void deletaListaComCamadas();//deleta elementos contido na lista de camadas exposta ao usuario
    void criaListaComCamadas();//preenche a lista de camadas exposta ao usuario

    void preenchePontosContinuo(Point ,Point,int);//o pc nao pega o mouse em todos os pontos, dai esse metodo fecha linha
    bool pontoDoRioMaisProximo(int posX, int posY, int raio);//ima pro mouse ir ao rio, facilitar ao clicar perto
    void criaVisualizacaoBarragem();//funcao que abre as janelas 2D ou 3D
    void preencheSolido(int posClickY,int posClickX,int indCamada,int numPreenchidos);//preenche um solido fechado desenhado da camada
    QPoint buscaMelhorPonto(VisualizacaoMapa,QList<QPoint>,double);//metodo que busca o melhor posicionamento de matriz
    void mousePressionadoParaCamada(QMouseEvent * ev);//metodo que tem os metodos a chamar ao se trabalhar com camada (nao é slot)
    void mousePressionadoParaBarragem(QMouseEvent * ev);//metodo que tem os metodos a chamar ao se trabalhar com barragem (nao é slot)
    int  valorDirecaoVetorNormal();//metodo que obtem o valor da direcao alem de verficar se os campos foram todos preenchidos corretamentes



protected slots:

    void on_actionAbrir_mapa_triggered();
    void on_barraZoom_sliderMoved(int position);
    void on_botaoZoomMais_clicked();
    void on_botaoZoomMenos_clicked();
    void on_botaoAtualizarFluxoMinimo_clicked();
    void trocaCoordenadas(QMouseEvent*);
    void defineCamada(int,int);
    void defineInundacao(QMouseEvent*);
    void adicionandoPontosACamada(QMouseEvent* ev);
    void  movendoMouse(QMouseEvent* ev);
    void moveBarragem(QKeyEvent* kev);
    void imprimeBarragem(VisualizacaoMapa,int);
    bool eEntruncamentoDeRios(int posx, int posy);
    void exporCamada(QTableWidgetItem*);
    //void keyPressEvent(QKeyEvent*);

private slots:

    void on_botaoAdicionarInundacao_clicked();
    void on_botaoExcluirInundacao_clicked();
    void on_botaoVisualizarInundacao_clicked();
    void on_insereCamada_clicked();
    void on_selecaoPontosCamada_clicked();
    void on_radioButtonV_clicked();
    void on_radioButtonDP_clicked();
    void on_pushButton_clicked();
    void moveZoomHorizontal(int);
    void moveZoomVertical(int);
    void on_actionSobre_triggered();
    void on_actionFechar_mapa_triggered();
    void on_actionCores_triggered();
    void on_deletaCamada_clicked();
    void on_botaoAlternaBC_clicked();

    void on_actionFunc_Objetivo_triggered();

    void on_caixaApresentaFuncaoObjetivo_clicked();

    void on_radioButtonM_clicked();

    void on_radioButtonManual_clicked();

    void on_radioButtonManual45_clicked();

    void on_radioButtonManual0_clicked();

    void on_radioButtonManual135_clicked();

    void on_radioButtonManual90_clicked();

    void on_botaoFechaManual_clicked();

private:

    janelaCamadas *uiCamadas; //janela barragem visual 3D
    janelabarragem *uiBarragem; //janela de adicionar barragem
    janelaBarragem2D *uiBarragem2d;//janela perfil barragem 2D
    Ui::JanelaPrincipal *ui;

};



#endif // JANELAPRINCIPAL_H
