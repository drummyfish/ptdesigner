/****************************************************************************
** Meta object code from reading C++ file 'mosaicdialog.h'
**
** Created: Mon Feb 24 13:34:30 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../texturemaker/mosaicdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mosaicdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MosaicDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,
      56,   13,   13,   13, 0x08,
      77,   13,   13,   13, 0x08,
      98,   13,   13,   13, 0x08,
     128,  122,   13,   13, 0x08,
     164,  122,   13,   13, 0x08,
     200,  122,   13,   13, 0x08,
     236,  122,   13,   13, 0x08,
     277,  272,   13,   13, 0x08,
     307,  272,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MosaicDialog[] = {
    "MosaicDialog\0\0on_clear_1_clicked()\0"
    "on_clear_2_clicked()\0on_clear_3_clicked()\0"
    "on_clear_4_clicked()\0on_buttonBox_accepted()\0"
    "index\0on_combo_1_currentIndexChanged(int)\0"
    "on_combo_2_currentIndexChanged(int)\0"
    "on_combo_3_currentIndexChanged(int)\0"
    "on_combo_4_currentIndexChanged(int)\0"
    "arg1\0on_repeat_x_valueChanged(int)\0"
    "on_repeat_y_valueChanged(int)\0"
};

void MosaicDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData MosaicDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MosaicDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_MosaicDialog,
      qt_meta_data_MosaicDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MosaicDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MosaicDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MosaicDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MosaicDialog))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
