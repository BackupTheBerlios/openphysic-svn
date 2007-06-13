TEMPLATE =   app
QT +=   gui \
  core
CONFIG +=   qt \
  debug \
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
  src/aboutimpl.h \
  src/testwinimpl.h \
  src/ocwindows.h \
  src/data.h \
  src/rpm.h \
  src/temperature.h \
  src/track.h \
  src/position.h \
  src/engine.h \
  src/pilot.h \
  src/vehicule.h \
  src/engine_state.h \
  src/chrono.h 
SOURCES +=   src/dialogimpl.cpp \
  src/main.cpp \
  src/mainwinimpl.cpp \
  src/aboutimpl.cpp \
  src/testwinimpl.cpp \
  src/ocwindows.cpp \
  src/data.cpp \
  src/rpm.cpp \
  src/temperature.cpp \
  src/track.cpp \
  src/position.cpp \
  src/engine.cpp \
  src/pilot.cpp \
  src/vehicule.cpp \
  src/engine_state.cpp \
  src/chrono.cpp

