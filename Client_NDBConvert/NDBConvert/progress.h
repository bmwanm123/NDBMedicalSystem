#ifndef PROGRESS_H
#define PROGRESS_H

#include <QDebug>
#include <QTimer>
#include <QProgressDialog>
#include <QWidget>
#include<QObject>

class Progress:public QObject
{
    Q_OBJECT
public:
    Progress();
    void progress();
protected:
    QProgressDialog *p_dlg;
    QTimer *t;
    QTimer *tmp;
    int steps=0;

//private slots:

public slots:
    void updateValue();
    void end();


};

#endif // PROGRESS_H
