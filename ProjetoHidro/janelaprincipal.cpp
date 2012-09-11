#include "janelaprincipal.h"
#include"janelacamadas.h"
#include "ui_janelaprincipal.h"
#include "qfile.h"
#include "qfiledialog.h"
#include <fstream>
#include <QScrollBar>
#include <QStyle>
#include <QSlider>
#include <QStringListModel>
#include <QTreeView>
#include <QStandardItemModel>
#include <map>
#include <QInputDialog>
#include <QFlag>
#include <QList>
#include <cmath>
#include <list>
#include <iomanip>
#include <cstring>
#include<janelasobre.h>
#include <QMessageBox>
#include <janelaopcaocor.h>
#include <janelaopcaofb.h>
#include <QDate>

/*!
  \class JanelaPrincipal

     \previouspage janelaopcaofb

     \contentspage

     \nextpage janelasobre

     \startpage All Classes

  \brief Class to create the main window


  */




/*!
  \variable JanelaPrincipal::mapeamentoAreaProjeto
  \brief a map to mapping stored VisualizacaoMapa in Area de Projeto by its name map to its VisualizacaoMapa


*/

/*!
  \variable JanelaPrincipal::stringAreaProjeto
  \brief a list with the names in mapeamentoAreaProjeto to help find an element in it.


*/


/*!
  \variable JanelaPrincipal::posXBotaoZoomMais
  \brief the position of button BotaoZoomMais in axis-x. It's help when scroll bar rolls to make always visible.


*/

/*!
  \variable JanelaPrincipal::posYBotaoZoomMais
  \brief the position of button BotaoZoomMais in axis-y. It's help when scroll bar rolls to make always visible.


*/

/*!
  \variable JanelaPrincipal::posXBotaoZoomMenos
  \brief the position of button BotaoZoomMenos in axis-x. It's help when scroll bar rolls to make always visible.


*/
/*!
  \variable JanelaPrincipal::posYBotaoZoomMenos
  \brief the position of button BotaoZoomMenos in axis-y. It's help when scroll bar rolls to make always visible.


*/
/*!
  \variable JanelaPrincipal::posXBarraZoom
  \brief the position of bar  BarraZoom in axis-x. It's help when scroll bar rolls to make always visible.


*/
/*!
  \variable JanelaPrincipal::posYBarraZoom
  \brief the position of bar  BarraZoom in axis-y. It's help when scroll bar rolls to make always visible.


*/


/*!
  \variable JanelaPrincipal::escolhendoPontosCamada
  \brief the flag to control if the user is selecting Camada's points in map or not.


*/

/*!
  \variable JanelaPrincipal::selecaoPontos
  \brief the flag to control if user will add or sub cells from the Camada


*/

/*!
  \variable JanelaPrincipal::selecaoPontoBarragem
  \brief the flag to control if user will add point to Camada or choose the dam position when mouse is pressed.


*/

/*!
  \variable JanelaPrincipal::listaDePosicoesMouse
  \brief the list with mouse positions for helping to create a continuos line. With the last and the before last create a cell's continuos line.


*/

/*!
  \variable JanelaPrincipal::pontosContinuos
  \brief the flag to control if will have continuos line or not


*/





using namespace std;

const QString JanelaPrincipal::urllog = "logErro.txt";


JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{



    //arquivoComBarrages.open("arquivoComBarragem.txt",ios_base::out);
    uiCamadas = new janelaCamadas(this);
    uiBarragem2d = new janelaBarragem2D(this);


    ui->listView = new QListView();

    ui->setupUi(this);
    ui->barraZoom->setStyleSheet("QSlider::groove:horizontal{border: 1px solid #bbb;background: white;width: 5px;border-radius: 2px;}QSlider::sub-page:vertical{background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #fff, stop: 0.4999 #eee, stop: 0.5 #ddd, stop: 1 #eee );border: 1px solid #777;width: 5px;border-radius: 2px;}QSlider::add-page:vertical {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #006400, stop: 0.4999 #556B2F, stop: 0.5 #2E8B57, stop: 1 #7CFC00 );border: 1px solid #777;width: 5px;border-radius: 2px;}QSlider::handle:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eee, stop:1 #ccc);border: 1px solid #777;height: 13px;margin-top: -2px;margin-bottom: -2px;border-radius: 4px;}QSlider::handle:vertical:hover {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd);border: 1px solid #444;border-radius: 2px;}QSlider::sub-page:vertical:disabled {background: #bbb;border-color: #999;}QSlider::add-page:vertical:disabled {background: #eee;border-color: #999;}QSlider::handle:vertical:disabled {background: #eee;border: 1px solid #aaa;border-radius: 2px;}");

    QObject::connect(this->ui->widget, SIGNAL(mouseMoveEvent(QMouseEvent*)),
                     this, SLOT(trocaCoordenadas(QMouseEvent*)));

    QObject::connect(this->ui->widget, SIGNAL(mousePressEvent(QMouseEvent*)),
                     this, SLOT(defineInundacao(QMouseEvent*)));

    QObject::connect(this->ui->widget, SIGNAL(mouseReleaseEvent(QMouseEvent*)),
                     this, SLOT(adicionandoPontosACamada(QMouseEvent*)));


    QObject::connect(this->ui->widget, SIGNAL(mouseMoveEvent(QMouseEvent*)),
                     this, SLOT(movendoMouse(QMouseEvent*)));



    QObject::connect(this->ui->widget, SIGNAL(keyPressEvent(QKeyEvent*)),
                     this, SLOT(moveBarragem(QKeyEvent*)));


    QObject::connect(this->ui->camadaTableWidget, SIGNAL(cellClicked(int,int)),
                     this, SLOT(defineCamada(int,int)));

    QObject::connect(this->ui->camadaTableWidget, SIGNAL(itemChanged(QTableWidgetItem*)),
                     this, SLOT(exporCamada(QTableWidgetItem*)));


    //signals para os botoes e a barra de zoom
    QObject::connect(this->ui->scrollArea->horizontalScrollBar(), SIGNAL(valueChanged ( int )),
                     this, SLOT(moveZoomHorizontal(int)));

    QObject::connect(this->ui->scrollArea->verticalScrollBar(), SIGNAL(valueChanged ( int )),
                     this, SLOT(moveZoomVertical(int)));







    ui->listView->setModel(new QStringListModel(stringAreaProjeto));

    ui->listView->model()->setHeaderData(0, Qt::Vertical,"numero");


    //atribuindo o valor de posicionamento da barra e botoes de zoom
    //para facilitar a movimentacao automatica dos mesmos
    posXBotaoZoomMais = ui->botaoZoomMais->geometry().x();
    posYBotaoZoomMais = ui->botaoZoomMais->geometry().y();

    posXBotaoZoomMenos = ui->botaoZoomMenos->geometry().x();
    posYBotaoZoomMenos = ui->botaoZoomMenos->geometry().y();

    posXBarraZoom = ui->barraZoom->geometry().x();
    posYBarraZoom = ui->barraZoom->geometry().y();

    escolhendoPontosCamada = false;

    selecaoPontos = true;

    QIcon iconeOlho("../imagens/olhoIcone.png");
    QSize sizeIcone  = iconeOlho.actualSize(this->size());
    ui->camadaTableWidget->horizontalHeaderItem(2)->setIcon(iconeOlho);


    int tableWidth = ui->camadaTableWidget->width();
    int c2Largura = 1.5*sizeIcone.width();
    int c0Largura = (tableWidth-c2Largura)/2;
    int c1Largura =(tableWidth-c2Largura)/2;

    ui->camadaTableWidget->setColumnWidth ( 0,c0Largura);
    ui->camadaTableWidget->setColumnWidth ( 1,c1Largura);
    ui->camadaTableWidget->setColumnWidth ( 2,c2Largura);

    ui->camadaTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    selecaoPontoBarragem = true;



}



/*!
  \fn JanelaPrincipal::preenchePontosContinuo(Point pIni,Point pFim,int indCamada)
  \brief Function to help the system for creating a continuos line when user is choosing the cells of Camada

  */


void JanelaPrincipal::preenchePontosContinuo(Point pIni,Point pFim,int indCamada){

    if(pIni==pFim)
        return;

    //define o vizinho de pIni a ser pintado
    int dirX;
    int dirY;

    if((pFim.getJ() - pIni.getJ())==0)dirX = 0;
    else dirX = (pFim.getJ() - pIni.getJ())/abs(pFim.getJ() - pIni.getJ());


    if((pFim.getI() - pIni.getI())==0)dirY = 0;
    else dirY =  (pFim.getI() - pIni.getI())/abs(pFim.getI() - pIni.getI());

    Point npIni (pIni.getI()+dirY,pIni.getJ()+dirX);


    //TRUQUE PARA CRIAR UMA LINHA DUPLA
    int dirXDuplo;
    int dirYDuplo;
    if(dirY == 0 ){
        dirXDuplo = 1;
        dirYDuplo = 0;

    }else{

        if(dirX == 0){
            dirXDuplo = 0;
            dirYDuplo = -1;

        }else{
            if(dirX*dirY>0){

                dirXDuplo = dirX;
                dirYDuplo = 0;

            }else{

                dirXDuplo = 0;
                dirYDuplo = dirY;

            }

        }
    }



    Point npIniDuplo (pIni.getI()+dirYDuplo,pIni.getJ()+dirXDuplo);


    Camada *c = &ui->widget->visualizacaoMapa->listaDeCamadas->operator [](indCamada);



    //testa se pontos sao validos


    c->alteraPonto(npIni,selecaoPontos);

    c->alteraPonto(npIniDuplo,selecaoPontos);

    //    ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[npIni.getI()][npIni.getJ()] = selecaoPontos;
    //    ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[npIniDuplo.getI()][npIniDuplo.getJ()] = selecaoPontos;



    preenchePontosContinuo(npIni,pFim,indCamada);








}



/*!
  \fn JanelaPrincipal::movendoMouse(QMouseEvent* ev)
  \brief Slot for receive command when mouse is moving. Used to create a line for Camada

  */
void JanelaPrincipal::movendoMouse(QMouseEvent* ev){




    //se  tiver alguma camada selecionada e usuario estiver escolhendo os pontos da camada ou seja o botao B/C ativo em C
    if(ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),0) != 0 && escolhendoPontosCamada){


        //Faz correção da posição do click
        ui->widget->posClickX = (ev->x()*ui->widget->visualizacaoMapa->getProporcaoX())/ui->widget->width();
        ui->widget->posClickY = (ev->y()*ui->widget->visualizacaoMapa->getProporcaoY())/ui->widget->height();

        //se o mouse pressionado for alem dos limites do mapa ignora a acao

        if(ui->widget->posClickX<0 || ui->widget->posClickX>=ui->widget->visualizacaoMapa->mapa->getNColunas()
                || ui->widget->posClickY<0 || ui->widget->posClickY >=ui->widget->visualizacaoMapa->mapa->getNLinhas())
            return;



        QString nome = (ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),0))->text();

        int indCamada = ui->widget->visualizacaoMapa->getIndCamada(nome);


        Point aux(ui->widget->posClickY,ui->widget->posClickX);
        Camada *c = &ui->widget->visualizacaoMapa->listaDeCamadas->operator [](indCamada);
        c->alteraPonto(aux,selecaoPontos);





        ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[ui->widget->posClickY][ui->widget->posClickX] = selecaoPontos;



        //se os pontos devem ser continuos cria-se uma linha do ultimo ate o atual
        if(pontosContinuos){


            if(!listaDePosicoesMouse.isEmpty()){
                Point pIni = listaDePosicoesMouse.last();
                Point pFim(ui->widget->posClickY,ui->widget->posClickX);
                preenchePontosContinuo(pIni,pFim,indCamada);
            }

            Point pUltimo(ui->widget->posClickY,ui->widget->posClickX);

            listaDePosicoesMouse.append(pUltimo);

        }



        //ui->widget->updateGL();

    }

}



/*!
  \fn JanelaPrincipal::moveBarragem(QKeyEvent* kev)
  \brief Slot for receive  command when key is pressed. Used to repositioning the dam in new position montante/juzante of the current dam position

  */
void JanelaPrincipal::moveBarragem(QKeyEvent* kev){

    int opAlgoritmoNBarragem ;

    if(ui->radioButtonV->isChecked())
        opAlgoritmoNBarragem = 10;
    if(ui->radioButtonDP->isChecked())
        opAlgoritmoNBarragem = 20;
     if(ui->radioButtonM->isChecked())
         opAlgoritmoNBarragem = 30;


    int valEp = ui->campoEntradaEpislonAlgoritmo->text().toInt();

    int valAlgoritmo = ui->campoEntradaValorAlgoritmo->text().toInt();


    //reposiciona a barragem com o proximo ponto mais a juzante
    if(kev->key() == Qt::Key_Q){

        //Se não existir mapa, sai da função
        if(!ui->widget->mapaEstaCarregado || ui->campoEntradaCapacidadeDesejada->text() == "" ){
            return;
        }

        int dir = ui->widget->visualizacaoMapa->fluxo->direcao[ui->widget->posClickY][ui->widget->posClickX];
        ui->widget->posClickX = ui->widget->posClickX  + ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1];
        ui->widget->posClickY = ui->widget->posClickY + ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0];


        if(eEntruncamentoDeRios(ui->widget->posClickY,ui->widget->posClickX)){


            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[ui->widget->posClickY][ui->widget->posClickX];

            ui->widget->posClickX = ui->widget->posClickX  + ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1];
            ui->widget->posClickY = ui->widget->posClickY + ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0];


        }



    }



    if(kev->key() == Qt::Key_A){


        //Se não existir mapa, sai da função
        if(!ui->widget->mapaEstaCarregado || ui->campoEntradaCapacidadeDesejada->text() == "" ){
            return;
        }



        //definir pra onde a barragem ira subir

        //verificar os oito vizinhos e escolher o de menor altitude
        int i = ui->widget->posClickY;
        int j = ui->widget->posClickX;
        int iEscolhido = i;
        int jEscolhido= j;


        //buscando nos oito vizinhos ao redor
        //        //i-1,j-1
        if(((i-1)>0 && (j-1)>0) && (ui->widget->visualizacaoMapa->fluxo->rio[i-1][j-1]  ) ){
            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i-1][j-1];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j-1) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i-1) == i){
                iEscolhido = i-1;
                jEscolhido = j-1;

            }

        }

        //i-1,j
        if((i-1)>0 && (ui->widget->visualizacaoMapa->fluxo->rio[i-1][j]  )){


            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i-1][j];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i-1) == i){
                iEscolhido = i-1;
                jEscolhido = j;

            }


        }



        //i-1,j+1
        if((i-1)>0 && (j+1)<ui->widget->visualizacaoMapa->mapa->getNColunas() && (ui->widget->visualizacaoMapa->fluxo->rio[i-1][j+1]  )){

            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i-1][j+1];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j+1) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i-1) == i){
                iEscolhido = i-1;
                jEscolhido = j+1;

            }



        }

        //i,j-1
        if( (j-1)>0   && (ui->widget->visualizacaoMapa->fluxo->rio[i][j-1]  )){

            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i][j-1];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j-1) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i) == i){
                iEscolhido = i;
                jEscolhido = j-1;

            }


        }

        //i,j+1
        if((j+1)<ui->widget->visualizacaoMapa->mapa->getNColunas() && (ui->widget->visualizacaoMapa->fluxo->rio[i][j+1]  )){

            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i][j+1];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j+1) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i) == i){
                iEscolhido = i;
                jEscolhido = j+1;

            }


        }

        //i+1,j-1
        if((i+1)<ui->widget->visualizacaoMapa->mapa->getNLinhas() && (j-1)>0  && (ui->widget->visualizacaoMapa->fluxo->rio[i+1][j-1]  )){


            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i+1][j-1];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j-1) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i+1) == i){
                iEscolhido = i+1;
                jEscolhido = j-1;

            }


        }

        //i+1,j
        if((i+1)<ui->widget->visualizacaoMapa->mapa->getNLinhas()  && (ui->widget->visualizacaoMapa->fluxo->rio[i+1][j]  ) ){



            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i+1][j];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i+1) == i){
                iEscolhido = i+1;
                jEscolhido = j;

            }

        }

        //i+1,j+1
        if((i+1)<ui->widget->visualizacaoMapa->mapa->getNLinhas() && (j+1)<ui->widget->visualizacaoMapa->mapa->getNColunas() && (ui->widget->visualizacaoMapa->fluxo->rio[i+1][j+1]  )){


            int dir = ui->widget->visualizacaoMapa->fluxo->direcao[i+1][j+1];
            if((ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1] + j+1) == j  && (ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0] + i+1) == i){
                iEscolhido = i+1;
                jEscolhido = j+1;

            }


        }



        ui->widget->posClickX = jEscolhido;
        ui->widget->posClickY = iEscolhido;


    }


    ui->widget->visualizacaoMapa->setInundacao(ui->widget->posClickX,ui->widget->posClickY,opAlgoritmoNBarragem,valAlgoritmo,valEp);

    ui->widget->updateGL();

    atualizaCamposSaida();



}



/*!
  \fn JanelaPrincipal::imprimeBarragem(VisualizacaoMapa viMapa,int indBarragem)
  \brief Function to print in a file the MDE with dam characteristics. Used when is necessary to avaliate differents dams
  */
void JanelaPrincipal::imprimeBarragem(VisualizacaoMapa viMapa,int indBarragem){



    //arquivoComBarrages<<endl<<indBarragem<<endl;

    QString indices = " Indices-";
    QString elevacoes = QString::number(indBarragem)+"-";
    QString rio = "Rio-";
    QString altBarragem = "AlturaBarragem-";
    QString areaAlagada = "Area Alagada-";
    altBarragem += QString::number(viMapa.inundacao->nivelAgua);

    areaAlagada +=QString::number(viMapa.inundacao->areaLaminaAgua);


    //TODO criar inundaçoes dos elementos
    QString nomeArquivo = "arquivoInundacaoPara";
    nomeArquivo +=QString::number(indBarragem);
    nomeArquivo+=".txt";
    ofstream saidaInundacao(nomeArquivo.toStdString().data());

    //imprimir elementos da barragem somente
    for(int i = 0;i<viMapa.mapa->getNLinhas();i++){
        for(int j = 0;j<viMapa.mapa->getNColunas();j++){
            if(!viMapa.fluxo->rio[i][j])
                saidaInundacao<<viMapa.fluxo->rio[i][j]<<" ";
            else saidaInundacao<<"-1"<<" ";


            if(viMapa.fluxo->rio[i][j] == 2){


                indices += QString::number(i);
                indices += ",";
                indices +=  QString::number(j);
                indices += "-";
                if(viMapa.fluxo->rio[i][j] == true){
                    rio += QString::number(i);
                    rio += ",";
                    rio+= QString::number(j);
                    rio+="-";

                }
                elevacoes +=  QString::number(viMapa.mapa->matrizDeElevacoes[i][j]);
                elevacoes += "-";



            }
        }

        saidaInundacao<<endl;
    }
    //    arquivoComBarrages << indices.toStdString();
    //    arquivoComBarrages <<endl;
    //    arquivoComBarrages <<elevacoes.toStdString();
    //    arquivoComBarrages <<endl;
    //    arquivoComBarrages<<rio.toStdString();
    //    arquivoComBarrages<<endl;
    //    arquivoComBarrages <<altBarragem.toStdString();
    //    arquivoComBarrages <<endl;
    //    arquivoComBarrages<<areaAlagada.toStdString();
    //    arquivoComBarrages<<endl;


}



