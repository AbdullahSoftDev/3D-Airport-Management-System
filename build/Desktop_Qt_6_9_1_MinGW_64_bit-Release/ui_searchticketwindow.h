/********************************************************************************
** Form generated from reading UI file 'searchticketwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHTICKETWINDOW_H
#define UI_SEARCHTICKETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchTicketWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_passengerName;
    QLineEdit *passengerNameSearchLineEdit;
    QLabel *label_bookingId;
    QLineEdit *bookingIdSearchLineEdit;
    QDateEdit *bookingDateSearchDateEdit;
    QPushButton *searchButton;
    QTableWidget *ticketsTableWidget;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *SearchTicketWindow)
    {
        if (SearchTicketWindow->objectName().isEmpty())
            SearchTicketWindow->setObjectName("SearchTicketWindow");
        SearchTicketWindow->resize(1304, 800);
        centralwidget = new QWidget(SearchTicketWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 20, 1301, 761));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(120, 0, 931, 501));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size: 50px;\n"
"color:black;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(label);

        label_passengerName = new QLabel(verticalLayoutWidget);
        label_passengerName->setObjectName("label_passengerName");
        label_passengerName->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label_passengerName);

        passengerNameSearchLineEdit = new QLineEdit(verticalLayoutWidget);
        passengerNameSearchLineEdit->setObjectName("passengerNameSearchLineEdit");
        passengerNameSearchLineEdit->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(passengerNameSearchLineEdit);

        label_bookingId = new QLabel(verticalLayoutWidget);
        label_bookingId->setObjectName("label_bookingId");

        verticalLayout->addWidget(label_bookingId);

        bookingIdSearchLineEdit = new QLineEdit(verticalLayoutWidget);
        bookingIdSearchLineEdit->setObjectName("bookingIdSearchLineEdit");

        verticalLayout->addWidget(bookingIdSearchLineEdit);

        bookingDateSearchDateEdit = new QDateEdit(verticalLayoutWidget);
        bookingDateSearchDateEdit->setObjectName("bookingDateSearchDateEdit");

        verticalLayout->addWidget(bookingDateSearchDateEdit);

        searchButton = new QPushButton(verticalLayoutWidget);
        searchButton->setObjectName("searchButton");

        verticalLayout->addWidget(searchButton);

        ticketsTableWidget = new QTableWidget(verticalLayoutWidget);
        ticketsTableWidget->setObjectName("ticketsTableWidget");
        ticketsTableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(ticketsTableWidget);

        backButton = new QPushButton(verticalLayoutWidget);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);

        menubar = new QMenuBar(SearchTicketWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        statusbar = new QStatusBar(SearchTicketWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 20, 22));

        retranslateUi(SearchTicketWindow);

        QMetaObject::connectSlotsByName(SearchTicketWindow);
    } // setupUi

    void retranslateUi(QWidget *SearchTicketWindow)
    {
        SearchTicketWindow->setWindowTitle(QCoreApplication::translate("SearchTicketWindow", "Search Tickets", nullptr));
        label->setText(QCoreApplication::translate("SearchTicketWindow", "            Search Your Ticket Here!", nullptr));
        label_passengerName->setText(QCoreApplication::translate("SearchTicketWindow", "Passenger Name:", nullptr));
        passengerNameSearchLineEdit->setPlaceholderText(QCoreApplication::translate("SearchTicketWindow", "Enter Passenger Name", nullptr));
        label_bookingId->setText(QCoreApplication::translate("SearchTicketWindow", "Booking ID:", nullptr));
        bookingIdSearchLineEdit->setPlaceholderText(QCoreApplication::translate("SearchTicketWindow", "Enter Booking ID", nullptr));
        searchButton->setText(QCoreApplication::translate("SearchTicketWindow", "Search", nullptr));
        backButton->setText(QCoreApplication::translate("SearchTicketWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchTicketWindow: public Ui_SearchTicketWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHTICKETWINDOW_H
