/****************************************************************************
** Meta object code from reading C++ file 'lightdialog.h'
**
** Created: Sat Feb 8 15:29:01 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../texturemaker/lightdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LightDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,
      65,   12,   12,   12, 0x08,
      98,   92,   12,   12, 0x08,
     142,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LightDialog[] = {
    "LightDialog\0\0on_pick_ambient_clicked()\0"
    "on_pick_diffuse_clicked()\0"
    "on_pick_specular_clicked()\0index\0"
    "on_curve_selection_currentIndexChanged(int)\0"
    "on_buttonBox_accepted()\0"
};

void LightDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LightDialog *_t = static_cast<LightDialog *>(_o);
        switch (_id) {
        case 0: _t->on_pick_ambient_clicked(); break;
        case 1: _t->on_pick_diffuse_clicked(); break;
        case 2: _t->on_pick_specular_clicked(); break;
        case 3: _t->on_curve_selection_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LightDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LightDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_LightDialog,
      qt_meta_data_LightDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LightDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LightDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LightDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LightDialog))
        return static_cast<void*>(const_cast< LightDialog*>(this));
    return CustomBlockDialog::qt_metacast(_clname);
}

int LightDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomBlockDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
