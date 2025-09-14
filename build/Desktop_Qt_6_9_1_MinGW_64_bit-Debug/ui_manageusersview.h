/********************************************************************************
** Form generated from reading UI file 'manageusersview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEUSERSVIEW_H
#define UI_MANAGEUSERSVIEW_H

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

class Ui_ManageUsersView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTableWidget *usersTableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addAdminButton;
    QPushButton *editAdminButton;
    QPushButton *removeAdminButton;

    void setupUi(QWidget *ManageUsersView)
    {
        if (ManageUsersView->objectName().isEmpty())
            ManageUsersView->setObjectName("ManageUsersView");
        ManageUsersView->resize(700, 500);
        verticalLayout = new QVBoxLayout(ManageUsersView);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(ManageUsersView);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: black;"));

        verticalLayout->addWidget(titleLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        usersTableWidget = new QTableWidget(ManageUsersView);
        if (usersTableWidget->columnCount() < 2)
            usersTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usersTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usersTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        usersTableWidget->setObjectName("usersTableWidget");

        verticalLayout->addWidget(usersTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addAdminButton = new QPushButton(ManageUsersView);
        addAdminButton->setObjectName("addAdminButton");

        horizontalLayout->addWidget(addAdminButton);

        editAdminButton = new QPushButton(ManageUsersView);
        editAdminButton->setObjectName("editAdminButton");

        horizontalLayout->addWidget(editAdminButton);

        removeAdminButton = new QPushButton(ManageUsersView);
        removeAdminButton->setObjectName("removeAdminButton");

        horizontalLayout->addWidget(removeAdminButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ManageUsersView);

        QMetaObject::connectSlotsByName(ManageUsersView);
    } // setupUi

    void retranslateUi(QWidget *ManageUsersView)
    {
        ManageUsersView->setWindowTitle(QCoreApplication::translate("ManageUsersView", "Manage Users", nullptr));
        titleLabel->setText(QCoreApplication::translate("ManageUsersView", "Manage Administrator Accounts", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usersTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageUsersView", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = usersTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageUsersView", "Password", nullptr));
        addAdminButton->setText(QCoreApplication::translate("ManageUsersView", "Add New Admin", nullptr));
        editAdminButton->setText(QCoreApplication::translate("ManageUsersView", "Edit Admin Details", nullptr));
        removeAdminButton->setText(QCoreApplication::translate("ManageUsersView", "Remove Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageUsersView: public Ui_ManageUsersView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEUSERSVIEW_H
