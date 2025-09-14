#include "flightsearchwindow.h"
#include "ui_flightsearchwindow.h" // Generated UI header for FlightSearchWindow
#include "mainwindow.h"             // Include MainWindow header for navigation

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView> // For QHeaderView::ResizeToContents
#include <QDate>
#include <QDateTime> // For parsing date and time (though not strictly used after change)
#include <QDebug>    // For debugging messages

FlightSearchWindow::FlightSearchWindow(QWidget *parent)
    : QWidget(parent) // Parent will typically be nullptr when created in MainWindow
    , ui(new Ui::FlightSearchWindow)
{
    ui->setupUi(this);
    mainWindow = nullptr; // Initialize the pointer

    setWindowTitle("Search Available Flights");
    applyStyling();      // Apply consistent styling
    setupFlightsTable(); // Setup table headers and properties

    // Connect signals and slots
    connect(ui->backButton, &QPushButton::clicked, this, &FlightSearchWindow::on_backButton_clicked);
    //connect(ui->searchButton, &QPushButton::clicked, this, &FlightSearchWindow::on_searchButton_clicked);
    // Note: Text changes and date changes are NOT connected to trigger search automatically,
    // as per your current code; search is only on button click.

    // Set up QDateEdit
    ui->dateEdit->setDate(QDate::currentDate()); // Set default date to today
    ui->dateEdit->setCalendarPopup(true);        // Enable calendar popup

    // Load all flights initially (no filters applied at startup)
    // By passing default arguments (empty strings and null QDate),
    // loadFlightsFromCsv will display all flights.
    loadFlightsFromCsv(AppPaths::getFlightsFilePath(),
                       QString(), QString(), QDate()); // Pass empty/null filters
}

FlightSearchWindow::~FlightSearchWindow()
{
    delete ui;
}

void FlightSearchWindow::setMainWindow(MainWindow *window)
{
    mainWindow = window;
}

