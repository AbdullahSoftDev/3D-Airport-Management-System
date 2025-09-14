/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName("UserDialog");
        UserDialog->resize(350, 150);
        UserDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(UserDialog);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        usernameLabel = new QLabel(UserDialog);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        gridLayout->addWidget(usernameLabel, 0, 0, 1, 1);

        usernameLineEdit = new QLineEdit(UserDialog);
        usernameLineEdit->setObjectName("usernameLineEdit");

        gridLayout->addWidget(usernameLineEdit, 0, 1, 1, 1);

        passwordLabel = new QLabel(UserDialog);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        gridLayout->addWidget(passwordLabel, 1, 0, 1, 1);

        passwordLineEdit = new QLineEdit(UserDialog);
        passwordLineEdit->setObjectName("passwordLineEdit");

        gridLayout->addWidget(passwordLineEdit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(UserDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(UserDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), UserDialog, SLOT(on_buttonBox_accepted()));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, UserDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QCoreApplication::translate("UserDialog", "User Details", nullptr));
        usernameLabel->setText(QCoreApplication::translate("UserDialog", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("UserDialog", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H
