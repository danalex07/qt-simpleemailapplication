#-------------------------------------------------
#
# Project created by QtCreator 2018-01-23T12:27:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmailApplication
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mail/emailaddress.cpp \
    mail/mimeattachment.cpp \
    mail/mimecontentformatter.cpp \
    mail/mimefile.cpp \
    mail/mimehtml.cpp \
    mail/mimeinlinefile.cpp \
    mail/mimemessage.cpp \
    mail/mimemultipart.cpp \
    mail/mimepart.cpp \
    mail/mimetext.cpp \
    mail/quotedprintable.cpp \
    mail/smtpclient.cpp

HEADERS += \
        mainwindow.h \
        mail/SmtpMime \
        mail/emailaddress.h \
        mail/mimeattachment.h \
    mail/mimecontentformatter.h \
    mail/mimefile.h \
    mail/mimehtml.h \
    mail/mimeinlinefile.h \
    mail/mimemessage.h \
    mail/mimemultipart.h \
    mail/mimepart.h \
    mail/mimetext.h \
    mail/quotedprintable.h \
    mail/smtpclient.h


FORMS += \
        mainwindow.ui

#win32: LIBS += -L$$PWD/./ -lSMTPEmail

#INCLUDEPATH += $$PWD/.
#DEPENDPATH += $$PWD/.
