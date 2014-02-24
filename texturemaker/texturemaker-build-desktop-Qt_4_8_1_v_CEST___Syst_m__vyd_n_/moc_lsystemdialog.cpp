/****************************************************************************
** Meta object code from reading C++ file 'lsystemdialog.h'
**
** Created: Mon Feb 24 13:34:27 2014
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
      20,   14, // methods
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
      97,   14,   14,   14, 0x08,
     122,   14,   14,   14, 0x08,
     146,   14,   14,   14, 0x08,
     176,   14,   14,   14, 0x08,
     206,   14,   14,   14, 0x08,
     237,   14,   14,   14, 0x08,
     267,   14,   14,   14, 0x08,
     297,   14,   14,   14, 0x08,
     330,   14,   14,   14, 0x08,
     367,   14,   14,   14, 0x08,
     405,   14,   14,   14, 0x08,
     441,   14,   14,   14, 0x08,
     475,   14,   14,   14, 0x08,
     514,   14,   14,   14, 0x08,
     551,   14,   14,   14, 0x08,
     588,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LSystemDialog[] = {
    "LSystemDialog\0\0on_browse_clicked()\0"
    "on_reload_clicked()\0on_buttonBox_accepted()\0"
    "on_save_clicked()\0on_button_push_clicked()\0"
    "on_button_pop_clicked()\0"
    "on_button_set_angle_clicked()\0"
    "on_button_turn_left_clicked()\0"
    "on_button_turn_right_clicked()\0"
    "on_button_set_color_clicked()\0"
    "on_button_draw_line_clicked()\0"
    "on_button_move_forward_clicked()\0"
    "on_button_set_step_percent_clicked()\0"
    "on_button_set_step_absolute_clicked()\0"
    "on_button_set_step_pixels_clicked()\0"
    "on_button_increase_step_clicked()\0"
    "on_button_set_width_absolute_clicked()\0"
    "on_button_set_width_pixels_clicked()\0"
    "on_button_set_style_pixels_clicked()\0"
    "on_button_set_style_absolute_clicked()\0"
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
        case 4: _t->on_button_push_clicked(); break;
        case 5: _t->on_button_pop_clicked(); break;
        case 6: _t->on_button_set_angle_clicked(); break;
        case 7: _t->on_button_turn_left_clicked(); break;
        case 8: _t->on_button_turn_right_clicked(); break;
        case 9: _t->on_button_set_color_clicked(); break;
        case 10: _t->on_button_draw_line_clicked(); break;
        case 11: _t->on_button_move_forward_clicked(); break;
        case 12: _t->on_button_set_step_percent_clicked(); break;
        case 13: _t->on_button_set_step_absolute_clicked(); break;
        case 14: _t->on_button_set_step_pixels_clicked(); break;
        case 15: _t->on_button_increase_step_clicked(); break;
        case 16: _t->on_button_set_width_absolute_clicked(); break;
        case 17: _t->on_button_set_width_pixels_clicked(); break;
        case 18: _t->on_button_set_style_pixels_clicked(); break;
        case 19: _t->on_button_set_style_absolute_clicked(); break;
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
