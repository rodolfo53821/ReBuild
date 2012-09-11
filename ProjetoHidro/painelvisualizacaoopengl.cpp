#include "painelvisualizacaoopengl.h"
#include "math.h"
#include "MapaMDE.h"
#include "janelaprincipal.h"


using namespace std;

/*!
  \class PainelVisualizacaoOpenGL


     \previouspage PainelVisualizacaoBarragemOpenGL

     \contentspage

     \nextpage VisualizacaoMapa



     \startpage All Classes
  Class to create a opengl painel to show user the MDE
  */


/*!
  \variable PainelVisualizacaoOpenGL::posClickX
  \brief the value in axis-x for click position
  */




/*!
  \variable PainelVisualizacaoOpenGL::posClickY
  \brief the value in axis-y for click position
  */

/*!
  \variable PainelVisualizacaoOpenGL::corAlagamento
  \brief the color value for the flooded area
  */

/*!
  \variable PainelVisualizacaoOpenGL::corRedeDeDrenagem
  \brief the color value for the drainage network
  */


/*!
  \variable PainelVisualizacaoOpenGL::corMaiorElevacao
  \brief the color value for the higher cell`s elevation
  */


/*!
  \variable PainelVisualizacaoOpenGL::corMenorElevacao
  \brief the color value for the higher cell`s elevation
  */


/*!
  \variable PainelVisualizacaoOpenGL::corBarragem
  \brief the color value for the dam
  */


/*!
  \variable PainelVisualizacaoOpenGL::corPadraoAlagamento
  \brief the default color value for the flooded area
  */

/*!
  \variable PainelVisualizacaoOpenGL::corPadraoRedeDeDrenagem
  \brief the defaultcolor value for the drainage network
  */


/*!
  \variable PainelVisualizacaoOpenGL::corPadraoMaiorElevacao
  \brief the default color value for the higher cell`s elevation
  */


/*!
  \variable PainelVisualizacaoOpenGL::corPadraoMenorElevacao
  \brief the default color value for the higher cell`s elevation
  */


/*!
  \variable PainelVisualizacaoOpenGL::corPadraoBarragem
  \brief the color value for the dam
  */
/*!
  \variable PainelVisualizacaoOpenGL::mapaEstaCarregado
  \brief the flag to control if the MDE is open
  */


/*!
  \variable PainelVisualizacaoOpenGL::flagPinta
  \brief the flag to control the opengl painel need to be all painted or only Camadas painted.
  */







/*!
  \fn PainelVisualizacaoOpenGL::mouseMoveEvent(QMouseEvent *)
  Signal for mouseMoveEvent. The slot \l {JanelaPrincipal::trocaCoordenadas()}{JanelaPrincipal::trocaCoordenadas(QMouseEvent *)} and \l {JanelaPrincipal::movendoMouse()}{JanelaPrincipal::movendoMouse(QMouseEvent *)}  catch this signal
  */

/*!
  \fn PainelVisualizacaoOpenGL::mousePressEvent ( QMouseEvent * event )
 Signal for mousePressEvent. The slot \l {JanelaPrincipal::defineInundacao()}{JanelaPrincipal::defineInundacao(QMouseEvent *)}  catch this signal
  */

/*!
  \fn PainelVisualizacaoOpenGL::keyPressEvent(QKeyEvent *)
  Signal for keyPressEvent. The slot  \l {JanelaPrincipal::moveBarragem()}{JanelaPrincipal::moveBarragem(QKeyEvent *)} catch this signal
  */

/*!
  \fn PainelVisualizacaoOpenGL::mouseReleaseEvent(QMouseEvent*)
  Signal for mouseReleaseEvent. The slot  \l {JanelaPrincipal::adicionandoPontosACamada()}{JanelaPrincipal::adicionandoPontosACamada(QKeyEvent *)}
 catch this signal
  */


/*!
  \fn PainelVisualizacaoOpenGL::PainelVisualizacaoOpenGL(QWidget *parent)
  Constructor
  */

