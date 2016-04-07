#ifndef RESFRAME_H
#define RESFRAME_H

#include <QFrame>
#include <QMap>
#include <QString>
#include "ui_ResFrame.h"
#include "UdpClient.h"

class ResFrame : public QFrame, Ui::ResFrame
{
    Q_OBJECT

public:
    explicit ResFrame(QWidget *parent = 0);
    ~ResFrame();
public slots :
    void SetRes ( const UdpClient::dataRecieve & date) ;
    void resetColor();
private:
    QMap< QString, QPushButton* > mapBut;
};

#endif // RESFRAME_H
