#ifndef MARQUEELABEL_H
#define MARQUEELABEL_H

#include <QLabel>
#include <QPropertyAnimation>
#include <QResizeEvent> // Needed for resizeEvent override
#include <QShowEvent>   // Needed for showEvent override

class MarqueeLabel : public QLabel
{
    Q_OBJECT // Don't forget this macro for Qt's meta-object system

public:
    explicit MarqueeLabel(QWidget *parent = nullptr);
    ~MarqueeLabel();

    // Public slot to start the marquee animation
    void startMarquee(int durationMs);

    // Public slot to stop the marquee animation
    void stopMarquee();

    // Overrides for base QLabel methods that are defined in marqueelabel.cpp
    // These declarations are what the compiler was complaining about being missing.
    void setText(const QString &text); // Declare setText override
    void showEvent(QShowEvent *event); // Declare showEvent override
    void resizeEvent(QResizeEvent *event); // Declare resizeEvent override


private:
    QPropertyAnimation *animation;
};

#endif // MARQUEELABEL_H
