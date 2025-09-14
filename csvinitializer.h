#ifndef CSVINITIALIZER_H
#define CSVINITIALIZER_H

#include <QString> // Required for QString
#include "AppPaths.h" // Your existing AppPaths class to get file locations

// CsvInitializer: A simple utility class to ensure specific CSV data files
// (tickets.csv and flights.csv) exist with their headers at application startup.
class CsvInitializer
{
public:
    // Static method to initialize the required CSV files.
    // Call this once at application startup (e.g., in main.cpp).
    static void ensureFilesExist();

private:
    // Private constructor to prevent instantiation, as it's a static utility class.
    CsvInitializer() = delete;

    // Helper static method to create a single CSV file if it doesn't exist,
    // and write the specified header to it.
    static bool createFileWithHeader(const QString &filePath, const QString &header);
};

#endif // CSVINITIALIZER_H
