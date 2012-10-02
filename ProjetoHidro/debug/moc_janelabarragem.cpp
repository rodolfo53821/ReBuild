/****************************************************************************
** Meta object code from reading C++ file 'janelabarragem.h'
**
** Created: Mon 1. Oct 21:26:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../janelabarragem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'janelabarragem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_janelabarragem[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      40,   15,   15,   15, 0x08,
      71,   66,   15,   15, 0x08,
     105,   66,   15,   15, 0x08,
     142,   66,   15,   15, 0x08,
     179,   66,   15,   15, 0x08,
     216,   66,   15,   15, 0x08,
     253,   66,   15,   15, 0x08,
     290,   66,   15,   15, 0x08,
     327,   66,   15,   15, 0x08,
     363,   66,   15,   15, 0x08,
     399,   66,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_janelabarragem[] = {
    "janelabarragem\0\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0arg1\0"
    "on_novoDireCamX_valueChanged(int)\0"
    "on_spinBoxPosicaoX_valueChanged(int)\0"
    "on_spinBoxPosicaoZ_valueChanged(int)\0"
    "on_spinBoxPosicaoY_valueChanged(int)\0"
    "on_spinBoxDirecaoX_valueChanged(int)\0"
    "on_spinBoxDirecaoY_valueChanged(int)\0"
    "on_spinBoxDirecaoZ_valueChanged(int)\0"
    "on_spinBoxNormalY_valueChanged(int)\0"
    "on_spinBoxNormalX_valueChanged(int)\0"
    "on_spinBoxNormalZ_valueChanged(int)\0"
};

const QMetaObject janelabarragem::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_janelabarragem,
      qt_meta_data_janelabarragem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &janelabarragem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *janelabarragem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *janelabarragem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_janelabarragem))
        return static_cast<void*>(const_cast< janelabarragem*>(this));
    return QDialog::qt_metacast(_clname);
}

int janelabarragem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: on_pushButton_2_clicked(); break;
        case 2: on_novoDireCamX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_spinBoxPosicaoX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_spinBoxPosicaoZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_spinBoxPosicaoY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_spinBoxDirecaoX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_spinBoxDirecaoY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_spinBoxDirecaoZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_spinBoxNormalY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_spinBoxNormalX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_spinBoxNormalZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
