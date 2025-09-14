#include "CsvInitializer.h"
#include <QFile>        // For file operations
#include <QTextStream>  // For reading/writing text to files
#include <QDir>         // For directory operations (creating folders)
#include <QFileInfo>    // For getting file information (like directory path)
#include <QDebug>       // For debugging output

// Helper static method to create a single CSV file if it doesn't exist.
// It also ensures the file's parent directory exists.
bool CsvInitializer::createFileWithHeader(const QString &filePath, const QString &header)
{
    QFile file(filePath);

    // Get the directory of the file. Your AppPaths::getBaseAppDataDirectory()
    // should already handle creating the main "Airlines" folder. This is a safeguard.
    QDir dir(QFileInfo(filePath).dir().path());

    // Ensure the directory for the file exists
    if (!dir.exists()) {
        qDebug() << "CsvInitializer: Directory for" << QFileInfo(filePath).fileName() << "does not exist. Attempting to create:" << dir.path();
        if (!dir.mkpath(dir.path())) { // Create the full directory path
            qWarning() << "CsvInitializer: Error: Could not create directory for" << QFileInfo(filePath).fileName() << ":" << dir.path();
            return false; // Indicate failure
        }
    }

    // Check if the file exists. If not, create it and write the header.
    if (!file.exists()) {
        qDebug() << "CsvInitializer: File" << QFileInfo(filePath).fileName() << "not found. Creating with header.";

        // Open the file in WriteOnly mode with Text flag; this will create it if it doesn't exist.
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "CsvInitializer: Error: Could not create file" << QFileInfo(filePath).fileName() << ":" << file.errorString();
            return false; // Indicate failure
        }

        QTextStream out(&file);
        out << header << "\n"; // Write the provided header followed by a newline
        file.close();
        qDebug() << "CsvInitializer: Successfully created" << QFileInfo(filePath).fileName() << "with header.";
        return true; // Indicate success
    } else {
        qDebug() << "CsvInitializer: File" << QFileInfo(filePath).fileName() << "already exists. No action needed.";
        return true; // Indicate success (file already exists)
    }
}

// Main static method to ensure only tickets.csv and bookings.csv exist with their headers.
void CsvInitializer::ensureFilesExist()
{
    qDebug() << "CsvInitializer: Starting CSV file existence check and initialization...";

    // Header for booking-related data (8 columns, as per previous discussions)
    const QString bookingHeader = "Booking ID,Flight Number,Passenger Name,Contact Number,Booking Date Time,Seats Booked,Total Fare,Status";

    // 1. Ensure bookings.csv exists
    if (!createFileWithHeader(AppPaths::getBookingsFilePath(), bookingHeader)) {
        qWarning() << "CsvInitializer: Failed to ensure bookings.csv exists. Booking functionality might be affected.";
    }

    // 2. Ensure tickets.csv exists
    // As per previous discussion, if this file has a different purpose, you'd need a different header.
    // Otherwise, if it duplicates bookings.csv, consider if it's truly needed.
    if (!createFileWithHeader(AppPaths::getTicketsFilePath(), bookingHeader)) {
        qWarning() << "CsvInitializer: Failed to ensure tickets.csv exists.";
    }

    qDebug() << "CsvInitializer: CSV file existence check and initialization complete.";
}
