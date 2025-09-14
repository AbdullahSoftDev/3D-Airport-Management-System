#include "usermanagerinitializer.h"
#include <QFile>        // For file operations
#include <QTextStream>  // For reading/writing text to files
#include <QDir>         // For directory operations
#include <QFileInfo>    // For getting file information (like directory path)
#include <QDebug>       // For debugging output
#include "AppPaths.h"   // Include AppPaths to get the standard file path

// The static constant member USERS_FILE_PATH is no longer defined here
// as its value is now retrieved dynamically via AppPaths::getUsersFilePath().
// const QString UserManagerInitializer::USERS_FILE_PATH = "C:/Users/Abdullah/AppData/Roaming/Airlines/users.csv"; // This line is correctly commented/removed

void UserManagerInitializer::initializeUsersFile()
{
    // Get the users file path using the AppPaths utility class.
    // This ensures the path is platform-independent and adheres to system standards.
    const QString usersFilePath = AppPaths::getUsersFilePath();
    QFile file(usersFilePath);

    // --- Ensure the application data directory exists ---
    // Get the directory object for the file's path (e.g., C:/Users/Abdullah/AppData/Roaming/Airlines)
    QDir dir(QFileInfo(usersFilePath).dir().path());
    if (!dir.exists()) { // Check if the directory exists
        qDebug() << "UserManagerInitializer: Directory for users file does not exist. Creating:" << dir.path();
        if (!dir.mkpath(dir.path())) { // Try to create the full directory path
            qWarning() << "UserManagerInitializer: Error: Could not create directory for users file:" << dir.path() << "-" << file.errorString();
            // In a production application, you might want to log this error more persistently
            // or notify the user with a QMessageBox if the application cannot proceed.
            return; // Exit if the directory cannot be created
        }
    }

    // --- Check if the users.csv file exists ---
    if (!file.exists()) {
        qDebug() << "UserManagerInitializer: Users file not found at" << usersFilePath << ". Attempting to create with header and default admin.";

        // Try to create and open the file for writing.
        // QIODevice::WriteOnly: Opens the file for writing.
        // QIODevice::Text: Treats the content as text (handles line endings).
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "UserManagerInitializer: Error: Could not create users file:" << file.errorString();
            // Similar to directory creation, handle this critical error appropriately.
            return; // Exit if the file cannot be created
        }

        QTextStream out(&file); // Create a text stream to write to the file
        out << "Username,Password\n"; // Write the CSV header line
        out << "admin,123\n";          // Write the default admin user credentials

        file.close(); // Close the file, ensuring all data is written to disk
        qDebug() << "UserManagerInitializer: Created users file with header and default admin at:" << usersFilePath;
    } else {
        qDebug() << "UserManagerInitializer: Users file already exists at" << usersFilePath << ". No action needed.";
    }
}
