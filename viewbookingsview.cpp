#include "viewbookingsview.h"
#include "ui_viewbookingsview.h" // Generated from ViewBookingsView.ui
#include <QDir>
#include <QFileInfo> // Added for QFileInfo (important for dir.path())
#include "AppPaths.h"   // <--- REQUIRED: Include AppPaths for standard path management

// REMOVED: The hardcoded path definition.
// const QString TICKETS_FILE_PATH = "C:/Users/Abdullah/AppData/Roaming/Airlines/tickets.csv";

ViewBookingsView::ViewBookingsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewBookingsView)
{
    ui->setupUi(this);
    setWindowTitle("View All Bookings"); // Set the window title for this view

    applyTableStyling(); // Apply styling to the table

    // Configure the table widget
    ui->bookingsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookingsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->bookingsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->bookingsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->bookingsTableWidget->setAlternatingRowColors(true); // Enable alternating row colors

    qDebug() << "ViewBookingsView created.";
}

ViewBookingsView::~ViewBookingsView()
{
    delete ui;
    qDebug() << "ViewBookingsView destroyed.";
}

void ViewBookingsView::applyTableStyling()
{
    // Styling for table headers
    QString tableHeaderStyle =
        "QHeaderView::section {"
        "    background-color: lightgray;"
        "    color: black;"
        "    padding: 6px;"
        "    border: 1px solid #c0c0c0;"
        "    font-weight: bold;"
        "}"
        "QHeaderView::section:hover { background-color: #d0d0d0; }"
        "QHeaderView::section:pressed { background-color: #c0c0c0; }";

    ui->bookingsTableWidget->horizontalHeader()->setStyleSheet(tableHeaderStyle);
    ui->bookingsTableWidget->verticalHeader()->setStyleSheet(tableHeaderStyle);

    // Styling for table contents
    QString tableContentStyle =
        "QTableWidget {"
        "    background-color: white;" // Changed from lightgray to white for main background
        "    gridline-color: #e0e0e0;" // Color of lines between cells
        "    border: 1px solid #a0a0a0;"
        "    alternate-background-color: #f5f5f5;" // For alternating row colors
        "}"
        "QTableWidget::item {"
        "    padding: 4px;"
        "    color: black;"
        "    background-color: white;" // Default item background
        "    border: 1px solid #e0e0e0;"
        "}"
        "QTableWidget::item:selected {"
        "    background-color: #d0e0ff;" // Background for selected items
        "    color: black;"
        "}"
        "QTableCornerButton::section {"
        "    background-color: lightgray;"
        "    border: 1px solid #c0c0c0;"
        "}";

    ui->bookingsTableWidget->setStyleSheet(tableContentStyle);
}


void ViewBookingsView::loadBookings()
{
    // Get the tickets file path using the AppPaths utility class
    const QString ticketsFilePath = AppPaths::getTicketsFilePath(); // <--- UPDATED: Get path dynamically
    QFile file(ticketsFilePath);

    // Create the tickets.csv file with header if it doesn't exist
    // This assumes your tickets.csv has a header row.
    if (!file.exists()) {
        qDebug() << "tickets.csv not found at" << ticketsFilePath << ". Creating with header.";

        // Check if the directory exists and is writable.
        QDir dir(QFileInfo(ticketsFilePath).dir().path()); // <--- UPDATED: Use dynamic path
        if (!dir.exists()) {
            if (!dir.mkpath(dir.path())) { // <--- UPDATED: Use dir.path() for robustness
                qWarning() << "Error: Could not create directory for tickets.csv:" << dir.path() << "-" << file.errorString();
                QMessageBox::critical(this, "File Creation Error",
                                      "Could not create directory for tickets.csv. Please check permissions:\n" + dir.path());
                return;
            }
        }

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "Error: Could not create tickets.csv:" << file.errorString();
            QMessageBox::critical(this, "File Creation Error",
                                  "Could not create tickets.csv file. Please check permissions:\n" + ticketsFilePath); // <--- UPDATED: Use dynamic path
            return;
        }
        QTextStream out(&file);
        out << "Booking ID,Flight Number,Passenger Name,Contact Number,Booking Date Time,Seats Booked,Total Fare,Status\n";
        file.close();
    }


    // Open the tickets.csv file for reading
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Could not load booking data. Please ensure 'tickets.csv' exists and is accessible.");
        qWarning() << "Error: Could not open file:" << ticketsFilePath << "-" << file.errorString(); // <--- UPDATED: Use dynamic path
        return;
    }

    QTextStream in(&file);
    ui->bookingsTableWidget->setRowCount(0); // Clear existing rows

    // Skip header row
    if (!in.atEnd()) {
        in.readLine();
    }

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        // Expected columns: Booking ID,Flight Number,Passenger Name,Contact Number,Booking Date Time,Seats Booked,Total Fare,Status
        const int EXPECTED_BOOKING_COLUMNS = 8;
        if (fields.size() == EXPECTED_BOOKING_COLUMNS) {
            ui->bookingsTableWidget->insertRow(row);

            ui->bookingsTableWidget->setItem(row, 0, new QTableWidgetItem(fields.at(0).trimmed())); // Booking ID
            ui->bookingsTableWidget->setItem(row, 1, new QTableWidgetItem(fields.at(1).trimmed())); // Flight Number
            ui->bookingsTableWidget->setItem(row, 2, new QTableWidgetItem(fields.at(2).trimmed())); // Passenger Name
            ui->bookingsTableWidget->setItem(row, 3, new QTableWidgetItem(fields.at(3).trimmed())); // Contact Number
            ui->bookingsTableWidget->setItem(row, 4, new QTableWidgetItem(fields.at(4).trimmed())); // Booking Date/Time
            ui->bookingsTableWidget->setItem(row, 5, new QTableWidgetItem(fields.at(5).trimmed())); // Seats Booked
            ui->bookingsTableWidget->setItem(row, 6, new QTableWidgetItem(fields.at(6).trimmed())); // Total Fare
            ui->bookingsTableWidget->setItem(row, 7, new QTableWidgetItem(fields.at(7).trimmed())); // Status

            row++;
        } else {
            qWarning() << "Warning: Skipping malformed booking row due to incorrect field count (" << fields.size() << " instead of " << EXPECTED_BOOKING_COLUMNS << "):" << line;
        }
    }

    file.close();
    ui->bookingsTableWidget->resizeColumnsToContents(); // Adjust column widths
    qDebug() << "Bookings loaded from:" << ticketsFilePath; // <--- UPDATED: Use dynamic path
}
