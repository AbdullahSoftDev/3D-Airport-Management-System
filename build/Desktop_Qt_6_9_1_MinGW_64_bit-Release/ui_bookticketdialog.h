/********************************************************************************
** Form generated from reading UI file 'bookticketdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKTICKETDIALOG_H
#define UI_BOOKTICKETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BookTicketDialog
{
public:
    QLineEdit *flightNumberLineEdit;
    QLineEdit *passengerNameLineEdit;
    QSpinBox *seatsBookedSpinBox;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *flightNumberLabel;
    QLabel *passengerNameLabel;
    QLabel *seatsBookedLabel;
    QLabel *bookingDateTimeLabel;
    QDateEdit *bookingDateTimeEdit;

    void setupUi(QDialog *BookTicketDialog)
    {
        if (BookTicketDialog->objectName().isEmpty())
            BookTicketDialog->setObjectName("BookTicketDialog");
        BookTicketDialog->resize(400, 300);
        flightNumberLineEdit = new QLineEdit(BookTicketDialog);
        flightNumberLineEdit->setObjectName("flightNumberLineEdit");
        flightNumberLineEdit->setGeometry(QRect(240, 80, 121, 20));
        passengerNameLineEdit = new QLineEdit(BookTicketDialog);
        passengerNameLineEdit->setObjectName("passengerNameLineEdit");
        passengerNameLineEdit->setGeometry(QRect(240, 120, 121, 20));
        seatsBookedSpinBox = new QSpinBox(BookTicketDialog);
        seatsBookedSpinBox->setObjectName("seatsBookedSpinBox");
        seatsBookedSpinBox->setGeometry(QRect(300, 170, 61, 22));
        buttonBox = new QDialogButtonBox(BookTicketDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(200, 260, 164, 41));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(BookTicketDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(-20, -70, 461, 391));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_2 = new QLabel(BookTicketDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 20, 271, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:30px"));
        flightNumberLabel = new QLabel(BookTicketDialog);
        flightNumberLabel->setObjectName("flightNumberLabel");
        flightNumberLabel->setGeometry(QRect(20, 80, 151, 20));
        flightNumberLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:15px"));
        passengerNameLabel = new QLabel(BookTicketDialog);
        passengerNameLabel->setObjectName("passengerNameLabel");
        passengerNameLabel->setGeometry(QRect(20, 120, 181, 20));
        passengerNameLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:15px"));
        seatsBookedLabel = new QLabel(BookTicketDialog);
        seatsBookedLabel->setObjectName("seatsBookedLabel");
        seatsBookedLabel->setGeometry(QRect(20, 170, 181, 20));
        seatsBookedLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:15px"));
        bookingDateTimeLabel = new QLabel(BookTicketDialog);
        bookingDateTimeLabel->setObjectName("bookingDateTimeLabel");
        bookingDateTimeLabel->setGeometry(QRect(20, 209, 91, 31));
        bookingDateTimeLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:15px"));
        bookingDateTimeEdit = new QDateEdit(BookTicketDialog);
        bookingDateTimeEdit->setObjectName("bookingDateTimeEdit");
        bookingDateTimeEdit->setGeometry(QRect(240, 220, 121, 21));
        label->raise();
        flightNumberLineEdit->raise();
        passengerNameLineEdit->raise();
        seatsBookedSpinBox->raise();
        buttonBox->raise();
        label_2->raise();
        flightNumberLabel->raise();
        passengerNameLabel->raise();
        seatsBookedLabel->raise();
        bookingDateTimeLabel->raise();
        bookingDateTimeEdit->raise();

        retranslateUi(BookTicketDialog);

        QMetaObject::connectSlotsByName(BookTicketDialog);
    } // setupUi

    void retranslateUi(QDialog *BookTicketDialog)
    {
        BookTicketDialog->setWindowTitle(QCoreApplication::translate("BookTicketDialog", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("BookTicketDialog", "Book New Ticket", nullptr));
        flightNumberLabel->setText(QCoreApplication::translate("BookTicketDialog", "Enter Flight Number:", nullptr));
        passengerNameLabel->setText(QCoreApplication::translate("BookTicketDialog", "Enter Passenger Name:", nullptr));
        seatsBookedLabel->setText(QCoreApplication::translate("BookTicketDialog", "Enter Number Of Seats:", nullptr));
        bookingDateTimeLabel->setText(QCoreApplication::translate("BookTicketDialog", "Enter Date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookTicketDialog: public Ui_BookTicketDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKTICKETDIALOG_H
