#include "bookticketdialog.h"
#include "ui_bookticketdialog.h" // Generated from BookTicketDialog.ui by uic

#include <QMessageBox>          // For QMessageBox
#include <QDebug>               // For qDebug
#include <QFile>                // For QFile
#include <QTextStream>          // For QTextStream
#include <QDateTime>            // For QDateTime (to generate timestamp and get current time)
#include <QRandomGenerator>     // For QRandomGenerator (to generate unique ID part)
#include <QCoreApplication>     // For QCoreApplication::applicationDirPath() - Not strictly needed if AppPaths is used fully
#include <QDir>                 // For QDir
#include <QFileInfo>            // For QFileInfo
#include "AppPaths.h"           // <<< NEW: Include your AppPaths header!


// Define a placeholder fare per seat (you can make this more dynamic later)
const double FARE_PER_SEAT = 150.00; // Example: 150.00 currency units per seat

BookTicketDialog::BookTicketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTicketDialog)
{
    ui->setupUi(this); // Initialize the UI from the .ui file

    // Set the initial date/time in the QDateTimeEdit to the current system date and time
    ui->bookingDateTimeEdit->setDateTime(QDateTime::currentDateTime());

    // Connect the signals from the QDialogButtonBox (OK/Cancel buttons) to their respective slots
    // THESE WERE COMMENTED OUT - UNCOMMENTING THEM SO YOUR BUTTONS WORK!
    //connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &BookTicketDialog::on_buttonBox_accepted);
    //connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &BookTicketDialog::on_buttonBox_rejected);
    qDebug() << "BookTicketDialog created.";
}

BookTicketDialog::~BookTicketDialog()
{
    delete ui; // Clean up the dynamically allocated Ui object
    qDebug() << "BookTicketDialog destroyed.";
}

// --- Getter Methods ---
// These methods allow the calling class (ManageBookingsView) to retrieve the input data
QString BookTicketDialog::getFlightNumber() const
{
    return ui->flightNumberLineEdit->text().trimmed(); // Get text and remove leading/trailing whitespace
}

QString BookTicketDialog::getPassengerName() const
{
    return ui->passengerNameLineEdit->text().trimmed(); // Get text and remove leading/trailing whitespace
}

int BookTicketDialog::getSeatsBooked() const
{
    return ui->seatsBookedSpinBox->value(); // Get the integer value from the spin box
}

QString BookTicketDialog::getBookingDateTime() const
{
    // Get the QDateTime object and format it into a string that matches your CSV format
    // (e.g., "YYYY-MM-DD HH:MM:SS")
    return ui->bookingDateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss");
}

// --- Private Helper Functions ---
QString BookTicketDialog::generateBookingID() const
{
    // Generates a simple unique booking ID.
    // This method combines a timestamp with a small random number to reduce collisions.
    // For a production system, a more robust ID generation (e.g., database auto-increment)
    // or checking for existing IDs would be necessary.
    QDateTime current = QDateTime::currentDateTime();
    QString timestamp = current.toString("yyyyMMddHHmmsszzz"); // Format: YearMonthDayHourMinSecMilliSec
    quint32 randomNum = QRandomGenerator::global()->generate(); // Get a random 32-bit unsigned integer

    // Format the ID as "BK" followed by timestamp and last 4 digits of random number
    return QString("BK%1%2").arg(timestamp).arg(randomNum % 10000);
}

double BookTicketDialog::calculateTotalFare(int seats) const
{
    // Calculates the total fare based on the number of seats and a predefined fare per seat.
    return seats * FARE_PER_SEAT;
}

