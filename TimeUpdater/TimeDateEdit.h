#ifndef TIMEDATEEDIT_H
#define TIMEDATEEDIT_H

#include <QFrame>
#include <QDateTime>
#include "ui_TimeDateEdit.h"

/**
 * @brief The TimeDateEdit class
 * Класс для работы с виджетом выбора времени
 */
class TimeDateEdit : public QFrame, Ui::TimeDateEdit
{
    Q_OBJECT

public:
    explicit TimeDateEdit(QWidget *parent = 0);
    ~TimeDateEdit();
    /**
     * @brief setDate
     * установить дату
     * @param date
     */
    void setDate(const QDateTime &date);
    /**
     * @brief getTime
     * получить время
     * @return
     */
    QDateTime getTime()const;
    /**
     * @brief getTimeStr
     * получить команду для установки времени
     * @return
     */
    QString getTimeStr( ) const;
private:
};

#endif // TIMEDATEEDIT_H
