/****************************************************************************
** Meta object code from reading C++ file 'PropertyWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editor/PropertyWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PropertyWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tungsten__PropertyWindow_t {
    QByteArrayData data[12];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tungsten__PropertyWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tungsten__PropertyWindow_t qt_meta_stringdata_Tungsten__PropertyWindow = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Tungsten::PropertyWindow"
QT_MOC_LITERAL(1, 25, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 20), // "treeSelectionChanged"
QT_MOC_LITERAL(4, 64, 20), // "primitiveListChanged"
QT_MOC_LITERAL(5, 85, 10), // "tabChanged"
QT_MOC_LITERAL(6, 96, 3), // "idx"
QT_MOC_LITERAL(7, 100, 12), // "sceneChanged"
QT_MOC_LITERAL(8, 113, 15), // "changeSelection"
QT_MOC_LITERAL(9, 129, 19), // "changePrimitiveName"
QT_MOC_LITERAL(10, 149, 10), // "Primitive*"
QT_MOC_LITERAL(11, 160, 1) // "p"

    },
    "Tungsten::PropertyWindow\0selectionChanged\0"
    "\0treeSelectionChanged\0primitiveListChanged\0"
    "tabChanged\0idx\0sceneChanged\0changeSelection\0"
    "changePrimitiveName\0Primitive*\0p"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tungsten__PropertyWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void Tungsten::PropertyWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PropertyWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->treeSelectionChanged(); break;
        case 2: _t->primitiveListChanged(); break;
        case 3: _t->tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sceneChanged(); break;
        case 5: _t->changeSelection(); break;
        case 6: _t->changePrimitiveName((*reinterpret_cast< Primitive*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PropertyWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PropertyWindow::selectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tungsten::PropertyWindow::staticMetaObject = { {
    &QSplitter::staticMetaObject,
    qt_meta_stringdata_Tungsten__PropertyWindow.data,
    qt_meta_data_Tungsten__PropertyWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tungsten::PropertyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tungsten::PropertyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tungsten__PropertyWindow.stringdata0))
        return static_cast<void*>(this);
    return QSplitter::qt_metacast(_clname);
}

int Tungsten::PropertyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Tungsten::PropertyWindow::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
