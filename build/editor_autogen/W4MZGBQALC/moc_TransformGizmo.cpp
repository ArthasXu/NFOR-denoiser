/****************************************************************************
** Meta object code from reading C++ file 'TransformGizmo.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editor/TransformGizmo.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TransformGizmo.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tungsten__TransformGizmo_t {
    QByteArrayData data[30];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tungsten__TransformGizmo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tungsten__TransformGizmo_t qt_meta_stringdata_Tungsten__TransformGizmo = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Tungsten::TransformGizmo"
QT_MOC_LITERAL(1, 25, 17), // "transformFinished"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5), // "Mat4f"
QT_MOC_LITERAL(4, 50, 5), // "delta"
QT_MOC_LITERAL(5, 56, 6), // "redraw"
QT_MOC_LITERAL(6, 63, 7), // "setMode"
QT_MOC_LITERAL(7, 71, 4), // "mode"
QT_MOC_LITERAL(8, 76, 20), // "toggleTranslateLocal"
QT_MOC_LITERAL(9, 97, 6), // "resize"
QT_MOC_LITERAL(10, 104, 1), // "w"
QT_MOC_LITERAL(11, 106, 1), // "h"
QT_MOC_LITERAL(12, 108, 7), // "fixAxis"
QT_MOC_LITERAL(13, 116, 4), // "axis"
QT_MOC_LITERAL(14, 121, 7), // "setView"
QT_MOC_LITERAL(15, 129, 1), // "m"
QT_MOC_LITERAL(16, 131, 13), // "setProjection"
QT_MOC_LITERAL(17, 145, 17), // "setFixedTransform"
QT_MOC_LITERAL(18, 163, 14), // "beginTransform"
QT_MOC_LITERAL(19, 178, 1), // "x"
QT_MOC_LITERAL(20, 180, 1), // "y"
QT_MOC_LITERAL(21, 182, 15), // "updateTransform"
QT_MOC_LITERAL(22, 198, 12), // "endTransform"
QT_MOC_LITERAL(23, 211, 14), // "abortTransform"
QT_MOC_LITERAL(24, 226, 13), // "setSnapToGrid"
QT_MOC_LITERAL(25, 240, 1), // "v"
QT_MOC_LITERAL(26, 242, 6), // "update"
QT_MOC_LITERAL(27, 249, 18), // "const QMouseEvent*"
QT_MOC_LITERAL(28, 268, 5), // "event"
QT_MOC_LITERAL(29, 274, 4) // "draw"

    },
    "Tungsten::TransformGizmo\0transformFinished\0"
    "\0Mat4f\0delta\0redraw\0setMode\0mode\0"
    "toggleTranslateLocal\0resize\0w\0h\0fixAxis\0"
    "axis\0setView\0m\0setProjection\0"
    "setFixedTransform\0beginTransform\0x\0y\0"
    "updateTransform\0endTransform\0"
    "abortTransform\0setSnapToGrid\0v\0update\0"
    "const QMouseEvent*\0event\0draw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tungsten__TransformGizmo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   98,    2, 0x0a /* Public */,
       8,    0,  101,    2, 0x0a /* Public */,
       9,    2,  102,    2, 0x0a /* Public */,
      12,    1,  107,    2, 0x0a /* Public */,
      14,    1,  110,    2, 0x0a /* Public */,
      16,    1,  113,    2, 0x0a /* Public */,
      17,    1,  116,    2, 0x0a /* Public */,
      18,    2,  119,    2, 0x0a /* Public */,
      21,    2,  124,    2, 0x0a /* Public */,
      22,    0,  129,    2, 0x0a /* Public */,
      23,    0,  130,    2, 0x0a /* Public */,
      24,    1,  131,    2, 0x0a /* Public */,
      26,    1,  134,    2, 0x0a /* Public */,
      29,    0,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 3,   15,
    QMetaType::Void, 0x80000000 | 3,   15,
    QMetaType::Void, 0x80000000 | 3,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Bool, 0x80000000 | 27,   28,
    QMetaType::Void,

       0        // eod
};

void Tungsten::TransformGizmo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TransformGizmo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->transformFinished((*reinterpret_cast< Mat4f(*)>(_a[1]))); break;
        case 1: _t->redraw(); break;
        case 2: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->toggleTranslateLocal(); break;
        case 4: _t->resize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->fixAxis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setView((*reinterpret_cast< const Mat4f(*)>(_a[1]))); break;
        case 7: _t->setProjection((*reinterpret_cast< const Mat4f(*)>(_a[1]))); break;
        case 8: _t->setFixedTransform((*reinterpret_cast< const Mat4f(*)>(_a[1]))); break;
        case 9: _t->beginTransform((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->updateTransform((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->endTransform(); break;
        case 12: _t->abortTransform(); break;
        case 13: _t->setSnapToGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: { bool _r = _t->update((*reinterpret_cast< const QMouseEvent*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->draw(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TransformGizmo::*)(Mat4f );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransformGizmo::transformFinished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TransformGizmo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransformGizmo::redraw)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tungsten::TransformGizmo::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Tungsten__TransformGizmo.data,
    qt_meta_data_Tungsten__TransformGizmo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tungsten::TransformGizmo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tungsten::TransformGizmo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tungsten__TransformGizmo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tungsten::TransformGizmo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Tungsten::TransformGizmo::transformFinished(Mat4f _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tungsten::TransformGizmo::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
