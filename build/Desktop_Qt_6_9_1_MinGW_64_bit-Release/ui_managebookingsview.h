/********************************************************************************
** Form generated from reading UI file 'managebookingsview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEBOOKINGSVIEW_H
#define UI_MANAGEBOOKINGSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageBookingsView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *bookingsTableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *bookTicketButton;
    QPushButton *confirmTicketButton;
    QPushButton *cancelTicketButton;

    void setupUi(QWidget *ManageBookingsView)
    {
        if (ManageBookingsView->objectName().isEmpty())
            ManageBookingsView->setObjectName("ManageBookingsView");
        ManageBookingsView->resize(800, 600);
        verticalLayout = new QVBoxLayout(ManageBookingsView);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ManageBookingsView);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #003366; padding-bottom: 10px;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        bookingsTableWidget = new QTableWidget(ManageBookingsView);
        if (bookingsTableWidget->columnCount() < 7)
            bookingsTableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        bookingsTableWidget->setObjectName("bookingsTableWidget");
        bookingsTableWidget->setAlternatingRowColors(true);
        bookingsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        bookingsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        bookingsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        bookingsTableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(bookingsTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        bookTicketButton = new QPushButton(ManageBookingsView);
        bookTicketButton->setObjectName("bookTicketButton");

        horizontalLayout->addWidget(bookTicketButton);

        confirmTicketButton = new QPushButton(ManageBookingsView);
        confirmTicketButton->setObjectName("confirmTicketButton");

        horizontalLayout->addWidget(confirmTicketButton);

        cancelTicketButton = new QPushButton(ManageBookingsView);
        cancelTicketButton->setObjectName("cancelTicketButton");

        horizontalLayout->addWidget(cancelTicketButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ManageBookingsView);

        QMetaObject::connectSlotsByName(ManageBookingsView);
    } // setupUi

    void retranslateUi(QWidget *ManageBookingsView)
    {
        ManageBookingsView->setWindowTitle(QCoreApplication::translate("ManageBookingsView", "Manage Bookings", nullptr));
        label->setText(QCoreApplication::translate("ManageBookingsView", "Manage Bookings", nullptr));
        QTableWidgetItem *___qtablewidgetitem = bookingsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageBookingsView", "Booking ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = bookingsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageBookingsView", "Flight Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = bookingsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageBookingsView", "Passenger Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = bookingsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManageBookingsView", "Seat Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = bookingsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ManageBookingsView", "Booking Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = bookingsTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ManageBookingsView", "Total Fare", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = bookingsTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ManageBookingsView", "Status", nullptr));
        bookTicketButton->setText(QCoreApplication::translate("ManageBookingsView", "Book New Ticket", nullptr));
        confirmTicketButton->setText(QCoreApplication::translate("ManageBookingsView", "Confirm Ticket", nullptr));
        cancelTicketButton->setText(QCoreApplication::translate("ManageBookingsView", "Cancel Ticket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageBookingsView: public Ui_ManageBookingsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEBOOKINGSVIEW_H
