/****************************************************************************
** Meta object code from reading C++ file 'mosaicdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../texturemaker/mosaicdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mosaicdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MosaicDialog_t {
    QByteArrayData data[15];
    char stringdata[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MosaicDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MosaicDialog_t qt_meta_stringdata_MosaicDialog = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 18),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 18),
QT_MOC_LITERAL(4, 52, 18),
QT_MOC_LITERAL(5, 71, 18),
QT_MOC_LITERAL(6, 90, 21),
QT_MOC_LITERAL(7, 112, 30),
QT_MOC_LITERAL(8, 143, 5),
QT_MOC_LITERAL(9, 149, 30),
QT_MOC_LITERAL(10, 180, 30),
QT_MOC_LITERAL(11, 211, 30),
QT_MOC_LITERAL(12, 242, 24),
QT_MOC_LITERAL(13, 267, 4),
QT_MOC_LITERAL(14, 272, 24)
    },
    "MosaicDialog\0on_clear_1_clicked\0\0"
    "on_clear_2_clicked\0on_clear_3_clicked\0"
    "on_clear_4_clicked\0on_buttonBox_accepted\0"
    "on_combo_1_currentIndexChanged\0index\0"
    "on_combo_2_currentIndexChanged\0"
    "on_combo_3_currentIndexChanged\0"
    "on_combo_4_currentIndexChanged\0"
    "on_repeat_x_valueChanged\0arg1\0"
    "on_repeat_y_valueChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MosaicDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08,
       3,    0,   70,    2, 0x08,
       4,    0,   71,    2, 0x08,
       5,    0,   72,    2, 0x08,
       6,    0,   73,    2, 0x08,
       7,    1,   74,    2, 0x08,
       9,    1,   77,    2, 0x08,
      10,    1,   80,    2, 0x08,
      11,    1,   83,    2, 0x08,
      12,    1,   86,    2, 0x08,
      14,    1,   89,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void MosaicDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MosaicDialog *_t = static_cast<MosaicDialog *>(_o);
        switch (_id) {
        case 0: _t->on_clear_1_clicked(); break;
        case 1: _t->on_clear_2_clicked(); break;
        case 2: _t->on_clear_3_clicked(); break;
        case 3: _t->on_clear_4_clicked(); break;
        case 4: _t->on_buttonBox_accepted(); break;
        case 5: _t->on_combo_1_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_combo_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_combo_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_combo_4_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_repeat_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_repeat_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MosaicDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_MosaicDialog.data,
      qt_meta_data_MosaicDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *MosaicDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MosaicDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MosaicDialog.stringdata))
        return static_cast<void*>(const_cast< MosaicDialog*>(this));
    return CustomBlockDialog::qt_metacast(_clname);
}

int MosaicDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomBlockDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
