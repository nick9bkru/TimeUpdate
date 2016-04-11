#ifndef RESFRAME_H
#define RESFRAME_H

#include <QFrame>
#include <QMap>
#include <QString>
#include "ui_ResFrame.h"
#include "UdpClient.h"

/**
 * @brief The ResFrame class
 * Виджет отображающий устанавливаемые рабочие места
 */
class ResFrame : public QFrame, Ui::ResFrame
{
    Q_OBJECT

public:
    explicit ResFrame(QWidget *parent = 0);
    ~ResFrame();
public slots :
    /**
     * @brief SetRes
     * устанавливает цвет в зависимости от результата
     * @param date
     */
    void SetRes ( const UdpClient::dataRecieve & date) ;
    /**
     * @brief resetColor
     * установить все квадраты красными
     */
    void resetColor();
private:
    /**
     * @brief mapBut
     * набор пар с названием и кнопкой
     */
    QMap< QString, QPushButton* > mapBut;
};

#endif // RESFRAME_H
