#include "manageflightsview.h"
#include "ui_manageflightsview.h" // Generated from ManageFlightsView.ui
#include <QDir>        // For directory operations
#include <QMessageBox> // For showing pop-up messages
#include <QDebug>      // For debug output
#include <QTableWidgetItem> // Essential for working with QTableWidget items
#include <QFile>       // For file operations (reading/writing CSV)
#include <QTextStream> // For text streaming (CSV read/write)
#include <QFileInfo>   // For QFileInfo to get directory path

#include "apppaths.h"        // Correctly included
#include "addflightdialog.h" // Make sure this is included for AddFlightDialog
#include "editflightdialog.h" // Include for EditFlightDialog

// REMOVED: Define the path for the flights.csv file
// IMPORTANT: No longer needed, as we'll use AppPaths::getFlightsFilePath()
// const QString FLIGHTS_FILE_PATH = "C:/Users/Abdullah/AppData/Roaming/Airlines/flights.csv"; // This line should remain commented or removed.

ManageFlightsView::ManageFlightsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageFlightsView)
{
    ui->setupUi(this);
    setWindowTitle("Manage Flights");

    applyTableStyling();

    // Configure the table widget
    ui->flightsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->flightsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->flightsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->flightsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Stretch columns to fit width
    ui->flightsTableWidget->setAlternatingRowColors(true); // Enable alternating row colors

    // *** UNCOMMENTED: Connect buttons to their actual slots ***
    //connect(ui->addFlightButton, &QPushButton::clicked, this, &ManageFlightsView::on_addFlightButton_clicked);
    //connect(ui->editFlightButton, &QPushButton::clicked, this, &ManageFlightsView::on_editFlightButton_clicked);
    //connect(ui->deleteFlightButton, &QPushButton::clicked, this, &ManageFlightsView::on_deleteFlightButton_clicked);

    QString buttonStyle =
        "QPushButton {"
        "   background-color: white;"     // Default background: white
        "   color: black;"                 // Default text: black
        "   border: 1px solid #333;"       // 1px solid black-ish outline
        "   border-radius: 5px;"           // Slightly rounded corners
        "   padding: 5px 10px;"            // Padding for better look
        "   font-weight: bold;"
        "   font-size: 10px;"              // Adjust font size as needed
        "}"
        "QPushButton:hover,"               // On hover
        "QPushButton:pressed {"            // On pressed (clicked)
        "   background-color: #FD5800;"    // Orange background
        "   color: black;"                 // Black text on orange
        "   border: 1px solid #FD5800;"    // Border matches background on hover/pressed
        "}";
    ui->addFlightButton->setStyleSheet(buttonStyle);
    ui->editFlightButton->setStyleSheet(buttonStyle);
    ui->deleteFlightButton->setStyleSheet(buttonStyle);

    // Call loadFlights here to populate the table when the view is created
    loadFlights();

    qDebug() << "ManageFlightsView created.";
}

ManageFlightsView::~ManageFlightsView()
{
    delete ui;
    qDebug() << "ManageFlightsView destroyed.";
}

void ManageFlightsView::applyTableStyling()
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

    ui->flightsTableWidget->horizontalHeader()->setStyleSheet(tableHeaderStyle);
    ui->flightsTableWidget->verticalHeader()->setStyleSheet(tableHeaderStyle);

    // Styling for table contents
    QString tableContentStyle =
        "QTableWidget {"
        "    background-color: white;"
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
        "}";

    ui->flightsTableWidget->setStyleSheet(tableContentStyle);
}

