/****************************************************************************
** Meta object code from reading C++ file 'capture.h'
**
** Created: Wed May 21 16:34:17 2014
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "capture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Capture[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      23,    8,    8,    8, 0x0a,
      38,    8,    8,    8, 0x0a,
      50,    8,    8,    8, 0x0a,
      63,    8,    8,    8, 0x0a,
      77,    8,    8,    8, 0x0a,
      90,    8,    8,    8, 0x0a,
     101,    8,    8,    8, 0x08,
     125,    8,    8,    8, 0x08,
     161,    8,    8,    8, 0x08,
     186,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Capture[] = {
    "Capture\0\0openCapture()\0closeCapture()\0"
    "readFrame()\0openPhotos()\0closePhotos()\0"
    "takePhotos()\0readData()\0on_serial_btn_clicked()\0"
    "on_image_close_pushButton_clicked()\0"
    "paintEvent(QPaintEvent*)\0readMyCom()\0"
};

const QMetaObject Capture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Capture,
      qt_meta_data_Capture, 0 }
};

const QMetaObject *Capture::metaObject() const
{
    return &staticMetaObject;
}

void *Capture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Capture))
        return static_cast<void*>(const_cast< Capture*>(this));
    return QWidget::qt_metacast(_clname);
}

int Capture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openCapture(); break;
        case 1: closeCapture(); break;
        case 2: readFrame(); break;
        case 3: openPhotos(); break;
        case 4: closePhotos(); break;
        case 5: takePhotos(); break;
        case 6: readData(); break;
        case 7: on_serial_btn_clicked(); break;
        case 8: on_image_close_pushButton_clicked(); break;
        case 9: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 10: readMyCom(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
