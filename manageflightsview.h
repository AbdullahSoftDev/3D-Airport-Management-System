#ifndef MANAGEFLIGHTSVIEW_H
#define MANAGEFLIGHTSVIEW_H

#include <QWidget>
#include "addflightdialog.h"

namespace Ui {
class ManageFlightsView;
}

class ManageFlightsView : public QWidget
{
    Q_OBJECT

public:
    explicit ManageFlightsView(QWidget *parent = nullptr);
    ~ManageFlightsView();

    // Make loadFlights public so Dashboard can call it
    void loadFlights(); // <--- MOVED TO PUBLIC

private slots:
    void on_addFlightButton_clicked();
    void on_editFlightButton_clicked();
    void on_deleteFlightButton_clicked();

private:
    Ui::ManageFlightsView *ui;
    void applyTableStyling();
    void writeFlightsToCsv(const QString &filePath);
};

#endif // MANAGEFLIGHTSVIEW_H
