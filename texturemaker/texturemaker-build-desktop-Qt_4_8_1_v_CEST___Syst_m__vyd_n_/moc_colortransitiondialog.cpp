/****************************************************************************
** Meta object code from reading C++ file 'colortransitiondialog.h'
**
** Created: Sat Feb 8 15:29:07 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../texturemaker/colortransitiondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colortransitiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ColorTransitionDialog[] = {

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
      23,   22,   22,   22, 0x08,
      50,   22,   22,   22, 0x08,
      74,   22,   22,   22, 0x08,
      99,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ColorTransitionDialog[] = {
    "ColorTransitionDialog\0\0"
    "on_delete_button_clicked()\0"
    "on_add_button_clicked()\0"
    "on_edit_button_clicked()\0"
    "on_buttonBox_accepted()\0"
};

void ColorTransitionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorTransitionDialog *_t = static_cast<ColorTransitionDialog *>(_o);
        switch (_id) {
        case 0: _t->on_delete_button_clicked(); break;
        case 1: _t->on_add_button_clicked(); break;
        case 2: _t->on_edit_button_clicked(); break;
        case 3: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ColorTransitionDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ColorTransitionDialog::staticMetaObject = {
    { &CustomBlockDialog::staticMetaObject, qt_meta_stringdata_ColorTransitionDialog,
      qt_meta_data_ColorTransitionDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorTransitionDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorTransitionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorTransitionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorTransitionDialog))
        return static_cast<void*>(const_cast< ColorTransitionDialog*>(this));
    return CustomBlockDialog::qt_metacast(_clname);
}

int ColorTransitionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
