/****************************************************************************
** Meta object code from reading C++ file 'painelvisualizacaoopengl.h'
**
** Created: Thu 16. Aug 23:01:55 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../painelvisualizacaoopengl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'painelvisualizacaoopengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PainelVisualizacaoOpenGL[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x05,
      61,   55,   25,   25, 0x05,
      91,   25,   25,   25, 0x05,
     117,   25,   25,   25, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PainelVisualizacaoOpenGL[] = {
    "PainelVisualizacaoOpenGL\0\0"
    "mouseMoveEvent(QMouseEvent*)\0event\0"
    "mousePressEvent(QMouseEvent*)\0"
    "keyPressEvent(QKeyEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
};

const QMetaObject PainelVisualizacaoOpenGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_PainelVisualizacaoOpenGL,
      qt_meta_data_PainelVisualizacaoOpenGL, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PainelVisualizacaoOpenGL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PainelVisualizacaoOpenGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PainelVisualizacaoOpenGL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PainelVisualizacaoOpenGL))
        return static_cast<void*>(const_cast< PainelVisualizacaoOpenGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int PainelVisualizacaoOpenGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PainelVisualizacaoOpenGL::mouseMoveEvent(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PainelVisualizacaoOpenGL::mousePressEvent(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PainelVisualizacaoOpenGL::keyPressEvent(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PainelVisualizacaoOpenGL::mouseReleaseEvent(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
