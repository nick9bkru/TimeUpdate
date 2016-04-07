#ifndef MAINWIDJET_H
#define MAINWIDJET_H

#include <QFrame>
#include "ui_MainWidjet.h"
#include "TimeDateEdit.h"
#include "UdpClient.h"
#include "ResFrame.h"

class MainWidjet : public QFrame, Ui::MainWidjet
{
    Q_OBJECT
    enum
    {
        PORT = 30000
    };
public:
    explicit MainWidjet(QWidget *parent = 0);
    ~MainWidjet();
private slots:
    void setTimeSlot();
private:
    TimeDateEdit * TimeEdit;
    UdpClient * udpSender;
    ResFrame *Result;
};

#endif // MAINWIDJET_H
