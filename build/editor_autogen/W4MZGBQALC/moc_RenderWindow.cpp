/****************************************************************************
** Meta object code from reading C++ file 'RenderWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editor/RenderWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tungsten__RenderWindow_t {
    QByteArrayData data[14];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tungsten__RenderWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tungsten__RenderWindow_t qt_meta_stringdata_Tungsten__RenderWindow = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Tungsten::RenderWindow"
QT_MOC_LITERAL(1, 23, 16), // "rendererFinished"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "startRender"
QT_MOC_LITERAL(4, 53, 11), // "abortRender"
QT_MOC_LITERAL(5, 65, 12), // "finishRender"
QT_MOC_LITERAL(6, 78, 7), // "refresh"
QT_MOC_LITERAL(7, 86, 12), // "toggleRender"
QT_MOC_LITERAL(8, 99, 6), // "zoomIn"
QT_MOC_LITERAL(9, 106, 7), // "zoomOut"
QT_MOC_LITERAL(10, 114, 9), // "resetView"
QT_MOC_LITERAL(11, 124, 13), // "togglePreview"
QT_MOC_LITERAL(12, 138, 17), // "toggleAutoRefresh"
QT_MOC_LITERAL(13, 156, 12) // "sceneChanged"

    },
    "Tungsten::RenderWindow\0rendererFinished\0"
    "\0startRender\0abortRender\0finishRender\0"
    "refresh\0toggleRender\0zoomIn\0zoomOut\0"
    "resetView\0togglePreview\0toggleAutoRefresh\0"
    "sceneChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tungsten__RenderWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tungsten::RenderWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rendererFinished(); break;
        case 1: _t->startRender(); break;
        case 2: _t->abortRender(); break;
        case 3: _t->finishRender(); break;
        case 4: _t->refresh(); break;
        case 5: _t->toggleRender(); break;
        case 6: _t->zoomIn(); break;
        case 7: _t->zoomOut(); break;
        case 8: _t->resetView(); break;
        case 9: _t->togglePreview(); break;
        case 10: _t->toggleAutoRefresh(); break;
        case 11: _t->sceneChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RenderWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RenderWindow::rendererFinished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tungsten::RenderWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Tungsten__RenderWindow.data,
    qt_meta_data_Tungsten__RenderWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tungsten::RenderWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tungsten::RenderWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tungsten__RenderWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tungsten::RenderWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Tungsten::RenderWindow::rendererFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
