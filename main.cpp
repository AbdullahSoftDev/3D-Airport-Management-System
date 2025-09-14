#include <QApplication> // Required for Qt application
#include "mainwindow.h"   // Include your main window header
#include "flightgenerator.h" // Assuming this is needed for your flight generation logic
#include "usermanagerinitializer.h"
#include "CsvInitializer.h"
#include <QGuiApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // --- Start: Global QMessageBox Styling ---
    // This stylesheet will apply to all QMessageBox instances in your application.
    // --- End: Global QMessageBox Styling ---
    a.setWindowIcon(QIcon(":/icons/flight_30822.ico")); // <--- Add this line
    CsvInitializer::ensureFilesExist();
    FlightGenerator::generateFlightsIfNotExist();
    FlightGenerator::generateFlightsIfNotExist(); // Keep your existing flight generation logic
    UserManagerInitializer::initializeUsersFile();
    MainWindow w;
    w.showMaximized(); // Keep your window maximization

    return a.exec();
}
