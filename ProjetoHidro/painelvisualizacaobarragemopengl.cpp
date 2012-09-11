#include "painelvisualizacaobarragemopengl.h"
#include <QKeyEvent>


/*!
  \class PainelVisualizacaoBarragemOpenGL

     \previouspage painelvisualizacaobarragem2dopengl

     \contentspage

     \nextpage PainelVisualizacaoOpenGL


\startpage All Classes

  \brief   Class to create a opengl painel with dam 3D visualization

  */

PainelVisualizacaoBarragemOpenGL::PainelVisualizacaoBarragemOpenGL(QWidget *parent) :
    QGLWidget(parent)
{



    setFormat(QGL::SingleBuffer/* DoubleBuffer */| QGL::DepthBuffer);

    posicaoCamera[0] = 0;
    posicaoCamera[1]= 0;
    posicaoCamera[2]= 0;

    normalCamera[0] = 0;
    normalCamera[1] = 1;
    normalCamera[2] = 0;

    direcaoCamera[0] = 0 ;
    direcaoCamera[1] = 0;
    direcaoCamera[2] = -1;



}

void PainelVisualizacaoBarragemOpenGL::carregandoInformacoes(VisualizacaoMapa *viMapa){

    visualizacaoMapa = new VisualizacaoMapa(*viMapa);

    //defineOrtho();

    updateGL();

}

void PainelVisualizacaoBarragemOpenGL::defineOrtho(){
    //setar o ortho com proporcao ao tamanho do mapa

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,30,30, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void PainelVisualizacaoBarragemOpenGL::keyPressEvent(QKeyEvent* kev){

    GLdouble cos5 = 0.996;
    GLdouble sen5 = 0.087;


    double rotaX,rotaY,rotaZ;

    //rotacoes em torno de y

    //roda esquerda para direita
    if(kev->key() == Qt::Key_D){

        rotaX = cos5 * posicaoCamera[0] - (-1) * sen5 * posicaoCamera[2];
        rotaZ = cos5 * posicaoCamera[2] + (-1) * sen5 * posicaoCamera[0];

        posicaoCamera[0] = rotaX;
        posicaoCamera[2] = rotaZ;



        //posição do vetor de view up
        rotaX = cos5 * normalCamera[0] - (-1) * sen5 * normalCamera[2];
        rotaZ = cos5 * normalCamera[2] + (-1) * sen5 * normalCamera[0];

        //                     normalCamera[0] = rotaX;
        //                     normalCamera[2] = rotaZ;


    }


    //roda esquerda para direita
    if(kev->key() == Qt::Key_A){


        rotaX = cos5 * posicaoCamera[0] - sen5 * posicaoCamera[2];
        rotaZ = cos5 * posicaoCamera[2] + sen5 * posicaoCamera[0];

        posicaoCamera[0] = rotaX;
        posicaoCamera[2] = rotaZ;

        //posição do vetor de view up
        rotaX = cos5 * normalCamera[0] - sen5 * normalCamera[2];
        rotaZ = cos5 * normalCamera[2] + sen5 * normalCamera[0];

        //                          normalCamera[0] = rotaX;
        //                          normalCamera[2] = rotaZ;




    }

    //rotacoes em torno de x
    //roda baixo para cima
    if(kev->key() == Qt::Key_W){


        rotaY = (cos5 * posicaoCamera[1] +  sen5 *posicaoCamera[2]);
        rotaZ = cos5 * posicaoCamera[2] -  sen5 * posicaoCamera[1];


        posicaoCamera[1] = rotaY;
        posicaoCamera[2] = rotaZ;


        //posição do vetor de view up
        rotaY = cos5 * normalCamera[1] - (-1) * sen5 * normalCamera[2];
        rotaZ = cos5 * normalCamera[2] + (-1) * sen5 * normalCamera[1];

        //                              normalCamera[1] = rotaY;
        //                              normalCamera[2] = rotaZ;


    }

    //roda cima para baixo
    if(kev->key() == Qt::Key_S){

        rotaY = cos5 * posicaoCamera[1] - sen5 * posicaoCamera[2];
        rotaZ = cos5 * posicaoCamera[2] + sen5 * posicaoCamera[1];

        posicaoCamera[1] = rotaY;
        posicaoCamera[2] = rotaZ;

        //posição do vetor de view up
        rotaY = cos5 * normalCamera[1] - sen5 * normalCamera[2];
        rotaZ = cos5 * normalCamera[2] + sen5 * normalCamera[1];

        //                            normalCamera[1] = rotaY;
        //                            normalCamera[2] = rotaZ;

    }
    double zMaisCamera = 1.5;
    double zMenosCamera = 0.5;
    if(kev->key() == Qt::Key_N){
        posicaoCamera[0] =  posicaoCamera[1] = posicaoCamera[2] *= zMaisCamera;

    }

    if(kev->key() == Qt::Key_F){
        posicaoCamera[0] =  posicaoCamera[1] = posicaoCamera[2] *= zMenosCamera;

    }

    updateGL();





}

void PainelVisualizacaoBarragemOpenGL::initializeGL(){

    qglClearColor(Qt::white);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor"
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
    GLfloat posicaoLuz[4]={-700.0, 700.0, 700.0, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

    // Especifica que a cor de fundo da janela será preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);

}

void PainelVisualizacaoBarragemOpenGL::resizeGL(int w, int h){

    double min = 10000000;
    double max = 0;
    for(int i = 0; i < visualizacaoMapa->mapa->getNLinhas();i++){
        for(int j = 0; j < visualizacaoMapa->mapa->getNColunas();j++){
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j] == visualizacaoMapa->mapa->getDadoInvalido()) continue;
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j]< min )min = visualizacaoMapa->mapa->matrizDeElevacoes[i][j];
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j]> max )max = visualizacaoMapa->mapa->matrizDeElevacoes[i][j];
        }
    }



    int w1 = visualizacaoMapa->mapa->getNColunas();
    int h1 = visualizacaoMapa->mapa->getNLinhas();



    direcaoCamera[0] = 0;
    direcaoCamera[1] = 0;
    direcaoCamera[2] = -1;



    posicaoCamera[0]= visualizacaoMapa->mapa->getNColunas()/2;
    posicaoCamera[1]= visualizacaoMapa->mapa->getNLinhas()/2;
    posicaoCamera[2] = visualizacaoMapa->mapa->matrizDeElevacoes[h1/2][w1/2];

    normalCamera[0]= 0;
    normalCamera[1]= 1;
    normalCamera[2] = 0;



    glViewport(0, 0, this->width(), this->height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1, 1, 1000);
    //glOrtho(-w1,w1,-h1,h1,1,1000);

}

