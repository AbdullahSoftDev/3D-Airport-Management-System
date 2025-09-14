/********************************************************************************
** Form generated from reading UI file 'Dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QLabel *dashboardTitleLabel;
    QLabel *label;
    QPushButton *viewBookingsButton;
    QPushButton *manageFlightsButton;
    QPushButton *manageUsersButton;
    QPushButton *manageBookingsButton;
    QPushButton *reportsButton;
    QPushButton *logoutButton;
    QStackedWidget *stackedWidget;
    QWidget *defaultPage;
    QVBoxLayout *defaultPageLayout;
    QSpacerItem *verticalSpacer_default_top;
    QLabel *welcomeLabel;
    QSpacerItem *verticalSpacer_default_bottom;
    QLabel *label_2;
    QPushButton *pushButton_8;

    void setupUi(QWidget *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1787, 877);
        dashboardTitleLabel = new QLabel(Dashboard);
        dashboardTitleLabel->setObjectName("dashboardTitleLabel");
        dashboardTitleLabel->setGeometry(QRect(20, 10, 481, 121));
        dashboardTitleLabel->setStyleSheet(QString::fromUtf8("font-size:55px; \n"
"font-weight: bold;\n"
"color:white;"));
        label = new QLabel(Dashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(-1390, -110, 1921, 1091));
        label->setStyleSheet(QString::fromUtf8("color: rgb(253, 88, 0);\n"
"background-color: rgb(253, 88, 0);"));
        viewBookingsButton = new QPushButton(Dashboard);
        viewBookingsButton->setObjectName("viewBookingsButton");
        viewBookingsButton->setGeometry(QRect(60, 250, 541, 71));
        viewBookingsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 24px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Rounded corners */\n"
"    padding: 15px 30px;      /* Add padding for better appearance */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Subtle box-shadow (note: QSS might interpret this differently than web CSS) */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #F8F8F8; /* Slightly off-white background on hover */\n"
"    border: 1px solid black;   /* Black border on hover */\n"
"    border-radius: 30px;       /* Keep border-radius same to maintain circular shape */\n"
"    box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3); /* Slightly more pronounced shadow on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E0E0E0; /* Darker background when pressed */\n"
""
                        "    box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.2); /* Smaller shadow when pressed */\n"
"}"));
        manageFlightsButton = new QPushButton(Dashboard);
        manageFlightsButton->setObjectName("manageFlightsButton");
        manageFlightsButton->setGeometry(QRect(60, 330, 541, 71));
        manageFlightsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 24px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Rounded corners */\n"
"    padding: 15px 30px;      /* Add padding for better appearance */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Subtle box-shadow (note: QSS might interpret this differently than web CSS) */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #F8F8F8; /* Slightly off-white background on hover */\n"
"    border: 1px solid black;   /* Black border on hover */\n"
"    border-radius: 30px;       /* Keep border-radius same to maintain circular shape */\n"
"    box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3); /* Slightly more pronounced shadow on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E0E0E0; /* Darker background when pressed */\n"
""
                        "    box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.2); /* Smaller shadow when pressed */\n"
"}"));
        manageUsersButton = new QPushButton(Dashboard);
        manageUsersButton->setObjectName("manageUsersButton");
        manageUsersButton->setGeometry(QRect(60, 410, 541, 71));
        manageUsersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 24px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Rounded corners */\n"
"    padding: 15px 30px;      /* Add padding for better appearance */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Subtle box-shadow (note: QSS might interpret this differently than web CSS) */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #F8F8F8; /* Slightly off-white background on hover */\n"
"    border: 1px solid black;   /* Black border on hover */\n"
"    border-radius: 30px;       /* Keep border-radius same to maintain circular shape */\n"
"    box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3); /* Slightly more pronounced shadow on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E0E0E0; /* Darker background when pressed */\n"
""
                        "    box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.2); /* Smaller shadow when pressed */\n"
"}"));
        manageBookingsButton = new QPushButton(Dashboard);
        manageBookingsButton->setObjectName("manageBookingsButton");
        manageBookingsButton->setGeometry(QRect(60, 170, 541, 71));
        manageBookingsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 24px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Rounded corners */\n"
"    padding: 15px 30px;      /* Add padding for better appearance */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Subtle box-shadow (note: QSS might interpret this differently than web CSS) */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #F8F8F8; /* Slightly off-white background on hover */\n"
"    border: 1px solid black;   /* Black border on hover */\n"
"    border-radius: 30px;       /* Keep border-radius same to maintain circular shape */\n"
"    box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3); /* Slightly more pronounced shadow on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E0E0E0; /* Darker background when pressed */\n"
""
                        "    box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.2); /* Smaller shadow when pressed */\n"