PainelVisualizacaoOpenGL::PainelVisualizacaoOpenGL(QWidget *parent) :
    QGLWidget(parent)
{

    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);

    corPadraoAlagamento.setRgb(0,0,255);
    corPadraoRedeDeDrenagem.setRgb(100,0,0);
    corPadraoMaiorElevacao.setRgb(0,255,0);
    corPadraoMenorElevacao.setRgb(205,150,0);
    corPadraoBarragem.setRgb(255,0,0);

}


/*!
  \overload PainelVisualizacaoOpenGL::initializeGL()
  Opengl functions needed. It is the init function of opengl painel
  */
void PainelVisualizacaoOpenGL::initializeGL(){

    glClearColor(1.0f,1.0f,1.0f,.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);



    glHint(GL_POINT_SMOOTH_HINT,GL_PERSPECTIVE_CORRECTION_HINT);

    posClickX = posClickY = -1;
    //visualizacaoMapa->marcaInicioX = visualizacaoMapa->marcaInicioY = visualizacaoMapa->marcaFinalX = visualizacaoMapa->marcaFinalY = -1;
    //visualizacaoMapa->marcouInicio = false;
    mapaEstaCarregado = false;
    flagPinta = true;

    setCoresPadrao();
}


/*!
  \fn PainelVisualizacaoOpenGL::setCoresPadrao()
 Function to set the default colors to the color`s variable
  */
void PainelVisualizacaoOpenGL::setCoresPadrao(){


    corAlagamento = (QColor(corPadraoAlagamento.name()));
    corAlagamento = QColor(corPadraoAlagamento.name());
    corBarragem = QColor(corPadraoBarragem.name());
    corMaiorElevacao = QColor(corPadraoMaiorElevacao.name());
    corMenorElevacao = QColor(corPadraoMenorElevacao.name());
    corRedeDeDrenagem = QColor(corPadraoRedeDeDrenagem.name());

}


/*!
  \fn PainelVisualizacaoOpenGL::zoomMapa(int zoom)
 Function to update the zoom in the opengl painel
  */
void PainelVisualizacaoOpenGL::zoomMapa(int zoom){

    visualizacaoMapa->setZoom(zoom);

    //Define novo tamanho do painel, faz a chamada do resizeGL
    this->resize(visualizacaoMapa->vetorDeZooms[0][zoom],visualizacaoMapa->vetorDeZooms[1][zoom]);
    updateGL();

}


/*!
  \fn PainelVisualizacaoOpenGL::resizeGL(int width, int height)
  Opengl functions needed. For when painel is resized or changed
  */
void PainelVisualizacaoOpenGL::resizeGL(int width, int height){

    glClearColor(1.0f,1.0f,1.0f,.0f);
    glClearDepth(1.0f);

    glViewport(0,0,width,height);
    //setar ponto para que contemple aumentar janela
    if(mapaEstaCarregado){
        visualizacaoMapa->setTamanhoPonto(width,height);
        // setMouseTracking(true);
    }
}


/*!
  \fn PainelVisualizacaoOpenGL::defineOrtho()
 Function to definy the ortho of opengl painel
  */