void ManageFlightsView::loadFlights()
{
    // *** MODIFIED: Use AppPaths::getFlightsFilePath() for the main file path variable ***
    QString filePath = AppPaths::getFlightsFilePath();
    QFile file(filePath);

    // Create the flights.csv file with header if it doesn't exist
    if (!file.exists()) {
        // *** MODIFIED: Use 'filePath' variable instead of commented-out FLIGHTS_FILE_PATH ***
        qDebug() << "flights.csv not found at" << filePath << ". Creating with header.";
        QDir dir(QFileInfo(filePath).dir().path()); // Use filePath here
        if (!dir.exists()) {
            if (!dir.mkpath(dir.path())) {
                qWarning() << "Error: Could not create directory for flights.csv:" << dir.path() << "-" << file.errorString();
                // Custom QMessageBox for file creation error (directory)
                QMessageBox msgBox(this);
                msgBox.setWindowTitle("File Creation Error");
                msgBox.setText("Could not create directory for flights.csv. Please check permissions:\n" + dir.path());
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setStyleSheet(
                    "QMessageBox {"
                    "    background-color: white;" // Make the message box background white
                    "}"
                    "QMessageBox QLabel {" // Target the QLabel that holds the message text
                    "    color: black;"    // Keep the text black
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
                msgBox.exec();
                return;
            }
        }

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "Error: Could not create flights.csv:" << file.errorString();
            // Custom QMessageBox for file creation error (file itself)
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("File Creation Error");
            msgBox.setText("Could not create flights.csv file. Please check permissions:\n" + filePath);
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStyleSheet(
                "QMessageBox {"
                "    background-color: white;" // Make the message box background white
                "}"
                "QMessageBox QLabel {" // Target the QLabel that holds the message text
                "    color: black;"    // Keep the text black
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
            msgBox.exec();
            return;
        }
        QTextStream out(&file);
        out << "Flight Number,Origin,Destination,Departure Date,Departure Time,Arrival Date,Arrival Time,Fare,Available Seats\n";
        file.close();
        qDebug() << "Created empty flights.csv with header at:" << filePath; // Use filePath here
    }

    // Open the flights.csv file for reading
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // *** MODIFIED: Use 'filePath' variable instead of commented-out FLIGHTS_FILE_PATH ***
        // Custom QMessageBox for file open error
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("File Error");
        msgBox.setText("Could not load flight data. Please ensure 'flights.csv' exists and is accessible at " + filePath + ".");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: white;" // Make the message box background white
            "}"
            "QMessageBox QLabel {" // Target the QLabel that holds the message text
            "    color: black;"    // Keep the text black
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
        msgBox.exec();
        qWarning() << "Error: Could not open file:" << filePath << "-" << file.errorString();
        return;
    }

    QTextStream in(&file);
    ui->flightsTableWidget->setRowCount(0); // Clear existing rows

    // Skip header row
    if (!in.atEnd()) {
        in.readLine();
    }

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        const int EXPECTED_FLIGHT_COLUMNS = 9; // Still 9 columns
        if (fields.size() == EXPECTED_FLIGHT_COLUMNS) {
            ui->flightsTableWidget->insertRow(row);

            ui->flightsTableWidget->setItem(row, 0, new QTableWidgetItem(fields.at(0).trimmed())); // Flight Number
            ui->flightsTableWidget->setItem(row, 1, new QTableWidgetItem(fields.at(1).trimmed())); // Origin
            ui->flightsTableWidget->setItem(row, 2, new QTableWidgetItem(fields.at(2).trimmed())); // Destination
            ui->flightsTableWidget->setItem(row, 3, new QTableWidgetItem(fields.at(3).trimmed())); // Departure Date
            ui->flightsTableWidget->setItem(row, 4, new QTableWidgetItem(fields.at(4).trimmed())); // Departure Time
            ui->flightsTableWidget->setItem(row, 5, new QTableWidgetItem(fields.at(5).trimmed())); // Arrival Date
            ui->flightsTableWidget->setItem(row, 6, new QTableWidgetItem(fields.at(6).trimmed())); // Arrival Time
            ui->flightsTableWidget->setItem(row, 7, new QTableWidgetItem(fields.at(7).trimmed())); // Fare
            ui->flightsTableWidget->setItem(row, 8, new QTableWidgetItem(fields.at(8).trimmed())); // Available Seats

            row++;
        } else {
            qWarning() << "Warning: Skipping malformed flight row due to incorrect field count (" << fields.size() << " instead of " << EXPECTED_FLIGHT_COLUMNS << "):" << line;
        }
    }

    file.close();
    ui->flightsTableWidget->resizeColumnsToContents(); // Adjust column widths after loading
    qDebug() << "Flights loaded from:" << filePath; // Use filePath here
}