"}"));
        reportsButton = new QPushButton(Dashboard);
        reportsButton->setObjectName("reportsButton");
        reportsButton->setGeometry(QRect(670, 630, 541, 71));
        reportsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 24px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Key property: This makes the corners rounded. */\n"
"                             /* For a perfect circle, set this to half of the button's smallest dimension (width or height). */\n"
"                             /* For example, if your button is 60x60px, border-radius: 30px; will make it a circle. */\n"
"                             /* If it's a perfect square button, you can also use border-radius: 50%; */\n"
"\n"
"    /* Optional: Add a subtle box-shadow for depth, as we discussed for labels */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2);\n"
"}"));
        logoutButton = new QPushButton(Dashboard);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(60, 490, 551, 71));
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;            /* Text color */\n"
"    border: 1px solid #ccc;  /* Border style */\n"
"    font-size: 24px;         /* Font size */\n"
"    background-color: white; /* Background color of the button */\n"
"    font-weight: bold;       /* Bold font */\n"
"    border-radius: 30px;     /* Rounded corners */\n"
"    padding: 15px 30px;      /* Add padding for better appearance */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Subtle box-shadow (note: QSS might interpret this differently than web CSS) */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #F8F8F8; /* Slightly off-white background on hover */\n"
"    border: 1px solid black;   /* Black border on hover */\n"
"    border-radius: 30px;       /* Keep border-radius same to maintain circular shape */\n"
"    box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3); /* Slightly more pronounced shadow on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E0E0E0; /* Darker background when pressed */\n"
""
                        "    box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.2); /* Smaller shadow when pressed */\n"
"}"));
        stackedWidget = new QStackedWidget(Dashboard);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(530, 40, 751, 551));
        defaultPage = new QWidget();
        defaultPage->setObjectName("defaultPage");
        defaultPageLayout = new QVBoxLayout(defaultPage);
        defaultPageLayout->setObjectName("defaultPageLayout");
        verticalSpacer_default_top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        defaultPageLayout->addItem(verticalSpacer_default_top);

        welcomeLabel = new QLabel(defaultPage);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setStyleSheet(QString::fromUtf8("font-size: 40px;\n"
"font-weight: bold; \n"
"color: rgb(0, 0, 0);"));
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        defaultPageLayout->addWidget(welcomeLabel);

        verticalSpacer_default_bottom = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        defaultPageLayout->addItem(verticalSpacer_default_bottom);

        stackedWidget->addWidget(defaultPage);
        label_2 = new QLabel(Dashboard);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(520, -40, 1401, 841));
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:white;\n"
"border: 1px solid black;  "));
        pushButton_8 = new QPushButton(Dashboard);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(140, 580, 401, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(0, 0, 0); /* Initial text color: White */\n"
"    font-size: 40px;\n"
"    border-radius: 30px;\n"
"	background-color: rgb(255, 255, 255);\n"
"    border: 1px solid black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(85, 170, 255); /* Text color on hover: Blue (the initial background color) */\n"
"    background-color: rgb(255, 255, 255); /* Background color on hover: White */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    color: rgb(255, 255, 255); /* Initial text color: White */\n"
"    background-color: rgb(85, 170, 255); /* Initial background color: Blue */\n"
"}"));
        pushButton_8->raise();
        label->raise();
        dashboardTitleLabel->raise();
        viewBookingsButton->raise();
        manageFlightsButton->raise();
        manageUsersButton->raise();
        manageBookingsButton->raise();
        logoutButton->raise();
        reportsButton->raise();
        label_2->raise();
        stackedWidget->raise();

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QWidget *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Form", nullptr));
        dashboardTitleLabel->setText(QCoreApplication::translate("Dashboard", "Admin Dashboard", nullptr));
        label->setText(QCoreApplication::translate("Dashboard", "TextLabel", nullptr));
        viewBookingsButton->setText(QCoreApplication::translate("Dashboard", "View Bookings", nullptr));
        manageFlightsButton->setText(QCoreApplication::translate("Dashboard", "Manage Flights ", nullptr));
        manageUsersButton->setText(QCoreApplication::translate("Dashboard", "Manage Users", nullptr));
        manageBookingsButton->setText(QCoreApplication::translate("Dashboard", "Manage Bookings ", nullptr));
        reportsButton->setText(QCoreApplication::translate("Dashboard", "Reports", nullptr));
        logoutButton->setText(QCoreApplication::translate("Dashboard", "Logout ", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("Dashboard", "   Welcome to Admin Dashboard!  ", nullptr));
        label_2->setText(QCoreApplication::translate("Dashboard", "TextLabel", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dashboard", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
