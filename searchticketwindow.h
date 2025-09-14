#ifndef SEARCHTICKETWINDOW_H
#define SEARCHTICKETWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDate>
#include <QVector>
#include "AppPaths.h"

// Forward declaration of MainWindow to avoid circular includes
class MainWindow;

namespace Ui {
class SearchTicketWindow;
}

class SearchTicketWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchTicketWindow(QWidget *parent = nullptr);
    ~SearchTicketWindow();

    void setMainWindow(MainWindow *window);

private slots:
    void performSearch();
    void on_searchButton_clicked();
    void on_backButton_clicked();

private:
    Ui::SearchTicketWindow *ui;
    MainWindow *mainWindow;

    void loadTicketsFromCsv(const QString &filePath);
};

#endif // SEARCHTICKETWINDOW_H
