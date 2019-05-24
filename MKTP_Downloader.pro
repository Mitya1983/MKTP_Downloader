TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
    -lboost_system \
    -lpthread \
    -lsqlite3

SOURCES += \
        main.cpp \
        pagedownloader.cpp \
        query.cpp \
        result.cpp \
        sqlite_wrapper.cpp \
        todatabase.cpp

HEADERS += \
    pagedownloader.h \
    query.h \
    result.h \
    sqlite_wrapper.h \
    todatabase.h
