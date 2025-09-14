#include "addflightdialog.h"
#include "ui_addflightdialog.h" // This is generated from your .ui file
#include <QMessageBox> // For showing messages (like errors)
#include <QDebug>      // For printing debug messages to Application Output

AddFlightDialog::AddFlightDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFlightDialog)
{
    ui->setupUi(this); // This sets up all the widgets from your .ui file
    setWindowTitle("Add New Flight"); // Set the window title for the dialog

    // Set default date/time to the current date/time for user convenience
    ui->departureDateEdit->setDate(QDate::currentDate());
    ui->departureTimeEdit->setTime(QTime::currentTime());
    ui->arrivalDateEdit->setDate(QDate::currentDate());
    ui->arrivalTimeEdit->setTime(QTime::currentTime());

    // Connect the standard OK/Cancel buttons to the dialog's accept/reject slots
    // When OK is clicked, accept() is called; when Cancel is clicked, reject() is called.
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddFlightDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &AddFlightDialog::reject);

    qDebug() << "AddFlightDialog constructor called.";
}

AddFlightDialog::~AddFlightDialog()
{
    delete ui; // Clean up the UI widgets
    qDebug() << "AddFlightDialog destructor called.";
}

// This function gathers all the user-entered data from the dialog
QMap<QString, QString> AddFlightDialog::getFlightData()
{
    QMap<QString, QString> data; // A map to store key-value pairs of flight data

    // Define the common stylesheet for QMessageBox instances in this dialog
    QString msgBoxStyle =
        "QMessageBox {"
        "    background-color: white; /* Main message box background */"
        "    border: 1px solid #c0c0c0; /* Optional: add a border to the message box */"
        "    padding: 10px; /* Padding inside the message box */"
        "}"
        "QMessageBox QLabel {"
        "    color: black;"           // Text color
        "    background-color: transparent;" // Ensure QLabel's own background is transparent to show QMessageBox background
        "    font-weight: normal;"    // Ensure text is not bold
        "}"
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
        "}";


    // --- Input Validation: Check if essential text fields are empty ---
    if (ui->flightNumberLineEdit->text().trimmed().isEmpty() ||
        ui->originLineEdit->text().trimmed().isEmpty() ||
        ui->destinationLineEdit->text().trimmed().isEmpty() ||
        ui->fareLineEdit->text().trimmed().isEmpty() ||
        ui->availableSeatsLineEdit->text().trimmed().isEmpty())
    {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning); // Set the icon (the warning triangle)
        msgBox.setWindowTitle("Input Error"); // Set the title
        msgBox.setText("Please fill in all required fields."); // Set the message text
        msgBox.setStyleSheet(msgBoxStyle); // Apply the common stylesheet
        msgBox.exec(); // Show the dialog modally
        return QMap<QString, QString>(); // Return an empty map to signal an error
    }

    // Validate Fare: must be a valid positive number
    bool fareOk;
    double fare = ui->fareLineEdit->text().trimmed().toDouble(&fareOk);
    if (!fareOk || fare < 0) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please enter a valid positive number for Fare.");
        msgBox.setStyleSheet(msgBoxStyle); // Apply the common stylesheet
        msgBox.exec();
        return QMap<QString, QString>();
    }

    // Validate Available Seats: must be a valid non-negative integer
    bool seatsOk;
    int availableSeats = ui->availableSeatsLineEdit->text().trimmed().toInt(&seatsOk);
    if (!seatsOk || availableSeats < 0) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please enter a valid non-negative number for Available Seats.");
        msgBox.setStyleSheet(msgBoxStyle); // Apply the common stylesheet
        msgBox.exec();
        return QMap<QString, QString>();
    }

    // --- Collect Data (if validation passes) ---
    // Ensure the keys here match the column headers in your CSV and QTableWidget
    data["Flight Number"] = ui->flightNumberLineEdit->text().trimmed();
    data["Origin"] = ui->originLineEdit->text().trimmed();
    data["Destination"] = ui->destinationLineEdit->text().trimmed();
    data["Departure Date"] = ui->departureDateEdit->date().toString("M/d/yyyy"); // Format date to match CSV
    data["Departure Time"] = ui->departureTimeEdit->time().toString("h:mm");        // Format time to match CSV
    data["Arrival Date"] = ui->arrivalDateEdit->date().toString("M/d/yyyy");
    data["Arrival Time"] = ui->arrivalTimeEdit->time().toString("h:mm");
    data["Fare"] = QString::number(fare, 'f', 2); // Format fare to 2 decimal places
    data["Available Seats"] = QString::number(availableSeats);

    qDebug() << "Flight data collected:" << data;
    return data; // Return the map with collected data
}
