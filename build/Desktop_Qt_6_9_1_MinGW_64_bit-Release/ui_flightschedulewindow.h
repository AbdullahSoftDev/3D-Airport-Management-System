/********************************************************************************
** Form generated from reading UI file 'flightschedulewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTSCHEDULEWINDOW_H
#define UI_FLIGHTSCHEDULEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightScheduleWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *scheduleTableWidget;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *FlightScheduleWindow)
    {
        if (FlightScheduleWindow->objectName().isEmpty())
            FlightScheduleWindow->setObjectName("FlightScheduleWindow");
        FlightScheduleWindow->resize(1201, 627);
        centralwidget = new QWidget(FlightScheduleWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(140, 50, 791, 521));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size: 50px;\n"
"color:black;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(label);

        scheduleTableWidget = new QTableWidget(centralwidget);
        scheduleTableWidget->setObjectName("scheduleTableWidget");

        verticalLayout->addWidget(scheduleTableWidget);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);

        menubar = new QMenuBar(FlightScheduleWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        statusbar = new QStatusBar(FlightScheduleWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(FlightScheduleWindow);

        QMetaObject::connectSlotsByName(FlightScheduleWindow);
    } // setupUi

    void retranslateUi(QWidget *FlightScheduleWindow)
    {
        FlightScheduleWindow->setWindowTitle(QCoreApplication::translate("FlightScheduleWindow", "Flight Schedule", nullptr));
        label->setText(QCoreApplication::translate("FlightScheduleWindow", "      Weekly Flights Schedule!", nullptr));
        backButton->setText(QCoreApplication::translate("FlightScheduleWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightScheduleWindow: public Ui_FlightScheduleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTSCHEDULEWINDOW_H
