/********************************************************************************
** Form generated from reading UI file 'manageflightsview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEFLIGHTSVIEW_H
#define UI_MANAGEFLIGHTSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageFlightsView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTableWidget *flightsTableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_left;
    QPushButton *addFlightButton;
    QPushButton *editFlightButton;
    QPushButton *deleteFlightButton;
    QSpacerItem *horizontalSpacer_right;

    void setupUi(QWidget *ManageFlightsView)
    {
        if (ManageFlightsView->objectName().isEmpty())
            ManageFlightsView->setObjectName("ManageFlightsView");
        ManageFlightsView->resize(800, 600);
        verticalLayout = new QVBoxLayout(ManageFlightsView);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(ManageFlightsView);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: black;"));

        verticalLayout->addWidget(titleLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        flightsTableWidget = new QTableWidget(ManageFlightsView);
        if (flightsTableWidget->columnCount() < 9)
            flightsTableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        flightsTableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        flightsTableWidget->setObjectName("flightsTableWidget");

        verticalLayout->addWidget(flightsTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_left);

        addFlightButton = new QPushButton(ManageFlightsView);
        addFlightButton->setObjectName("addFlightButton");

        horizontalLayout->addWidget(addFlightButton);

        editFlightButton = new QPushButton(ManageFlightsView);
        editFlightButton->setObjectName("editFlightButton");

        horizontalLayout->addWidget(editFlightButton);

        deleteFlightButton = new QPushButton(ManageFlightsView);
        deleteFlightButton->setObjectName("deleteFlightButton");

        horizontalLayout->addWidget(deleteFlightButton);

        horizontalSpacer_right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_right);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ManageFlightsView);

        QMetaObject::connectSlotsByName(ManageFlightsView);
    } // setupUi

    void retranslateUi(QWidget *ManageFlightsView)
    {
        ManageFlightsView->setWindowTitle(QCoreApplication::translate("ManageFlightsView", "Manage Flights", nullptr));
        titleLabel->setText(QCoreApplication::translate("ManageFlightsView", "Manage Flight Schedules", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flightsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageFlightsView", "Flight Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flightsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageFlightsView", "Origin", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = flightsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageFlightsView", "Destination", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = flightsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManageFlightsView", "Departure Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = flightsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ManageFlightsView", "Departure Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = flightsTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ManageFlightsView", "Arrival Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = flightsTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ManageFlightsView", "Arrival Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = flightsTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ManageFlightsView", "Available Seats", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = flightsTableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ManageFlightsView", "Fare", nullptr));
        addFlightButton->setText(QCoreApplication::translate("ManageFlightsView", "Add Flight", nullptr));
        editFlightButton->setText(QCoreApplication::translate("ManageFlightsView", "Edit Flight", nullptr));
        deleteFlightButton->setText(QCoreApplication::translate("ManageFlightsView", "Delete Flight", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageFlightsView: public Ui_ManageFlightsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEFLIGHTSVIEW_H
