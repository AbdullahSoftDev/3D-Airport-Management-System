#ifndef VIEWBOOKINGSVIEW_H
#define VIEWBOOKINGSVIEW_H

#include <QWidget>
#include <QTableWidget> // For displaying data in a table
#include <QHeaderView>  // For styling table headers
#include <QFile>        // For file operations
#include <QTextStream>  // For reading text from file
#include <QMessageBox>  // For displaying error messages
#include <QDebug>       // For debugging output
#include "AppPaths.h"

namespace Ui {
class ViewBookingsView;
}

class ViewBookingsView : public QWidget
{
    Q_OBJECT

public:
    explicit ViewBookingsView(QWidget *parent = nullptr);
    ~ViewBookingsView();

    // Method to load and display booking data
    void loadBookings();

private:
    Ui::ViewBookingsView *ui;

    // Helper method for styling the table
    void applyTableStyling();
};

#endif // VIEWBOOKINGSVIEW_H