void PainelVisualizacaoBarragemOpenGL::desenhaTerreno(){



    int xBarragemNaRede,yBarragemNaRede,zBarragemNaRede;


    //identificando min e max das cores
    double min = 10000000;
    double max = 0;
    for(int i = 0; i < visualizacaoMapa->mapa->getNLinhas();i++){
        for(int j = 0; j < visualizacaoMapa->mapa->getNColunas();j++){
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j] == visualizacaoMapa->mapa->getDadoInvalido()) continue;
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j]< min )min = visualizacaoMapa->mapa->matrizDeElevacoes[i][j];
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j]> max )max = visualizacaoMapa->mapa->matrizDeElevacoes[i][j];
        }
    }




    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(posicaoCamera[0],posicaoCamera[1],posicaoCamera[2],direcaoCamera[0],direcaoCamera[1],direcaoCamera[2],normalCamera[0],normalCamera[1],normalCamera[2]);



    for(int i =   0; i < visualizacaoMapa->mapa->getNLinhas();i++){
        for(int j =  0; j < visualizacaoMapa->mapa->getNColunas();j++){

            GLfloat elevacao = visualizacaoMapa->mapa->matrizDeElevacoes[i][j];
            //elevacao = elevacao - min + 0.3*(max-min);
            //dado invalido
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j] == visualizacaoMapa->mapa->getDadoInvalido())
                continue;

            //     ______
            //    /______/|
            //    |     | |
            //    | 1___|_|   1 vert j,i
            //    |/____|/




            else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==2) { //barragem
                glColor3f(1.0f, 0.0f, 0.0);
            }

            //else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==3) { //acima_barragem
            //        glColor3f(.5f, .5f, .5f);
            //}

            else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==4) {//água na borda da barragem
                glColor3f(0.0f, 0.75f, 1.0);
            }

            else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==5) { //água
                glColor3f(0.0f, 0.25f, 1.0);
            }
            else{

                if(!visualizacaoMapa->fluxo->rio[i][j]) //Se não for rio, pinta cor normal, caso contrário, azul
                    glColor3f(0,1-((visualizacaoMapa->mapa->matrizDeElevacoes[i][j] - min)/(max-min) ),(visualizacaoMapa->mapa->matrizDeElevacoes[i][j] - min)/(max-min));
                else
                    glColor3f(0,0,0);
            }



            //frontal
            glBegin(GL_QUAD_STRIP);
            glNormal3f(0,-1,0);
            glVertex3f(j,i+1,0);
            glVertex3f(j,i+1,elevacao);
            glVertex3f(j+1,i+1,elevacao);
            glVertex3f(j+1,i+1,0);
            glEnd();



            //traseiro
            glBegin(GL_QUAD_STRIP);
            glNormal3f(0,1,0);
            glVertex3f(j,i,0);
            glVertex3f(j,i,elevacao);
            glVertex3f(j+1,i,elevacao);
            glVertex3f(j+1,i,0);
            glEnd();

            //esquerdo
            glBegin(GL_QUAD_STRIP);
            glNormal3f(-1,0,0);
            glVertex3f(j,i,0);
            glVertex3f(j,i,elevacao);
            glVertex3f(j,i+1,elevacao);
            glVertex3f(j,i+1,0);
            glEnd();

            //direito
            glBegin(GL_QUAD_STRIP);
            glNormal3f(1,0,0);
            glVertex3f(j+1,i+1,0);
            glVertex3f(j+1,i+1,elevacao);
            glVertex3f(j,i+1,elevacao);
            glVertex3f(j,i+1,0);
            glEnd();



            //baixo
            glBegin(GL_QUAD_STRIP);
            glNormal3f(0,-0,-1);
            glVertex3f(j+1,i,0);
            glVertex3f(j,i,0);
            glVertex3f(j,i+1,0);
            glVertex3f(j+1,i+1,0);
            glEnd();

            //cima
            glBegin(GL_QUAD_STRIP);
            glNormal3f(0,0,1);
            glVertex3f(j,i,elevacao);
            glVertex3f(j+1,i,elevacao);
            glVertex3f(j+1,i+1,elevacao);
            glVertex3f(j,i+1,elevacao);

            glEnd();






            //desenha barragem
            if (visualizacaoMapa->inundacao->matrizEstados[i][j]==2){

                if(visualizacaoMapa->inundacao->matrizEstados[i][j] == 1){
                    xBarragemNaRede = j;
                    yBarragemNaRede = i;
                    zBarragemNaRede = elevacao;


                }

                int altBarragem = visualizacaoMapa->inundacao->nivelAgua;
                //altBarragem = altBarragem + min - 0.3*(max-min);

                glColor3f(0.64f,0.42f,0.04f);
                //frontal
                glBegin(GL_QUAD_STRIP);
                glNormal3f(0,-1,0);
                glVertex3f(j,i+1,elevacao);
                glVertex3f(j,i+1,altBarragem);
                glVertex3f(j+1,i+1,altBarragem);
                glVertex3f(j+1,i+1,elevacao);
                glEnd();



                //traseiro
                glBegin(GL_QUAD_STRIP);
                glNormal3f(0,1,0);
                glVertex3f(j,i,elevacao);
                glVertex3f(j,i,altBarragem);
                glVertex3f(j+1,i,altBarragem);
                glVertex3f(j+1,i,elevacao);
                glEnd();

                //esquerdo
                glBegin(GL_QUAD_STRIP);
                glNormal3f(-1,0,0);
                glVertex3f(j,i,elevacao);
                glVertex3f(j,i,altBarragem);
                glVertex3f(j,i+1,altBarragem);
                glVertex3f(j,i+1,elevacao);
                glEnd();

                //direito
                glBegin(GL_QUAD_STRIP);
                glNormal3f(1,0,0);
                glVertex3f(j+1,i+1,elevacao);
                glVertex3f(j+1,i+1,altBarragem);
                glVertex3f(j,i+1,altBarragem);
                glVertex3f(j,i+1,elevacao);
                glEnd();



                //baixo
                glBegin(GL_QUAD_STRIP);
                glNormal3f(0,-0,-1);
                glVertex3f(j+1,i,elevacao);
                glVertex3f(j,i,elevacao);
                glVertex3f(j,i+1,elevacao);
                glVertex3f(j+1,i+1,elevacao);
                glEnd();

                //cima
                glBegin(GL_QUAD_STRIP);
                glNormal3f(0,0,1);
                glVertex3f(j,i,altBarragem);
                glVertex3f(j+1,i,altBarragem);
                glVertex3f(j+1,i+1,altBarragem);
                glVertex3f(j,i+1,altBarragem);

            }

        }
    }


    //    posicaoCamera[0]= 1.5*xBarragemNaRede;
    //    posicaoCamera[1]= 1.5*yBarragemNaRede;
    //    posicaoCamera[2] = 1.5*zBarragemNaRede;



    //   gluLookAt(posicaoCamera[0],posicaoCamera[1],posicaoCamera[2],direcaoCamera[0],direcaoCamera[1],direcaoCamera[2],normalCamera[0],normalCamera[1],normalCamera[2]);


}




void PainelVisualizacaoBarragemOpenGL::paintGL(){    

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    desenhaTerreno();

    glFlush();

}
