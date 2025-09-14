/********************************************************************************
** Form generated from reading UI file 'FlightSearchWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTSEARCHWINDOW_H
#define UI_FLIGHTSEARCHWINDOW_H

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

class Ui_FlightSearchWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *originLineEdit;
    QLabel *label_2;
    QLineEdit *destinationLineEdit;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QPushButton *searchButton;
    QTableWidget *flightsTableWidget;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *FlightSearchWindow)
    {
        if (FlightSearchWindow->objectName().isEmpty())
            FlightSearchWindow->setObjectName("FlightSearchWindow");
        FlightSearchWindow->resize(1086, 734);
        centralwidget = new QWidget(FlightSearchWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1141, 701));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(190, 40, 801, 561));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font-size: 50px;\n"
"color:black;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(label_4);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        originLineEdit = new QLineEdit(layoutWidget);
        originLineEdit->setObjectName("originLineEdit");

        verticalLayout->addWidget(originLineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        destinationLineEdit = new QLineEdit(layoutWidget);
        destinationLineEdit->setObjectName("destinationLineEdit");

        verticalLayout->addWidget(destinationLineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        verticalLayout->addWidget(dateEdit);

        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName("searchButton");

        verticalLayout->addWidget(searchButton);

        flightsTableWidget = new QTableWidget(layoutWidget);
        flightsTableWidget->setObjectName("flightsTableWidget");

        verticalLayout->addWidget(flightsTableWidget);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);

        menubar = new QMenuBar(FlightSearchWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        statusbar = new QStatusBar(FlightSearchWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 20, 22));

        retranslateUi(FlightSearchWindow);

        QMetaObject::connectSlotsByName(FlightSearchWindow);
    } // setupUi

    void retranslateUi(QWidget *FlightSearchWindow)
    {
        FlightSearchWindow->setWindowTitle(QCoreApplication::translate("FlightSearchWindow", "Search Available Flights", nullptr));
        label_4->setText(QCoreApplication::translate("FlightSearchWindow", " Search Your Desired Flight Here!", nullptr));
        label->setText(QCoreApplication::translate("FlightSearchWindow", "Origin:", nullptr));
        label_2->setText(QCoreApplication::translate("FlightSearchWindow", "Destination:", nullptr));
        label_3->setText(QCoreApplication::translate("FlightSearchWindow", "Departure Date:", nullptr));
        searchButton->setText(QCoreApplication::translate("FlightSearchWindow", "Search Flights", nullptr));
        backButton->setText(QCoreApplication::translate("FlightSearchWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightSearchWindow: public Ui_FlightSearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTSEARCHWINDOW_H
