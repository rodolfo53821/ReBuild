#ifndef PAINELVISUALIZACAOBARRAGEMOPENGL_H
#define PAINELVISUALIZACAOBARRAGEMOPENGL_H

#include <QGLWidget>
#include "VisualizacaoMapa.h"

class PainelVisualizacaoBarragemOpenGL : public QGLWidget
{
    Q_OBJECT
public:


    //===construtor
    explicit PainelVisualizacaoBarragemOpenGL(QWidget *parent = 0);



    //====atributo
    int posicaoCamera[3], normalCamera[3], direcaoCamera[3];


    //=====metodos
    void carregandoInformacoes(VisualizacaoMapa *);
    void desenhaTerreno();



protected :


    //===metodos opengl
    void defineOrtho();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

signals:


public slots:
    void keyPressEvent(QKeyEvent *);


private:
    VisualizacaoMapa *visualizacaoMapa;

};

#endif // PAINELVISUALIZACAOBARRAGEMOPENGL_H
