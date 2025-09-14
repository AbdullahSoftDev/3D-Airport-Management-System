#include "flightgenerator.h"
// No need to explicitly include "AppPaths.h" here if already in the header file.

// REMOVED: const QString FLIGHTS_FILE_PATH = "C:/Users/Abdullah/AppData/Roaming/Airlines/flights.csv";
// REMOVED: const QString APP_DATA_DIR = "C:/Users/Abdullah/AppData/Roaming/Airlines";


void FlightGenerator::generateFlightsIfNotExist()
{
    QString flightsFilePath = AppPaths::getFlightsFilePath(); // <<< Get the dynamic path for the file
    QString appDataDir = AppPaths::getBaseAppDataDirectory(); // <<< Get the dynamic path for the base directory

    QFile file(flightsFilePath); // <<< Use the dynamic path for the file

    // Check if the flights.csv file already exists
    if (file.exists()) {
        qDebug() << "flights.csv already exists at:" << flightsFilePath << ". Skipping generation."; // <<< CORRECTED: Use flightsFilePath
        return; // File exists, no need to generate
    }

    qDebug() << "flights.csv not found. Attempting to generate 250 random flights with specific format...";

    // Ensure the directory exists
    QDir dir(appDataDir); // <<< Use the dynamic path for the directory
    if (!dir.exists()) {
        qDebug() << "Creating directory:" << appDataDir; // <<< CORRECTED: Use appDataDir
        if (!dir.mkpath(".")) { // Create the directory (recursively if needed)
            qWarning() << "Error: Could not create directory for flights.csv:" << appDataDir; // <<< CORRECTED: Use appDataDir
            QMessageBox::critical(nullptr, "File System Error",
                                  "Could not create application data directory. Please check permissions:\n" + appDataDir); // <<< CORRECTED: Use appDataDir
            return;
        }
    }

    // Try to open the file for writing
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Error: Could not create flights.csv:" << file.errorString();
        QMessageBox::critical(nullptr, "File Creation Error",
                              "Could not create flights.csv file. Please check permissions:\n" + flightsFilePath); // <<< CORRECTED: Use flightsFilePath
        return;
    }

    QTextStream out(&file);

    // Write the CSV header
    out << "Flight Number,Origin,Destination,Departure Date,Departure Time,Arrival Date,Arrival Time,Fare,Available Seats\n";

    // Predefined list of city names for random flight generation, as per your sample data.
    QStringList airportCities = {"Doha", "Karachi", "Islamabad", "Lahore", "Paris", "Jeddah", "London", "New York", "Sialkot", "Dubai"};
    QDate startDate = QDate::currentDate().addDays(1); // Start from tomorrow, July 25, 2025
    QRandomGenerator *random = QRandomGenerator::global();

    // Generate 250 flights
    for (int i = 0; i < 250; ++i) { // Number of flights
        // Origin and Destination (ensure they are different)
        QString origin = airportCities.at(random->bounded(airportCities.size()));
        QString destination;
        do {
            destination = airportCities.at(random->bounded(airportCities.size()));
        } while (destination == origin);

        // Departure Date (within the next 30 days)
        QDate departureDate = startDate.addDays(random->bounded(30));
        QTime departureTime = QTime(random->bounded(0, 24), random->bounded(0, 60));
        QDateTime departureDateTime(departureDate, departureTime);

        // Arrival Date/Time (1 to 12 hours after departure) - adjusted to ensure realistic duration
        // The original sample shows very long durations, but for a single flight,
        // a duration of a few hours up to ~24 hours is more typical.
        int flightDurationHours = random->bounded(1, 13); // 1 to 12 hours
        int flightDurationMinutes = random->bounded(0, 60); // 0 to 59 minutes
        QDateTime arrivalDateTime = departureDateTime.addSecs(flightDurationHours * 3600 + flightDurationMinutes * 60);

        // Flight Number (e.g., PKDOKA07061895) - Matches your specific format
        QString originPrefix = origin.left(2).toUpper();
        QString destinationPrefix = destination.left(2).toUpper();
        // Format date as MMDD for flight number, using padded numbers
        QString datePrefix = departureDate.toString("MMdd");
        QString flightNumber = QString("PK%1%2%3%4").arg(originPrefix).arg(destinationPrefix).arg(datePrefix).arg(random->bounded(1000, 9999));

        // Fare (50 to 500) - Adjusted range to match sample values and format as integer
        double fare = random->bounded(50, 501); // Generates 50 to 500 (inclusive)

        // Available Seats (50 to 500) - Adjusted range to match sample values
        int availableSeats = random->bounded(50, 501); // Generates 50 to 500 (inclusive)

        // Write to CSV with specific date and time formats
        out << flightNumber << ","
            << origin << ","
            << destination << ","
            << departureDateTime.toString("M/d/yyyy") << "," // Date format M/D/YYYY
            << departureDateTime.toString("H:mm") << ","    // Time format H:MM (no leading zero for hour if single digit)
            << arrivalDateTime.toString("M/d/yyyy") << ","    // Date format M/D/YYYY
            << arrivalDateTime.toString("H:mm") << ","        // Time format H:MM (no leading zero for hour if single digit)
            << QString::number(qRound(fare)) << ","          // Fare as integer
            << QString::number(availableSeats) << "\n";
    }

    file.close();
    qDebug() << "Successfully generated 250 random flights to:" << flightsFilePath; // <<< CORRECTED: Use flightsFilePath
}