// --- New helper function to write all data from QTableWidget to CSV ---
// This function reads all data currently in the QTableWidget and writes it back to the CSV.
// It will overwrite the existing file.
void ManageFlightsView::writeFlightsToCsv(const QString &filePath)
{
    QFile file(filePath);
    // Open the file in WriteOnly mode, Text mode, and Truncate (clears existing content)
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        // Custom QMessageBox for file write error
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("File Write Error");
        msgBox.setText("Could not write to flights.csv file.\n" + file.errorString());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: white;" // Make the message box background white
            "}"
            "QMessageBox QLabel {" // Target the QLabel that holds the message text
            "    color: black;"    // Keep the text black
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
        msgBox.exec();
        qWarning() << "Error: Could not write to file:" << filePath << "-" << file.errorString();
        return;
    }

    QTextStream out(&file);

    // First, write the header row. This MUST match the order of your columns in the table.
    out << "Flight Number,Origin,Destination,Departure Date,Departure Time,Arrival Date,Arrival Time,Fare,Available Seats\n";

    // Now, iterate through each row and column of the QTableWidget and write to CSV
    for (int row = 0; row < ui->flightsTableWidget->rowCount(); ++row) {
        QStringList rowData;
        for (int col = 0; col < ui->flightsTableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->flightsTableWidget->item(row, col);
            if (item) {
                // Enclose item text in double quotes if it contains commas or newlines
                // This is standard for CSV to handle fields with delimiters
                QString cellText = item->text();
                if (cellText.contains(',') || cellText.contains('\n') || cellText.contains('"')) {
                    cellText = "\"" + cellText.replace("\"", "\"\"") + "\"";
                }
                rowData << cellText;
            } else {
                rowData << ""; // Add empty string for empty cells
            }
        }
        out << rowData.join(',') << "\n"; // Join columns with commas and add a newline for the next row
    }

    file.close(); // Close the file
    qDebug() << "Flights data successfully written to:" << filePath;
}

