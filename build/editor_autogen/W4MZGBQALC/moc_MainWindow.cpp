/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editor/MainWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tungsten__MainWindow_t {
    QByteArrayData data[13];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tungsten__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tungsten__MainWindow_t qt_meta_stringdata_Tungsten__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Tungsten::MainWindow"
QT_MOC_LITERAL(1, 21, 12), // "sceneChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "showPreview"
QT_MOC_LITERAL(4, 47, 1), // "v"
QT_MOC_LITERAL(5, 49, 8), // "newScene"
QT_MOC_LITERAL(6, 58, 9), // "openScene"
QT_MOC_LITERAL(7, 68, 11), // "reloadScene"
QT_MOC_LITERAL(8, 80, 10), // "closeScene"
QT_MOC_LITERAL(9, 91, 9), // "saveScene"
QT_MOC_LITERAL(10, 101, 11), // "saveSceneAs"
QT_MOC_LITERAL(11, 113, 13), // "togglePreview"
QT_MOC_LITERAL(12, 127, 4) // "path"

    },
    "Tungsten::MainWindow\0sceneChanged\0\0"
    "showPreview\0v\0newScene\0openScene\0"
    "reloadScene\0closeScene\0saveScene\0"
    "saveSceneAs\0togglePreview\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tungsten__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x0a /* Public */,
       6,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void Tungsten::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sceneChanged(); break;
        case 1: _t->showPreview((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->newScene(); break;
        case 3: _t->openScene(); break;
        case 4: _t->reloadScene(); break;
        case 5: _t->closeScene(); break;
        case 6: _t->saveScene(); break;
        case 7: _t->saveSceneAs(); break;
        case 8: _t->togglePreview(); break;
        case 9: _t->openScene((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sceneChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tungsten::MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Tungsten__MainWindow.data,
    qt_meta_data_Tungsten__MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tungsten::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tungsten::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tungsten__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Tungsten::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Tungsten::MainWindow::sceneChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
