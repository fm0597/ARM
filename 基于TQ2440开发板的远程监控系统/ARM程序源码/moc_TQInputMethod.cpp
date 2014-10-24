/****************************************************************************
** Meta object code from reading C++ file 'TQInputMethod.h'
**
** Created: Sat May 17 05:46:17 2014
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TQInputMethod.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TQInputMethod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TQInputMethod[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TQInputMethod[] = {
    "TQInputMethod\0\0confirmContent()\0"
};

const QMetaObject TQInputMethod::staticMetaObject = {
    { &QWSInputMethod::staticMetaObject, qt_meta_stringdata_TQInputMethod,
      qt_meta_data_TQInputMethod, 0 }
};

const QMetaObject *TQInputMethod::metaObject() const
{
    return &staticMetaObject;
}

void *TQInputMethod::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TQInputMethod))
        return static_cast<void*>(const_cast< TQInputMethod*>(this));
    return QWSInputMethod::qt_metacast(_clname);
}

int TQInputMethod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWSInputMethod::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: confirmContent(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