/*!
  \fn JanelaPrincipal::buscaMelhorPonto(VisualizacaoMapa viMapa,QList<QPoint> listaPontos, double volumeDesejado)
  \brief Function to find the best dam position in a stretch of drainage network
  */
QPoint JanelaPrincipal::buscaMelhorPonto(VisualizacaoMapa viMapa,QList<QPoint> listaPontos, double volumeDesejado){
    //cria varias inundaçoes para cada ponto

    QPoint melhorPonto(0,0);



    int melhorFuncaoObjetivo = 99999999;

    QList<QPoint>::Iterator it = listaPontos.begin();


    int opAlgoritmoNBarragem ;

    if(ui->radioButtonV->isChecked())
        opAlgoritmoNBarragem = 10;
    if(ui->radioButtonDP->isChecked())
        opAlgoritmoNBarragem = 20;
     if(ui->radioButtonM->isChecked())
         opAlgoritmoNBarragem = 30;



    int valEp = ui->campoEntradaEpislonAlgoritmo->text().toInt();
    int valAlgoritmo = ui->campoEntradaValorAlgoritmo->text().toInt();


    //indice para identificar barragens
    int indBarragem = 0;

    //deve-se criar a matriz com a soma das camadas
    viMapa.atualizaCamadasSomadas();


    while(it !=listaPontos.end()){

        int auxPosX = ((QPoint)*it).x();
        int auxPosY = ((QPoint)*it).y();

        viMapa.setInundacao(auxPosX,auxPosY,opAlgoritmoNBarragem,valAlgoritmo,valEp);

        //imprimeBarragem(viMapa,indBarragem);
        indBarragem++;

        int funcaoOC = viMapa.getFuncaoObjetivo();
        //  testa se o volume corrente é melhor do que o melhor associado

        if( funcaoOC < melhorFuncaoObjetivo){
            melhorPonto.setX(auxPosX);
            melhorPonto.setY(auxPosY);

            melhorFuncaoObjetivo = funcaoOC;

        }





        it++;
    }



    //arquivoComBarrages.close();
    //arquivoComBarrages.flush();
    //retorna o melhor ponto
    return melhorPonto;


}



/*!
  \fn JanelaPrincipal::defineCamada(int a, int b)
  \brief Slot for when a cell of Camada map is selected. Is not in use
  */

void JanelaPrincipal::defineCamada(int a, int b){





}


/*!
  \fn JanelaPrincipal::eEntruncamentoDeRios(int posx, int posy)
  \brief Function to define that a cell in drainage network has more than two neighbors that is in drainage network too
  */

bool JanelaPrincipal::eEntruncamentoDeRios(int posx, int posy){


    //verifica se existe mais do que 2 vizinhos sendo rio, assim sendo esta é uma situação de entruncamento
    int numVizinhosRio = 0;
    int i ;
    int j ;

    int dir = ui->widget->visualizacaoMapa->fluxo->direcao[ui->widget->posClickY][ui->widget->posClickX];

    j = ui->widget->posClickX  + ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][1];
    i = ui->widget->posClickY + ui->widget->visualizacaoMapa->fluxo->direcaoDeFluxo[dir][0];


    int col = ui->widget->visualizacaoMapa->mapa->getNColunas();
    int lin = ui->widget->visualizacaoMapa->mapa->getNLinhas();
    /*
      i-1,j-1   i-1  i-1,j+1
      j-1            j+1
      i+1,j-1  i+1   i+1,j+1


      */
    if((i-1) >0 && (j-1)>0){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i-1][j-1])
            numVizinhosRio++;
    }

    if((i-1) >0 ){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i-1][j])
            numVizinhosRio++;
    }

    if((i-1)>0 && (j+1) < col){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i-1][j+1])
            numVizinhosRio++;
    }


    if((j-1) >0 ){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i][j-1])
            numVizinhosRio++;
    }

    if( (j+1) < col){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i][j+1])
            numVizinhosRio++;
    }


    if((i+1) < lin && (j-1)>0){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i+1][j-1])
            numVizinhosRio++;
    }

    if((i+1) < lin ){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i+1][j])
            numVizinhosRio++;
    }

    if((i+1) < lin && (j+1) < col){
        if(ui->widget->visualizacaoMapa->fluxo->rio[i+1][j+1])
            numVizinhosRio++;
    }

    return numVizinhosRio>2;

}



/*!
  \fn JanelaPrincipal::criaVisualizacaoBarragem()
  \brief Function to decide and invoke the 2D or 3D visualization
  */

void JanelaPrincipal::criaVisualizacaoBarragem(){



    if(ui->checkBoxVisualiza3D->isChecked()){



        uiBarragem = new janelabarragem(ui->widget->visualizacaoMapa,this);


        uiBarragem->show();
    }


    if(ui->checkBoxVisualiza2D->isChecked()){

        uiBarragem2d->recarregandoMapa(ui->widget->visualizacaoMapa);

        uiBarragem2d->show();
    }


}



/*!
  \fn JanelaPrincipal::adicionandoPontosACamada(QMouseEvent* evM)
  \brief Slot for when the mouse is released. Used for finish selecting points of the Camada.
  */
void JanelaPrincipal::adicionandoPontosACamada(QMouseEvent* evM){


    escolhendoPontosCamada = false;
    pontosContinuos = false;

    ui->widget->repaint();


}


/*!
  \fn JanelaPrincipal::preencheSolido(int posClickY,int posClickX,int indCamada)
  \brief Function to fill the solid drawed by user before
  */

void JanelaPrincipal::preencheSolido(int posClickY,int posClickX,int indCamada,int numPreenchidos){

    int nColunas = ui->widget->visualizacaoMapa->mapa->getNColunas();
    int nLinhas = ui->widget->visualizacaoMapa->mapa->getNLinhas();

    if(numPreenchidos>2500)
        return;

    if(posClickY<0 ||  posClickX <0 || posClickY>=nLinhas ||  posClickX >=nColunas)
        return;


    //se achou uma borda retorna ou elemento pintado



    //pinta somente no mapa
    if(ui->widget->visualizacaoMapa->mapa->matrizDeElevacoes[posClickY][posClickX] == ui->widget->visualizacaoMapa->mapa->getDadoInvalido())
        return;


    Point aux(posClickY,posClickX);
    Camada *c = &ui->widget->visualizacaoMapa->listaDeCamadas->operator [](indCamada);
    c->alteraPonto(aux,true);





    //    ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[posClickY][posClickX] = true ;

    int i,j;

    i = posClickY-1;
    j = posClickX-1;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas ) {

        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }
    i = posClickY-1;
    j = posClickX;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas) {
        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }
    i = posClickY-1;
    j = posClickX+1;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas ) {
        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }

    i = posClickY;
    j = posClickX-1;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas ) {
        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }
    i = posClickY;
    j = posClickX+1;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas ) {
        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }


    i = posClickY+1;
    j = posClickX-1;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas ) {
        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }
    i = posClickY+1;
    j = posClickX;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas ) {
        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }
    i = posClickY+1;
    j = posClickX+1;
    if (i>=0 && j>=0 && i<nLinhas && j<nColunas ) {
        if(!ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[i][j])
            preencheSolido(i,j,indCamada,numPreenchidos+1);
    }


}


/*!
  \fn JanelaPrincipal::mousePressionadoParaCamada(QMouseEvent * ev)
  \brief Function dedictated for separated the functions that is invoked when the mouse is pressed and the Selecting Camada is actived
  */
//função separa para quando o mouse é apertado e se esta escolhendo pontos da Camada
void JanelaPrincipal::mousePressionadoParaCamada(QMouseEvent * ev){



    //caso esteja no modo selecao de pontos de camada

    if(ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),0) != 0)
    {

        QString nome = (ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),0))->text();

        int indCamada = ui->widget->visualizacaoMapa->getIndCamada(nome);


        ui->widget->posClickX = (ev->x()*ui->widget->visualizacaoMapa->getProporcaoX())/ui->widget->width();
        ui->widget->posClickY = (ev->y()*ui->widget->visualizacaoMapa->getProporcaoY())/ui->widget->height();


        if(ev->button() == Qt::LeftButton){


            escolhendoPontosCamada = true;
            pontosContinuos = true;



            Point aux(ui->widget->posClickY,ui->widget->posClickX);
            Camada *c = &ui->widget->visualizacaoMapa->listaDeCamadas->operator [](indCamada);
            c->alteraPonto(aux,selecaoPontos);



            //            ui->widget->visualizacaoMapa->listaDeCamadas->at(indCamada).pontos[ui->widget->posClickY][ui->widget->posClickX] = selecaoPontos;

            Point pClick(ui->widget->posClickY,ui->widget->posClickX);
            listaDePosicoesMouse.append(pClick);


        }else{

            preencheSolido(ui->widget->posClickY,ui->widget->posClickX,indCamada,0);

        }
    }else{


        //tela avisando que deveria se selecionar uma camada

    }


}



/*!
  \fn JanelaPrincipal::mousePressionadoParaBarragem(QMouseEvent * ev)
  \brief Function dedictated for separated the functions that is invoked when the mouse is pressed and the Position Dam is actived
  */
