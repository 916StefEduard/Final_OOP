/****************************************************************************
** Meta object code from reading C++ file 'firststarter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/FirstMenu/firststarter.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'firststarter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_firststarter_t {
    const uint offsetsAndSize[14];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_firststarter_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_firststarter_t qt_meta_stringdata_firststarter = {
    {
QT_MOC_LITERAL(0, 12), // "firststarter"
QT_MOC_LITERAL(13, 10), // "start_menu"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 4), // "argc"
QT_MOC_LITERAL(30, 6), // "char**"
QT_MOC_LITERAL(37, 4), // "argv"
QT_MOC_LITERAL(42, 9) // "construct"

    },
    "firststarter\0start_menu\0\0argc\0char**\0"
    "argv\0construct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_firststarter[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x0a,    0 /* Public */,
       6,    0,   31,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Int, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,

       0        // eod
};

void firststarter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<firststarter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->start_menu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char**(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->construct(); break;
        default: ;
        }
    }
}

const QMetaObject firststarter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_firststarter.offsetsAndSize,
    qt_meta_data_firststarter,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_firststarter_t

, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<char * *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *firststarter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *firststarter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_firststarter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int firststarter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
