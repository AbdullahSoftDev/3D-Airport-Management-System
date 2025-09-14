#ifndef ADDFLIGHTDIALOG_H
#define ADDFLIGHTDIALOG_H

#include <QDialog>
#include <QMap>    // We'll use QMap to easily return the flight data
#include <QDate>   // Needed for QDateEdit
#include <QTime>   // Needed for QTimeEdit

namespace Ui {
class AddFlightDialog;
}

class AddFlightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFlightDialog(QWidget *parent = nullptr);
    ~AddFlightDialog();

    // This method will collect all the data from the input fields
    // and return it as a QMap (key-value pairs)
    QMap<QString, QString> getFlightData();

private:
    Ui::AddFlightDialog *ui;
};

#endif // ADDFLIGHTDIALOG_H
