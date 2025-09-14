#ifndef FLIGHTGENERATOR_H
#define FLIGHTGENERATOR_H

#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QRandomGenerator> // For generating random numbers
#include <QFile>           // For file operations
#include <QTextStream>     // For reading/writing text
#include <QDir>            // For directory operations
#include <QDebug>          // For debugging output
#include <QMessageBox>     // For showing messages (e.g., errors)
#include "AppPaths.h"
class FlightGenerator
{
public:
    // Static method to generate flight data if the CSV file does not exist.
    // It will create 250 random flights with details matching your Passenger_BookTicket expectations.
    static void generateFlightsIfNotExist();

private:
    // Private constructor to prevent instantiation, as this is a utility class with static methods.
    FlightGenerator() = delete;
    // Private destructor
    ~FlightGenerator() = delete;
};

#endif // FLIGHTGENERATOR_H
