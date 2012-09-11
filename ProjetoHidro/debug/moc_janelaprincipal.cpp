/****************************************************************************
** Meta object code from reading C++ file 'janelaprincipal.h'
**
** Created: Thu 16. Aug 23:01:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../janelaprincipal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'janelaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JanelaPrincipal[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x09,
      58,   49,   16,   16, 0x09,
      88,   16,   16,   16, 0x09,
     115,   16,   16,   16, 0x09,
     143,   16,   16,   16, 0x09,
     182,   16,   16,   16, 0x09,
     215,  213,   16,   16, 0x09,
     237,   16,   16,   16, 0x09,
     270,  267,   16,   16, 0x09,
     309,  267,   16,   16, 0x09,
     340,  336,   16,   16, 0x09,
     365,  213,   16,   16, 0x09,
     418,  408,  403,   16, 0x09,
     448,   16,   16,   16, 0x09,
     479,   16,   16,   16, 0x08,
     516,   16,   16,   16, 0x08,
     551,   16,   16,   16, 0x08,
     589,   16,   16,   16, 0x08,
     615,   16,   16,   16, 0x08,
     648,   16,   16,   16, 0x08,
     674,   16,   16,   16, 0x08,
     701,   16,   16,   16, 0x08,
     725,   16,   16,   16, 0x08,
     749,   16,   16,   16, 0x08,
     771,   16,   16,   16, 0x08,
     798,   16,   16,   16, 0x08,
     831,   16,   16,   16, 0x08,
     858,   16,   16,   16, 0x08,
     884,   16,   16,   16, 0x08,
     912,   16,   16,   16, 0x08,
     947,   16,   16,   16, 0x08,
     989,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JanelaPrincipal[] = {
    "JanelaPrincipal\0\0on_actionAbrir_mapa_triggered()\0"
    "position\0on_barraZoom_sliderMoved(int)\0"
    "on_botaoZoomMais_clicked()\0"
    "on_botaoZoomMenos_clicked()\0"
    "on_botaoAtualizarFluxoMinimo_clicked()\0"
    "trocaCoordenadas(QMouseEvent*)\0,\0"
    "defineCamada(int,int)\0"
    "defineInundacao(QMouseEvent*)\0ev\0"
    "adicionandoPontosACamada(QMouseEvent*)\0"
    "movendoMouse(QMouseEvent*)\0kev\0"
    "moveBarragem(QKeyEvent*)\0"
    "imprimeBarragem(VisualizacaoMapa,int)\0"
    "bool\0posx,posy\0eEntruncamentoDeRios(int,int)\0"
    "exporCamada(QTableWidgetItem*)\0"
    "on_botaoAdicionarInundacao_clicked()\0"
    "on_botaoExcluirInundacao_clicked()\0"
    "on_botaoVisualizarInundacao_clicked()\0"
    "on_insereCamada_clicked()\0"
    "on_selecaoPontosCamada_clicked()\0"
    "on_radioButtonV_clicked()\0"
    "on_radioButtonDP_clicked()\0"
    "on_pushButton_clicked()\0moveZoomHorizontal(int)\0"
    "moveZoomVertical(int)\0on_actionSobre_triggered()\0"
    "on_actionFechar_mapa_triggered()\0"
    "on_actionCores_triggered()\0"
    "on_deletaCamada_clicked()\0"
    "on_botaoAlternaBC_clicked()\0"
    "on_actionFunc_Objetivo_triggered()\0"
    "on_caixaApresentaFuncaoObjetivo_clicked()\0"
    "on_radioButtonM_clicked()\0"
};

const QMetaObject JanelaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_JanelaPrincipal,
      qt_meta_data_JanelaPrincipal, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JanelaPrincipal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JanelaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JanelaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JanelaPrincipal))
        return static_cast<void*>(const_cast< JanelaPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int JanelaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionAbrir_mapa_triggered(); break;
        case 1: on_barraZoom_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_botaoZoomMais_clicked(); break;
        case 3: on_botaoZoomMenos_clicked(); break;
        case 4: on_botaoAtualizarFluxoMinimo_clicked(); break;
        case 5: trocaCoordenadas((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: defineCamada((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: defineInundacao((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: adicionandoPontosACamada((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: movendoMouse((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: moveBarragem((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 11: imprimeBarragem((*reinterpret_cast< VisualizacaoMapa(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: { bool _r = eEntruncamentoDeRios((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: exporCamada((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 14: on_botaoAdicionarInundacao_clicked(); break;
        case 15: on_botaoExcluirInundacao_clicked(); break;
        case 16: on_botaoVisualizarInundacao_clicked(); break;
        case 17: on_insereCamada_clicked(); break;
        case 18: on_selecaoPontosCamada_clicked(); break;
        case 19: on_radioButtonV_clicked(); break;
        case 20: on_radioButtonDP_clicked(); break;
        case 21: on_pushButton_clicked(); break;
        case 22: moveZoomHorizontal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: moveZoomVertical((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: on_actionSobre_triggered(); break;
        case 25: on_actionFechar_mapa_triggered(); break;
        case 26: on_actionCores_triggered(); break;
        case 27: on_deletaCamada_clicked(); break;
        case 28: on_botaoAlternaBC_clicked(); break;
        case 29: on_actionFunc_Objetivo_triggered(); break;
        case 30: on_caixaApresentaFuncaoObjetivo_clicked(); break;
        case 31: on_radioButtonM_clicked(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