void PainelVisualizacaoOpenGL::defineOrtho(){
    //setar o ortho com proporcao ao tamanho do mapa
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,visualizacaoMapa->getProporcaoX(),visualizacaoMapa->getProporcaoY(), 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/*!
  \fn PainelVisualizacaoOpenGL::mudaCores(QStringList listaCores)
 Function to modify the color`s variable. The new colors is stored by its name in the list listaCores.
  */

void PainelVisualizacaoOpenGL::mudaCores(QStringList listaCores){

    corAlagamento = QColor(listaCores.at(0));

    corBarragem = QColor(listaCores.at(1));
    corMaiorElevacao = QColor(listaCores.at(2));
    corMenorElevacao = QColor(listaCores.at(3));
    corRedeDeDrenagem = QColor(listaCores.at(4));

}


/*!
  \fn PainelVisualizacaoOpenGL::carregandoMapa(const char *arquivo)
 Function to create and load a new MDE to show user.
  */
void PainelVisualizacaoOpenGL::carregandoMapa(const char *arquivo){

    visualizacaoMapa = new VisualizacaoMapa(arquivo, this->width(), this->height());

    defineOrtho();

    mapaEstaCarregado = true;


    computaFluxo();

    updateGL();



}

/*!
  \fn PainelVisualizacaoOpenGL::computaFluxo()
 Function to call the function for calculate the flow
  */

void PainelVisualizacaoOpenGL::computaFluxo()
{

    visualizacaoMapa->fluxo->calculaFluxo(visualizacaoMapa->getMapa()->matrizDeElevacoes,visualizacaoMapa->getMapa()->getDadoInvalido());

    updateGL();

}


/*!
  \fn PainelVisualizacaoOpenGL::pintaEixo()
 Function to draw a guidance axis
  */
void PainelVisualizacaoOpenGL::pintaEixo(){

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0,0,0);

    for(int i = 0; i<this->width();i++){
        if(i == this->width()/2) glColor3f(1,0,0);

        glVertex2i(i,0);
    }


    for(int i = 0; i< this->height();i++){
        if(i == this->height()/2) glColor3f(0,0,0);

        glVertex2i(0,i);
    }


    glColor3f(0,0,1);
    glVertex2i(0,this->height());
    glVertex2i(this->width(),0);

    glEnd();


}


/*!
  \fn PainelVisualizacaoOpenGL::getCorGradient(double gradientProporcao)
 Function to discovery a color from a gradient made by the maximum and minimum cell`s elevation
  */
QColor PainelVisualizacaoOpenGL::getCorGradient(double gradientProporcao){

    int rMenor = corMaiorElevacao.red()<corMenorElevacao.red()?corMaiorElevacao.red():corMenorElevacao.red();
    int gMenor = corMaiorElevacao.green()<corMenorElevacao.green()?corMaiorElevacao.green():corMenorElevacao.green();
    int bMenor = corMaiorElevacao.blue()<corMenorElevacao.blue()?corMaiorElevacao.blue():corMenorElevacao.blue();


    int red = rMenor + abs(corMaiorElevacao.red() - corMenorElevacao.red())*gradientProporcao;
    int green = gMenor + abs(corMaiorElevacao.green() - corMenorElevacao.green())*gradientProporcao;
    int blue = bMenor + abs(corMaiorElevacao.blue() - corMenorElevacao.blue() )*gradientProporcao;


    QColor resp(red,green,blue);

    return resp;


}


/*!
  \fn  PainelVisualizacaoOpenGL::pintaCamadas()
 Function to draw only the Camadas in listaDeCamadas
  */
void PainelVisualizacaoOpenGL::pintaCamadas(){

    glBegin(GL_POINTS) ;
    for(int it = 0; it< visualizacaoMapa->listaDeCamadas->size();it++){

        Camada c = visualizacaoMapa->listaDeCamadas->at(it);

        if(!c.estaVisivel) continue;


        for(int j = 0; j < c.listaDePontos.size();j++){
            glColor3f(((float)c.getCorCamada().toRgb().red())/255,((float)c.getCorCamada().toRgb().green()/255),((float)c.getCorCamada().toRgb().blue()/255));
            glVertex2f(c.listaDePontos.at(j).getJ(),c.listaDePontos.at(j).getI());
        }
    }

    glEnd();



}


/*!
  \fn  PainelVisualizacaoOpenGL::pintaTudo()
 Function to draw everything
  */