// --- Implementation for Add Flight button click ---
void ManageFlightsView::on_addFlightButton_clicked()
{
    qDebug() << "Add Flight button clicked!";
    AddFlightDialog addDialog(this); // Create the dialog, 'this' makes it a child of ManageFlightsView

    // Show the dialog modally (user must interact with it before interacting with main window)
    if (addDialog.exec() == QDialog::Accepted) {
        QMap<QString, QString> newFlightData = addDialog.getFlightData();

        // Check if the dialog successfully returned data (i.e., user clicked OK and validation passed)
        if (!newFlightData.isEmpty()) {
            // Add a new row to theTableWidget
            int newRow = ui->flightsTableWidget->rowCount();
            ui->flightsTableWidget->insertRow(newRow);

            // Populate the new row with data from the dialog
            // IMPORTANT: The order here MUST match your QTableWidget columns and CSV headers
            ui->flightsTableWidget->setItem(newRow, 0, new QTableWidgetItem(newFlightData["Flight Number"]));
            ui->flightsTableWidget->setItem(newRow, 1, new QTableWidgetItem(newFlightData["Origin"]));
            ui->flightsTableWidget->setItem(newRow, 2, new QTableWidgetItem(newFlightData["Destination"]));
            ui->flightsTableWidget->setItem(newRow, 3, new QTableWidgetItem(newFlightData["Departure Date"]));
            ui->flightsTableWidget->setItem(newRow, 4, new QTableWidgetItem(newFlightData["Departure Time"]));
            ui->flightsTableWidget->setItem(newRow, 5, new QTableWidgetItem(newFlightData["Arrival Date"]));
            ui->flightsTableWidget->setItem(newRow, 6, new QTableWidgetItem(newFlightData["Arrival Time"]));
            ui->flightsTableWidget->setItem(newRow, 7, new QTableWidgetItem(newFlightData["Fare"]));
            ui->flightsTableWidget->setItem(newRow, 8, new QTableWidgetItem(newFlightData["Available Seats"]));

            // Adjust column widths to fit content
            ui->flightsTableWidget->resizeColumnsToContents();

            // --- Update CSV file ---
            // *** MODIFIED: Use AppPaths::getFlightsFilePath() ***
            writeFlightsToCsv(AppPaths::getFlightsFilePath()); // Rewrite the entire CSV with the updated table data
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Success");
            msgBox.setText("Flight added successfully and CSV updated!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setStyleSheet(
                "QMessageBox {"
                "    background-color: white;" // Make the message box background white
                "}"
                "QMessageBox QLabel {" // Target the QLabel that holds the message text
                "    color: black;"    // Keep the text black
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
            msgBox.exec();
        } else {
            // This would happen if getFlightData() returned an empty map (e.g., due to validation failure)
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Add Flight Failed");
            msgBox.setText("Flight data could not be retrieved. Please check inputs.");
            msgBox.setIcon(QMessageBox::Warning); // Set the warning icon
            msgBox.setStyleSheet(
                "QMessageBox {"
                "    background-color: white;" // Make the message box background white
                "}"
                "QMessageBox QLabel {" // Target the QLabel that holds the message text
                "    color: black;"    // Keep the text black
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
            msgBox.exec();
        }
    } else {
        qDebug() << "Add Flight dialog cancelled by user.";
    }
}

// --- Implementation for Edit Flight button click ---
void ManageFlightsView::on_editFlightButton_clicked()
{
    qDebug() << "Edit Flight button clicked!";

    QModelIndexList selectedRows = ui->flightsTableWidget->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        // Custom QMessageBox for "No Flight Selected" (Edit)
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("No Flight Selected");
        msgBox.setText("Please select a flight from the table to edit.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: white;" // Make the message box background white
            "}"
            "QMessageBox QLabel {" // Target the QLabel that holds the message text
            "    color: black;"    // Keep the text black
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
        msgBox.exec();
        return;
    }

    // Get the first selected row (since selection mode is SingleSelection)
    int selectedRow = selectedRows.first().row();

    // Extract existing data from the selected row into a QMap
    QMap<QString, QString> existingFlightData;
    // IMPORTANT: Ensure the indices match your table columns exactly
    existingFlightData["Flight Number"] = ui->flightsTableWidget->item(selectedRow, 0)->text();
    existingFlightData["Origin"] = ui->flightsTableWidget->item(selectedRow, 1)->text();
    existingFlightData["Destination"] = ui->flightsTableWidget->item(selectedRow, 2)->text();
    existingFlightData["Departure Date"] = ui->flightsTableWidget->item(selectedRow, 3)->text();
    existingFlightData["Departure Time"] = ui->flightsTableWidget->item(selectedRow, 4)->text();
    existingFlightData["Arrival Date"] = ui->flightsTableWidget->item(selectedRow, 5)->text();
    existingFlightData["Arrival Time"] = ui->flightsTableWidget->item(selectedRow, 6)->text();
    existingFlightData["Fare"] = ui->flightsTableWidget->item(selectedRow, 7)->text();
    existingFlightData["Available Seats"] = ui->flightsTableWidget->item(selectedRow, 8)->text();

    // Create and show the EditFlightDialog, pre-filling it with existing data
    EditFlightDialog editDialog(existingFlightData, this);

    if (editDialog.exec() == QDialog::Accepted) {
        QMap<QString, QString> updatedFlightData = editDialog.getFlightData();

        if (!updatedFlightData.isEmpty()) {
            // Update the QTableWidget row with the new data
            // Note: Flight Number is read-only in dialog, so it should be same.
            ui->flightsTableWidget->item(selectedRow, 1)->setText(updatedFlightData["Origin"]);
            ui->flightsTableWidget->item(selectedRow, 2)->setText(updatedFlightData["Destination"]);
            ui->flightsTableWidget->item(selectedRow, 3)->setText(updatedFlightData["Departure Date"]);
            ui->flightsTableWidget->item(selectedRow, 4)->setText(updatedFlightData["Departure Time"]);
            ui->flightsTableWidget->item(selectedRow, 5)->setText(updatedFlightData["Arrival Date"]);
            ui->flightsTableWidget->item(selectedRow, 6)->setText(updatedFlightData["Arrival Time"]);
            ui->flightsTableWidget->item(selectedRow, 7)->setText(updatedFlightData["Fare"]);
            ui->flightsTableWidget->item(selectedRow, 8)->setText(updatedFlightData["Available Seats"]);

            ui->flightsTableWidget->resizeColumnsToContents(); // Adjust column widths

            // Rewrite the CSV file to reflect the updated data
            // *** MODIFIED: Use AppPaths::getFlightsFilePath() ***
            writeFlightsToCsv(AppPaths::getFlightsFilePath());
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Success");
            msgBox.setText("Flight updated successfully and CSV updated!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setStyleSheet(
                "QMessageBox {"
                "    background-color: white;" // Make the message box background white
                "}"
                "QMessageBox QLabel {" // Target the QLabel that holds the message text
                "    color: black;"    // Keep the text black
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
            msgBox.exec();
        } else {
            // This case means validation failed inside the dialog
            // Custom QMessageBox for "Edit Flight Failed"
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Edit Flight Failed");
            msgBox.setText("Flight data could not be updated due to invalid input.");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setStyleSheet(
                "QMessageBox {"
                "    background-color: white;" // Make the message box background white
                "}"
                "QMessageBox QLabel {" // Target the QLabel that holds the message text
                "    color: black;"    // Keep the text black
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
            msgBox.exec();
        }
    } else {
        qDebug() << "Edit Flight dialog cancelled by user.";
    }
}

// --- NEW IMPLEMENTATION for Delete Flight button click ---
void ManageFlightsView::on_deleteFlightButton_clicked()
{
    qDebug() << "Delete Flight button clicked!";

    QModelIndexList selectedRows = ui->flightsTableWidget->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        // Custom QMessageBox for "No Flight Selected" (Delete)
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("No Flight Selected");
        msgBox.setText("Please select a flight from the table to delete.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: white;" // Make the message box background white
            "}"
            "QMessageBox QLabel {" // Target the QLabel that holds the message text
            "    color: black;"    // Keep the text black
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
        msgBox.exec();
        return;
    }

    // Get the first selected row (since selection mode is SingleSelection)
    int selectedRow = selectedRows.first().row();

    // Get the flight number for confirmation message
    QString flightNumber = ui->flightsTableWidget->item(selectedRow, 0)->text();

    // Ask for confirmation before deleting
    QMessageBox confirmMsgBox(this);
    confirmMsgBox.setWindowTitle("Confirm Deletion");
    confirmMsgBox.setText("Are you sure you want to delete flight " + flightNumber + "?\nThis action cannot be undone.");
    confirmMsgBox.setIcon(QMessageBox::Question);
    confirmMsgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    confirmMsgBox.setStyleSheet(
        "QMessageBox {"
        "    background-color: white;" // Make the message box background white
        "}"
        "QMessageBox QLabel {" // Target the QLabel that holds the message text
        "    color: black;"    // Keep the text black
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
    int reply = confirmMsgBox.exec();

    if (reply == QMessageBox::Yes) {
        // Remove the row from the QTableWidget
        ui->flightsTableWidget->removeRow(selectedRow);

        // Rewrite the CSV file to reflect the deletion
        // *** MODIFIED: Use AppPaths::getFlightsFilePath() ***
        writeFlightsToCsv(AppPaths::getFlightsFilePath());
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Success");
        msgBox.setText("Flight " + flightNumber + " deleted successfully and CSV updated!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: white;" // Make the message box background white
            "}"
            "QMessageBox QLabel {" // Target the QLabel that holds the message text
            "    color: black;"    // Keep the text black
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
        msgBox.exec();
    } else {
        qDebug() << "Delete Flight cancelled by user.";
    }
}