void FlightSearchWindow::applyStyling()
{
    // Consistent styling with your other windows (e.g., Passenger_BookTicket, SearchTicketWindow)
    this->setStyleSheet(
        "QWidget#FlightSearchWindow { background-color: white; }"
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
        // Styling for QMessageBox
        "QMessageBox {"
        "    background-color: white;" // Make the message box background white
        "}"
        "QMessageBox QLabel {" // Keep the text black
        "    color: black;"
        "}"
        "QMessageBox QPushButton {" // Style for buttons within QMessageBox
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

    ui->flightsTableWidget->horizontalHeader()->setStyleSheet(tableHeaderStyle);
    ui->flightsTableWidget->verticalHeader()->setStyleSheet(tableHeaderStyle);

    QString tableContentStyle =
        "QTableWidget {"
        "    background-color: lightgray;" // Background for empty areas of the table
        "    gridline-color: #e0e0e0;"
        "    border: 1px solid #a0a0a0;"
        "    alternate-background-color: #f5f5f5;" // Optional: for striped rows
        "}"
        "QTableWidget::item {"
        "    padding: 4px;"
        "    color: black;"
        "    background-color: white;" // CRITICAL: Ensure cells themselves are white
        "    border: 1px solid #e0e0e0;"
        "}"
        "QTableWidget::item:selected {"
        "    background-color: #d0e0ff;"
        "    color: black;"
        "}"
        "QTableCornerButton::section {"
        "    background-color: lightgray;" // Top-left corner button
        "    border: 1px solid #c0c0c0;"
        "}";

    ui->flightsTableWidget->setStyleSheet(tableContentStyle);
}

void FlightSearchWindow::setupFlightsTable()
{
    ui->flightsTableWidget->setColumnCount(7); // Matches the flight data columns
    QStringList headers;
    headers << "Flight Number" << "Origin" << "Destination" << "Departure Time"
            << "Arrival Time" << "Available Seats" << "Fare";
    ui->flightsTableWidget->setHorizontalHeaderLabels(headers);
    ui->flightsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->flightsTableWidget->setSelectionMode(QAbstractItemView::NoSelection); // Make table read-only, no selection
    ui->flightsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Disable editing
    ui->flightsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->flightsTableWidget->horizontalHeader()->setStretchLastSection(true); // Ensure last column stretches if space available
}

void FlightSearchWindow::loadFlightsFromCsv(const QString &filePath,
                                            const QString &originFilter,
                                            const QString &destinationFilter,
                                            const QDate &dateFilter) // dateFilter can be null QDate()
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Could not load flight data. Please ensure 'flights.csv' exists and is accessible.");
        qWarning() << "Error: Could not open file:" << filePath << "-" << file.errorString();
        return;
    }

    QTextStream in(&file);
    ui->flightsTableWidget->setRowCount(0); // Clear existing rows before loading

    if (!in.atEnd()) {
        in.readLine(); // Skip header row
    }

    int row = 0;
    bool foundAnyFlight = false; // Flag to check if any flight is added to the table
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        const int EXPECTED_FLIGHT_COLUMNS = 9; // Based on previous analysis (Flight#, Origin, Dest, DepDate, DepTime, ArrDate, ArrTime, Fare, Seats)
        if (fields.size() == EXPECTED_FLIGHT_COLUMNS) {
            QString flightNumber = fields.at(0).trimmed();
            QString origin = fields.at(1).trimmed();
            QString destination = fields.at(2).trimmed();
            QString departureDateStr = fields.at(3).trimmed();
            QString departureTimeStr = fields.at(4).trimmed();
            QString arrivalDateStr = fields.at(5).trimmed();
            QString arrivalTimeStr = fields.at(6).trimmed();
            QString fare = fields.at(7).trimmed();
            QString availableSeats = fields.at(8).trimmed();

            QDate flightDepartureDate = QDate::fromString(departureDateStr, "yyyy-MM-dd");
            if (!flightDepartureDate.isValid()) {
                // Try other common formats if needed
                flightDepartureDate = QDate::fromString(departureDateStr, "M/d/yyyy");
            }
            if (!flightDepartureDate.isValid()) {
                qWarning() << "Warning: Invalid departure date format for flight" << flightNumber << ":" << departureDateStr;
                continue; // Skip this row if date is invalid
            }

            // Apply filters: A field matches if its filter is empty OR it contains the filter text (case-insensitive)
            bool matchesOrigin = originFilter.isEmpty() || origin.contains(originFilter, Qt::CaseInsensitive);
            bool matchesDestination = destinationFilter.isEmpty() || destination.contains(destinationFilter, Qt::CaseInsensitive);
            // The date matches if dateFilter is a null QDate (no filter) OR the flight's departure date matches the filter date
            bool matchesDate = dateFilter.isNull() || (flightDepartureDate == dateFilter);

            if (matchesOrigin && matchesDestination && matchesDate) {
                ui->flightsTableWidget->insertRow(row);

                ui->flightsTableWidget->setItem(row, 0, new QTableWidgetItem(flightNumber));
                ui->flightsTableWidget->setItem(row, 1, new QTableWidgetItem(origin));
                ui->flightsTableWidget->setItem(row, 2, new QTableWidgetItem(destination));
                ui->flightsTableWidget->setItem(row, 3, new QTableWidgetItem(departureDateStr + " " + departureTimeStr));
                ui->flightsTableWidget->setItem(row, 4, new QTableWidgetItem(arrivalDateStr + " " + arrivalTimeStr));
                ui->flightsTableWidget->setItem(row, 5, new QTableWidgetItem(availableSeats));
                ui->flightsTableWidget->setItem(row, 6, new QTableWidgetItem(fare));

                foundAnyFlight = true; // Mark that at least one flight was added
                row++;
            }
        } else {
            qWarning() << "Warning: Skipping malformed flight row due to incorrect field count (" << fields.size() << " instead of " << EXPECTED_FLIGHT_COLUMNS << "):" << line;
        }
    }

    file.close();
    ui->flightsTableWidget->resizeColumnsToContents(); // Resize columns after loading/filtering

    // Show "No Flights Found" message only if filters were applied and no results found
    // This message should appear if the table is empty AND at least one filter was non-empty/non-null.
    if (!foundAnyFlight && (!originFilter.isEmpty() || !destinationFilter.isEmpty() || !dateFilter.isNull())) {
        QMessageBox::information(this, "No Flights Found", "No flights match your search criteria.");
    }
}

// --- Slot Implementations ---

void FlightSearchWindow::on_searchButton_clicked()
{
    QString origin = ui->originLineEdit->text().trimmed();
    QString destination = ui->destinationLineEdit->text().trimmed();
    QDate selectedDate = ui->dateEdit->date(); // Get the date currently in the QDateEdit

    // Determine the actual date filter to pass to loadFlightsFromCsv:
    // We only want to apply a date filter if the user has explicitly changed the date
    // from the initial default (which is QDate::currentDate()).
    QDate filterDate; // Initialize as a null QDate
    if (selectedDate != QDate::currentDate()) {
        filterDate = selectedDate; // If the date is different from current date, apply it as a filter
    }
    // If selectedDate IS QDate::currentDate(), filterDate remains a null QDate(),
    // meaning no date filter will be applied.

    // Load flights with the determined filters
    loadFlightsFromCsv(AppPaths::getFlightsFilePath(), // CORRECTED: Use AppPaths
                       origin, destination, filterDate);

    qDebug() << "Flights searched with Origin:" << origin
             << ", Destination:" << destination
             << ", Date:" << (filterDate.isNull() ? "No Date Filter (showing all dates)" : filterDate.toString("yyyy-MM-dd"));
}


void FlightSearchWindow::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show(); // Show the main window
        this->hide();        // Hide the current window
        qDebug() << "Navigating back to Main Window from Flight Search.";
    } else {
        QMessageBox::warning(this, "Navigation Error", "Cannot go back: Main Window not accessible.");
        qDebug() << "Error: MainWindow pointer not set in FlightSearchWindow!";
    }
}
