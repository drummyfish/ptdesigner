/****************************************************************************
** Meta object code from reading C++ file 'convolutiondialog.h'
**
** Created: Mon Feb 24 13:34:24 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../texturemaker/convolutiondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convolutiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConvolutionDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x08,
      58,   19,   18,   18, 0x08,
      93,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConvolutionDialog[] = {
    "ConvolutionDialog\0\0arg1\0"
    "on_matrix_width_valueChanged(int)\0"
    "on_matrix_height_valueChanged(int)\0"
    "on_buttonBox_accepted()\0"
};

void ConvolutionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConvolutionDialog *_t = static_cast<ConvolutionDialog *>(_o);
        switch (_id) {
        case 0: _t->on_matrix_width_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_matrix_height_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConvolutionDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConvolutionDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_ConvolutionDialog,
      qt_meta_data_ConvolutionDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConvolutionDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConvolutionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConvolutionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConvolutionDialog))
        return static_cast<void*>(const_cast< ConvolutionDialog*>(this));
    return CustomBlockDialog::qt_metacast(_clname);
}

int ConvolutionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomBlockDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
