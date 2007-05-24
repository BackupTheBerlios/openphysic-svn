TEMPLATE =   app
QT +=   gui \
  core
CONFIG +=   qt \
  release \
  warn_on \
  console
DESTDIR +=   bin
OBJECTS_DIR +=   build
MOC_DIR +=   build
UI_DIR +=   build
FORMS +=   ui/dialog.ui \
  ui/about.ui \
  ui/mainwin.ui \
  ui/testwin.ui
HEADERS +=   src/dialogimpl.h \
  src/mainwinimpl.h \
  src/aboutimpl.h
SOURCES +=   src/dialogimpl.cpp \
  src/main.cpp \
  src/mainwinimpl.cpp \
  src/aboutimpl.cpp