void PainelVisualizacaoOpenGL::pintaTudo(){

    double min = visualizacaoMapa->mapa->minElev;
    double max = visualizacaoMapa->mapa->maxElev;


    //para o ponto deve haver um fator de correcao
    //pois o mesmo nao esta associando o valor que deveria na teoria ser o correto

    glPointSize(visualizacaoMapa->getTamanhoDoPonto());

    glBegin(GL_POINTS) ;
    for(int i = 0; i < visualizacaoMapa->mapa->getNLinhas();i++){
        for(int j = 0; j < visualizacaoMapa->mapa->getNColunas();j++){
            if(visualizacaoMapa->mapa->matrizDeElevacoes[i][j] == visualizacaoMapa->mapa->getDadoInvalido()){

                glColor3f(1,1,1);
                if(visualizacaoMapa->fluxo->rio[i][j])
                    glColor3f(float(corRedeDeDrenagem.red())/255,(float)corRedeDeDrenagem.green()/255,(float)corRedeDeDrenagem.blue()/255);

            }
            else{


                double gradientProporcao  = (visualizacaoMapa->mapa->matrizDeElevacoes[i][j] - min)/(max-min);

                QColor corGradient = getCorGradient(gradientProporcao);

                if(visualizacaoMapa->inundacao->matrizEstados[i][j] == 1)
                    if(!visualizacaoMapa->fluxo->rio[i][j]) //Se não for rio, pinta cor normal, caso contrário, azul
                        glColor3f((float)corGradient.red()/255,(float)corGradient.green()/255,(float)corGradient.blue()/255);
                    else
                        glColor3f(float(corRedeDeDrenagem.red())/255,(float)corRedeDeDrenagem.green()/255,(float)corRedeDeDrenagem.blue()/255);


                else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==2) { //barragem
                    glColor3f(float(corBarragem.red())/255,(float)corBarragem.green()/255,(float)corBarragem.blue()/255);
                }

                //else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==3) { //acima_barragem
                //        glColor3f(.5f, .5f, .5f);
                //}

                else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==4) {//água na borda da barragem
                    glColor3f(0.0f, 0.75f, 1.0);
                }

                else if (visualizacaoMapa->inundacao->matrizEstados[i][j]==5) { //água
                    glColor3f(float(corAlagamento.red())/255,(float)corAlagamento.green()/255,(float)corAlagamento.blue()/255);
                }

            }


//            for(int it = 0; it< visualizacaoMapa->listaDeCamadas->size();it++){
//                Camada c = visualizacaoMapa->listaDeCamadas->at(it);

//                if(!c.estaVisivel) continue;
//                if(c.pontos[i][j])
//                    glColor3f(((float)c.getCorCamada().toRgb().red())/255,((float)c.getCorCamada().toRgb().green()/255),((float)c.getCorCamada().toRgb().blue()/255));


//            }

            glVertex2f(j,i);



        }

    }

    //imprimindo as camadas
    //nao eh o metodo mais eficiente, pois poderiamos varrer a matriz uma unica vez e
    // ir imprimindo as camadas

    pintaCamadas();
    //    for(int it = 0; it< visualizacaoMapa->listaDeCamadas->size();it++){

    //        Camada c = visualizacaoMapa->listaDeCamadas->at(it);

    //        if(!c.estaVisivel) continue;

    //        glColor3f(((float)c.getCorCamada().toRgb().red())/255,((float)c.getCorCamada().toRgb().green()/255),((float)c.getCorCamada().toRgb().blue()/255));

    //        for(int i = 0; i < visualizacaoMapa->mapa->getNLinhas();i++){
    //            for(int j = 0; j < visualizacaoMapa->mapa->getNColunas();j++){
    //                if(c.pontos[i][j])
    //                    glVertex2f(j,i);

    //            }
    //        }

    //    }




    glEnd() ;

    //teste imprimindo aonde setou mouse
    glBegin(GL_POINTS) ;
    //glPointSize(60);
    glColor3f(1,0,0);
    glVertex2f(posClickX,posClickY);
    glColor3f(1,1,1);
    glVertex2f(visualizacaoMapa->marcaInicioX,visualizacaoMapa->marcaInicioY);
    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(visualizacaoMapa->marcaFinalX,visualizacaoMapa->marcaFinalY);
    glEnd();


}


/*!
  \fn  PainelVisualizacaoOpenGL::paintGL()
 Opengl functions needed. For opengl painting. Decide here if it will paint all or a part of scenario.
  */
void PainelVisualizacaoOpenGL::paintGL(){


    if(mapaEstaCarregado == true){

        if(flagPinta){
            glClearColor(1.0f,1.0f,1.0f,.0f);
            glClearDepth(1.0f);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();
            pintaTudo();

        }

        else{



            glLoadIdentity();
            pintaCamadas();



        }


    }else{

        glClearColor(1.0f,1.0f,1.0f,.0f);
        glClearDepth(1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

    }

}
