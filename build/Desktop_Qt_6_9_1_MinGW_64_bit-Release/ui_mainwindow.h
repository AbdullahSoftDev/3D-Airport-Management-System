/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *searchTicketButton;
    QPushButton *flightSearchButton;
    QPushButton *flightScheduleButton;
    QPushButton *passengerBookTicketButton;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1291, 718);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(-10, -80, 1501, 881));
        centralwidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-370, 50, 841, 921));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"        background-color: rgb(85, 170, 255);\n"
"    color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 120, 451, 61));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:45px;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 270, 451, 91));
        label_4->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-weight:bold;\n"
"font-size:42px;\n"
"background-color: transparent;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(210, 180, 171, 71));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:45px;"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(-60, 280, 531, 80));
        label_7->setMinimumSize(QSize(80, 80));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 1px solid black; /* Outline of the circle */\n"
"    border-radius: 40px; /* Half of the width/height (80px / 2 = 40px) */\n"
"    background-color: white; /* No fill */\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(750, -60, 521, 501));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/airbus.png")));
        label_6->setScaledContents(true);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(970, 660, 431, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 255, 255); /* Initial text color: White */\n"
"	font-weight:bold;\n"
"    font-size: 40px;\n"
"    border-radius: 30px;\n"
"    background-color: rgb(85, 170, 255); /* Initial background color: Blue */\n"
"    border: 1px solid black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(85, 170, 255); /* Text color on hover: Blue (the initial background color) */\n"
"    background-color: rgb(255, 255, 255); /* Background color on hover: White */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    color: rgb(255, 255, 255); /* Initial text color: White */\n"
"    background-color: rgb(85, 170, 255); /* Initial background color: Blue */\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(1401, 600, 20, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(255, 255, 255); /* Initial text color: White */\n"
"	font-weight:bold;\n"
"    font-size: 40px;\n"
"    border-radius: 30px;\n"
"    background-color: rgb(85, 170, 255); /* Initial background color: Blue */\n"
"    border: 1px solid black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(85, 170, 255); /* Text color on hover: Blue (the initial background color) */\n"
"    background-color: rgb(255, 255, 255); /* Background color on hover: White */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    color: rgb(255, 255, 255); /* Initial text color: White */\n"
"    background-color: rgb(85, 170, 255); /* Initial background color: Blue */\n"
"}"));
        searchTicketButton = new QPushButton(centralwidget);
        searchTicketButton->setObjectName("searchTicketButton");
        searchTicketButton->setGeometry(QRect(60, 390, 541, 71));
        searchTicketButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 30px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Key property: This makes the corners rounded. */\n"
"                             /* For a perfect circle, set this to half of the button's smallest dimension (width or height). */\n"
"                             /* For example, if your button is 60x60px, border-radius: 30px; will make it a circle. */\n"
"                             /* If it's a perfect square button, you can also use border-radius: 50%; */\n"
"\n"
"    /* Optional: Add a subtle box-shadow for depth, as we discussed for labels */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
"}"));
        flightSearchButton = new QPushButton(centralwidget);
        flightSearchButton->setObjectName("flightSearchButton");
        flightSearchButton->setGeometry(QRect(60, 630, 541, 71));
        flightSearchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 30px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Key property: This makes the corners rounded. */\n"
"                             /* For a perfect circle, set this to half of the button's smallest dimension (width or height). */\n"
"                             /* For example, if your button is 60x60px, border-radius: 30px; will make it a circle. */\n"
"                             /* If it's a perfect square button, you can also use border-radius: 50%; */\n"
"\n"
"    /* Optional: Add a subtle box-shadow for depth, as we discussed for labels */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
"}"));
        flightScheduleButton = new QPushButton(centralwidget);
        flightScheduleButton->setObjectName("flightScheduleButton");
        flightScheduleButton->setGeometry(QRect(60, 550, 541, 71));
        flightScheduleButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 9pt \"Segoe UI\";\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 30px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Key property: This makes the corners rounded. */\n"
"                             /* For a perfect circle, set this to half of the button's smallest dimension (width or height). */\n"
"                             /* For example, if your button is 60x60px, border-radius: 30px; will make it a circle. */\n"
"                             /* If it's a perfect square button, you can also use border-radius: 50%; */\n"
"\n"
"    /* Optional: Add a subtle box-shadow for depth, as we discussed for labels */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
"}"));
        passengerBookTicketButton = new QPushButton(centralwidget);
        passengerBookTicketButton->setObjectName("passengerBookTicketButton");
        passengerBookTicketButton->setGeometry(QRect(60, 470, 541, 71));
        passengerBookTicketButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size:30px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Key property: This makes the corners rounded. */\n"
"                             /* For a perfect circle, set this to half of the button's smallest dimension (width or height). */\n"
"                             /* For example, if your button is 60x60px, border-radius: 30px; will make it a circle. */\n"
"                             /* If it's a perfect square button, you can also use border-radius: 50%; */\n"
"\n"
"    /* Optional: Add a subtle box-shadow for depth, as we discussed for labels */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(470, 70, 1061, 751));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"border-color: rgb(0, 0, 0);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(470, 170, 961, 661));
        label_8->setStyleSheet(QString::fromUtf8(""));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/images/resources/an_airport_with_no_airplanes_just_atc.jpeg")));
        label_8->setScaledContents(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(790, 150, 481, 401));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/images/resources/airbus.png")));
        label_9->setScaledContents(true);
        label_6->raise();
        label_2->raise();
        label->raise();
        label_5->raise();
        label_7->raise();
        label_4->raise();
        searchTicketButton->raise();
        flightSearchButton->raise();
        flightScheduleButton->raise();
        passengerBookTicketButton->raise();
        label_3->raise();
        pushButton_9->raise();
        label_8->raise();
        pushButton_8->raise();
        label_9->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1291, 17));
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 20, 22));
        menubar->raise();
        statusbar->raise();
        centralwidget->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Airport Management System", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Airport Management ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Passenger Dashboard", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "System", nullptr));
        label_7->setText(QString());
        label_6->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", " Admin Login       ", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", " Flight Manager Login          ", nullptr));
        searchTicketButton->setText(QCoreApplication::translate("MainWindow", "Search Ticket                             ", nullptr));
        flightSearchButton->setText(QCoreApplication::translate("MainWindow", "Search Flight                             ", nullptr));
        flightScheduleButton->setText(QCoreApplication::translate("MainWindow", "Flight Schedule                             ", nullptr));
        passengerBookTicketButton->setText(QCoreApplication::translate("MainWindow", "Book Ticket                             ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