//função separa para quando o mouse é apertado e se esta escolhendo ponto de posicionamento da barragem ou o trecho
void JanelaPrincipal::mousePressionadoParaBarragem(QMouseEvent * ev){


    //verifica se os campos necessarios estao prenchidos

    bool textoOK;


    bool orientaOK = true;

    QMessageBox erroFaltaParametros;
    erroFaltaParametros.setText("Preencha os campos necessários e com valores válidos antes de posicionar a barragem:");
    erroFaltaParametros.setIcon(QMessageBox::Warning);

    if(ui->campoEntradaCapacidadeDesejada->text().toInt(&textoOK,10) == 0){

        erroFaltaParametros.setText( erroFaltaParametros.text()+"\n" + "-Erro em Capacidade Desejada ");


    }


    if( (!ui->radioButtonV->isChecked()&&!ui->radioButtonDP->isChecked()&&!ui->radioButtonM->isChecked() ) ){

        erroFaltaParametros.setText(erroFaltaParametros.text()+"\n" +"-Erro em Orientação da Barragem");


    }



    if((ui->radioButtonDP->isChecked() || ui->radioButtonV->isChecked() || ui->radioButtonM->isChecked()) && ui->campoEntradaValorAlgoritmo->text().toInt(&orientaOK,10)== 0){

        erroFaltaParametros.setText(erroFaltaParametros.text() +"\n"+"-Erro em N.Viz.");


    }

    if( (ui->campoEntradaEpislonAlgoritmo->text().toInt(&orientaOK,10) == 0 && ui->radioButtonDP->isChecked())){

        erroFaltaParametros.setText(erroFaltaParametros.text()+"\n" +"-Erro em Epsilon");


    }

    if(QString::compare(erroFaltaParametros.text(),
                        "Preencha os campos necessários e com valores válidos antes de posicionar a barragem:")!=0){

        erroFaltaParametros.exec();
        return;

    }


    int opAlgoritmoNBarragem ;

    if(ui->radioButtonV->isChecked())
        opAlgoritmoNBarragem = 10;
    if(ui->radioButtonDP->isChecked())
        opAlgoritmoNBarragem = 20;


    int valEp = ui->campoEntradaEpislonAlgoritmo->text().toInt();

    int valAlgoritmo = ui->campoEntradaValorAlgoritmo->text().toInt();



    //Busca as entradas dos campos de volume desejado e largura maxima da barragem
    ui->widget->visualizacaoMapa->inundacao->tamanhoMaximoDaBarragem = ui->campoEntradaLargMaxBarragem->text().toInt();
    ui->widget->visualizacaoMapa->inundacao->volumeAlvo = ui->campoEntradaCapacidadeDesejada->text().toInt();

    //Faz correção da posição do click
    ui->widget->posClickX = (ev->x()*ui->widget->visualizacaoMapa->getProporcaoX())/ui->widget->width();
    ui->widget->posClickY = (ev->y()*ui->widget->visualizacaoMapa->getProporcaoY())/ui->widget->height();



    //Botão esquerdo do mouse, desenha barragem
    if(ev->button()==Qt::LeftButton){
        //Inunda apenas se clicar sobre um rio
        QKeyEvent *q = new QKeyEvent(QEvent::KeyPress,Qt::Key_Q,Qt::NoModifier);
        if(ui->widget->visualizacaoMapa->fluxo->rio[ui->widget->posClickY][ui->widget->posClickX] ){
            if(eEntruncamentoDeRios(ui->widget->posClickY,ui->widget->posClickX))
                moveBarragem(q);
            else
                ui->widget->visualizacaoMapa->setInundacao(ui->widget->posClickX,ui->widget->posClickY,opAlgoritmoNBarragem,valAlgoritmo,valEp);


        }
        else
            if( pontoDoRioMaisProximo(ui->widget->posClickX,ui->widget->posClickY,20) ){
                if(eEntruncamentoDeRios(ui->widget->posClickY,ui->widget->posClickX))
                    moveBarragem(q);
                else
                    ui->widget->visualizacaoMapa->setInundacao(ui->widget->posClickX,ui->widget->posClickY,opAlgoritmoNBarragem,valAlgoritmo,valEp);

            }

        delete q;

        ui->widget->updateGL();
        criaVisualizacaoBarragem();
        ui->widget->setFocus();

    }

    //Botão direito do mouse, marca trecho=====
    else if(ev->button()==Qt::RightButton){


        //Checa se clicou sobre rio e faz ajuste
        if(!ui->widget->visualizacaoMapa->fluxo->rio[ui->widget->posClickY][ui->widget->posClickX])
            pontoDoRioMaisProximo(ui->widget->posClickX,ui->widget->posClickY,20);


        //verifica se ja marcou os dois pontos
        if(ui->widget->visualizacaoMapa->marcouFim){
            ui->widget->visualizacaoMapa->marcouInicio = false;
            ui->widget->visualizacaoMapa->marcouFim = false;
        }


        //Verifica se já foi marcado inicio do trecho selecionado
        if(!ui->widget->visualizacaoMapa->marcouInicio)
        {
            //Marca posição clicada como inicial ao trecho para escolha da barragem
            ui->widget->visualizacaoMapa->marcaInicioX = ui->widget->posClickX;
            ui->widget->visualizacaoMapa->marcaInicioY = ui->widget->posClickY;

            ui->widget->visualizacaoMapa->marcouInicio = true;
        }
        else
        {
            //Marca posição final do trecho
            ui->widget->visualizacaoMapa->marcaFinalX = ui->widget->posClickX;
            ui->widget->visualizacaoMapa->marcaFinalY = ui->widget->posClickY;


            //Define ponto mais à montante e à jusante
            int montanteX, montanteY;

            //if(ui->widget->visualizacaoMapa->fluxo->fluxo[ui->widget->visualizacaoMapa->marcaInicioY][ui->widget->visualizacaoMapa->marcaInicioX] < ui->widget->visualizacaoMapa->fluxo->fluxo[ui->widget->visualizacaoMapa->marcaFinalY][ui->widget->visualizacaoMapa->marcaFinalX])
            //{
            montanteX = ui->widget->visualizacaoMapa->marcaInicioX;
            montanteY = ui->widget->visualizacaoMapa->marcaInicioY;
            bool **matrizVisitados;
            bool encontrado = false;
            int linhas = ui->widget->visualizacaoMapa->getMapa()->getNLinhas();
            int colunas = ui->widget->visualizacaoMapa->getMapa()->getNColunas();

            matrizVisitados = new bool*[linhas];
            for(int i=0; i<linhas; ++i){
                matrizVisitados[i] = new bool[colunas];
                for(int j=0; j<colunas; ++j)
                    matrizVisitados[i][j] = 0;


            }

            //achando o trecho para a busca

            int pontosAvaliados = 0;
            try{

                ui->widget->visualizacaoMapa->encontraPontosJusante(montanteX,montanteY,encontrado, matrizVisitados,pontosAvaliados);

            }catch(int e){

                QMessageBox erroFaltaParametros;

                erroFaltaParametros.setText("Não foi possível determinar um trecho válido com os posicionamentos que você definiu. Por favor escolha outros."+ui->widget->visualizacaoMapa->maxPontosABuscar);
                erroFaltaParametros.setIcon(QMessageBox::Warning);

                erroFaltaParametros.exec();

                ui->widget->visualizacaoMapa->marcouFim = true;
                return;


            }


            QList<QPoint> listaDePossiveisPontos;

            for(int i=0; i<linhas; ++i){
                for(int j=0; j<colunas; ++j)
                    if(matrizVisitados[i][j]){
                        ui->widget->visualizacaoMapa->fluxo->rio[i][j] = 5;
                        QPoint aux(j,i);
                        listaDePossiveisPontos.push_front(aux);
                    }
            }//fim for
            //}//fim if

            double volumeDesejado =   ui->campoEntradaCapacidadeDesejada->text().toDouble();


            //                arquivoComBarrages <<"Ponto inicial"<<ui->widget->visualizacaoMapa->marcaInicioX<<" "<<ui->widget->visualizacaoMapa->marcaInicioY<<endl;
            //                arquivoComBarrages <<"Ponto final"<<ui->widget->visualizacaoMapa->marcaFinalX<<" "<<ui->widget->visualizacaoMapa->marcaFinalY<<endl;

            QPoint melhorPonto = buscaMelhorPonto(*ui->widget->visualizacaoMapa,listaDePossiveisPontos,volumeDesejado);

            ui->widget->visualizacaoMapa->marcouFim = true;
            if(ui->widget->visualizacaoMapa->fluxo->rio[melhorPonto.y()][melhorPonto.x()])
                ui->widget->visualizacaoMapa->setInundacao(melhorPonto.x(),melhorPonto.y(),opAlgoritmoNBarragem,valAlgoritmo,valEp);

        }//fim else que condiz com sendo o segundo click

    }
    //Exibe informações nos campos de saida
    atualizaCamposSaida();




}

/*!
  \fn JanelaPrincipal::defineInundacao(QMouseEvent * ev)
  \brief Slot for when mouse is pressed. It has a selector to decide what function call (the mousePressionadoParaCamada(QMouseEvent * ev) or the mousePressionadoParaBarragem(QMouseEvent * ev))
  */


//slot para mouse pressionado
void JanelaPrincipal::defineInundacao(QMouseEvent * ev){
    //Se não existir mapa, sai da função
    if(!ui->widget->mapaEstaCarregado ){
        return;
    }



    //Faz correção da posição do click
    ui->widget->posClickX = (ev->x()*ui->widget->visualizacaoMapa->getProporcaoX())/ui->widget->width();
    ui->widget->posClickY = (ev->y()*ui->widget->visualizacaoMapa->getProporcaoY())/ui->widget->height();

    //se o mouse pressionado for alem dos limites do mapa ignora a acao

    if(ui->widget->posClickX<0 || ui->widget->posClickX>=ui->widget->visualizacaoMapa->mapa->getNColunas()
            || ui->widget->posClickY<0 || ui->widget->posClickY>=ui->widget->visualizacaoMapa->mapa->getNColunas())
        return;


    //seleciona qual funcao chamar
    if(!selecaoPontoBarragem){



        ui->widget->flagPinta = false;
        mousePressionadoParaCamada( ev);


    }else{

        ui->widget->flagPinta = true;
        mousePressionadoParaBarragem(ev);



    }




    ui->widget->updateGL();
}


/*!
  \fn JanelaPrincipal::pontoDoRioMaisProximo(int posX, int posY, int raio)
  \brief Function to attract the click of mouse for a drainage network cell
  */
