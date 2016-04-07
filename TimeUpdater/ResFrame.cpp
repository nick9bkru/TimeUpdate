#include "ResFrame.h"
#include <QDebug>
#include "Singleton.h"
#include "ServersIp.h"

ResFrame::ResFrame(QWidget *parent) :
    QFrame(parent),Ui::ResFrame ()
{
    setupUi(this);
    mapBut.insert( "РМО1", Rmo1Button );
    mapBut.insert( "РМО2", Rmo2Button );
    mapBut.insert( "РМО3", Rmo3Button );
    mapBut.insert( "РМО4", Rmo4Button );
    mapBut.insert( "РМДИ1", Rmdi1Button );
    mapBut.insert( "РМДИ2", Rmdi2Button );
    mapBut.insert( "ЦУУ1", CUU1Button );
    mapBut.insert( "ЦУУ2", CUU2Button );
    mapBut.insert( "РМИШ", RmishButton );

}

ResFrame::~ResFrame()
{

}

void ResFrame::SetRes ( const UdpClient::dataRecieve & date)
{
    //if ( )
    QString name = Util::Singleton<ServersIp>::getInstance().getName( date.addr.toString() );

    if ( date.data.contains( "--ERROR" ) )
    {
        return;
    }
    qDebug() << " ResFrame::SetRes name == " << name;

    QPushButton* but = mapBut[ name ];
    but->setStyleSheet( "background-color: rgb(49,242,55);" );



};

void ResFrame::resetColor()
{
    for( QMap< QString, QPushButton* >::iterator it = mapBut.begin(); it != mapBut.end(); it ++ )
    {
      it.value()->setStyleSheet( "background-color: rgb(242,0,0);" );
    }
};