// --- Slot Implementations ---
void BookTicketDialog::on_buttonBox_accepted()
{
    // This slot is called when the user clicks the "Book Ticket" (OK) button.

    // 1. Retrieve all necessary data from the UI input fields
    QString flightNumber = ui->flightNumberLineEdit->text().trimmed();
    QString passengerName = ui->passengerNameLineEdit->text().trimmed();
    int seatsBooked = ui->seatsBookedSpinBox->value();
    QString bookingDateTime = ui->bookingDateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss");

    double totalFare = calculateTotalFare(seatsBooked);

    // 2. Basic input validation
    // Check if essential fields are not empty and seats booked is a positive number
    if (flightNumber.isEmpty() || passengerName.isEmpty() || seatsBooked <= 0) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please fill in all required fields (Flight Number, Passenger Name, Seats Booked) and ensure seats are positive.");
        msgBox.setIcon(QMessageBox::Warning); // Set the warning icon
        // Apply the desired stylesheet
        msgBox.setStyleSheet(
            "QMessageBox { background-color: white;}"
            "QLabel { color: black;}"
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
        msgBox.exec(); // Display the message box
        return; // Do not close the dialog; let the user correct the input
    }

    // 3. Generate a unique Booking ID for this new booking
    QString bookingID = generateBookingID();

    // 4. Prepare the new booking record as a QStringList
    // The order of elements here MUST match the column order in your tickets.csv file:
    // BookingID,FlightNumber,PassengerName,PassengerContact,BookingDateTime,SeatsBooked,TotalFare,Status
    QStringList newBookingRecord;
    newBookingRecord << bookingID
                     << flightNumber
                     << passengerName
                     << "" // Use empty string for PassengerContact as there's no UI input for it
                     << bookingDateTime
                     << QString::number(seatsBooked)
                     << QString::number(totalFare, 'f', 2) // Format total fare to 2 decimal places
                     << "Booked"; // Hardcode Status to "Booked" as there's no UI input for it

    // 5. Read existing data from the CSV file and append the new record
    // First, define the path using AppPaths
    QString bookingsFilePath = AppPaths::getTicketsFilePath();
    QFile file(bookingsFilePath); // <<< Use the dynamic path

    QStringList existingLines; // This list will hold all lines, including the header and existing bookings

    QDir dir(QFileInfo(bookingsFilePath).dir().path()); // <<< Use dynamic path
    if (!dir.exists()) {
        if (!dir.mkpath(dir.path())) { // Try to create the directory path
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("File Error");
            msgBox.setText("Could not create directory for bookings file: " + dir.path());
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStyleSheet(
                "QMessageBox { background-color: black; color: white; font-weight: bold; }"
                "QLabel { color: white; font-weight: bold; }"
                "QPushButton { background-color: #555555; color: white; border: 1px solid #777777; padding: 5px 10px; min-width: 60px; }"
                "QPushButton:hover { background-color: #777777; }"
                );
            msgBox.exec();
            qWarning() << "Error: Could not create directory for bookings file:" << dir.path();
            return; // Exit if directory creation fails
        }
    }

    // Check if the file already exists
    if (file.exists()) {
        // If file exists, open it in read-only mode to get its current content
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("File Error");
            msgBox.setText("Could not open bookings file for reading.\n" + file.errorString());
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStyleSheet(
                "QMessageBox { background-color: black; color: white; font-weight: bold; }"
                "QLabel { color: white; font-weight: bold; }"
                "QPushButton { background-color: #555555; color: white; border: 1px solid #777777; padding: 5px 10px; min-width: 60px; }"
                "QPushButton:hover { background-color: #777777; }"
                );
            msgBox.exec();
            qWarning() << "Error: Could not open file for reading:" << file.errorString();
            return; // Exit if file cannot be opened for reading
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            existingLines << in.readLine(); // Read all lines into the list
        }
        file.close(); // Close the file after reading

        // Ensure the header is present as the first line.
        // This handles cases where the file might be empty or corrupted (missing header).
        if (existingLines.isEmpty() || !existingLines.first().startsWith("BookingID,")) {
            existingLines.prepend("BookingID,FlightNumber,PassengerName,PassengerContact,BookingDateTime,SeatsBooked,TotalFare,Status");
        }
    } else {
        // If the file does not exist, initialize existingLines with just the header
        existingLines << "BookingID,FlightNumber,PassengerName,PassengerContact,BookingDateTime,SeatsBooked,TotalFare,Status";
    }

    // Append the new booking record (formatted as a comma-separated string) to the list
    QString newRecordLine = newBookingRecord.join(',');
    existingLines << newRecordLine;

    // 6. Write all data (header + old records + new record) back to the file
    // Open in WriteOnly mode with Truncate to overwrite the entire file with the updated content
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("File Error");
        msgBox.setText("Could not save booking to file.\n" + file.errorString());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(
            "QMessageBox { background-color: black; color: white; font-weight: bold; }"
            "QLabel { color: white; font-weight: bold; }"
            "QPushButton {"
            "    background-color: lightgray;"
            "    color: black;"
            "    border: 1px solid #c0c0c0;"
            "    padding: 5px 15px;"
            "    border-radius: 3px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #d0d0d0;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #c0c0c0;"
            "}"
            );
        msgBox.exec();
        qWarning() << "Error: Could not open file for writing:" << file.errorString();
        return; // Exit if file cannot be opened for writing
    }
    QTextStream out(&file);
    for (const QString &line : existingLines) {
        out << line << "\n"; // Write each line followed by a newline character
    }
    file.close(); // Close the file after writing

    qDebug() << "New booking successfully added to:" << bookingsFilePath;

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Booking Successful");
    msgBox.setText("New ticket booked successfully!\nBooking ID: " + bookingID);
    msgBox.setIcon(QMessageBox::Information); // Set the information icon
    msgBox.setStyleSheet(
        "QMessageBox { background-color: white;}"
        "QLabel { color: black;}"
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
    msgBox.exec(); // Display the message box


    // 7. Emit a signal (optional) and accept the dialog to close it
    emit bookingDataReady(newBookingRecord); // Emits the data of the new record
    accept(); // Close the dialog with an "Accepted" status, indicating success
}

void BookTicketDialog::on_buttonBox_rejected()
{
    // This slot is called when the user clicks the "Cancel" button or closes the dialog.
    qDebug() << "Book ticket dialog cancelled.";
    reject(); // Close the dialog with a "Rejected" status
}
