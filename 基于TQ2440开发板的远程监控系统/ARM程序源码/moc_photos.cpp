/****************************************************************************
** Meta object code from reading C++ file 'photos.h'
**
** Created: Sat May 17 02:53:43 2014
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "photos.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'photos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Photos[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,    7,    7,    7, 0x0a,
      33,    7,    7,    7, 0x0a,
      49,    7,    7,    7, 0x0a,
      61,    7,    7,    7, 0x0a,
      75,    7,    7,    7, 0x0a,
      89,    7,    7,    7, 0x0a,
     103,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Photos[] = {
    "Photos\0\0closeImage()\0openFiles()\0"
    "previousPhoto()\0nextPhoto()\0expandImage()\0"
    "narrowImage()\0deleteImage()\0adjustPhoto()\0"
};

const QMetaObject Photos::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Photos,
      qt_meta_data_Photos, 0 }
};

const QMetaObject *Photos::metaObject() const
{
    return &staticMetaObject;
}

void *Photos::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Photos))
        return static_cast<void*>(const_cast< Photos*>(this));
    return QWidget::qt_metacast(_clname);
}

int Photos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: closeImage(); break;
        case 1: openFiles(); break;
        case 2: previousPhoto(); break;
        case 3: nextPhoto(); break;
        case 4: expandImage(); break;
        case 5: narrowImage(); break;
        case 6: deleteImage(); break;
        case 7: adjustPhoto(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Photos::closeImage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
