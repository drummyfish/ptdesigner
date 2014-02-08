/****************************************************************************
** Meta object code from reading C++ file 'lsystemdialog.h'
**
** Created: Sat Feb 8 15:29:07 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../texturemaker/lsystemdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lsystemdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LSystemDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      35,   14,   14,   14, 0x08,
      55,   14,   14,   14, 0x08,
      79,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LSystemDialog[] = {
    "LSystemDialog\0\0on_browse_clicked()\0"
    "on_reload_clicked()\0on_buttonBox_accepted()\0"
    "on_save_clicked()\0"
};

void LSystemDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData LSystemDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LSystemDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_LSystemDialog,
      qt_meta_data_LSystemDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LSystemDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LSystemDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LSystemDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LSystemDialog))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
