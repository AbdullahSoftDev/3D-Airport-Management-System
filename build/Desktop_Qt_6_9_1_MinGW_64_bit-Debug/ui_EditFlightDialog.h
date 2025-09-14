/********************************************************************************
** Form generated from reading UI file 'EditFlightDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFLIGHTDIALOG_H
#define UI_EDITFLIGHTDIALOG_H

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

class Ui_EditFlightDialog
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

    void setupUi(QDialog *EditFlightDialog)
    {
        if (EditFlightDialog->objectName().isEmpty())
            EditFlightDialog->setObjectName("EditFlightDialog");
        EditFlightDialog->resize(450, 550);
        EditFlightDialog->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;"));
        verticalLayout = new QVBoxLayout(EditFlightDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(EditFlightDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: white;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        flightNumberLabel = new QLabel(EditFlightDialog);
        flightNumberLabel->setObjectName("flightNumberLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, flightNumberLabel);

        flightNumberLineEdit = new QLineEdit(EditFlightDialog);
        flightNumberLineEdit->setObjectName("flightNumberLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, flightNumberLineEdit);

        originLabel = new QLabel(EditFlightDialog);
        originLabel->setObjectName("originLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, originLabel);

        originLineEdit = new QLineEdit(EditFlightDialog);
        originLineEdit->setObjectName("originLineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, originLineEdit);

        destinationLabel = new QLabel(EditFlightDialog);
        destinationLabel->setObjectName("destinationLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, destinationLabel);

        destinationLineEdit = new QLineEdit(EditFlightDialog);
        destinationLineEdit->setObjectName("destinationLineEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, destinationLineEdit);

        departureDateLabel = new QLabel(EditFlightDialog);
        departureDateLabel->setObjectName("departureDateLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, departureDateLabel);

        departureDateEdit = new QDateEdit(EditFlightDialog);
        departureDateEdit->setObjectName("departureDateEdit");
        departureDateEdit->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, departureDateEdit);

        departureTimeLabel = new QLabel(EditFlightDialog);
        departureTimeLabel->setObjectName("departureTimeLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, departureTimeLabel);

        departureTimeEdit = new QTimeEdit(EditFlightDialog);
        departureTimeEdit->setObjectName("departureTimeEdit");
        departureTimeEdit->setCalendarPopup(false);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, departureTimeEdit);

        arrivalDateLabel = new QLabel(EditFlightDialog);
        arrivalDateLabel->setObjectName("arrivalDateLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, arrivalDateLabel);

        arrivalDateEdit = new QDateEdit(EditFlightDialog);
        arrivalDateEdit->setObjectName("arrivalDateEdit");
        arrivalDateEdit->setCalendarPopup(true);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, arrivalDateEdit);

        arrivalTimeLabel = new QLabel(EditFlightDialog);
        arrivalTimeLabel->setObjectName("arrivalTimeLabel");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, arrivalTimeLabel);

        arrivalTimeEdit = new QTimeEdit(EditFlightDialog);
        arrivalTimeEdit->setObjectName("arrivalTimeEdit");
        arrivalTimeEdit->setCalendarPopup(false);

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, arrivalTimeEdit);

        fareLabel = new QLabel(EditFlightDialog);
        fareLabel->setObjectName("fareLabel");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, fareLabel);

        fareLineEdit = new QLineEdit(EditFlightDialog);
        fareLineEdit->setObjectName("fareLineEdit");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, fareLineEdit);

        availableSeatsLabel = new QLabel(EditFlightDialog);
        availableSeatsLabel->setObjectName("availableSeatsLabel");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, availableSeatsLabel);

        availableSeatsLineEdit = new QLineEdit(EditFlightDialog);
        availableSeatsLineEdit->setObjectName("availableSeatsLineEdit");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, availableSeatsLineEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(EditFlightDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(EditFlightDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditFlightDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditFlightDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditFlightDialog);
    } // setupUi

    void retranslateUi(QDialog *EditFlightDialog)
    {
        EditFlightDialog->setWindowTitle(QCoreApplication::translate("EditFlightDialog", "Edit Flight Details", nullptr));
        titleLabel->setText(QCoreApplication::translate("EditFlightDialog", "Edit Flight Details", nullptr));
        flightNumberLabel->setText(QCoreApplication::translate("EditFlightDialog", "Flight Number:", nullptr));
        originLabel->setText(QCoreApplication::translate("EditFlightDialog", "Origin:", nullptr));
        destinationLabel->setText(QCoreApplication::translate("EditFlightDialog", "Destination:", nullptr));
        departureDateLabel->setText(QCoreApplication::translate("EditFlightDialog", "Departure Date:", nullptr));
        departureTimeLabel->setText(QCoreApplication::translate("EditFlightDialog", "Departure Time:", nullptr));
        arrivalDateLabel->setText(QCoreApplication::translate("EditFlightDialog", "Arrival Date:", nullptr));
        arrivalTimeLabel->setText(QCoreApplication::translate("EditFlightDialog", "Arrival Time:", nullptr));
        fareLabel->setText(QCoreApplication::translate("EditFlightDialog", "Fare:", nullptr));
        fareLineEdit->setPlaceholderText(QCoreApplication::translate("EditFlightDialog", "e.g., 150.00", nullptr));
        availableSeatsLabel->setText(QCoreApplication::translate("EditFlightDialog", "Available Seats:", nullptr));
        availableSeatsLineEdit->setPlaceholderText(QCoreApplication::translate("EditFlightDialog", "e.g., 200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditFlightDialog: public Ui_EditFlightDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITFLIGHTDIALOG_H
