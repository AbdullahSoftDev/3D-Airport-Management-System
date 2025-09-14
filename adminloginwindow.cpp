#include "adminloginwindow.h"
#include "ui_adminloginwindow.h" // Automatically generated from your .ui file
#include "mainwindow.h"          // Needed to access MainWindow for navigation
#include "dashboard.h"           // Needed to use the Dashboard class

#include <QMessageBox> // Already included by adminloginwindow.h, but good to have here too
#include <QDebug>      // Already included by adminloginwindow.h, but good to have here too
#include "AppPaths.h"  // <<< NEW: Include your AppPaths header!

// Constructor
AdminLoginWindow::AdminLoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminLoginWindow)
{
    ui->setupUi(this);
    mainWindow = nullptr;
    dashboard = nullptr;

    setWindowTitle("Admin Login");
    applyStyling();

    // Connect the login button. Ensure it's not commented out.
    //connect(ui->loginButton, &QPushButton::clicked, this, &AdminLoginWindow::on_loginButton_clicked);
    connect(ui->forgotPasswordButton, &QPushButton::clicked, this, &AdminLoginWindow::on_forgotPasswordButton_clicked);
    connect(ui->backButton, &QPushButton::clicked, this, &AdminLoginWindow::on_backButton_clicked);

    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    qDebug() << "AdminLoginWindow created.";
}

// Destructor
AdminLoginWindow::~AdminLoginWindow()
{
    delete ui;
    qDebug() << "AdminLoginWindow destroyed.";
}

void AdminLoginWindow::setMainWindow(MainWindow *window)
{
    mainWindow = window;
}

void AdminLoginWindow::setDashboard(Dashboard *dashboard)
{
    this->dashboard = dashboard;
}

void AdminLoginWindow::applyStyling()
{
    this->setStyleSheet(
        "QWidget#AdminLoginWindow { background-color: rgb(255, 255, 255); }"
        "QLabel {"
        "    border: none;"
        "    color: black;"
        "    background-color: transparent;"
        "    font-size: 15px;"
        "}"
        "QLineEdit {"
        "    border: 0.5px solid black;"
        "    color: black;"
        "    background-color: white;"
        "    padding: 5px;"
        "}"
        "QPushButton {"
        "    border: 0.5px solid black;"
        "    color: black;"
        "    background-color: white;"
        "    padding: 5px;"
        "}"
        "QPushButton#loginButton:hover { background-color: lightgreen; }"
        "QPushButton#loginButton:pressed { background-color: lightgreen; }"
        "QPushButton#forgotPasswordButton:hover { background-color: red; }"
        "QPushButton#forgotPasswordButton:pressed { background-color: red; }"
        "QPushButton#backButton:hover { background-color: rgb(85, 170, 255); }"
        "QPushButton#backButton:pressed { background-color: rgb(85, 170, 255); }"
        );
}

// THIS IS THE NEW FUNCTION IMPLEMENTATION TO CHECK CREDENTIALS FROM THE CSV FILE
bool AdminLoginWindow::checkCredentialsFromFile(const QString &username, const QString &password)
{
    // --- CHANGE STARTS HERE ---
    QString usersFilePath = AppPaths::getUsersFilePath(); // <<< NEW: Get path dynamically
    QFile file(usersFilePath);                            // <<< Use the dynamic path

    if (!file.exists()) {
        qWarning() << "Users file not found at:" << usersFilePath; // <<< Use dynamic path for warnings
        QMessageBox::critical(this, "File Error", "User database file not found. Please ensure users.csv exists at:\n" + usersFilePath); // <<< Use dynamic path for error message
        return false;
    }
    // --- CHANGE ENDS HERE ---

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open users file for reading:" << file.errorString();
        QMessageBox::critical(this, "File Error", "Could not open user database. Please check file permissions.");
        return false;
    }

    QTextStream in(&file);
    if (!in.atEnd()) {
        in.readLine(); // Skip the header line (e.g., "Username,Password")
    }

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() == 2) { // Expecting exactly 2 fields: Username, Password
            QString fileUsername = fields.at(0).trimmed();
            QString filePassword = fields.at(1).trimmed();

            // Compare entered credentials with the current line from the file
            // Username comparison is case-insensitive
            // Password comparison is case-sensitive
            if (fileUsername.compare(username, Qt::CaseInsensitive) == 0 && filePassword == password) {
                file.close(); // Important: Close the file as soon as a match is found
                return true;  // Credentials match!
            }
        } else {
            qWarning() << "Skipping malformed line in users.csv:" << line;
        }
    }

    file.close(); // Close the file if no match is found after checking all lines
    return false; // No matching credentials found
}