//função para atrair o click do mouse para um ponto da rede de drenagem
bool JanelaPrincipal::pontoDoRioMaisProximo(int posX, int posY, int raio)
{



    try{
        //posicao clicks
        int x = ui->widget->posClickX;
        int y = ui->widget->posClickY;

        int distVizinho = 1;
        int maxConjuntoVizinhos = raio;
        boolean encontrado = false;
        //for que define a quantidade de vizinhos a serem buscados
        //em cada lado, cima e baixo, para cada distVizinhos
        for(int j = 3; j < maxConjuntoVizinhos; j += 2){

            //define intervalo dos vizinhos
            int iMin = (-1)*(j/2);
            int iMax = (j/2);

            //for para vericar os vizinhos da primeira e ultima linha e coluna, para o distVizinho em questao
            for(int i = iMin; i < iMax; i++ ){

                //primeira linha
                //teste para nao exceder os limites da matriz
                //nao esta antes da primeira linha e nao excede a ultima coluna nem a primeira
                if( ((y - distVizinho) >= 0) && ((x + i) < ui->widget->visualizacaoMapa->getMapa()->getNColunas()) && ((x + i) >= 0)){
                    //vericando se o vizinho é rio
                    if(ui->widget->visualizacaoMapa->fluxo->rio[y - distVizinho][x + i]){
                        ui->widget->posClickX = x + i;
                        ui->widget->posClickY = y - distVizinho;
                        encontrado = true;
                        break;
                    }

                }//fim if primeira linha

                //ultima linha
                //teste para nao exceder os limites da matriz
                //nao esta depois da ultima linha e nao excede a ultima coluna nem a primeira
                if( ((y + distVizinho) < ui->widget->visualizacaoMapa->getMapa()->getNLinhas()) && ((x + i) < ui->widget->visualizacaoMapa->getMapa()->getNColunas()) && ((x + i) >= 0)){
                    //vericando se o vizinho é rio
                    if(ui->widget->visualizacaoMapa->fluxo->rio[y + distVizinho][x + i]){
                        ui->widget->posClickX = x + i;
                        ui->widget->posClickY = y + distVizinho;
                        encontrado = true;
                        break;
                    }

                }//fim if ultima linha


                //teste para evitar verificaçoes duplicadas dos cantos
                if((i != iMin) && (i != iMax)){

                    //primeira coluna
                    //teste para nao exceder os limites da matriz
                    //nao esta depois da ultima linha e antes a primeira linha e primeira coluna
                    if( ((y + i) < ui->widget->visualizacaoMapa->getMapa()->getNLinhas()) && ((y + i) >= 0) && ((x - distVizinho) >= 0)){
                        //vericando se o vizinho é rio
                        if(ui->widget->visualizacaoMapa->fluxo->rio[y + i][x - distVizinho]){
                            ui->widget->posClickX = x - distVizinho;
                            ui->widget->posClickY = y + i;
                            encontrado = true;
                            break;
                        }

                    }//fim if primeira coluna

                    //ultima coluna
                    //teste para nao exceder os limites da matriz
                    //nao esta depois da ultima linha e antes a primeira linha e nem depois da ultima coluna
                    if( ((y + i) < ui->widget->visualizacaoMapa->getMapa()->getNLinhas()) && ((y + i) >= 0) && ((x + distVizinho) < ui->widget->visualizacaoMapa->getMapa()->getNColunas())){
                        //vericando se o vizinho é rio
                        if(ui->widget->visualizacaoMapa->fluxo->rio[y + i][x + distVizinho]){
                            ui->widget->posClickX = x + distVizinho;
                            ui->widget->posClickY = y + i;
                            encontrado = true;
                            break;
                        }

                    }//fim if ultima coluna

                }//fim if teste para evitar cantos

            }//fim for interno

            distVizinho++;
            if(encontrado)
                break;

        }//fim for externo


        if(encontrado){
            double evX = (1.0*ui->widget->posClickX/ui->widget->visualizacaoMapa->getProporcaoX())*ui->widget->width();
            double evY = (1.0*ui->widget->posClickY/ui->widget->visualizacaoMapa->getProporcaoY())*ui->widget->height();


            QCursor::setPos(ui->widget->mapToGlobal(QPoint(evX,evY)));
        }

        return encontrado;
    }catch(exception e){

        QString erroMsg="Erro no metodo pontoMaisProximo na classe janelPrincipal";
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
  \fn JanelaPrincipal::trocaCoordenadas(QMouseEvent*q)
  \brief Slot for when mouse is moved. Used to set the position of the mouse in the main window
  */
void JanelaPrincipal::trocaCoordenadas(QMouseEvent*q){

    //Faz a captura da posição do mouse e seta o valor dos campos de saida
    if(this->ui->widget->mapaEstaCarregado){
        char auxX[10];
        char auxY[10];
        itoa(q->x()/this->ui->widget->visualizacaoMapa->getProporcaoZoom(),auxX,10);
        itoa(q->y()/this->ui->widget->visualizacaoMapa->getProporcaoZoom(),auxY,10);
        this->ui->campoSaidaCoordenadasX->setText(auxX);
        this->ui->campoSaidaCoordenadasY->setText(auxY);
    }


}



/*!
  \fn JanelaPrincipal::~JanelaPrincipal()
  \brief Destructor
  */
JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}


/*!
  \fn JanelaPrincipal::habilitandoBotoes()
  \brief Function to enable the buttons, fields and others.
  */
void JanelaPrincipal::habilitandoBotoes(){
    ui->barraZoom->setEnabled(true);
    ui->botaoZoomMais->setEnabled(true);
    ui->botaoZoomMenos->setEnabled(true);


    ui->botaoAdicionarInundacao->setEnabled(true);
    //    ui->botaoExcluirInundacao->setEnabled(true);
    //    ui->botaoVisualizarInundacao->setEnabled(true);


    ui->botaoAtualizarFluxoMinimo->setEnabled(true);


    ui->insereCamada->setEnabled(true);
    ui->deletaCamada->setEnabled(true);
    ui->selecaoPontosCamada->setEnabled(true);


    ui->actionFechar_mapa->setEnabled(true);

    ui->botaoAlternaBC->setEnabled(true);

    this->ui->caixaApresentaFuncaoObjetivo->setEnabled(true);






}


/*!
  \fn JanelaPrincipal::desAbilitandoBotoes()
  \brief Function to disable the buttons, fields and others.
  */
void JanelaPrincipal::desAbilitandoBotoes(){
    ui->barraZoom->setEnabled(false);
    ui->botaoAdicionarInundacao->setEnabled(false);
    ui->botaoAtualizarFluxoMinimo->setEnabled(false);

    if(stringAreaProjeto.empty()){
        ui->botaoVisualizarInundacao->setEnabled(false);
        ui->botaoExcluirInundacao->setEnabled(false);
    }
    ui->botaoZoomMais->setEnabled(false);
    ui->botaoZoomMenos->setEnabled(false);

    ui->insereCamada->setEnabled(false);
    ui->deletaCamada->setEnabled(false);
    ui->selecaoPontosCamada->setEnabled(false);

    ui->actionFechar_mapa->setEnabled(false);

    ui->botaoAlternaBC->setEnabled(false);

    repaint();

}


/*!
  \fn JanelaPrincipal::setaTamanhoBarraDeZoom()
  \brief Function to set the size of zoom bar
  */
void JanelaPrincipal::setaTamanhoBarraDeZoom(){

    ui->barraZoom->setMinimum(0);
    if(ui->widget->mapaEstaCarregado)
        ui->barraZoom->setMaximum(this->ui->widget->visualizacaoMapa->tamanhoDaBarraDeZoom);
    else
        ui->barraZoom->setMaximum(10);

    ui->barraZoom->repaint();



}


/*!
  \fn JanelaPrincipal::setaTelaPadrao()
  \brief Function to set the default window with clear fields, disable buttons and others
  */
void JanelaPrincipal::setaTelaPadrao(){
    //nesta funcao setaremos a tela padrao
    //limpando os campos e os sliders voltando ao seu normal

    this->ui->barraZoom->setSliderPosition(0);

    //campos de entrada
    this->ui->campoEntradaCapacidadeDesejada->setText("");
    this->ui->campoEntradaFluxoMinimo->setText("");
    this->ui->campoEntradaLargMaxBarragem->setText("");
    this->ui->campoEntradaValorAlgoritmo->setText("");
    this->ui->campoEntradaEpislonAlgoritmo->setText("");

    this->ui->radioButtonDP->setChecked(false);
    this->ui->radioButtonV->setChecked(false);

    //campos de saida
    this->ui->caixaPreSalvo->setChecked(false);

    this->ui->campoSaidaAlturaBarragem->setText("");
    this->ui->campoSaidaAreaLaminaDaAgua->setText("");
    this->ui->campoSaidaCaminhoArquivo->setText("");
    this->ui->campoSaidaCapacidadeTotal->setText("");

    this->ui->campoSaidaCoordenadasX->setText("");
    this->ui->campoSaidaCoordenadasY->setText("");

    this->ui->campoSaidaCoordenadasBaseX->setText("");
    this->ui->campoSaidaCoordenadasBaseY->setText("");

    this->ui->campoSaidaExtensaoBarragem->setText("");
    this->ui->campoSaidaFluxoMinimo->setText("-");
    this->ui->campoSaidaNomeArquivo->setText("");




    this->ui->campoSaidaAreaBarragem->setText("");
    this->ui->campoSaidaFuncaoObjetivo->setText("");
    //setando as barras de zoom

    setaTamanhoBarraDeZoom();



}


/*!
  \fn JanelaPrincipal::on_actionAbrir_mapa_triggered()
  \brief Slot for when option actionAbrir_mapa is pressed
  */
//slot de chamada para o actionAbrir_mapa quando pressionado, cria o MDE seta-o na tela de visualizacao
void JanelaPrincipal::on_actionAbrir_mapa_triggered(){

    QString fileName = QFileDialog::getOpenFileName(this,"Escolha o mapa");//getting the file name
    if(!fileName.isNull()){



        ui->groupBox_7->setTitle(ui->groupBox_7->title()+"-Carregando mapa. Espere por favor ....");
        ui->groupBox_7->repaint();


        if(ui->widget->mapaEstaCarregado){
            delete ui->widget->visualizacaoMapa;
            ui->widget->visualizacaoMapa = NULL;
        }
        this->ui->widget->carregandoMapa(fileName.toAscii().data());

        ui->groupBox_7->setTitle("Visualização");
        ui->groupBox_7->repaint();

        setaTelaPadrao();
        habilitandoBotoes();

        this->ui->campoSaidaNomeArquivo->setText( fileName.section("/",-1,-1));
        this->ui->campoSaidaCaminhoArquivo->setText(fileName);

        //Seta campo de saida de fluxo
        char saidaFluxo[20];
        itoa(ui->widget->visualizacaoMapa->fluxo->fluxoMinimo,saidaFluxo,10);
        this->ui->campoSaidaFluxoMinimo->setText(saidaFluxo);


    }


}


/*!
  \fn JanelaPrincipal::atualizaCamposSaida()
  \brief Function to update the fields to show user
  */
void JanelaPrincipal::atualizaCamposSaida(){

    //nome do arquivo e caminho
    QString aux1(this->ui->widget->visualizacaoMapa->getMapa()->getNomeArquivo());
    this->ui->campoSaidaNomeArquivo->setText(aux1);

    QString aux2(this->ui->widget->visualizacaoMapa->getMapa()->getCaminhoArquivo());
    this->ui->campoSaidaCaminhoArquivo->setText(aux2);

    //Seta campo de saida de fluxo
    char saidaFluxo[20];
    itoa(ui->widget->visualizacaoMapa->fluxo->fluxoMinimo,saidaFluxo,10);
    this->ui->campoSaidaFluxoMinimo->setText(saidaFluxo);

    this->ui->caixaPreSalvo->setChecked(this->ui->widget->visualizacaoMapa->estaPreSalvo);


    //campos de resposta
    char auxSaida[20];
    itoa(ui->widget->visualizacaoMapa->inundacao->areaLaminaAgua,auxSaida,10);
    ui->campoSaidaAreaLaminaDaAgua->setText(auxSaida);
    itoa(ui->widget->visualizacaoMapa->inundacao->volumeAgua,auxSaida,10);
    ui->campoSaidaCapacidadeTotal->setText(auxSaida);
    itoa(ui->widget->visualizacaoMapa->inundacao->nivelAgua,auxSaida,10);
    ui->campoSaidaAlturaBarragem->setText(auxSaida);
    itoa(ui->widget->visualizacaoMapa->inundacao->comprimentoBarragemTocada,auxSaida,10);
    ui->campoSaidaExtensaoBarragem->setText(auxSaida);
    itoa(ui->widget->visualizacaoMapa->inundacao->areaBarragemTocada,auxSaida,10);
    ui->campoSaidaAreaBarragem->setText(auxSaida);


    if(ui->caixaApresentaFuncaoObjetivo->isChecked()){

        ui->widget->visualizacaoMapa->atualizaCamadasSomadas();
        int respFO = ui->widget->visualizacaoMapa->getFuncaoObjetivo();
        itoa(respFO,auxSaida,10);
        ui->campoSaidaFuncaoObjetivo->setText(auxSaida);
    }

    //setando paramentros da solucao

    itoa(this->ui->widget->visualizacaoMapa->inundacao->volumeAlvo,auxSaida,10);
    ui->campoEntradaCapacidadeDesejada->setText(auxSaida);

    itoa(this->ui->widget->visualizacaoMapa->inundacao->getPosicaoBarragem().x,auxSaida,10);
    ui->campoSaidaCoordenadasBaseX->setText(auxSaida);
    itoa(this->ui->widget->visualizacaoMapa->inundacao->getPosicaoBarragem().y,auxSaida,10);
    ui->campoSaidaCoordenadasBaseY->setText(auxSaida);


}



/*!
  \fn JanelaPrincipal::on_barraZoom_sliderMoved(int position)
  \brief Slot for when barraZoom is moved
  */
void JanelaPrincipal::on_barraZoom_sliderMoved(int position){

    this->ui->widget->zoomMapa(position);

}


/*!
  \fn JanelaPrincipal::on_botaoZoomMais_clicked()
  \brief Slot for when button botaoZoomMais is pressed. Zoom in the map
  */
//slot para o botao de zoom mais...aumenta o zoom
void JanelaPrincipal::on_botaoZoomMais_clicked(){

    if(this->ui->barraZoom->sliderPosition() < this->ui->barraZoom->maximum()){
        this->ui->barraZoom->setSliderPosition( this->ui->barraZoom->sliderPosition() + 1);
        on_barraZoom_sliderMoved(this->ui->barraZoom->sliderPosition());
        int tamBarraHorizontal = ui->scrollArea->horizontalScrollBar()->maximum();
        int tamBarraVertical = ui->scrollArea->verticalScrollBar()->maximum();

        ui->scrollArea->horizontalScrollBar()->setValue(tamBarraHorizontal/2);
        ui->scrollArea->verticalScrollBar()->setValue(tamBarraVertical/2);

    }

}


/*!
  \fn JanelaPrincipal::on_botaoAtualizarFluxoMinimo_clicked()
  \brief Slot for when button botaoAtualizarFluxoMinimo is pressed. Use to update the drainage network based on this value
  */
void JanelaPrincipal::on_botaoAtualizarFluxoMinimo_clicked(){

    int valorCampo = this->ui->campoEntradaFluxoMinimo->text().toInt();

    if(valorCampo>=0){
        this->ui->widget->visualizacaoMapa->fluxo->fluxoMinimo = valorCampo;
        this->ui->campoSaidaFluxoMinimo->setText(this->ui->campoEntradaFluxoMinimo->text());
        this->ui->widget->computaFluxo();
    }

}


/*!
  \fn JanelaPrincipal::on_botaoZoomMenos_clicked()
  \brief Slot for when button botaoZoomMenos is pressed. Zoom out the map
  */
void JanelaPrincipal::on_botaoZoomMenos_clicked(){
    if(this->ui->barraZoom->sliderPosition() > 0){
        this->ui->barraZoom->setSliderPosition( this->ui->barraZoom->sliderPosition() - 1);
        on_barraZoom_sliderMoved(this->ui->barraZoom->sliderPosition());

        int tamBarraHorizontal = ui->scrollArea->horizontalScrollBar()->maximum();
        int tamBarraVertical = ui->scrollArea->verticalScrollBar()->maximum();

        ui->scrollArea->horizontalScrollBar()->setValue(tamBarraHorizontal/2);
        ui->scrollArea->verticalScrollBar()->setValue(tamBarraVertical/2);


    }
}


/*!
  \fn JanelaPrincipal::on_botaoAdicionarInundacao_clicked()
  \brief Slot for when button botaoAdicionarInundacao is pressed. Salve this reservoir in the Area de Projeto
  */

//slot para o botao adicionarInundacao. Usado para adicionar(salvar) o reservatorio a area de projeto
void JanelaPrincipal::on_botaoAdicionarInundacao_clicked(){

    bool ok;
    QString text = QInputDialog::getText(this, tr(""),
                                         tr("Nomeie a inundaçao"), QLineEdit::Normal,
                                         QString::null, &ok);
    if (!(ok && !text.isEmpty()))
        return;



    //==Verifica se existe elemento com o mesmo nome na árvore==
    //Se existir, concatena o trecho "_i" ao nome do elemento, onde i é o numero de elementos de mesmo nome
    bool primeiraVez = true;
    int quantos = 0;
    while(mapeamentoAreaProjeto.count(text.toStdString()) > 0){
        if(primeiraVez){
            text.append("_"); //Concatena numero ao nome para evitar duplicidade
            text.append("1");
            quantos++;
            primeiraVez = false;
        }
        else
        {
            //Concatena o número equivalente ao número de elementos de igual nome já existentes
            char textQuantos[5];
            char textQuantosProximo[5];
            itoa(quantos,textQuantos,10);
            itoa(quantos+1,textQuantosProximo,10);
            text.replace(textQuantos,textQuantosProximo);
            quantos++;
        }

    }

    VisualizacaoMapa auxVisualicaoMapa(*ui->widget->visualizacaoMapa);
    //setando o mapa estar pre salvo
    auxVisualicaoMapa.estaPreSalvo = true;
    //adicionando-o ao map
    map<string,VisualizacaoMapa>::iterator it = mapeamentoAreaProjeto.begin();
    mapeamentoAreaProjeto.insert(it,pair<string,VisualizacaoMapa>(text.toStdString(),auxVisualicaoMapa));

    //adicionando a lista de string
    stringAreaProjeto.append(text);


    ((QStringListModel*)(ui->listView->model()))->setStringList(stringAreaProjeto);




    ui->botaoExcluirInundacao->setEnabled(true);
    ui->botaoVisualizarInundacao->setEnabled(true);



}


/*!
  \fn JanelaPrincipal::on_botaoExcluirInundacao_clicked()
  \brief Slot for when button botaoExcluirInundacao is pressed. Exlude the selected reservoir in the Area de Projeto
  */

//slot para o botao excluirInundacao. Usado para excluir o reservatorio selecionado da area de projeto
void JanelaPrincipal::on_botaoExcluirInundacao_clicked(){

    QStringListModel *auxList =  ((QStringListModel*)ui->listView->model());

    QModelIndex indObejetoSelecionado = ui->listView->currentIndex();

    if(!indObejetoSelecionado.isValid())
        return;
    else{//caso esteja selecionado alguma inundaçao salva

        QString stringARemover = (auxList->data(indObejetoSelecionado,0)).toString();


        //LIMPAR DA LISTA DE VISUALIZACAO
        stringAreaProjeto.removeOne(stringARemover);
        ((QStringListModel*)(ui->listView->model()))->setStringList(stringAreaProjeto);
        ui->listView->update();



        //LIMPAR DO MAP
        //areaProjeto.erase(*areaProjeto.find(stringARemover));
        mapeamentoAreaProjeto.erase(mapeamentoAreaProjeto.find(stringARemover.toStdString()));

        if(mapeamentoAreaProjeto.find(stringARemover.toStdString()) == mapeamentoAreaProjeto.end())
            cout<<"Retirou";

    }


    if(stringAreaProjeto.isEmpty()){

        ui->botaoExcluirInundacao->setEnabled(false);
        ui->botaoVisualizarInundacao->setEnabled(false);

    }




}



/*!
  \fn JanelaPrincipal::on_botaoVisualizarInundacao_clicked()
  \brief Slot for when button botaoVisualizarInundacao is pressed. Show the selected reservoir in Area de Visualizacao

  */
//slot para o botao visualizarInundacao. Usado para visualizar na Area de visualizacao o reservatorio selecionado da area de projeto
void JanelaPrincipal::on_botaoVisualizarInundacao_clicked(){


    QStringListModel *auxList =  ((QStringListModel*)ui->listView->model());

    QModelIndex indObejetoSelecionado = ui->listView->currentIndex();

    if(!indObejetoSelecionado.isValid())
        return;
    else{//caso esteja selecionado alguma inundaçao salva

        QString stringObjetoSelecionado = (auxList->data(indObejetoSelecionado,0)).toString();

        //libera a memoria do antigo
        delete ui->widget->visualizacaoMapa;
        //atribui o objeto selecionado ao atributo de visualizaçao da tela


        ui->widget->visualizacaoMapa = new VisualizacaoMapa( mapeamentoAreaProjeto.at(stringObjetoSelecionado.toStdString()));

        //cria o mapa de camadas
        deletaListaComCamadas();
        criaListaComCamadas();



        //Zera o valor do zoom caso esteja ampliado
        ui->widget->mapaEstaCarregado = true;
        setaTelaPadrao();
        habilitandoBotoes();
        ui->widget->zoomMapa(0);


        //define ortho para a visualicao a ser apresentada
        ui->widget->defineOrtho();
        //atualiza a tela e todo os campos
        ui->widget->update();
        //atualizando todos os campos
        atualizaCamposSaida();

    }


}


/*!
  \fn JanelaPrincipal::on_insereCamada_clicked()
  \brief Slot for when button insereCamada is pressed. Used to create a new Camada (critical region) insert in Camada`s mapping and in current MDE Camada`s list

  */
//slot para o botao insereCamada. Usado para inserir uma nova camada, inser esta na mapeamento de camadas
void JanelaPrincipal::on_insereCamada_clicked(){
    bool ok;
    //obtendo os parametros para a nova camada
    QStringList parametrosNovaCamada = uiCamadas->getValores(ok);

    //verificando se nao foi apertado ok ou se os campos estao vazios
    if( !ok || parametrosNovaCamada.at(0).isEmpty() || parametrosNovaCamada.at(1).isEmpty() )
        return;






    //==Verifica se existe elemento com o mesmo nome na árvore de camadas==
    //Se existir, concatena o trecho "_i" ao nome do elemento, onde i é o numero de elementos de mesmo nome

    int maior = 0;
    int quantos = 0;
    bool existeIgual = false;

    QString nome;


    //percorrendo a lista toda e contando quantos elementos com nome repetido
    //a principio era realizado com o objeto table porem devidos a paus nao definidos foi
    //utilizado a lista
    for(int i = 0;i<ui->widget->visualizacaoMapa->listaDeCamadas->size();i++){


        Camada aux = ui->widget->visualizacaoMapa->listaDeCamadas->at(i);
        QStringList listNome = (aux).getNome().split(QRegExp("_"));




        if(listNome.at(0) == parametrosNovaCamada.at(0)){
            if(listNome.size() == 1) existeIgual = true;
            if(listNome.size()== 1)
                quantos = 1;

            else{
                bool ok = false;
                if(maior < (listNome.at(1).toInt(&ok,10) + 1))
                    maior = listNome.at(1).toInt(&ok,10) + 1;


                quantos = maior;




            }




        }
    }

    if(!existeIgual )
        nome = parametrosNovaCamada.at(0);
    else{


        nome = parametrosNovaCamada.at(0)+"_";

        char textQuantos[5];
        itoa(quantos,textQuantos,10);
        nome += (textQuantos);
    }







    //criar um elemento camada com os dados
    Camada camadaASerInserida(nome,parametrosNovaCamada.at(1).toDouble(),QColor::QColor(parametrosNovaCamada.at(2)), ui->widget->visualizacaoMapa->mapa->getNLinhas(),ui->widget->visualizacaoMapa->mapa->getNColunas());

    //inserir este elemento no objeto lista contendo as camadas, para quando necessario usa-lo pelo

    ui->widget->visualizacaoMapa->listaDeCamadas->insert(ui->widget->visualizacaoMapa->listaDeCamadas->end(),camadaASerInserida);



    //inserir esta camada na lista que eh exposta ao usuario


    int cp = ui->camadaTableWidget->rowCount();
    ui->camadaTableWidget->insertRow(cp);

    // ui->camadaTableWidget->setRowCount();

    //    inserindo o item ultimalinhax0
    QTableWidgetItem *itemNome =  new QTableWidgetItem(0);
    itemNome->setText(nome);
    itemNome->setBackgroundColor(camadaASerInserida.getCorCamada());
    ui->camadaTableWidget->setItem(cp,0,itemNome);


    //inserindo o item ultimalinhax1
    QTableWidgetItem *itemPeso =  new QTableWidgetItem(0);
    itemPeso->setText( QString::number(camadaASerInserida.getPeso(),'g',6));
    itemPeso->setBackgroundColor(camadaASerInserida.getCorCamada());

    ui->camadaTableWidget->setItem(cp,1,itemPeso);



    //    //inserindo o check box
    QCheckBox *q = new QCheckBox();
    q->setCheckState(Qt::Checked);



    //inserindo o checkbox ultimalinhax1
    QTableWidgetItem *itemCheckBox =  new QTableWidgetItem(0);


    itemCheckBox->setCheckState(Qt::Checked);

    itemCheckBox->setFlags( itemCheckBox->flags()| Qt::ItemIsUserCheckable);
    itemCheckBox->setCheckState(Qt::Checked);


    ui->camadaTableWidget->setItem(cp,2,itemCheckBox);




}



/*!
  \fn JanelaPrincipal::exporCamada(QTableWidgetItem* qtwItem)
  \brief Slot for when item of Camada map`s is changed. Used to show or not the Camada to the user

  */
//slot para quando um item do mapeamento de camadas é modificado. Usado para expor ou não a camada ao usuario
void JanelaPrincipal::exporCamada(QTableWidgetItem* qtwItem){


    if(ui->camadaTableWidget->currentRow() == -1) return;
    QString nome = (ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),0))->text();

    int ind = ui->widget->visualizacaoMapa->getIndCamada(nome);
    bool resp;



    if(ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),2)->checkState() == 0)
        resp = false;
    else
        resp = true;







    //Gambiarrra devido ao metodo retornar apenas const
    //dai cria-se um objeto modifica o valor desejado e
    // deleta o antigo da lista, inserindo o novo na mesma
    ///

    //criar uma camada inserir os novos elementos
    Camada c =  ui->widget->visualizacaoMapa->listaDeCamadas->operator [](ind);
    //verificar se foi o botao de check o pressionado
    if(c.estaVisivel == resp)
        return;

    c.estaVisivel = resp;

    //deletar a antiga...
    ui->widget->visualizacaoMapa->listaDeCamadas->removeAt(ind);
    //inserir a nova
    ui->widget->visualizacaoMapa->listaDeCamadas->insert(ind,c);
    ui->widget->flagPinta = true;
    ui->widget->repaint();
    ui->widget->flagPinta = false;

}


