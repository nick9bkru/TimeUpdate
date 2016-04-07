#include "TimeDateEdit.h"
#include <QDate>
#include <QDebug>
TimeDateEdit::TimeDateEdit(QWidget *parent) :
    QFrame(parent),Ui::TimeDateEdit()
{
    setupUi( this );
    for ( int i = 0 ; i < 31; i++ )
    {
      DateBox->insertItem(i, QString ("%1").arg( i+1 ) );
      YearBox->insertItem(i, QString ("%1").arg( i+2010 ) );
    }
    setDate (QDateTime::currentDateTime());
}

TimeDateEdit::~TimeDateEdit()
{
}

void TimeDateEdit::setDate( const QDateTime & date)
{
    DateBox->setCurrentIndex( date.date().day() -1 );
    YearBox->setCurrentIndex( date.date().year() - 2010 );
    MonthBox->setCurrentIndex( date.date().month() -1 );
    timeEdit->setTime( date.time() );
};

QDateTime TimeDateEdit::getTime()const
{
   QDateTime ret;
   ret.setDate( QDate( YearBox->currentIndex() + 2010,
                       MonthBox->currentIndex() + 1, DateBox->currentIndex() + 1 ) );

   ret.setTime( timeEdit->time() );
   if ( !ret.isValid() )
   {
    throw ( QString ( "No correct data" ) );
   }
   qDebug() << ret.toString();
   return ret;
};

QString TimeDateEdit::getTimeStr( ) const
{
   QString ret;
   QDateTime time = getTime();
   ret = QString ("date %1%2%3%4%5").arg( time.date().month(), 2 , 10, QLatin1Char( '0' ) ).arg(time.date().day(), 2, 10, QLatin1Char( '0' ))
                                           .arg( time.time().hour(), 2, 10, QLatin1Char( '0' ) ).arg( time.time().minute(), 2, 10, QLatin1Char( '0' ) )
                                             .arg( time.date().year() % 100, 2, 10, QLatin1Char( '0' ) );
   qDebug() << ret;
   return ret;
};

