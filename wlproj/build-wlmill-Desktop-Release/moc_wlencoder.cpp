/****************************************************************************
** Meta object code from reading C++ file 'wlencoder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../wlmotion/modules/wlencoder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlencoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WLEncoder_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WLEncoder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WLEncoder_t qt_meta_stringdata_WLEncoder = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WLEncoder"
QT_MOC_LITERAL(1, 10, 12), // "changedError"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10) // "changedCnt"

    },
    "WLEncoder\0changedError\0\0changedCnt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WLEncoder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       3,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::Long,    2,

       0        // eod
};

void WLEncoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WLEncoder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changedError((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 1: _t->changedCnt((*reinterpret_cast< long(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WLEncoder::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WLEncoder::changedError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WLEncoder::*)(long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WLEncoder::changedCnt)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WLEncoder::staticMetaObject = { {
    &WLElement::staticMetaObject,
    qt_meta_stringdata_WLEncoder.data,
    qt_meta_data_WLEncoder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WLEncoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WLEncoder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WLEncoder.stringdata0))
        return static_cast<void*>(this);
    return WLElement::qt_metacast(_clname);
}

int WLEncoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WLElement::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WLEncoder::changedError(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WLEncoder::changedCnt(long _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE