#ifndef APPPATHS_H
#define APPPATHS_H

#include <QString> // Required for QString

// This class provides centralized access to all application-specific file paths.
// It uses QStandardPaths to ensure paths are correct for the current user and OS.
class AppPaths
{
public:
    // Static method to get the base directory for application data.
    // On Windows: C:/Users/YourUser/AppData/Roaming/Airlines/
    // On macOS:    ~/Library/Application Support/Airlines/
    // On Linux:    ~/.local/share/Airlines/
    static QString getBaseAppDataDirectory();

    // Static methods to get specific file paths within the base directory.
    static QString getUsersFilePath();
    static QString getFlightsFilePath();
    static QString getPassengersFilePath();
    static QString getBookingsFilePath(); // This was already here, good.
    static QString getTicketsFilePath();  // This was already here, good.

    // REMOVED: No need for a separate getAppDataPath() if getBaseAppDataDirectory() is used consistently.
    // If you explicitly intended to have a path *without* the "Airlines" subfolder,
    // then getAppDataPath() would be declared here. But for consistency with your other getters,
    // getBaseAppDataDirectory() is the correct one to use.

private:
    // Private constructor to prevent direct instantiation of this utility class.
    AppPaths() = delete;
};

#endif // APPPATHS_H
