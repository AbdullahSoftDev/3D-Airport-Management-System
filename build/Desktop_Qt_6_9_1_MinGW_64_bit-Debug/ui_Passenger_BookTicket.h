/********************************************************************************
** Form generated from reading UI file 'Passenger_BookTicket.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGER_BOOKTICKET_H
#define UI_PASSENGER_BOOKTICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passenger_BookTicket
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *passengerNameLineEdit_Passenger;
    QLabel *label;
    QSpinBox *numTicketsSpinBox_Passenger;
    QLabel *label_3;
    QDateEdit *flightDateSelection_Passenger;
    QPushButton *bookTicketButton_Passenger;
    QPushButton *backButton_Passenger;
    QTableWidget *availableFlightsTableWidget_Passenger;
    QTableWidget *Showselectedflight;
    QPushButton *pushButton_8;
    QStatusBar *statusbar;

    void setupUi(QWidget *Passenger_BookTicket)
    {
        if (Passenger_BookTicket->objectName().isEmpty())
            Passenger_BookTicket->setObjectName("Passenger_BookTicket");
        Passenger_BookTicket->resize(1426, 698);
        centralwidget = new QWidget(Passenger_BookTicket);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1461, 691));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(690, 160, 581, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passengerNameLineEdit_Passenger = new QLineEdit(layoutWidget);
        passengerNameLineEdit_Passenger->setObjectName("passengerNameLineEdit_Passenger");

        verticalLayout->addWidget(passengerNameLineEdit_Passenger);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        numTicketsSpinBox_Passenger = new QSpinBox(layoutWidget);
        numTicketsSpinBox_Passenger->setObjectName("numTicketsSpinBox_Passenger");
        numTicketsSpinBox_Passenger->setMinimum(1);

        verticalLayout->addWidget(numTicketsSpinBox_Passenger);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        flightDateSelection_Passenger = new QDateEdit(layoutWidget);
        flightDateSelection_Passenger->setObjectName("flightDateSelection_Passenger");
        flightDateSelection_Passenger->setCalendarPopup(true);

        verticalLayout->addWidget(flightDateSelection_Passenger);

        bookTicketButton_Passenger = new QPushButton(layoutWidget);
        bookTicketButton_Passenger->setObjectName("bookTicketButton_Passenger");

        verticalLayout->addWidget(bookTicketButton_Passenger);

        backButton_Passenger = new QPushButton(layoutWidget);
        backButton_Passenger->setObjectName("backButton_Passenger");

        verticalLayout->addWidget(backButton_Passenger);

        availableFlightsTableWidget_Passenger = new QTableWidget(centralwidget);
        availableFlightsTableWidget_Passenger->setObjectName("availableFlightsTableWidget_Passenger");
        availableFlightsTableWidget_Passenger->setGeometry(QRect(10, 10, 661, 611));
        availableFlightsTableWidget_Passenger->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Showselectedflight = new QTableWidget(centralwidget);
        Showselectedflight->setObjectName("Showselectedflight");
        Showselectedflight->setGeometry(QRect(690, 390, 581, 81));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(680, 90, 601, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-weight: bold;   /* Makes the text bold */\n"
"    font-size: 45px;     /* Adjust the size as needed, e.g., 16px, 20px */\n"
"    color: BLACK; \n"
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
        statusbar = new QStatusBar(Passenger_BookTicket);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(Passenger_BookTicket);

        QMetaObject::connectSlotsByName(Passenger_BookTicket);
    } // setupUi

    void retranslateUi(QWidget *Passenger_BookTicket)
    {
        Passenger_BookTicket->setWindowTitle(QCoreApplication::translate("Passenger_BookTicket", "Book Ticket", nullptr));
        label_2->setText(QCoreApplication::translate("Passenger_BookTicket", "Enter Your Name:", nullptr));
        label->setText(QCoreApplication::translate("Passenger_BookTicket", "Enter Number of tickets:", nullptr));
        label_3->setText(QCoreApplication::translate("Passenger_BookTicket", "Enter Date:", nullptr));
        bookTicketButton_Passenger->setText(QCoreApplication::translate("Passenger_BookTicket", "Book", nullptr));
        backButton_Passenger->setText(QCoreApplication::translate("Passenger_BookTicket", "Back", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Passenger_BookTicket", "BOOK YOUR TICKET HERE!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passenger_BookTicket: public Ui_Passenger_BookTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGER_BOOKTICKET_H
