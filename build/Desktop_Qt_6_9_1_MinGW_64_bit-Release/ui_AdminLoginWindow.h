/********************************************************************************
** Form generated from reading UI file 'AdminLoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGINWINDOW_H
#define UI_ADMINLOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminLoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QLabel *statusLabel;
    QPushButton *loginButton;
    QPushButton *forgotPasswordButton;
    QPushButton *backButton;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *AdminLoginWindow)
    {
        if (AdminLoginWindow->objectName().isEmpty())
            AdminLoginWindow->setObjectName("AdminLoginWindow");
        AdminLoginWindow->resize(1523, 798);
        AdminLoginWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(AdminLoginWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1741, 901));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(250, 130, 775, 291));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #333;"));

        verticalLayout->addWidget(label);

        usernameLineEdit = new QLineEdit(layoutWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #ccc; border-radius: 5px; padding: 10px; color: #333;"));

        verticalLayout->addWidget(usernameLineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #333;"));

        verticalLayout->addWidget(label_2);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #ccc; border-radius: 5px; padding: 10px; color: #333;"));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordLineEdit);

        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #333;"));

        verticalLayout->addWidget(statusLabel);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #ccc;\n"
"     color: black;\n"
"     background-color: white;\n"
"     border-radius: 5px;\n"
"     padding: 10px;\n"
"     font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"     background-color: rgb(85, 170, 255);\n"
"     color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"     background-color: rgb(85, 170, 255);\n"
"}"));

        verticalLayout->addWidget(loginButton);

        forgotPasswordButton = new QPushButton(layoutWidget);
        forgotPasswordButton->setObjectName("forgotPasswordButton");
        forgotPasswordButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #ccc;\n"
"     color: black;\n"
"     background-color: white;\n"
"     border-radius: 5px;\n"
"     padding: 10px;\n"
"     font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"     background-color: #dc3545;\n"
"     color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"     background-color: #dc3545;\n"
"}"));

        verticalLayout->addWidget(forgotPasswordButton);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName("backButton");
        backButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #ccc;\n"
"     background-color: white;\n"
"     color: black;\n"
"     border-radius: 5px;\n"
"     padding: 10px;\n"
"     font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"     background-color: black;\n"
"     color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"     background-color: black;\n"
"}"));

        verticalLayout->addWidget(backButton);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 30, 851, 81));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 60px;\n"
"color:black;\n"
"font-weight:bold;"));
        menubar = new QMenuBar(AdminLoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 17));
        statusbar = new QStatusBar(AdminLoginWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 20, 22));

        retranslateUi(AdminLoginWindow);

        QMetaObject::connectSlotsByName(AdminLoginWindow);
    } // setupUi

    void retranslateUi(QWidget *AdminLoginWindow)
    {
        AdminLoginWindow->setWindowTitle(QCoreApplication::translate("AdminLoginWindow", "Admin Login", nullptr));
        label->setText(QCoreApplication::translate("AdminLoginWindow", "Username:", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("AdminLoginWindow", "Enter Your Username", nullptr));
        label_2->setText(QCoreApplication::translate("AdminLoginWindow", "Password:", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("AdminLoginWindow", "Enter Your Password", nullptr));
        statusLabel->setText(QCoreApplication::translate("AdminLoginWindow", "Status:", nullptr));
        loginButton->setText(QCoreApplication::translate("AdminLoginWindow", "Login", nullptr));
        forgotPasswordButton->setText(QCoreApplication::translate("AdminLoginWindow", "Forgot Password?", nullptr));
        backButton->setText(QCoreApplication::translate("AdminLoginWindow", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("AdminLoginWindow", "      Dear Admin Please Login!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminLoginWindow: public Ui_AdminLoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGINWINDOW_H
