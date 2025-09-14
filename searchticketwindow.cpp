#include "searchticketwindow.h"
#include "ui_searchticketwindow.h"
#include "mainwindow.h"
#include <QDate>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QHeaderView>

extern const QString globalMessageBoxStyle;

SearchTicketWindow::SearchTicketWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchTicketWindow)
{
    ui->setupUi(this);
    mainWindow = nullptr;

    // --- Apply Global Stylesheet for window and common widgets (Light Theme) ---
    this->setStyleSheet(
        "QWidget#SearchTicketWindow { background-color: white; }"
        "QLabel { color: black; }"
        "QPushButton {"
        "    background-color: lightgray;"
        "    color: black;"
        "    border: 1px solid #c0c0c0;"
        "    padding: 5px 15px;"
        "    border-radius: 3px;"
        "}"
        "QPushButton:hover { background-color: #d0d0d0; }"
        "QPushButton:pressed { background-color: #c0c0c0; }"
        "QLineEdit {"
        "    background-color: white;"
        "    color: black;"
        "    border: 1px solid #a0a0a0;"
        "    padding: 5px;"
        "    border-radius: 3px;"
        "}"
        "QDateEdit {"
        "    background-color: white;"
        "    color: black;"
        "    border: 1px solid #a0a0a0;"
        "    padding: 5px;"
        "    border-radius: 3px;"
        "    selection-background-color: #d0e0ff;"
        "    selection-color: black;"
        "}"
        );

    // --- Apply Stylesheet for QTableWidget Headers (Horizontal and Vertical) ---
    ui->ticketsTableWidget->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "    background-color: lightgray;"
        "    color: black;"
        "    padding: 6px;"
        "    border: 1px solid #c0c0c0;"
        "    font-weight: bold;"
        "}"
        "QHeaderView::section:hover {"
        "    background-color: #d0d0d0;"
        "}"
        "QHeaderView::section:pressed {"
        "    background-color: #c0c0c0;"
        "}"
        );

    ui->ticketsTableWidget->verticalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "    background-color: lightgray;"
        "    color: black;"
        "    padding: 6px;"
        "    border: 1px solid #c0c0c0;"
        "    font-weight: normal;"
        "}"
        "QHeaderView::section:hover {"
        "    background-color: #d0d0d0;"
        "}"
        "QHeaderView::section:pressed {"
        "    background-color: #c0c0c0;"
        "}"
        );

    // Apply styling for the table content itself (cells), overall table, AND the problematic grey areas
    ui->ticketsTableWidget->setStyleSheet(
        "QTableWidget {"
        "    background-color: lightgray;"
        "    gridline-color: #e0e0e0;"
        "    border: 1px solid #a0a0a0;"
        "    alternate-background-color: #f5f5f5;"
        "}"
        "QTableWidget::item {"
        "    padding: 4px;"
        "    color: black;"
        "    background-color: white;"
        "    border: 1px solid #e0e0e0;"
        "}"
        "QTableWidget::item:selected {"
        "    background-color: #d0e0ff;"
        "    color: black;"
        "}"
        "QTableCornerButton::section {"
        "    background-color: lightgray;"
        "    border: 1px solid #c0c0c0;"
        "}"
        );


    connect(ui->backButton, &QPushButton::clicked, this, &SearchTicketWindow::on_backButton_clicked);
    //connect(ui->searchButton, &QPushButton::clicked, this, &SearchTicketWindow::on_searchButton_clicked); // Ensure this is connected

    // --- Table Widget Setup (Based on your NEW 8-column CSV and desired order) ---
    ui->ticketsTableWidget->setColumnCount(8);
    QStringList headerLabels;
    headerLabels << "Booking ID"
                 << "Flight Number"
                 << "Passenger Name"
                 << "Contact Number"
                 << "Booking Date"
                 << "Seats Booked"
                 << "Total Fare"
                 << "Status";
    ui->ticketsTableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->ticketsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ticketsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


    // --- QDateEdit Setup ---
    ui->bookingDateSearchDateEdit->setDate(QDate::currentDate());
    ui->bookingDateSearchDateEdit->setCalendarPopup(true);

    loadTicketsFromCsv(AppPaths::getTicketsFilePath());
}

SearchTicketWindow::~SearchTicketWindow()
{
    delete ui;
}

void SearchTicketWindow::setMainWindow(MainWindow *window)
{
    mainWindow = window;
}

