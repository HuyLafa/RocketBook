TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT +=sql


SOURCES += main.cpp \
    rocketuser.cpp \
    profile.cpp \
    ../database/accountdb.cpp \
    ../database/frienddb.cpp \
    ../database/blogdb.cpp \
    ../database/commentdb.cpp \
    ../database/multimediadb.cpp \
    ../database/tweetdb.cpp \
    ../database/profiledb.cpp \
    blog.cpp \
    comment.cpp \
    post.cpp \
    scrapbook.cpp \
    tweet.cpp \
    feed.cpp \
    accountcontroller.cpp \
    multimedia.cpp \
    message.cpp \
    chat.cpp

HEADERS += \
    rocketuser.h \
    profile.h \
    ../database/*.h \
    blog.h \
    comment.h \
    post.h \
    scrapbook.h \
    tweet.h \
    feed.h \
    accountcontroller.h \
    multimedia.h \
    message.h \
    chat.h
