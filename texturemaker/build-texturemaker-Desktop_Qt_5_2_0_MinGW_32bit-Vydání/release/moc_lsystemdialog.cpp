/****************************************************************************
** Meta object code from reading C++ file 'lsystemdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../texturemaker/lsystemdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lsystemdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LSystemDialog_t {
    QByteArrayData data[6];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LSystemDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LSystemDialog_t qt_meta_stringdata_LSystemDialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 17),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 17),
QT_MOC_LITERAL(4, 51, 21),
QT_MOC_LITERAL(5, 73, 15)
    },
    "LSystemDialog\0on_browse_clicked\0\0"
    "on_reload_clicked\0on_buttonBox_accepted\0"
    "on_save_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LSystemDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    0,   35,    2, 0x08,
       4,    0,   36,    2, 0x08,
       5,    0,   37,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LSystemDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LSystemDialog *_t = static_cast<LSystemDialog *>(_o);
        switch (_id) {
        case 0: _t->on_browse_clicked(); break;
        case 1: _t->on_reload_clicked(); break;
        case 2: _t->on_buttonBox_accepted(); break;
        case 3: _t->on_save_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LSystemDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_LSystemDialog.data,
      qt_meta_data_LSystemDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *LSystemDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LSystemDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LSystemDialog.stringdata))
        return static_cast<void*>(const_cast< LSystemDialog*>(this));
    return CustomBlockDialog::qt_metacast(_clname);
}

int LSystemDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomBlockDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