/*!
  \fn JanelaPrincipal::on_selecaoPontosCamada_clicked()
  \brief Slot for when button selecaoPontosCamada is pressed. Define if the user will add or delete a point of the Camada in map

  */

//slot para o botao selecaoPontosCamada que define se quando o usuario clicar estará adicionando ou nao pontos a camada
void JanelaPrincipal::on_selecaoPontosCamada_clicked(){

    selecaoPontos = !selecaoPontos;



    //coloco o icone de adicionar celulas a camada
    if(selecaoPontos){

        QIcon icone("../imagens/selecaoMais.png");
        ui->selecaoPontosCamada->setIcon(icone);



    }else{

        QIcon icone("../imagens/selecaoMenos.png");

        ui->selecaoPontosCamada->setIcon(icone);



    }


    ui->selecaoPontosCamada->repaint();

    repaint();
}



void JanelaPrincipal::on_radioButtonV_clicked(){
    ui->campoEntradaEpislonAlgoritmo->setEnabled(false);
}

void JanelaPrincipal::on_radioButtonDP_clicked()
{
    ui->campoEntradaEpislonAlgoritmo->setEnabled(true);
}

void JanelaPrincipal::on_pushButton_clicked()
{


    ui->botaoZoomMais->setGeometry(10,10,10,10);
}

