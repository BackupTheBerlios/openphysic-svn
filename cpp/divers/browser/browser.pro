TEMPLATE = app

QT += gui \
  core \
  xml

TARGET = 

DEPENDPATH += . build src ui

INCLUDEPATH += . src build

CONFIG +=   qt \
  debug \
  warn_on \
  console

DESTDIR +=   bin

OBJECTS_DIR +=   build

MOC_DIR +=   build

UI_DIR +=   build

DEFINES += QT_NO_CAST_FROM_ASCII


# Input
HEADERS += src/browser.h \

FORMS += ui/browser.ui \

SOURCES += src/browser.cpp \
  src/main.cpp \

