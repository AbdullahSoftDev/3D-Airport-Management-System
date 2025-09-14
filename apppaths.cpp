#include "AppPaths.h"
#include <QStandardPaths> // For getting standard OS paths
#include <QDir>           // For directory operations (creating folders)
#include <QFileInfo>      // For getting file info (like directory path from a file path)
#include <QDebug>         // For debugging output

// Helper function to get the base application data directory and ensure it exists.
// This will create the "Airlines" subfolder if it doesn't exist.
QString AppPaths::getBaseAppDataDirectory()
{
    // Get the standard writable location for application data for the current user.
    // This resolves to different paths on different OSes (e.g., AppData/Roaming on Windows).
    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir appDir(appDataLocation);

    // Define your application's specific subfolder within the standard AppData location.
    // This creates a path like: C:/Users/YourUser/AppData/Roaming/Airlines/
    QString appSpecificPath = appDir.filePath("Airlines"); // "Airlines" is your app's main data folder

    // Ensure this specific directory exists. If it doesn't, create it and any missing parent directories.
    if (!QDir(appSpecificPath).exists()) {
        qDebug() << "AppPaths: Application data directory does not exist. Creating:" << appSpecificPath;
        // mkpath creates the directory and any necessary parent directories.
        if (!QDir().mkpath(appSpecificPath)) {
            qWarning() << "AppPaths: Error: Could not create application data directory:" << appSpecificPath;
            return QString(); // Return an empty string to indicate failure
        }
    }
    return appSpecificPath; // Return the path to your app's data directory
}

QString AppPaths::getBookingsFilePath()
{
    QString base = getBaseAppDataDirectory();
    if (base.isEmpty()) return QString();
    return QDir(base).filePath("bookings.csv");
}

// Implementation for getting the users.csv file path
QString AppPaths::getUsersFilePath()
{
    QString base = getBaseAppDataDirectory(); // Get the base directory
    if (base.isEmpty()) return QString();      // Handle case where base directory couldn't be created
    return QDir(base).filePath("users.csv"); // Append the filename
}

// Implementation for getting the flights.csv file path
QString AppPaths::getFlightsFilePath()
{
    QString base = getBaseAppDataDirectory();
    if (base.isEmpty()) return QString();
    return QDir(base).filePath("flights.csv");
}

// Implementation for getting the passengers.csv file path
QString AppPaths::getPassengersFilePath()
{
    QString base = getBaseAppDataDirectory();
    if (base.isEmpty()) return QString();
    return QDir(base).filePath("passengers.csv");
}

// Implementation for getting the tickets.csv file path
QString AppPaths::getTicketsFilePath()
{
    // CORRECTED: Call getBaseAppDataDirectory() directly
    QString base = getBaseAppDataDirectory();
    if (base.isEmpty()) return QString();
    return QDir(base).filePath("tickets.csv"); // Ensure "tickets.csv" matches your actual filename
}
// Add implementations for any other file paths you define in AppPaths.h
/*
QString AppPaths::getSettingsFilePath()
{
    QString base = getBaseAppDataDirectory();
    if (base.isEmpty()) return QString();
    return QDir(base).filePath("settings.ini");
}
*/
