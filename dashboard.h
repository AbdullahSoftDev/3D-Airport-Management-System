#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include "managebookingsview.h"
#include "viewbookingsview.h"
#include "manageflightsview.h"
#include "manageusersview.h"   // <<< Keep this ONE include for ManageUsersView

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

signals:
    // This signal will be emitted when the user requests to logout
    void logoutRequested();

private slots:
    void on_viewBookingsButton_clicked();
    void on_manageFlightsButton_clicked();
    void on_manageUsersButton_clicked(); // <<< ENSURE ONLY ONE DECLARATION OF THIS SLOT
    void on_reportsButton_clicked();
    void on_manageBookingsButton_clicked();
    void on_logoutButton_clicked();

private:
    Ui::Dashboard *ui;
    ManageBookingsView *manageBookingsView;
    ManageFlightsView *manageFlightsView;
    ViewBookingsView *viewBookingsView;
    ManageUsersView *manageUsersView;   // <<< UNCOMMENT THIS LINE: Declare pointer for ManageUsersView
    // ReportsView *reportsView; // Keep commented if not implemented yet
};

#endif // DASHBOARD_H
