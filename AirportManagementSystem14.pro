QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RC_ICONS=flight_30822.ico
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addflightdialog.cpp \
    adminloginwindow.cpp \
    apppaths.cpp \
    bookticketdialog.cpp \
    csvinitializer.cpp \
    dashboard.cpp \
    editflightdialog.cpp \
    flightgenerator.cpp \
    flightschedulewindow.cpp \
    flightsearchwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    managebookingsview.cpp \
    manageflightsview.cpp \
    manageusersview.cpp \
    marqueelabel.cpp \
    passenger_bookticket.cpp \
    searchticketwindow.cpp \
    userdialog.cpp \
    usermanagerinitializer.cpp \
    viewbookingsview.cpp

HEADERS += \
    addflightdialog.h \
    adminloginwindow.h \
    apppaths.h \
    bookticketdialog.h \
    csvinitializer.h \
    dashboard.h \
    editflightdialog.h \
    flightgenerator.h \
    flightschedulewindow.h \
    flightsearchwindow.h \
    mainwindow.h \
    managebookingsview.h \
    manageflightsview.h \
    manageusersview.h \
    marqueelabel.h \
    passenger_bookticket.h \
    searchticketwindow.h \
    userdialog.h \
    usermanagerinitializer.h \
    viewbookingsview.h

FORMS += \
    AdminLoginWindow.ui \
    Dashboard.ui \
    EditFlightDialog.ui \
    FlightSearchWindow.ui \
    Passenger_BookTicket.ui \
    addflightdialog.ui \
    bookticketdialog.ui \
    flightschedulewindow.ui \
    mainwindow.ui \
    managebookingsview.ui \
    manageflightsview.ui \
    manageusersview.ui \
    searchticketwindow.ui \
    userdialog.ui \
    viewbookingsview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