// Slot for login button click
void AdminLoginWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text();

    QString msgBoxStyle = "QMessageBox { background-color: white; } QLabel { color: black; border: none; font-weight: bold; } QPushButton { background-color: lightgray; color: black; border: 0.5px solid darkgray; border-radius: 3px; padding: 5px 20px; } QPushButton:hover { background-color: gray; }";

    if (username.isEmpty() || password.isEmpty()) {
        ui->statusLabel->setText("Status: Please enter both username and password.");
        QMessageBox msgBox(this);
        msgBox.setText("Username and password cannot be empty.");
        msgBox.setWindowTitle("Login Failed");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(msgBoxStyle);
        msgBox.exec();
        return;
    }

    // Call the new function to check credentials from the file
    if (checkCredentialsFromFile(username, password)) { // <<< This line remains the same logic
        ui->statusLabel->setText("Status: Login Successful!");
        QMessageBox msgBox(this);
        msgBox.setText("Welcome, Admin!");
        msgBox.setWindowTitle("Login Success");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet(msgBoxStyle);
        msgBox.exec();

        if (dashboard) {
            this->hide();
            dashboard->show();

            if (mainWindow) {
                disconnect(dashboard, &Dashboard::logoutRequested, mainWindow, &MainWindow::show);
                connect(dashboard, &Dashboard::logoutRequested, mainWindow, &MainWindow::show);
            } else {
                qDebug() << "Warning: MainWindow pointer is null, cannot set up logout navigation from Dashboard.";
            }

            ui->usernameLineEdit->clear();
            ui->passwordLineEdit->clear();
            ui->statusLabel->setText("Status:");
            qDebug() << "Admin logged in successfully, showing Dashboard.";
        } else {
            QMessageBox::warning(this, "Navigation Error", "Dashboard not accessible after login. Please ensure it's set.");
            qDebug() << "Error: Dashboard pointer not set in AdminLoginWindow!";
        }
    } else { // Login failed (either username not found or password incorrect)
        ui->statusLabel->setText("Status: Invalid Username or Password.");
        QMessageBox msgBox(this);
        msgBox.setText("Invalid Username or Password.");
        msgBox.setWindowTitle("Login Failed");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(msgBoxStyle);
        msgBox.exec();
        ui->passwordLineEdit->clear(); // Clear password field on failure
        qDebug() << "Admin login failed for username:" << username;
    }
}

void AdminLoginWindow::on_forgotPasswordButton_clicked()
{
    QString msgBoxStyle = "QMessageBox { background-color: white; } QLabel { color: black; border: none; font-weight: bold; } QPushButton { background-color: lightgray; color: black; border: 0.5px solid darkgray; border-radius: 3px; padding: 5px 20px; } QPushButton:hover { background-color: gray; }";

    QMessageBox msgBox(this);
    msgBox.setText("Please contact the system administrator to reset your password.");
    msgBox.setWindowTitle("Forgot Password");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStyleSheet(msgBoxStyle);
    msgBox.exec();
    ui->statusLabel->setText("Status: Forgot Password clicked.");
    qDebug() << "Forgot Password button clicked.";
}

void AdminLoginWindow::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
        this->hide();
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
        ui->statusLabel->setText("Status:");
        qDebug() << "Navigating back to Main Window from Admin Login.";
    } else {
        QMessageBox::warning(this, "Navigation Error", "Cannot go back: Main Window not accessible.");
        qDebug() << "Error: MainWindow pointer not set in AdminLoginWindow!";
    }
}
