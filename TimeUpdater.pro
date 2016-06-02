TEMPLATE = subdirs

greaterThan ( QT_VERSION, 4.4 ) {
  DEFINES += QT44
  SUBDIRS += \
    SingleAppLib\
}
SUBDIRS += \
    TimeUpdater\
    TimeUpdateServ



