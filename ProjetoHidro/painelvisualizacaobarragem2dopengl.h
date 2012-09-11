#ifndef PAINELVISUALIZACAOBARRAGEM2DOPENGL_H
#define PAINELVISUALIZACAOBARRAGEM2DOPENGL_H
#include<QGLWidget>
#include<VisualizacaoMapa.h>
#include<QList>


class painelvisualizacaobarragem2dopengl : public QGLWidget
{
    Q_OBJECT

public:


    //====construtor
    explicit painelvisualizacaobarragem2dopengl(QWidget *parent = 0);


    //====atributos
    int maxAltura,minAltura,proporcaoAltura,proporcaoImpressao;
    VisualizacaoMapa *visualizacaoMapa;
    QList<Point> pontosDaBarragem;


    //===metodos
    void carregandoInformacoes(VisualizacaoMapa *viMapa);
    void defineBarragem();


protected:


    //===metodos opengl
    void defineOrtho();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // PAINELVISUALIZACAOBARRAGEM2DOPENGL_H