void SearchTicketWindow::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Navigation Error", "Cannot go back: Main Window not accessible.");
        qDebug() << "Error: MainWindow pointer not set in SearchTicketWindow!";
    }
}

void SearchTicketWindow::loadTicketsFromCsv(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Could not load ticket data. Please ensure 'tickets.csv' exists and is accessible.");
        qWarning() << "Error: Could not open file:" << filePath << "-" << file.errorString();
        return;
    }

    QTextStream in(&file);
    ui->ticketsTableWidget->setRowCount(0); // Clear existing rows

    if (!in.atEnd()) {
        in.readLine(); // Skip header row
    }

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        const int EXPECTED_CSV_COLUMNS = 8;
        if (fields.size() == EXPECTED_CSV_COLUMNS) {
            ui->ticketsTableWidget->insertRow(row);

            ui->ticketsTableWidget->setItem(row, 0, new QTableWidgetItem(fields.at(0).trimmed())); // Booking ID
            ui->ticketsTableWidget->setItem(row, 1, new QTableWidgetItem(fields.at(1).trimmed())); // Flight Number
            ui->ticketsTableWidget->setItem(row, 2, new QTableWidgetItem(fields.at(2).trimmed())); // Passenger Name
            ui->ticketsTableWidget->setItem(row, 3, new QTableWidgetItem(fields.at(3).trimmed())); // Passenger Contact
            ui->ticketsTableWidget->setItem(row, 4, new QTableWidgetItem(fields.at(4).trimmed())); // Booking Date
            ui->ticketsTableWidget->setItem(row, 5, new QTableWidgetItem(fields.at(5).trimmed())); // Seats Booked
            ui->ticketsTableWidget->setItem(row, 6, new QTableWidgetItem(fields.at(6).trimmed())); // Total Fare
            ui->ticketsTableWidget->setItem(row, 7, new QTableWidgetItem(fields.at(7).trimmed())); // Status

            row++;
        } else {
            qWarning() << "Warning: Skipping malformed row due to incorrect field count (" << fields.size() << " instead of " << EXPECTED_CSV_COLUMNS << "):" << line;
        }
    }

    file.close();
    ui->ticketsTableWidget->resizeColumnsToContents(); // Resize columns after loading data
}

void SearchTicketWindow::on_searchButton_clicked()
{
    performSearch();
}

