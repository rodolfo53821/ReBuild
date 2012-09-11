#ifndef PAINELVISUALIZACAOOPENGL_H
#define PAINELVISUALIZACAOOPENGL_H

#include <QGLWidget>
#include <QMouseEvent>
#include <MapaMDE.h>
#include <VisualizacaoMapa.h>

class PainelVisualizacaoOpenGL : public QGLWidget
{
    Q_OBJECT

public:

    //=====construtor
    explicit PainelVisualizacaoOpenGL(QWidget *parent = 0);


    //===atributos
    VisualizacaoMapa *visualizacaoMapa;

    int posClickX;
    int posClickY;
    QColor corAlagamento;
    QColor corRedeDeDrenagem;
    QColor corMaiorElevacao;
    QColor corMenorElevacao;
    QColor corBarragem;//cor dos elementos
    QColor corPadraoAlagamento;
    QColor corPadraoRedeDeDrenagem;
    QColor corPadraoMaiorElevacao;
    QColor corPadraoMenorElevacao;
    QColor corPadraoBarragem;
    bool mapaEstaCarregado;//verifica se mapa carregado na area de visualizacao
    bool flagPinta;


    //====metodos
    void zoomMapa(int zoom);
    void carregandoMapa(const char*);
    void pintaTudo();
    void pintaEixo();
    void pintaCamadas();
    void computaFluxo(); //Esse método faz a chamada da função de cálculo de fluxo do objeto Fluxo.
    void mudaCores(QStringList);//muda as cores e vira uma lista de string
    //contendo em ordem alfabetica os elementos cuja a cor sera mudada
    void setCoresPadrao();
    QColor getCorGradient(double gradientProporcao);//define a cor dentro do gradiente formado pela cor da maior e menor elevacao



   //====metodos opengl
     void defineOrtho();


protected:

    //====metodos opengl
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();


signals:
//====signals que sao conectados a metodos na janela principal
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent ( QMouseEvent * event );
    void keyPressEvent(QKeyEvent *);
    void mouseReleaseEvent(QMouseEvent*);


public slots:

};

#endif // PAINELVISUALIZACAOOPENGL_H
