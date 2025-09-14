/********************************************************************************
** Form generated from reading UI file 'addflightdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFLIGHTDIALOG_H
#define UI_ADDFLIGHTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddFlightDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *flightNumberLabel;
    QLineEdit *flightNumberLineEdit;
    QLabel *originLabel;
    QLineEdit *originLineEdit;
    QLabel *destinationLabel;
    QLineEdit *destinationLineEdit;
    QLabel *departureDateLabel;
    QDateEdit *departureDateEdit;
    QLabel *departureTimeLabel;
    QTimeEdit *departureTimeEdit;
    QLabel *arrivalDateLabel;
    QDateEdit *arrivalDateEdit;
    QLabel *arrivalTimeLabel;
    QTimeEdit *arrivalTimeEdit;
    QLabel *fareLabel;
    QLineEdit *fareLineEdit;
    QLabel *availableSeatsLabel;
    QLineEdit *availableSeatsLineEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddFlightDialog)
    {
        if (AddFlightDialog->objectName().isEmpty())
            AddFlightDialog->setObjectName("AddFlightDialog");
        AddFlightDialog->resize(450, 550);
        AddFlightDialog->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;"));
        verticalLayout = new QVBoxLayout(AddFlightDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AddFlightDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: white;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        flightNumberLabel = new QLabel(AddFlightDialog);
        flightNumberLabel->setObjectName("flightNumberLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, flightNumberLabel);

        flightNumberLineEdit = new QLineEdit(AddFlightDialog);
        flightNumberLineEdit->setObjectName("flightNumberLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, flightNumberLineEdit);

        originLabel = new QLabel(AddFlightDialog);
        originLabel->setObjectName("originLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, originLabel);

        originLineEdit = new QLineEdit(AddFlightDialog);
        originLineEdit->setObjectName("originLineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, originLineEdit);

        destinationLabel = new QLabel(AddFlightDialog);
        destinationLabel->setObjectName("destinationLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, destinationLabel);

        destinationLineEdit = new QLineEdit(AddFlightDialog);
        destinationLineEdit->setObjectName("destinationLineEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, destinationLineEdit);

        departureDateLabel = new QLabel(AddFlightDialog);
        departureDateLabel->setObjectName("departureDateLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, departureDateLabel);

        departureDateEdit = new QDateEdit(AddFlightDialog);
        departureDateEdit->setObjectName("departureDateEdit");
        departureDateEdit->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, departureDateEdit);

        departureTimeLabel = new QLabel(AddFlightDialog);
        departureTimeLabel->setObjectName("departureTimeLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, departureTimeLabel);

        departureTimeEdit = new QTimeEdit(AddFlightDialog);
        departureTimeEdit->setObjectName("departureTimeEdit");
        departureTimeEdit->setCalendarPopup(false);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, departureTimeEdit);

        arrivalDateLabel = new QLabel(AddFlightDialog);
        arrivalDateLabel->setObjectName("arrivalDateLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, arrivalDateLabel);

        arrivalDateEdit = new QDateEdit(AddFlightDialog);
        arrivalDateEdit->setObjectName("arrivalDateEdit");
        arrivalDateEdit->setCalendarPopup(true);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, arrivalDateEdit);

        arrivalTimeLabel = new QLabel(AddFlightDialog);
        arrivalTimeLabel->setObjectName("arrivalTimeLabel");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, arrivalTimeLabel);

        arrivalTimeEdit = new QTimeEdit(AddFlightDialog);
        arrivalTimeEdit->setObjectName("arrivalTimeEdit");
        arrivalTimeEdit->setCalendarPopup(false);

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, arrivalTimeEdit);

        fareLabel = new QLabel(AddFlightDialog);
        fareLabel->setObjectName("fareLabel");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, fareLabel);

        fareLineEdit = new QLineEdit(AddFlightDialog);
        fareLineEdit->setObjectName("fareLineEdit");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, fareLineEdit);

        availableSeatsLabel = new QLabel(AddFlightDialog);
        availableSeatsLabel->setObjectName("availableSeatsLabel");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, availableSeatsLabel);

        availableSeatsLineEdit = new QLineEdit(AddFlightDialog);
        availableSeatsLineEdit->setObjectName("availableSeatsLineEdit");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, availableSeatsLineEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AddFlightDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddFlightDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddFlightDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddFlightDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddFlightDialog);
    } // setupUi

    void retranslateUi(QDialog *AddFlightDialog)
    {
        AddFlightDialog->setWindowTitle(QCoreApplication::translate("AddFlightDialog", "Add New Flight", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddFlightDialog", "Enter New Flight Details", nullptr));
        flightNumberLabel->setText(QCoreApplication::translate("AddFlightDialog", "Flight Number:", nullptr));
        originLabel->setText(QCoreApplication::translate("AddFlightDialog", "Origin:", nullptr));
        destinationLabel->setText(QCoreApplication::translate("AddFlightDialog", "Destination:", nullptr));
        departureDateLabel->setText(QCoreApplication::translate("AddFlightDialog", "Departure Date:", nullptr));
        departureTimeLabel->setText(QCoreApplication::translate("AddFlightDialog", "Departure Time:", nullptr));
        arrivalDateLabel->setText(QCoreApplication::translate("AddFlightDialog", "Arrival Date:", nullptr));
        arrivalTimeLabel->setText(QCoreApplication::translate("AddFlightDialog", "Arrival Time:", nullptr));
        fareLabel->setText(QCoreApplication::translate("AddFlightDialog", "Fare:", nullptr));
        fareLineEdit->setPlaceholderText(QCoreApplication::translate("AddFlightDialog", "e.g., 150.00", nullptr));
        availableSeatsLabel->setText(QCoreApplication::translate("AddFlightDialog", "Available Seats:", nullptr));
        availableSeatsLineEdit->setPlaceholderText(QCoreApplication::translate("AddFlightDialog", "e.g., 200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFlightDialog: public Ui_AddFlightDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFLIGHTDIALOG_H
