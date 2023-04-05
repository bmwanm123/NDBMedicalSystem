/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "ToNDBButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "SelectFile_clicked"
QT_MOC_LITERAL(4, 51, 21), // "btnMenu_Close_clicked"
QT_MOC_LITERAL(5, 73, 19), // "btnMenu_Max_clicked"
QT_MOC_LITERAL(6, 93, 19), // "btnMenu_Min_clicked"
QT_MOC_LITERAL(7, 113, 23), // "btnMenu_setting_clicked"
QT_MOC_LITERAL(8, 137, 22), // "btnMenu_change_clicked"
QT_MOC_LITERAL(9, 160, 23), // "btn_dataDisplay_clicked"
QT_MOC_LITERAL(10, 184, 21), // "btn_dataInput_clicked"
QT_MOC_LITERAL(11, 206, 19), // "btn_dataNdb_clicked"
QT_MOC_LITERAL(12, 226, 23), // "btn_saveSetting_clicked"
QT_MOC_LITERAL(13, 250, 12), // "connect_slot"
QT_MOC_LITERAL(14, 263, 9), // "send_slot"
QT_MOC_LITERAL(15, 273, 9) // "recv_slot"

    },
    "MainWindow\0ToNDBButton_clicked\0\0"
    "SelectFile_clicked\0btnMenu_Close_clicked\0"
    "btnMenu_Max_clicked\0btnMenu_Min_clicked\0"
    "btnMenu_setting_clicked\0btnMenu_change_clicked\0"
    "btn_dataDisplay_clicked\0btn_dataInput_clicked\0"
    "btn_dataNdb_clicked\0btn_saveSetting_clicked\0"
    "connect_slot\0send_slot\0recv_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ToNDBButton_clicked(); break;
        case 1: _t->SelectFile_clicked(); break;
        case 2: _t->btnMenu_Close_clicked(); break;
        case 3: _t->btnMenu_Max_clicked(); break;
        case 4: _t->btnMenu_Min_clicked(); break;
        case 5: _t->btnMenu_setting_clicked(); break;
        case 6: _t->btnMenu_change_clicked(); break;
        case 7: _t->btn_dataDisplay_clicked(); break;
        case 8: _t->btn_dataInput_clicked(); break;
        case 9: _t->btn_dataNdb_clicked(); break;
        case 10: _t->btn_saveSetting_clicked(); break;
        case 11: _t->connect_slot(); break;
        case 12: _t->send_slot(); break;
        case 13: _t->recv_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
