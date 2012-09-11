/********************************************************************************
** Form generated from reading UI file 'janelaprincipal.ui'
**
** Created: Thu 16. Aug 23:00:50 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "painelvisualizacaoopengl.h"

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QAction *actionAbrir_mapa;
    QAction *actionExportar_mapa;
    QAction *actionSair;
    QAction *actionSalvar;
    QAction *actionSobre;
    QAction *actionFechar_mapa;
    QAction *actionCores;
    QAction *actionFunc_Objetivo;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListView *listView;
    QPushButton *botaoAdicionarInundacao;
    QPushButton *botaoExcluirInundacao;
    QPushButton *botaoVisualizarInundacao;
    QWidget *tab_2;
    QPushButton *botaoAlternaBC;
    QTableWidget *camadaTableWidget;
    QPushButton *insereCamada;
    QPushButton *deletaCamada;
    QPushButton *selecaoPontosCamada;
    QGroupBox *groupBox_2;
    QLineEdit *campoEntradaCapacidadeDesejada;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *campoEntradaLargMaxBarragem;
    QPushButton *botaoAtualizarFluxoMinimo;
    QLabel *label_2;
    QLineEdit *campoEntradaFluxoMinimo;
    QGroupBox *groupBox_3;
    QRadioButton *radioButtonV;
    QRadioButton *radioButtonDP;
    QLineEdit *campoEntradaValorAlgoritmo;
    QLabel *label_7;
    QLineEdit *campoEntradaEpislonAlgoritmo;
    QLabel *label_10;
    QRadioButton *radioButtonM;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    PainelVisualizacaoOpenGL *widget;
    QSlider *barraZoom;
    QPushButton *botaoZoomMais;
    QPushButton *botaoZoomMenos;
    QFormLayout *formLayout_2;
    QGroupBox *groupBox_5;
    QLineEdit *campoSaidaCoordenadasBaseY;
    QLineEdit *campoSaidaCoordenadasBaseX;
    QLineEdit *campoSaidaCoordenadasY;
    QLineEdit *campoSaidaCoordenadasX;
    QLabel *label_19;
    QLabel *label_18;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QCheckBox *caixaPreSalvo;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_17;
    QLineEdit *campoSaidaFluxoMinimo;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_14;
    QLineEdit *campoSaidaNomeArquivo;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_15;
    QLineEdit *campoSaidaCaminhoArquivo;
    QCheckBox *checkBoxVisualiza2D;
    QCheckBox *checkBoxVisualiza3D;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLineEdit *campoSaidaAlturaBarragem;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_11;
    QLineEdit *campoSaidaAreaBarragem;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLineEdit *campoSaidaExtensaoBarragem;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLineEdit *campoSaidaCapacidadeTotal;
    QWidget *layoutWidget8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLineEdit *campoSaidaAreaLaminaDaAgua;
    QGroupBox *groupBox_9;
    QLineEdit *campoSaidaFuncaoObjetivo;
    QCheckBox *caixaApresentaFuncaoObjetivo;
    QMenuBar *menuBar;
    QMenu *menuTeste;
    QMenu *menuAjuda;
    QMenu *menuEdita;
    QMenu *menuOp_es;

    void setupUi(QMainWindow *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName(QString::fromUtf8("JanelaPrincipal"));
        JanelaPrincipal->resize(1027, 624);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JanelaPrincipal->sizePolicy().hasHeightForWidth());
        JanelaPrincipal->setSizePolicy(sizePolicy);
        JanelaPrincipal->setMinimumSize(QSize(1027, 624));
        JanelaPrincipal->setMaximumSize(QSize(1027, 624));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../imagens/logo3.png"), QSize(), QIcon::Normal, QIcon::Off);
        JanelaPrincipal->setWindowIcon(icon);
        JanelaPrincipal->setIconSize(QSize(160, 120));
        actionAbrir_mapa = new QAction(JanelaPrincipal);
        actionAbrir_mapa->setObjectName(QString::fromUtf8("actionAbrir_mapa"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../imagens/iconeAbrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir_mapa->setIcon(icon1);
        actionAbrir_mapa->setShortcutContext(Qt::ApplicationShortcut);
        actionExportar_mapa = new QAction(JanelaPrincipal);
        actionExportar_mapa->setObjectName(QString::fromUtf8("actionExportar_mapa"));
        actionExportar_mapa->setEnabled(false);
        actionExportar_mapa->setMenuRole(QAction::ApplicationSpecificRole);
        actionSair = new QAction(JanelaPrincipal);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionSalvar = new QAction(JanelaPrincipal);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionSalvar->setEnabled(false);
        actionSobre = new QAction(JanelaPrincipal);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        actionFechar_mapa = new QAction(JanelaPrincipal);
        actionFechar_mapa->setObjectName(QString::fromUtf8("actionFechar_mapa"));
        actionFechar_mapa->setEnabled(false);
        actionCores = new QAction(JanelaPrincipal);
        actionCores->setObjectName(QString::fromUtf8("actionCores"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../imagens/iconePincel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCores->setIcon(icon2);
        actionFunc_Objetivo = new QAction(JanelaPrincipal);
        actionFunc_Objetivo->setObjectName(QString::fromUtf8("actionFunc_Objetivo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../imagens/iconeEngrenagem.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFunc_Objetivo->setIcon(icon3);
        centralWidget = new QWidget(JanelaPrincipal);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(161, 320));
        groupBox->setMaximumSize(QSize(161, 320));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(2, 7, 160, 300));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(160, 300));
        tabWidget->setMaximumSize(QSize(160, 300));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(true);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        tab->setMinimumSize(QSize(160, 300));
        tab->setMaximumSize(QSize(160, 300));
        listView = new QListView(tab);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(3, 4, 128, 265));
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);
        listView->setMinimumSize(QSize(128, 265));
        listView->setMaximumSize(QSize(128, 265));
        listView->setFrameShape(QFrame::WinPanel);
        listView->setLineWidth(3);
        listView->setTabKeyNavigation(true);
        listView->setIconSize(QSize(4, 1));
        listView->setFlow(QListView::TopToBottom);
        listView->setLayoutMode(QListView::Batched);
        listView->setViewMode(QListView::ListMode);
        listView->setModelColumn(0);
        botaoAdicionarInundacao = new QPushButton(tab);
        botaoAdicionarInundacao->setObjectName(QString::fromUtf8("botaoAdicionarInundacao"));
        botaoAdicionarInundacao->setEnabled(false);
        botaoAdicionarInundacao->setGeometry(QRect(2, 272, 45, 23));
        sizePolicy.setHeightForWidth(botaoAdicionarInundacao->sizePolicy().hasHeightForWidth());
        botaoAdicionarInundacao->setSizePolicy(sizePolicy);
        botaoAdicionarInundacao->setMinimumSize(QSize(45, 23));
        botaoAdicionarInundacao->setMaximumSize(QSize(45, 23));
        botaoExcluirInundacao = new QPushButton(tab);
        botaoExcluirInundacao->setObjectName(QString::fromUtf8("botaoExcluirInundacao"));
        botaoExcluirInundacao->setEnabled(false);
        botaoExcluirInundacao->setGeometry(QRect(47, 272, 45, 23));
        botaoExcluirInundacao->setMinimumSize(QSize(45, 23));
        botaoExcluirInundacao->setMaximumSize(QSize(45, 23));
        botaoVisualizarInundacao = new QPushButton(tab);
        botaoVisualizarInundacao->setObjectName(QString::fromUtf8("botaoVisualizarInundacao"));
        botaoVisualizarInundacao->setEnabled(false);
        botaoVisualizarInundacao->setGeometry(QRect(92, 272, 41, 23));
        sizePolicy.setHeightForWidth(botaoVisualizarInundacao->sizePolicy().hasHeightForWidth());
        botaoVisualizarInundacao->setSizePolicy(sizePolicy);
        botaoVisualizarInundacao->setMinimumSize(QSize(41, 23));
        botaoVisualizarInundacao->setMaximumSize(QSize(41, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(true);
        botaoAlternaBC = new QPushButton(tab_2);
        botaoAlternaBC->setObjectName(QString::fromUtf8("botaoAlternaBC"));
        botaoAlternaBC->setEnabled(false);
        botaoAlternaBC->setGeometry(QRect(90, 272, 38, 23));
        sizePolicy.setHeightForWidth(botaoAlternaBC->sizePolicy().hasHeightForWidth());
        botaoAlternaBC->setSizePolicy(sizePolicy);
        botaoAlternaBC->setMinimumSize(QSize(38, 23));
        botaoAlternaBC->setMaximumSize(QSize(38, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("ESRI Oil, Gas, & Water"));
        botaoAlternaBC->setFont(font);
        botaoAlternaBC->setAcceptDrops(false);
        botaoAlternaBC->setAutoFillBackground(false);
        botaoAlternaBC->setStyleSheet(QString::fromUtf8(""));
        botaoAlternaBC->setIconSize(QSize(19, 19));
        botaoAlternaBC->setCheckable(false);
        botaoAlternaBC->setAutoExclusive(false);
        botaoAlternaBC->setAutoDefault(false);
        botaoAlternaBC->setDefault(false);
        botaoAlternaBC->setFlat(false);
        camadaTableWidget = new QTableWidget(tab_2);
        if (camadaTableWidget->columnCount() < 3)
            camadaTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        camadaTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        camadaTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        camadaTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        camadaTableWidget->setObjectName(QString::fromUtf8("camadaTableWidget"));
        camadaTableWidget->setEnabled(true);
        camadaTableWidget->setGeometry(QRect(3, 4, 128, 265));
        sizePolicy.setHeightForWidth(camadaTableWidget->sizePolicy().hasHeightForWidth());
        camadaTableWidget->setSizePolicy(sizePolicy);
        camadaTableWidget->setMinimumSize(QSize(128, 265));
        camadaTableWidget->setMaximumSize(QSize(128, 265));
        camadaTableWidget->setFocusPolicy(Qt::ClickFocus);
        camadaTableWidget->setFrameShape(QFrame::WinPanel);
        camadaTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        camadaTableWidget->setAutoScroll(false);
        camadaTableWidget->setAutoScrollMargin(1);
        camadaTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        camadaTableWidget->setTabKeyNavigation(true);
        camadaTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        camadaTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        camadaTableWidget->setShowGrid(false);
        camadaTableWidget->setGridStyle(Qt::DotLine);
        camadaTableWidget->setRowCount(0);
        camadaTableWidget->setColumnCount(3);
        camadaTableWidget->horizontalHeader()->setDefaultSectionSize(49);
        camadaTableWidget->horizontalHeader()->setMinimumSectionSize(49);
        camadaTableWidget->verticalHeader()->setVisible(false);
        camadaTableWidget->verticalHeader()->setDefaultSectionSize(43);
        camadaTableWidget->verticalHeader()->setMinimumSectionSize(2);
        insereCamada = new QPushButton(tab_2);
        insereCamada->setObjectName(QString::fromUtf8("insereCamada"));
        insereCamada->setEnabled(false);
        insereCamada->setGeometry(QRect(2, 272, 25, 23));
        sizePolicy.setHeightForWidth(insereCamada->sizePolicy().hasHeightForWidth());
        insereCamada->setSizePolicy(sizePolicy);
        insereCamada->setMinimumSize(QSize(25, 23));
        insereCamada->setMaximumSize(QSize(25, 23));
        deletaCamada = new QPushButton(tab_2);
        deletaCamada->setObjectName(QString::fromUtf8("deletaCamada"));
        deletaCamada->setEnabled(false);
        deletaCamada->setGeometry(QRect(27, 272, 25, 23));
        sizePolicy.setHeightForWidth(deletaCamada->sizePolicy().hasHeightForWidth());
        deletaCamada->setSizePolicy(sizePolicy);
        deletaCamada->setMinimumSize(QSize(25, 23));
        deletaCamada->setMaximumSize(QSize(25, 23));
        selecaoPontosCamada = new QPushButton(tab_2);
        selecaoPontosCamada->setObjectName(QString::fromUtf8("selecaoPontosCamada"));
        selecaoPontosCamada->setEnabled(false);
        selecaoPontosCamada->setGeometry(QRect(52, 272, 38, 23));
        sizePolicy.setHeightForWidth(selecaoPontosCamada->sizePolicy().hasHeightForWidth());
        selecaoPontosCamada->setSizePolicy(sizePolicy);
        selecaoPontosCamada->setMinimumSize(QSize(38, 23));
        selecaoPontosCamada->setMaximumSize(QSize(38, 23));
        selecaoPontosCamada->setFont(font);
        selecaoPontosCamada->setAcceptDrops(false);
        selecaoPontosCamada->setAutoFillBackground(false);
        selecaoPontosCamada->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../imagens/selecaoMais.png"), QSize(), QIcon::Normal, QIcon::Off);
        selecaoPontosCamada->setIcon(icon4);
        selecaoPontosCamada->setIconSize(QSize(19, 19));
        selecaoPontosCamada->setCheckable(false);
        selecaoPontosCamada->setAutoExclusive(false);
        selecaoPontosCamada->setAutoDefault(false);
        selecaoPontosCamada->setDefault(false);
        selecaoPontosCamada->setFlat(false);
        tabWidget->addTab(tab_2, QString());

        formLayout->setWidget(0, QFormLayout::LabelRole, groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(true);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(161, 177));
        groupBox_2->setMaximumSize(QSize(161, 190));
        groupBox_2->setBaseSize(QSize(0, 0));
        campoEntradaCapacidadeDesejada = new QLineEdit(groupBox_2);
        campoEntradaCapacidadeDesejada->setObjectName(QString::fromUtf8("campoEntradaCapacidadeDesejada"));
        campoEntradaCapacidadeDesejada->setGeometry(QRect(10, 40, 140, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 151, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);
        label_3->setGeometry(QRect(10, 70, 147, 16));
        campoEntradaLargMaxBarragem = new QLineEdit(groupBox_2);
        campoEntradaLargMaxBarragem->setObjectName(QString::fromUtf8("campoEntradaLargMaxBarragem"));
        campoEntradaLargMaxBarragem->setEnabled(false);
        campoEntradaLargMaxBarragem->setGeometry(QRect(10, 90, 140, 22));
        botaoAtualizarFluxoMinimo = new QPushButton(groupBox_2);
        botaoAtualizarFluxoMinimo->setObjectName(QString::fromUtf8("botaoAtualizarFluxoMinimo"));
        botaoAtualizarFluxoMinimo->setEnabled(false);
        botaoAtualizarFluxoMinimo->setGeometry(QRect(129, 140, 24, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Wingdings 3"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        botaoAtualizarFluxoMinimo->setFont(font1);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 76, 16));
        campoEntradaFluxoMinimo = new QLineEdit(groupBox_2);
        campoEntradaFluxoMinimo->setObjectName(QString::fromUtf8("campoEntradaFluxoMinimo"));
        campoEntradaFluxoMinimo->setGeometry(QRect(10, 140, 111, 22));

        formLayout->setWidget(1, QFormLayout::LabelRole, groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(60, 60));
        radioButtonV = new QRadioButton(groupBox_3);
        radioButtonV->setObjectName(QString::fromUtf8("radioButtonV"));
        radioButtonV->setGeometry(QRect(10, 12, 82, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        radioButtonV->setFont(font2);
        radioButtonDP = new QRadioButton(groupBox_3);
        radioButtonDP->setObjectName(QString::fromUtf8("radioButtonDP"));
        radioButtonDP->setGeometry(QRect(10, 42, 82, 17));
        campoEntradaValorAlgoritmo = new QLineEdit(groupBox_3);
        campoEntradaValorAlgoritmo->setObjectName(QString::fromUtf8("campoEntradaValorAlgoritmo"));
        campoEntradaValorAlgoritmo->setGeometry(QRect(118, 10, 41, 20));
        sizePolicy.setHeightForWidth(campoEntradaValorAlgoritmo->sizePolicy().hasHeightForWidth());
        campoEntradaValorAlgoritmo->setSizePolicy(sizePolicy);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 14, 46, 13));
        campoEntradaEpislonAlgoritmo = new QLineEdit(groupBox_3);
        campoEntradaEpislonAlgoritmo->setObjectName(QString::fromUtf8("campoEntradaEpislonAlgoritmo"));
        campoEntradaEpislonAlgoritmo->setGeometry(QRect(118, 35, 41, 20));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(98, 28, 51, 31));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../imagens/eLetra.png")));
        label_10->setScaledContents(false);
        radioButtonM = new QRadioButton(groupBox_3);
        radioButtonM->setObjectName(QString::fromUtf8("radioButtonM"));
        radioButtonM->setGeometry(QRect(10, 27, 82, 17));

        formLayout->setWidget(2, QFormLayout::SpanningRole, groupBox_3);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(579, 529));
        groupBox_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_7->setFlat(false);
        gridLayout_2 = new QGridLayout(groupBox_7);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(groupBox_7);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setBaseSize(QSize(700, 700));
        scrollArea->setMouseTracking(true);
        scrollArea->setMidLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        widget = new PainelVisualizacaoOpenGL();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 540, 527));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(540, 510));
        widget->setBaseSize(QSize(700, 700));
        widget->setCursor(QCursor(Qt::ArrowCursor));
        widget->setMouseTracking(true);
        barraZoom = new QSlider(widget);
        barraZoom->setObjectName(QString::fromUtf8("barraZoom"));
        barraZoom->setEnabled(false);
        barraZoom->setGeometry(QRect(11, 38, 10, 83));
        sizePolicy.setHeightForWidth(barraZoom->sizePolicy().hasHeightForWidth());
        barraZoom->setSizePolicy(sizePolicy);
        barraZoom->setAcceptDrops(true);
        barraZoom->setAutoFillBackground(false);
        barraZoom->setStyleSheet(QString::fromUtf8("gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.299435 rgba(0, 230, 0, 255), stop:0.429379 rgba(12, 245, 30, 255), stop:0.66 rgba(0, 200, 0, 255), stop:0.779661 rgba(0, 234, 0, 255), stop:1 rgba(0, 255, 0, 223));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.299435 rgba(0, 230, 0, 255), stop:0.429379 rgba(12, 245, 30, 255), stop:0.66 rgba(0, 200, 0, 255), stop:0.779661 rgba(0, 234, 0, 255), stop:1 rgba(0, 255, 0, 223));\n"
"border-color: rgb(170, 0, 0);\n"
"border-bottom-color: rgb(170, 0, 0);\n"
"border-left-color: rgb(170, 0, 0);\n"
"border-right-color: rgb(170, 0, 0);"));
        barraZoom->setMinimum(0);
        barraZoom->setMaximum(22);
        barraZoom->setOrientation(Qt::Vertical);
        barraZoom->setTickPosition(QSlider::NoTicks);
        barraZoom->setTickInterval(4);
        botaoZoomMais = new QPushButton(widget);
        botaoZoomMais->setObjectName(QString::fromUtf8("botaoZoomMais"));
        botaoZoomMais->setEnabled(false);
        botaoZoomMais->setGeometry(QRect(8, 24, 16, 14));
        sizePolicy.setHeightForWidth(botaoZoomMais->sizePolicy().hasHeightForWidth());
        botaoZoomMais->setSizePolicy(sizePolicy);
        botaoZoomMais->setStyleSheet(QString::fromUtf8(""));
        botaoZoomMais->setIconSize(QSize(13, 13));
        botaoZoomMais->setFlat(false);
        botaoZoomMenos = new QPushButton(widget);
        botaoZoomMenos->setObjectName(QString::fromUtf8("botaoZoomMenos"));
        botaoZoomMenos->setEnabled(false);
        botaoZoomMenos->setGeometry(QRect(8, 121, 16, 14));
        sizePolicy.setHeightForWidth(botaoZoomMenos->sizePolicy().hasHeightForWidth());
        botaoZoomMenos->setSizePolicy(sizePolicy);
        botaoZoomMenos->setIconSize(QSize(13, 13));
        botaoZoomMenos->setFlat(false);
        scrollArea->setWidget(widget);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_7, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setMinimumSize(QSize(241, 285));
        groupBox_5->setMaximumSize(QSize(241, 285));
        campoSaidaCoordenadasBaseY = new QLineEdit(groupBox_5);
        campoSaidaCoordenadasBaseY->setObjectName(QString::fromUtf8("campoSaidaCoordenadasBaseY"));
        campoSaidaCoordenadasBaseY->setEnabled(false);
        campoSaidaCoordenadasBaseY->setGeometry(QRect(120, 200, 81, 22));
        campoSaidaCoordenadasBaseX = new QLineEdit(groupBox_5);
        campoSaidaCoordenadasBaseX->setObjectName(QString::fromUtf8("campoSaidaCoordenadasBaseX"));
        campoSaidaCoordenadasBaseX->setEnabled(false);
        campoSaidaCoordenadasBaseX->setGeometry(QRect(10, 200, 81, 22));
        campoSaidaCoordenadasY = new QLineEdit(groupBox_5);
        campoSaidaCoordenadasY->setObjectName(QString::fromUtf8("campoSaidaCoordenadasY"));
        campoSaidaCoordenadasY->setEnabled(false);
        campoSaidaCoordenadasY->setGeometry(QRect(120, 250, 81, 22));
        campoSaidaCoordenadasX = new QLineEdit(groupBox_5);
        campoSaidaCoordenadasX->setObjectName(QString::fromUtf8("campoSaidaCoordenadasX"));
        campoSaidaCoordenadasX->setEnabled(false);
        campoSaidaCoordenadasX->setGeometry(QRect(10, 250, 81, 22));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 230, 83, 16));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 180, 211, 16));
        layoutWidget = new QWidget(groupBox_5);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 150, 141, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        caixaPreSalvo = new QCheckBox(layoutWidget);
        caixaPreSalvo->setObjectName(QString::fromUtf8("caixaPreSalvo"));
        caixaPreSalvo->setEnabled(false);
        caixaPreSalvo->setCheckable(false);
        caixaPreSalvo->setChecked(false);

        horizontalLayout->addWidget(caixaPreSalvo);

        layoutWidget1 = new QWidget(groupBox_5);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 120, 151, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_2->addWidget(label_17);

        campoSaidaFluxoMinimo = new QLineEdit(layoutWidget1);
        campoSaidaFluxoMinimo->setObjectName(QString::fromUtf8("campoSaidaFluxoMinimo"));
        campoSaidaFluxoMinimo->setEnabled(false);

        horizontalLayout_2->addWidget(campoSaidaFluxoMinimo);

        layoutWidget2 = new QWidget(groupBox_5);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 221, 41));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout->addWidget(label_14);

        campoSaidaNomeArquivo = new QLineEdit(layoutWidget2);
        campoSaidaNomeArquivo->setObjectName(QString::fromUtf8("campoSaidaNomeArquivo"));
        campoSaidaNomeArquivo->setEnabled(false);

        verticalLayout->addWidget(campoSaidaNomeArquivo);

        layoutWidget3 = new QWidget(groupBox_5);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 70, 221, 41));
        verticalLayout_6 = new QVBoxLayout(layoutWidget3);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_6->addWidget(label_15);

        campoSaidaCaminhoArquivo = new QLineEdit(layoutWidget3);
        campoSaidaCaminhoArquivo->setObjectName(QString::fromUtf8("campoSaidaCaminhoArquivo"));
        campoSaidaCaminhoArquivo->setEnabled(false);

        verticalLayout_6->addWidget(campoSaidaCaminhoArquivo);


        formLayout_2->setWidget(1, QFormLayout::LabelRole, groupBox_5);

        checkBoxVisualiza2D = new QCheckBox(centralWidget);
        checkBoxVisualiza2D->setObjectName(QString::fromUtf8("checkBoxVisualiza2D"));
        checkBoxVisualiza2D->setEnabled(false);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, checkBoxVisualiza2D);

        checkBoxVisualiza3D = new QCheckBox(centralWidget);
        checkBoxVisualiza3D->setObjectName(QString::fromUtf8("checkBoxVisualiza3D"));
        checkBoxVisualiza3D->setEnabled(false);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, checkBoxVisualiza3D);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMinimumSize(QSize(241, 240));
        groupBox_4->setMaximumSize(QSize(241, 240));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(9, 18, 225, 97));
        groupBox_6->setMinimumSize(QSize(225, 97));
        groupBox_6->setMaximumSize(QSize(225, 97));
        layoutWidget4 = new QWidget(groupBox_6);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(119, 16, 101, 35));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        campoSaidaAlturaBarragem = new QLineEdit(layoutWidget4);
        campoSaidaAlturaBarragem->setObjectName(QString::fromUtf8("campoSaidaAlturaBarragem"));
        campoSaidaAlturaBarragem->setEnabled(false);

        verticalLayout_4->addWidget(campoSaidaAlturaBarragem);

        layoutWidget5 = new QWidget(groupBox_6);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(8, 54, 101, 35));
        verticalLayout_7 = new QVBoxLayout(layoutWidget5);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_7->addWidget(label_11);

        campoSaidaAreaBarragem = new QLineEdit(layoutWidget5);
        campoSaidaAreaBarragem->setObjectName(QString::fromUtf8("campoSaidaAreaBarragem"));
        campoSaidaAreaBarragem->setEnabled(false);

        verticalLayout_7->addWidget(campoSaidaAreaBarragem);

        layoutWidget6 = new QWidget(groupBox_6);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(7, 16, 101, 35));
        verticalLayout_5 = new QVBoxLayout(layoutWidget6);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        campoSaidaExtensaoBarragem = new QLineEdit(layoutWidget6);
        campoSaidaExtensaoBarragem->setObjectName(QString::fromUtf8("campoSaidaExtensaoBarragem"));
        campoSaidaExtensaoBarragem->setEnabled(false);
        campoSaidaExtensaoBarragem->setAcceptDrops(true);

        verticalLayout_5->addWidget(campoSaidaExtensaoBarragem);

        groupBox_8 = new QGroupBox(groupBox_4);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(9, 120, 225, 61));
        layoutWidget7 = new QWidget(groupBox_8);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(8, 18, 101, 35));
        verticalLayout_3 = new QVBoxLayout(layoutWidget7);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        campoSaidaCapacidadeTotal = new QLineEdit(layoutWidget7);
        campoSaidaCapacidadeTotal->setObjectName(QString::fromUtf8("campoSaidaCapacidadeTotal"));
        campoSaidaCapacidadeTotal->setEnabled(false);

        verticalLayout_3->addWidget(campoSaidaCapacidadeTotal);

        layoutWidget8 = new QWidget(groupBox_8);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(120, 18, 101, 35));
        verticalLayout_2 = new QVBoxLayout(layoutWidget8);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget8);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        campoSaidaAreaLaminaDaAgua = new QLineEdit(layoutWidget8);
        campoSaidaAreaLaminaDaAgua->setObjectName(QString::fromUtf8("campoSaidaAreaLaminaDaAgua"));
        campoSaidaAreaLaminaDaAgua->setEnabled(false);

        verticalLayout_2->addWidget(campoSaidaAreaLaminaDaAgua);

        groupBox_9 = new QGroupBox(groupBox_4);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(9, 188, 225, 43));
        campoSaidaFuncaoObjetivo = new QLineEdit(groupBox_9);
        campoSaidaFuncaoObjetivo->setObjectName(QString::fromUtf8("campoSaidaFuncaoObjetivo"));
        campoSaidaFuncaoObjetivo->setEnabled(false);
        campoSaidaFuncaoObjetivo->setGeometry(QRect(8, 18, 99, 20));
        caixaApresentaFuncaoObjetivo = new QCheckBox(groupBox_9);
        caixaApresentaFuncaoObjetivo->setObjectName(QString::fromUtf8("caixaApresentaFuncaoObjetivo"));
        caixaApresentaFuncaoObjetivo->setEnabled(false);
        caixaApresentaFuncaoObjetivo->setGeometry(QRect(126, 20, 70, 17));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, groupBox_4);


        gridLayout->addLayout(formLayout_2, 0, 2, 1, 1);

        JanelaPrincipal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(JanelaPrincipal);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1027, 21));
        menuTeste = new QMenu(menuBar);
        menuTeste->setObjectName(QString::fromUtf8("menuTeste"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        menuEdita = new QMenu(menuBar);
        menuEdita->setObjectName(QString::fromUtf8("menuEdita"));
        menuEdita->setEnabled(true);
        menuOp_es = new QMenu(menuEdita);
        menuOp_es->setObjectName(QString::fromUtf8("menuOp_es"));
        JanelaPrincipal->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(campoEntradaCapacidadeDesejada);
        label_3->setBuddy(campoEntradaLargMaxBarragem);
        label_2->setBuddy(campoEntradaFluxoMinimo);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuTeste->menuAction());
        menuBar->addAction(menuEdita->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuTeste->addAction(actionAbrir_mapa);
        menuTeste->addAction(actionFechar_mapa);
        menuTeste->addAction(actionExportar_mapa);
        menuTeste->addAction(actionSalvar);
        menuTeste->addAction(actionSair);
        menuAjuda->addAction(actionSobre);
        menuEdita->addAction(menuOp_es->menuAction());
        menuOp_es->addAction(actionCores);
        menuOp_es->addAction(actionFunc_Objetivo);

        retranslateUi(JanelaPrincipal);
        QObject::connect(actionSair, SIGNAL(triggered()), JanelaPrincipal, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QApplication::translate("JanelaPrincipal", "Re-Build(Beta 1.0)", 0, QApplication::UnicodeUTF8));
        actionAbrir_mapa->setText(QApplication::translate("JanelaPrincipal", "Abrir mapa...", 0, QApplication::UnicodeUTF8));
        actionExportar_mapa->setText(QApplication::translate("JanelaPrincipal", "Exportar mapa...", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("JanelaPrincipal", "Sair", 0, QApplication::UnicodeUTF8));
        actionSalvar->setText(QApplication::translate("JanelaPrincipal", "Salvar", 0, QApplication::UnicodeUTF8));
        actionSobre->setText(QApplication::translate("JanelaPrincipal", "Sobre", 0, QApplication::UnicodeUTF8));
        actionFechar_mapa->setText(QApplication::translate("JanelaPrincipal", "Fechar mapa...", 0, QApplication::UnicodeUTF8));
        actionCores->setText(QApplication::translate("JanelaPrincipal", "Cores", 0, QApplication::UnicodeUTF8));
        actionFunc_Objetivo->setText(QApplication::translate("JanelaPrincipal", "Func.Objetivo", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\303\201rea de trabalho</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tab->setToolTip(QApplication::translate("JanelaPrincipal", "\303\201rea destinada a armazenar os distintos reservat\303\263rios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        botaoAdicionarInundacao->setToolTip(QApplication::translate("JanelaPrincipal", "Adiciona o reservat\303\263rio corrente a \n"
"\303\201rea de projeto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botaoAdicionarInundacao->setText(QApplication::translate("JanelaPrincipal", "+", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botaoExcluirInundacao->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Exclui o reservat\303\263rio selecionado</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">da \303\201rea de Projeto</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botaoExcluirInundacao->setText(QApplication::translate("JanelaPrincipal", "-", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botaoVisualizarInundacao->setToolTip(QApplication::translate("JanelaPrincipal", "Visualiza reservat\303\263rio selecionado\n"
"da \303\201rea de Projeto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botaoVisualizarInundacao->setText(QApplication::translate("JanelaPrincipal", "->", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("JanelaPrincipal", "\303\201rea de Projeto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_2->setToolTip(QApplication::translate("JanelaPrincipal", "\303\201rea destinada a armazenar camadas de pontos \n"
"cr\303\255ticos em um alagamento\n"
"", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        botaoAlternaBC->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'ESRI Oil, Gas, &amp; Water'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Adiciona/subtrair c\303\251lulas a camada corrente</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botaoAlternaBC->setText(QApplication::translate("JanelaPrincipal", "B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = camadaTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("JanelaPrincipal", "Nome", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = camadaTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("JanelaPrincipal", "Peso", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        camadaTableWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        insereCamada->setToolTip(QApplication::translate("JanelaPrincipal", "Adiciona uma camada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        insereCamada->setText(QApplication::translate("JanelaPrincipal", "+", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deletaCamada->setToolTip(QApplication::translate("JanelaPrincipal", "Exclui camada selecionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deletaCamada->setText(QApplication::translate("JanelaPrincipal", "-", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selecaoPontosCamada->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'ESRI Oil, Gas, &amp; Water'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Adiciona/subtrair c\303\251lulas a camada corrente</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        selecaoPontosCamada->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("JanelaPrincipal", "Camadas", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("JanelaPrincipal", "Par\303\242metros", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        campoEntradaCapacidadeDesejada->setToolTip(QApplication::translate("JanelaPrincipal", "Define a capacidade desejada para criar o reservat\303\263rio.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("JanelaPrincipal", "Capacidade desejada(m\302\263)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("JanelaPrincipal", "Larg. Max. Barragem(m\302\262)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        campoEntradaLargMaxBarragem->setToolTip(QApplication::translate("JanelaPrincipal", "Define o valor m\303\241ximo para a extens\303\243o da barragem.\n"
"N\303\243o presente nesta vers\303\243o.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        botaoAtualizarFluxoMinimo->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Wingdings 3'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">Atualiza fluxo m\303\255nimo</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        botaoAtualizarFluxoMinimo->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        botaoAtualizarFluxoMinimo->setText(QApplication::translate("JanelaPrincipal", "Q", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JanelaPrincipal", "Fluxo m\303\255nimo", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("JanelaPrincipal", "Orienta\303\247ao Barragem", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButtonV->setToolTip(QApplication::translate("JanelaPrincipal", "Orienta\303\247ao da barragem por soma dos vetores de vizinhos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        radioButtonV->setText(QApplication::translate("JanelaPrincipal", "DIRSV", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButtonDP->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Orienta\303\247\303\243o da barragem com uso do algoritmo de Douglas-Peucker</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        radioButtonDP->setText(QApplication::translate("JanelaPrincipal", "DIRDP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        campoEntradaValorAlgoritmo->setToolTip(QApplication::translate("JanelaPrincipal", "P\303\242ramentro do algoritmo\n"
"referente a quantidade de pontos\n"
"sequenciais da rede de drenagem", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("JanelaPrincipal", "N.Vizi.", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
#ifndef QT_NO_TOOLTIP
        radioButtonM->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Orienta\303\247\303\243o da barragem atrav\303\251s da dire\303\247\303\243o m\303\251dia dos vetores dos vizinhos</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        radioButtonM->setText(QApplication::translate("JanelaPrincipal", "DIRMV", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("JanelaPrincipal", "Visualiza\303\247\303\243o", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botaoZoomMais->setToolTip(QApplication::translate("JanelaPrincipal", "Zoom +", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botaoZoomMais->setText(QApplication::translate("JanelaPrincipal", "+", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botaoZoomMenos->setToolTip(QApplication::translate("JanelaPrincipal", "Zoom -", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botaoZoomMenos->setText(QApplication::translate("JanelaPrincipal", "-", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("JanelaPrincipal", "Infos do mapa corrente", 0, QApplication::UnicodeUTF8));
        campoSaidaCoordenadasBaseY->setText(QString());
        campoSaidaCoordenadasBaseX->setText(QString());
        campoSaidaCoordenadasY->setText(QString());
        campoSaidaCoordenadasX->setText(QString());
        label_19->setText(QApplication::translate("JanelaPrincipal", "Coordenadas ", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("JanelaPrincipal", "Coordenadas da base da barragem:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("JanelaPrincipal", "Pr\303\251-salvo:", 0, QApplication::UnicodeUTF8));
        caixaPreSalvo->setText(QString());
        label_17->setText(QApplication::translate("JanelaPrincipal", "Fluxo min.:", 0, QApplication::UnicodeUTF8));
        campoSaidaFluxoMinimo->setText(QApplication::translate("JanelaPrincipal", "-", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("JanelaPrincipal", "Arquivo:", 0, QApplication::UnicodeUTF8));
        campoSaidaNomeArquivo->setText(QString());
        label_15->setText(QApplication::translate("JanelaPrincipal", "Caminho:", 0, QApplication::UnicodeUTF8));
        campoSaidaCaminhoArquivo->setText(QString());
#ifndef QT_NO_TOOLTIP
        checkBoxVisualiza2D->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Vizualiza\303\247\303\243o da barragem 2D</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">N\303\243o dispon\303\255vel nesta vers\303\243o</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBoxVisualiza2D->setText(QApplication::translate("JanelaPrincipal", "Visualiza2D", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBoxVisualiza3D->setToolTip(QApplication::translate("JanelaPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Vizualiza\303\247\303\243o 3D da barragem</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">N\303\243o dispon\303\255vel nesta vers\303\243o</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBoxVisualiza3D->setText(QApplication::translate("JanelaPrincipal", "Visualiza3D", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("JanelaPrincipal", "Resultados dos par\303\242metros correntes", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("JanelaPrincipal", "Barragem", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("JanelaPrincipal", "Altura(m)", 0, QApplication::UnicodeUTF8));
        campoSaidaAlturaBarragem->setText(QString());
        label_11->setText(QApplication::translate("JanelaPrincipal", "\303\201rea(m\302\262)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("JanelaPrincipal", "Extens\303\243o(m)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        campoSaidaExtensaoBarragem->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        campoSaidaExtensaoBarragem->setText(QString());
        groupBox_8->setTitle(QApplication::translate("JanelaPrincipal", "Reservat\303\263rio", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("JanelaPrincipal", "Capacidade(m\302\263)", 0, QApplication::UnicodeUTF8));
        campoSaidaCapacidadeTotal->setText(QString());
        label_8->setText(QApplication::translate("JanelaPrincipal", "\303\201rea(m\302\262)", 0, QApplication::UnicodeUTF8));
        campoSaidaAreaLaminaDaAgua->setText(QString());
        groupBox_9->setTitle(QApplication::translate("JanelaPrincipal", "Fun\303\247\303\243o Objetivo", 0, QApplication::UnicodeUTF8));
        caixaApresentaFuncaoObjetivo->setText(QApplication::translate("JanelaPrincipal", "Apresenta", 0, QApplication::UnicodeUTF8));
        menuTeste->setTitle(QApplication::translate("JanelaPrincipal", "Arquivo", 0, QApplication::UnicodeUTF8));
        menuAjuda->setTitle(QApplication::translate("JanelaPrincipal", "Ajuda", 0, QApplication::UnicodeUTF8));
        menuEdita->setTitle(QApplication::translate("JanelaPrincipal", "Edita", 0, QApplication::UnicodeUTF8));
        menuOp_es->setTitle(QApplication::translate("JanelaPrincipal", "Op\303\247\303\265es", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
