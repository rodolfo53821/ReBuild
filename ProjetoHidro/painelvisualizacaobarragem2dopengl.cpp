#include "painelvisualizacaobarragem2dopengl.h"

/*!
  \class painelvisualizacaobarragem2dopengl

     \previouspage MapaMDE

     \contentspage

     \nextpage PainelVisualizacaoBarragemOpenGL

\startpage All Classes


   \brief   Class to create a opengl painel with dam 2D visualization

  */

painelvisualizacaobarragem2dopengl::painelvisualizacaobarragem2dopengl(QWidget *parent) :
    QGLWidget(parent)
{

    setFormat(QGL::SingleBuffer | QGL::DepthBuffer);

    maxAltura = 0;
    minAltura = 10000000;
    proporcaoAltura = 0;


    this->visualizacaoMapa = NULL;

}


void painelvisualizacaobarragem2dopengl::defineBarragem(){



    //caso a lista de pontos da barragem nao esteja vazia reiniciala
    if(!pontosDaBarragem.empty()){
        pontosDaBarragem.clear();

        maxAltura = 0;
        minAltura = 10000000;
        proporcaoAltura = 0;



    }

    for(int i = 0;i<visualizacaoMapa->mapa->getNLinhas();i++){
        for(int j = 0;j<visualizacaoMapa->mapa->getNColunas();j++){
            //se for barragem poe na lista
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j] == visualizacaoMapa->mapa->getDadoInvalido())
                continue;

            if(visualizacaoMapa->inundacao->matrizEstados[i][j] == 2){
                Point pAux(i,j);
                pontosDaBarragem.insert(pontosDaBarragem.end(),pAux);


                if(maxAltura< visualizacaoMapa->mapa->matrizDeElevacoes[i][j])
                    maxAltura =  visualizacaoMapa->mapa->matrizDeElevacoes[i][j];

                if(minAltura > visualizacaoMapa->mapa->matrizDeElevacoes[i][j])
                    minAltura =  visualizacaoMapa->mapa->matrizDeElevacoes[i][j];


            }
        }
    }

    proporcaoAltura = (minAltura - int(maxAltura/minAltura));
    proporcaoImpressao = ((maxAltura + int(maxAltura/minAltura)) - proporcaoAltura);

}

void painelvisualizacaobarragem2dopengl::carregandoInformacoes(VisualizacaoMapa *viMapa){



    if(visualizacaoMapa != NULL){
        delete visualizacaoMapa;
        this->visualizacaoMapa = NULL;
    }


    visualizacaoMapa = new VisualizacaoMapa(*viMapa);

    defineBarragem();

    defineOrtho();

    updateGL();



}

void painelvisualizacaobarragem2dopengl::defineOrtho(){


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,50,50, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void painelvisualizacaobarragem2dopengl::initializeGL(){

    glClearColor(1.0f,1.0f,1.0f,.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);

    glHint(GL_POINT_SMOOTH_HINT,GL_PERSPECTIVE_CORRECTION_HINT);



}

void painelvisualizacaobarragem2dopengl::resizeGL(int w, int h){

    glViewport(0,0,w,h);




}

void painelvisualizacaobarragem2dopengl::paintGL(){


    glClearColor(1.0f,1.0f,1.0f,.0f);
    glClearDepth(1.0f);



    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-(pontosDaBarragem.size()*0.1),pontosDaBarragem.size()*1.1,0, proporcaoImpressao);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    //IMPRIMINDO barragem/

    for(int i = 0; i<pontosDaBarragem.size();i++){

        int iPonto = (pontosDaBarragem.at(i)).getI();
        int jPonto = (pontosDaBarragem.at(i)).getJ();


        int elevacao = visualizacaoMapa->mapa->matrizDeElevacoes[iPonto][jPonto];



        if(  visualizacaoMapa->inundacao->posicaoBarragem.x == jPonto && visualizacaoMapa->inundacao->posicaoBarragem.y == iPonto )
            glColor3f(0,0,0);
        else
            glColor3f(0,1,0);
        glBegin(GL_QUADS);
        glVertex2f(i,0);
        glVertex2f(i,elevacao - proporcaoAltura);
        glVertex2f(i+1,elevacao - proporcaoAltura);
        glVertex2f(i+1,0);
        glEnd();


        //defindo eixo
        if(i == 0 || (i == (pontosDaBarragem.size()-1)) ) glColor3f(1,0,0);
        else glColor3f(0,0,0);
        glBegin(GL_POINTS);
        glVertex2f(i,0);
        glEnd();


    }





}
