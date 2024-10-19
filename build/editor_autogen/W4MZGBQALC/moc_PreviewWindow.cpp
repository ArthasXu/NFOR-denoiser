/****************************************************************************
** Meta object code from reading C++ file 'PreviewWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editor/PreviewWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PreviewWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tungsten__PreviewWindow_t {
    QByteArrayData data[21];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tungsten__PreviewWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tungsten__PreviewWindow_t qt_meta_stringdata_Tungsten__PreviewWindow = {
    {
QT_MOC_LITERAL(0, 0, 23), // "Tungsten::PreviewWindow"
QT_MOC_LITERAL(1, 24, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 20), // "primitiveListChanged"
QT_MOC_LITERAL(4, 63, 15), // "toggleSelectAll"
QT_MOC_LITERAL(5, 79, 9), // "grabGizmo"
QT_MOC_LITERAL(6, 89, 17), // "transformFinished"
QT_MOC_LITERAL(7, 107, 5), // "Mat4f"
QT_MOC_LITERAL(8, 113, 5), // "delta"
QT_MOC_LITERAL(9, 119, 18), // "recomputeCentroids"
QT_MOC_LITERAL(10, 138, 18), // "computeHardNormals"
QT_MOC_LITERAL(11, 157, 20), // "computeSmoothNormals"
QT_MOC_LITERAL(12, 178, 16), // "freezeTransforms"
QT_MOC_LITERAL(13, 195, 18), // "duplicateSelection"
QT_MOC_LITERAL(14, 214, 8), // "addModel"
QT_MOC_LITERAL(15, 223, 15), // "deleteSelection"
QT_MOC_LITERAL(16, 239, 13), // "togglePreview"
QT_MOC_LITERAL(17, 253, 11), // "resetCamera"
QT_MOC_LITERAL(18, 265, 15), // "showContextMenu"
QT_MOC_LITERAL(19, 281, 12), // "sceneChanged"
QT_MOC_LITERAL(20, 294, 15) // "changeSelection"

    },
    "Tungsten::PreviewWindow\0selectionChanged\0"
    "\0primitiveListChanged\0toggleSelectAll\0"
    "grabGizmo\0transformFinished\0Mat4f\0"
    "delta\0recomputeCentroids\0computeHardNormals\0"
    "computeSmoothNormals\0freezeTransforms\0"
    "duplicateSelection\0addModel\0deleteSelection\0"
    "togglePreview\0resetCamera\0showContextMenu\0"
    "sceneChanged\0changeSelection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tungsten__PreviewWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    1,  103,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x0a /* Public */,
      20,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
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
    QMetaType::Void,

       0        // eod
};

void Tungsten::PreviewWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreviewWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->primitiveListChanged(); break;
        case 2: _t->toggleSelectAll(); break;
        case 3: _t->grabGizmo(); break;
        case 4: _t->transformFinished((*reinterpret_cast< Mat4f(*)>(_a[1]))); break;
        case 5: _t->recomputeCentroids(); break;
        case 6: _t->computeHardNormals(); break;
        case 7: _t->computeSmoothNormals(); break;
        case 8: _t->freezeTransforms(); break;
        case 9: _t->duplicateSelection(); break;
        case 10: _t->addModel(); break;
        case 11: _t->deleteSelection(); break;
        case 12: _t->togglePreview(); break;
        case 13: _t->resetCamera(); break;
        case 14: _t->showContextMenu(); break;
        case 15: _t->sceneChanged(); break;
        case 16: _t->changeSelection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PreviewWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PreviewWindow::selectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PreviewWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PreviewWindow::primitiveListChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tungsten::PreviewWindow::staticMetaObject = { {
    &QGLWidget::staticMetaObject,
    qt_meta_stringdata_Tungsten__PreviewWindow.data,
    qt_meta_data_Tungsten__PreviewWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tungsten::PreviewWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tungsten::PreviewWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tungsten__PreviewWindow.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int Tungsten::PreviewWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Tungsten::PreviewWindow::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tungsten::PreviewWindow::primitiveListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
