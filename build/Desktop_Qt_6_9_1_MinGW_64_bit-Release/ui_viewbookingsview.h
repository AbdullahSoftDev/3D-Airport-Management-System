/********************************************************************************
** Form generated from reading UI file 'viewbookingsview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWBOOKINGSVIEW_H
#define UI_VIEWBOOKINGSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewBookingsView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTableWidget *bookingsTableWidget;

    void setupUi(QWidget *ViewBookingsView)
    {
        if (ViewBookingsView->objectName().isEmpty())
            ViewBookingsView->setObjectName("ViewBookingsView");
        ViewBookingsView->resize(603, 231);
        verticalLayout = new QVBoxLayout(ViewBookingsView);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(ViewBookingsView);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: black;"));

        verticalLayout->addWidget(titleLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        bookingsTableWidget = new QTableWidget(ViewBookingsView);
        if (bookingsTableWidget->columnCount() < 8)
            bookingsTableWidget->setColumnCount(8);
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
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        bookingsTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        bookingsTableWidget->setObjectName("bookingsTableWidget");

        verticalLayout->addWidget(bookingsTableWidget);


        retranslateUi(ViewBookingsView);

        QMetaObject::connectSlotsByName(ViewBookingsView);
    } // setupUi

    void retranslateUi(QWidget *ViewBookingsView)
    {
        ViewBookingsView->setWindowTitle(QCoreApplication::translate("ViewBookingsView", "View Bookings", nullptr));
        titleLabel->setText(QCoreApplication::translate("ViewBookingsView", "All Bookings", nullptr));
        QTableWidgetItem *___qtablewidgetitem = bookingsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ViewBookingsView", "Booking ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = bookingsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ViewBookingsView", "Flight Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = bookingsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ViewBookingsView", "Passenger Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = bookingsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ViewBookingsView", "Contact Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = bookingsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ViewBookingsView", "Booking Date/Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = bookingsTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ViewBookingsView", "Seats Booked", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = bookingsTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ViewBookingsView", "Total Fare", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = bookingsTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ViewBookingsView", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewBookingsView: public Ui_ViewBookingsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWBOOKINGSVIEW_H