/*!
  \fn JanelaPrincipal::moveZoomHorizontal(int value)
  \brief Slot for when horizontal roll bar is moved. Used to repositioning the zoom bar/buttons, and it become always visible

  */

//slot para quando a barra de rolagem horizontal é movida. Usada para reposicionar a barra/botoes de zoom e assim estando sempre visivel
void JanelaPrincipal::moveZoomHorizontal(int value){
    //move zoom mais
    ui->botaoZoomMais->setGeometry(posXBotaoZoomMais + value,ui->botaoZoomMais->geometry().y(),ui->botaoZoomMais->geometry().width(),ui->botaoZoomMais->geometry().height());
    //move zoom menos
    ui->botaoZoomMenos->setGeometry(posXBotaoZoomMenos + value,ui->botaoZoomMenos->geometry().y(),ui->botaoZoomMenos->geometry().width(),ui->botaoZoomMenos->geometry().height());

    //move barra zoom
    ui->barraZoom->setGeometry(posXBarraZoom + value,ui->barraZoom->geometry().y(),ui->barraZoom->geometry().width(),ui->barraZoom->geometry().height());

}


/*!
  \fn JanelaPrincipal::moveZoomVertical(int value)
  \brief Slot for when vertical roll bar is moved. Used to repositioning the zoom bar/buttons, and it become always visible

  */
