/****************************************************************************
** Meta object code from reading C++ file 'lightdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../texturemaker/lightdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LightDialog_t {
    QByteArrayData data[9];
    char stringdata[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LightDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LightDialog_t qt_meta_stringdata_LightDialog = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 23),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 23),
QT_MOC_LITERAL(4, 61, 24),
QT_MOC_LITERAL(5, 86, 38),
QT_MOC_LITERAL(6, 125, 5),
QT_MOC_LITERAL(7, 131, 21),
QT_MOC_LITERAL(8, 153, 21)
    },
    "LightDialog\0on_pick_ambient_clicked\0"
    "\0on_pick_diffuse_clicked\0"
    "on_pick_specular_clicked\0"
    "on_curve_selection_currentIndexChanged\0"
    "index\0on_buttonBox_accepted\0"
    "on_set_preset_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LightDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    0,   46,    2, 0x08,
       5,    1,   47,    2, 0x08,
       7,    0,   50,    2, 0x08,
       8,    0,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LightDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LightDialog *_t = static_cast<LightDialog *>(_o);
        switch (_id) {
        case 0: _t->on_pick_ambient_clicked(); break;
        case 1: _t->on_pick_diffuse_clicked(); break;
        case 2: _t->on_pick_specular_clicked(); break;
        case 3: _t->on_curve_selection_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_buttonBox_accepted(); break;
        case 5: _t->on_set_preset_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject LightDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_LightDialog.data,
      qt_meta_data_LightDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *LightDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LightDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LightDialog.stringdata))
        return static_cast<void*>(const_cast< LightDialog*>(this));
    return CustomBlockDialog::qt_metacast(_clname);
}

int LightDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomBlockDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
