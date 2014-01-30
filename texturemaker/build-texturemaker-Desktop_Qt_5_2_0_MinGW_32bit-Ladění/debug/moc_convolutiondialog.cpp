/****************************************************************************
** Meta object code from reading C++ file 'convolutiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../texturemaker/convolutiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convolutiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConvolutionDialog_t {
    QByteArrayData data[6];
    char stringdata[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConvolutionDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConvolutionDialog_t qt_meta_stringdata_ConvolutionDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 28),
QT_MOC_LITERAL(2, 47, 0),
QT_MOC_LITERAL(3, 48, 4),
QT_MOC_LITERAL(4, 53, 29),
QT_MOC_LITERAL(5, 83, 21)
    },
    "ConvolutionDialog\0on_matrix_width_valueChanged\0"
    "\0arg1\0on_matrix_height_valueChanged\0"
    "on_buttonBox_accepted\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConvolutionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08,
       4,    1,   32,    2, 0x08,
       5,    0,   35,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ConvolutionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConvolutionDialog *_t = static_cast<ConvolutionDialog *>(_o);
        switch (_id) {
        case 0: _t->on_matrix_width_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_matrix_height_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObject ConvolutionDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_ConvolutionDialog.data,
      qt_meta_data_ConvolutionDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConvolutionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConvolutionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConvolutionDialog.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