void SearchTicketWindow::performSearch()
{
    QString passengerName = ui->passengerNameSearchLineEdit->text().trimmed();
    QString bookingId = ui->bookingIdSearchLineEdit->text().trimmed();
    QString searchDateFormatted = ui->bookingDateSearchDateEdit->date().toString("yyyy-MM-dd");

    QDate defaultDate = QDate::currentDate();

    // Reload all data from CSV to ensure we're filtering on the latest data
    loadTicketsFromCsv(AppPaths::getTicketsFilePath());

    // After reloading, if all search fields are empty (including default date),
    // then all tickets are already loaded and visible, so no need to filter.
    bool allFieldsEmpty = passengerName.isEmpty() && bookingId.isEmpty() &&
                          (ui->bookingDateSearchDateEdit->date() == defaultDate);

    if (allFieldsEmpty) {
        // If no specific search criteria, ensure all rows are visible
        for (int i = 0; i < ui->ticketsTableWidget->rowCount(); ++i) {
            ui->ticketsTableWidget->setRowHidden(i, false);
        }
        return;
    }

    qDebug() << "--- Starting Search ---";
    qDebug() << "Search Passenger Name Input:" << passengerName;
    qDebug() << "Search Booking ID Input:" << bookingId;
    qDebug() << "Search Date Input (Formatted):" << searchDateFormatted;

    int visibleRowCount = 0;
    for (int i = 0; i < ui->ticketsTableWidget->rowCount(); ++i) {
        bool matchPassenger = true;
        bool matchBookingId = true;
        bool matchBookingDate = true;

        // --- Apply Passenger Name Filter (Table Column 2) ---
        if (!passengerName.isEmpty()) {
            QTableWidgetItem* item = ui->ticketsTableWidget->item(i, 2);
            if (item) {
                QString tablePassengerName = item->text().trimmed();
                matchPassenger = tablePassengerName.contains(passengerName, Qt::CaseInsensitive);
                qDebug() << "Row" << i << " -> Passenger Name (Table):" << tablePassengerName << ", Input:" << passengerName << ", Match:" << matchPassenger;
            } else {
                matchPassenger = false;
                qWarning() << "Warning: No item found at row" << i << ", col 2 for passenger name. Row will be hidden.";
            }
        }

        // --- Apply Booking ID Filter (Table Column 0) ---
        if (!bookingId.isEmpty()) {
            QTableWidgetItem* item = ui->ticketsTableWidget->item(i, 0);
            if (item) {
                QString tableBookingId = item->text().trimmed();
                matchBookingId = tableBookingId.contains(bookingId, Qt::CaseInsensitive);
                qDebug() << "Row" << i << " -> Booking ID (Table):" << tableBookingId << ", Input:" << bookingId << ", Match:" << matchBookingId;
            } else {
                matchBookingId = false;
                qWarning() << "Warning: No item found at row" << i << ", col 0 for booking ID. Row will be hidden.";
            }
        }

        // --- Apply Booking Date Filter (Table Column 4) ---
        // Only filter by date if the QDateEdit is NOT set to the current default date
        if (ui->bookingDateSearchDateEdit->date() != defaultDate) {
            QTableWidgetItem* item = ui->ticketsTableWidget->item(i, 4);
            if (item) {
                QString rawDateTimeString = item->text().trimmed();

                QDateTime tableDateTime;
                // Try various common date/time formats from CSV
                tableDateTime = QDateTime::fromString(rawDateTimeString, Qt::ISODate);
                if (!tableDateTime.isValid()) {
                    tableDateTime = QDateTime::fromString(rawDateTimeString, "M/d/yyyy HH:mm");
                }
                if (!tableDateTime.isValid()) {
                    tableDateTime = QDateTime::fromString(rawDateTimeString, "yyyy-MM-dd HH:mm:ss");
                }
                if (!tableDateTime.isValid()) {
                    tableDateTime = QDateTime::fromString(rawDateTimeString, "yyyy-MM-dd");
                }
                if (!tableDateTime.isValid()) {
                    tableDateTime = QDateTime::fromString(rawDateTimeString, "dd-MM-yyyy");
                }

                if (tableDateTime.isValid()) {
                    QString tableDateOnly = tableDateTime.date().toString("yyyy-MM-dd");
                    matchBookingDate = (tableDateOnly == searchDateFormatted);
                } else {
                    matchBookingDate = false;
                    qWarning() << "Invalid or unhandled date/time format in CSV for row" << i << " (Table Column 4):" << rawDateTimeString << ". Row will be hidden.";
                }
                qDebug() << "Row" << i << " -> Raw Date String:" << rawDateTimeString << ", Parsed Date:" << (tableDateTime.isValid() ? tableDateTime.date().toString("yyyy-MM-dd") : "Invalid") << ", Search Date:" << searchDateFormatted << ", Match:" << matchBookingDate;
            } else {
                matchBookingDate = false;
                qWarning() << "Warning: No item found at row" << i << ", col 4 for booking date. Row will be hidden.";
            }
        } else {
            matchBookingDate = true;
        }

        bool rowVisible = (matchPassenger && matchBookingId && matchBookingDate);
        ui->ticketsTableWidget->setRowHidden(i, !rowVisible);
        if (rowVisible) {
            visibleRowCount++;
        }
        qDebug() << "Row" << i << " -> Final Visibility:" << rowVisible;
    }

    if (visibleRowCount == 0 && !allFieldsEmpty) {
        // Create a QMessageBox instance
        QMessageBox msgBox(this);
        msgBox.setText("No tickets found matching your criteria.");
        msgBox.setWindowTitle("No Results");
        msgBox.setIcon(QMessageBox::Information); // Keep the information icon

        // Apply stylesheet to the QMessageBox
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: white;" // Make the message box background white
            "}"
            "QMessageBox QLabel {" // Target the QLabel that holds the message text
            "    color: black;"     // Keep the text black
            "}"
            // Style for the OK button within this specific QMessageBox
            "QMessageBox QPushButton {"
            "    background-color: lightgray;"
            "    color: black;"
            "    border: 1px solid #c0c0c0;"
            "    padding: 5px 15px;"
            "    border-radius: 3px;"
            "}"
            "QMessageBox QPushButton:hover {"
            "    background-color: #d0d0d0;"
            "}"
            "QMessageBox QPushButton:pressed {"
            "    background-color: #c0c0c0;"
            "}"
            );
        msgBox.exec(); // Show the message box
    }
    qDebug() << "--- Search Finished. Visible Rows:" << visibleRowCount << "---";
}
