#ifndef TIMEDATEEDIT_H
#define TIMEDATEEDIT_H

#include <QFrame>
#include <QDateTime>
#include "ui_TimeDateEdit.h"

class TimeDateEdit : public QFrame, Ui::TimeDateEdit
{
    Q_OBJECT

public:
    explicit TimeDateEdit(QWidget *parent = 0);
    ~TimeDateEdit();
    void setDate(const QDateTime &date);
    QDateTime getTime()const;
    QString getTimeStr( ) const;
private:
};

#endif // TIMEDATEEDIT_H
