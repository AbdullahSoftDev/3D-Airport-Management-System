#include "dashboard.h"
#include "ui_dashboard.h" // Crucial: This includes the generated UI class definition

#include <QMessageBox> // Required for QMessageBox
#include <QDebug>      // For debugging output

// Ensure all view headers are included here as well
#include "managebookingsview.h"
#include "viewbookingsview.h"
#include "manageflightsview.h"
#include "manageusersview.h"

Dashboard::Dashboard(QWidget *parent) :
    QWidget(parent), // Initialize the QWidget base class
    ui(new Ui::Dashboard), // Instantiate the Ui::Dashboard object
    // Initialize member pointers to nullptr (good practice)
    manageBookingsView(nullptr),
    manageFlightsView(nullptr),
    viewBookingsView(nullptr),
    manageUsersView(nullptr)
{
    ui->setupUi(this); // Set up the user interface elements defined in dashboard.ui
    setWindowTitle("Admin Dashboard"); // Set the window title

    // --- UPDATED: REMOVE THIS LINE ---
    // setAttribute(Qt::WA_DeleteOnClose); // REMOVE THIS: Dashboard is owned by main.cpp, it should not delete itself
    // --- END UPDATED ---

    // --- Initialize and Add Views to stackedWidget ---
    manageBookingsView = new ManageBookingsView(this);
    ui->stackedWidget->addWidget(manageBookingsView);
    qDebug() << "ManageBookingsView added to stackedWidget at index" << ui->stackedWidget->indexOf(manageBookingsView);

    manageFlightsView = new ManageFlightsView(this);
    ui->stackedWidget->addWidget(manageFlightsView);
    qDebug() << "ManageFlightsView added to stackedWidget at index" << ui->stackedWidget->indexOf(manageFlightsView);

    manageUsersView = new ManageUsersView(this);
    ui->stackedWidget->addWidget(manageUsersView);
    qDebug() << "ManageUsersView added to stackedWidget at index" << ui->stackedWidget->indexOf(manageUsersView);

    viewBookingsView = new ViewBookingsView(this);
    ui->stackedWidget->addWidget(viewBookingsView);
    qDebug() << "ViewBookingsView added to stackedWidget at index" << ui->stackedWidget->indexOf(viewBookingsView);

    // Set default page
    ui->stackedWidget->setCurrentWidget(ui->defaultPage);
    qDebug() << "Current stackedWidget index set to defaultPage (index" << ui->stackedWidget->currentIndex() << ")";

    // --- Connect Signals to Slots for Dashboard buttons ---
    connect(ui->viewBookingsButton, &QPushButton::clicked, this, &Dashboard::on_viewBookingsButton_clicked);
    connect(ui->manageFlightsButton, &QPushButton::clicked, this, &Dashboard::on_manageFlightsButton_clicked);
    connect(ui->manageUsersButton, &QPushButton::clicked, this, &Dashboard::on_manageUsersButton_clicked);
    //connect(ui->reportsButton, &QPushButton::clicked, this, &Dashboard::on_reportsButton_clicked);
    connect(ui->manageBookingsButton, &QPushButton::clicked, this, &Dashboard::on_manageBookingsButton_clicked);
    //connect(ui->logoutButton, &QPushButton::clicked, this, &Dashboard::on_logoutButton_clicked);

    // Apply some basic styling directly in code (you can expand this or use .ui stylesheets)
    this->setStyleSheet(
        "QLabel#dashboardTitleLabel { font-size: 24px; font-weight: bold; color: black; }" // Title label style
        // Add more styling here if needed
        );

    qDebug() << "Dashboard created and initialized. StackedWidget has " << ui->stackedWidget->count() << " pages.";
}

Dashboard::~Dashboard()
{
    delete ui;
    qDebug() << "Dashboard destroyed.";
}

// --- Implementations of your private slots for dashboard actions ---

void Dashboard::on_viewBookingsButton_clicked()
{
    qDebug() << "View Bookings button clicked. Showing ViewBookingsView.";
    ui->stackedWidget->setCurrentWidget(viewBookingsView);
    viewBookingsView->loadBookings(); // Call the load method for this view
}

void Dashboard::on_manageFlightsButton_clicked()
{
    qDebug() << "Manage Flights button clicked. Showing ManageFlightsView.";
    ui->stackedWidget->setCurrentWidget(manageFlightsView);
    manageFlightsView->loadFlights(); // Call the load method for this view
}

void Dashboard::on_manageUsersButton_clicked()
{
    qDebug() << "Manage Users button clicked. Showing ManageUsersView.";
    ui->stackedWidget->setCurrentWidget(manageUsersView);
    manageUsersView->loadUsers(); // Load data for ManageUsersView
}

void Dashboard::on_reportsButton_clicked()
{
    QMessageBox::information(this, "Action", "View Reports button clicked!");
    qDebug() << "View Reports button clicked.";
}

void Dashboard::on_manageBookingsButton_clicked()
{
    qDebug() << "Manage Bookings button clicked. Showing ManageBookingsView.";
    ui->stackedWidget->setCurrentWidget(manageBookingsView);
    manageBookingsView->loadBookings(); // Call the load method for this view
}

void Dashboard::on_logoutButton_clicked()
{
    QString msgBoxStyle =
        "QMessageBox { background-color: white; }"
        "QMessageBox QLabel { color: black; border: none; font-weight: bold; }"
        "QMessageBox QPushButton { background-color: lightgray; color: black; border: 0.5px solid darkgray; border-radius: 3px; padding: 5px 20px; }"
        "QMessageBox QPushButton:hover { background-color: gray; }";

    QMessageBox msgBox(this);
    msgBox.setText("Are you sure you want to logout?");
    msgBox.setWindowTitle("Logout Confirmation");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet(msgBoxStyle);

    if (msgBox.exec() == QMessageBox::Yes) {
        qDebug() << "Logout confirmed. Emitting logoutRequested signal.";
        emit logoutRequested(); // Emit the signal
        // --- UPDATED: Change close() to hide() ---
        this->hide(); // Hide the dashboard instead of closing/deleting it
        // --- END UPDATED ---
        qDebug() << "Dashboard hidden. Control returned to calling window.";
    }
}