//slot para quando a barra de rolagem vertical é movida. Usada para reposicionar a barra/botoes de zoom e assim estando sempre visivel

void JanelaPrincipal::moveZoomVertical(int value){
    //move zoom mais
    ui->botaoZoomMais->setGeometry(ui->botaoZoomMais->geometry().x(),posYBotaoZoomMais + value,ui->botaoZoomMais->geometry().width(),ui->botaoZoomMais->geometry().height());
    //move zoom menos
    ui->botaoZoomMenos->setGeometry(ui->botaoZoomMenos->geometry().x(),posYBotaoZoomMenos + value,ui->botaoZoomMenos->geometry().width(),ui->botaoZoomMenos->geometry().height());

    //move barra zoom
    ui->barraZoom->setGeometry(ui->barraZoom->geometry().x(),posYBarraZoom + value,ui->barraZoom->geometry().width(),ui->barraZoom->geometry().height());

}

/*!
  \fn JanelaPrincipal::on_actionSobre_triggered()
  \brief Slot for when option actionSobre is pressed. Show the about window

  */
//slot para quando a opcao sobre é pressionada. Usada para apresentar a janela de sobre

void JanelaPrincipal::on_actionSobre_triggered()
{

    janelasobre *js = new janelasobre();

    js->exec();

    delete js;


}



/*!
  \fn JanelaPrincipal::criaListaComCamadas()
  \brief Function to construct the Camada mapping for the current MDE showing in Area de Visualizacao

  */
//funcao para criar a lista de camadas para a visualizacao corrente na Area de Visualizacao. Geralmente utilizada quando se quer visualizar um
//reservatorio presente na lista de reservatorios (Area de projeto)
void JanelaPrincipal::criaListaComCamadas(){






    for(int it=0;it<ui->widget->visualizacaoMapa->listaDeCamadas->size();it++){

        //criar um elemento camada com os dados

        Camada camadaASerInserida = ui->widget->visualizacaoMapa->listaDeCamadas->operator [](it);

        //inserir esta camada na lista que eh exposta ao usuario


        int cp = ui->camadaTableWidget->rowCount();
        ui->camadaTableWidget->insertRow(cp);



        //    inserindo o item ultimalinhax0
        QTableWidgetItem *itemNome =  new QTableWidgetItem(0);
        itemNome->setText(camadaASerInserida.getNome());
        itemNome->setBackgroundColor(camadaASerInserida.getCorCamada());
        ui->camadaTableWidget->setItem(cp,0,itemNome);


        //inserindo o item ultimalinhax1
        QTableWidgetItem *itemPeso =  new QTableWidgetItem(0);
        itemPeso->setText( QString::number(camadaASerInserida.getPeso(),'g',6));
        itemPeso->setBackgroundColor(camadaASerInserida.getCorCamada());

        ui->camadaTableWidget->setItem(cp,1,itemPeso);

        //inserindo o checkbox ultimalinhax1
        QTableWidgetItem *itemCheckBox =  new QTableWidgetItem(0);


        itemCheckBox->setFlags( itemCheckBox->flags()| Qt::ItemIsUserCheckable);
        if(camadaASerInserida.estaVisivel)
            itemCheckBox->setCheckState(Qt::Checked);
        else
            itemCheckBox->setCheckState(Qt::Unchecked);

        ui->camadaTableWidget->setItem(cp,2,itemCheckBox);


    }

}


/*!
  \fn JanelaPrincipal::deletaListaComCamadas()
  \brief Function to clear the Camada mapping for the current MDE showing in Area de Visualizacao. Doesnt delete the Camada associated with the MDE

  */
//funcao para criar a lista de camadas para a visualizacao corrente na Area de Visualizacao. Geralmente utilizada quando se quer visualizar um
//reservatorio presente na lista de reservatorios (Area de projeto)
void JanelaPrincipal::deletaListaComCamadas(){


    int numLinhas = ui->camadaTableWidget->rowCount();
    for(int i=0; i<numLinhas;i++){

        //deletar o elemento no mapeamento exposto ao usuario
        //elimina-se o primeiro ate que a lista esteja vazia
        ui->camadaTableWidget->removeRow(0);
    }
}


/*!
  \fn JanelaPrincipal::on_actionFechar_mapa_triggered()
  \brief Slot for when option actionFechar is pressed. Used to close the current MDE in Area de Visualizacao
  */
void JanelaPrincipal::on_actionFechar_mapa_triggered()
{
    delete ui->widget->visualizacaoMapa;
    ui->widget->visualizacaoMapa = NULL;
    ui->widget->mapaEstaCarregado = false;

    //tem que deletar os elementos na map de camada exposta ao usuario

    deletaListaComCamadas();


    setaTelaPadrao();
    desAbilitandoBotoes();
    repaint();
    ui->widget->updateGL();

}


/*!
  \fn JanelaPrincipal::on_actionCores_triggered()
  \brief Slot for when option actionCores is pressed. Used to change the colors of the map in Area de Visualizacao
  */
//invoca tela de troca de cores
void JanelaPrincipal::on_actionCores_triggered()
{
    janelaOpcaoCor *opCor = new janelaOpcaoCor();

    bool botaoApertado = false;
    QStringList cores = opCor->getValores(botaoApertado);


    if(botaoApertado){
        if(cores.isEmpty())
            ui->widget->setCoresPadrao();
        else

            ui->widget->mudaCores(cores);
    }
    delete opCor;


}

/*!
  \fn JanelaPrincipal::on_deletaCamada_clicked()
  \brief Slot for when button deletaCamada is pressed. Used delete the selected Camada from the Camada`s mapping and current MDE Camada`s list
  */
void JanelaPrincipal::on_deletaCamada_clicked()
{

    //verificar o elemento selecionado e com a posicao do mouse inserir

    //se nenhuma linha foi inserida deve-se retornar
    if(ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),0) == 0)
        return;
    //pegar o nome
    QString nome = (ui->camadaTableWidget->item(ui->camadaTableWidget->currentRow(),0))->text();



    //deletar o elemento na lista de camadas
    int ind = ui->widget->visualizacaoMapa->getIndCamada(nome);
    ui->widget->visualizacaoMapa->listaDeCamadas->removeAt(ind);

    //deletar o elemento no mapeamento exposto ao usuario
    ui->camadaTableWidget->removeRow(ui->camadaTableWidget->currentRow());




    ui->camadaTableWidget->repaint();

    ui->widget->repaint();



}

/*!
  \fn JanelaPrincipal::on_botaoAlternaBC_clicked()
  \brief Slot for when button botaoAlternaBC is pressed. Used to change the user option: (C) for selecting points of Camada, (B) for selecting the position or trecho of the dam.
  */
void JanelaPrincipal::on_botaoAlternaBC_clicked()
{

    selecaoPontoBarragem = !selecaoPontoBarragem;



    if(selecaoPontoBarragem)
        ui->botaoAlternaBC->setText("B");

    else
        ui->botaoAlternaBC->setText("C");


}


/*!
  \fn JanelaPrincipal::actionFunc_Objetivo
  \brief Slot for when option actionFunc_Objetivo is pressed. Used to change the values of objective function used in the positioning algorithm.
  */
void JanelaPrincipal::on_actionFunc_Objetivo_triggered()
{

    janelaopcaofb *opfb = new janelaopcaofb();


    bool ok;
    QStringList listaDeParametros = opfb->getValores(ok);



    if(ok){//atualiza os valores da funcao objetivo


        if(listaDeParametros.isEmpty())//seta os valores padroes
            ui->widget->visualizacaoMapa->atualizaPesos(ui->widget->visualizacaoMapa->pesoAreaAlagadaPadrao,ui->widget->visualizacaoMapa->pesoABarragemPadrao,
                                                        ui->widget->visualizacaoMapa->pesoVolumePadrao,ui->widget->visualizacaoMapa->pesoEBarragemPadrao,
                                                        ui->widget->visualizacaoMapa->pesoHBarragemPadrao);

        else
            ui->widget->visualizacaoMapa->atualizaPesos(listaDeParametros.at(0).toInt(0,10),listaDeParametros.at(1).toInt(0,10),
                                                        listaDeParametros.at(2).toInt(0,10),listaDeParametros.at(3).toInt(0,10),
                                                        listaDeParametros.at(4).toInt(0,10));



    }else{


    }

}

void JanelaPrincipal::on_caixaApresentaFuncaoObjetivo_clicked()
{
    if(ui->caixaApresentaFuncaoObjetivo->isChecked()){
        char auxSaida[10];
        ui->widget->visualizacaoMapa->atualizaCamadasSomadas();
        int respFO = ui->widget->visualizacaoMapa->getFuncaoObjetivo();
        itoa(respFO,auxSaida,10);
        ui->campoSaidaFuncaoObjetivo->setText(auxSaida);


    }else{
        ui->campoSaidaFuncaoObjetivo->setText("");



    }
}

void JanelaPrincipal::on_radioButtonM_clicked()
{
    ui->campoEntradaEpislonAlgoritmo->setEnabled(false);
}
