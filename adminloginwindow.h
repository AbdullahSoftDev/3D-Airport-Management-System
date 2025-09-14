#ifndef ADMINLOGINWINDOW_H
#define ADMINLOGINWINDOW_H

#include <QWidget>
#include <QString>
#include <QFile>        // REQUIRED for file operations
#include <QTextStream> // REQUIRED for reading text from file
#include <QMessageBox> // For displaying messages
#include <QDebug>      // For debugging output
// #include "AppPaths.h" // Not strictly needed in header if AppPaths isn't used in member declarations

// Forward declarations to avoid circular dependencies
class MainWindow;
class Dashboard;

namespace Ui {
class AdminLoginWindow;
}

class AdminLoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLoginWindow(QWidget *parent = nullptr);
    ~AdminLoginWindow();

    void setMainWindow(MainWindow *window);
    void setDashboard(Dashboard *dashboard);

private slots:
    void on_loginButton_clicked();
    void on_forgotPasswordButton_clicked();
    void on_backButton_clicked();

private:
    Ui::AdminLoginWindow *ui;
    MainWindow *mainWindow;
    Dashboard *dashboard;

    void applyStyling();

    // THIS IS THE NEW FUNCTION THAT READS FROM CSV
    bool checkCredentialsFromFile(const QString &username, const QString &password);

    // REMOVED: const QString USERS_FILE_PATH = "C:/Users/Abdullah/AppData/Roaming/Airlines/users.csv";
};

#endif // ADMINLOGINWINDOW_H
