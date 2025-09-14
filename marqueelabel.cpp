#include "marqueelabel.h"
#include <QFontMetrics> // To measure text width
#include <QPoint>       // For position animation
#include <QEasingCurve> // For animation easing (e.g., linear for constant speed)
#include <QDebug>       // For debugging output

MarqueeLabel::MarqueeLabel(QWidget *parent)
    : QLabel(parent) // Call QLabel constructor
{
    // Initialize animation pointer. Parent the animation to 'this' (the MarqueeLabel)
    // This ensures the animation is automatically deleted when MarqueeLabel is deleted.
    animation = new QPropertyAnimation(this, "pos", this);

    // Set text alignment to left for scrolling effect.
    // Vertical center alignment is good for text within the label's height.
    setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    // Remove default padding/margins that might interfere with precise positioning
    setContentsMargins(0, 0, 0, 0);

    // This is important: Disable QLabel's default auto-sizing behavior
    // We want the QLabel (MarqueeLabel instance) to have a fixed width (that of its parent, label_3)
    // so that the text can scroll within it.
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed); // Ignore horizontal size hint, fix vertical
    // Or, you can use setFixedWidth() in MainWindow if you prefer.
    // For now, this policy hints to layouts that its horizontal size can be ignored.

    // Enable auto fill background so that the transparent background-color in stylesheet works
    setAutoFillBackground(true);
}

MarqueeLabel::~MarqueeLabel()
{
    // The animation is parented to 'this', so it will be automatically deleted by Qt.
    // No need to explicitly delete 'animation' here, unless it was not parented.
    // However, stopping it is good practice to ensure no lingering animations.
    if (animation->state() == QAbstractAnimation::Running) {
        animation->stop();
    }
}

// Override setText to ensure animation is restarted if text changes
void MarqueeLabel::setText(const QString &text)
{
    QLabel::setText(text); // Call base QLabel's setText
    // Restart animation if text changes and it's already visible
    if (isVisible()) {
        startMarquee(animation->duration()); // Use current duration
    }
}

// Override showEvent to start animation when the label becomes visible
void MarqueeLabel::showEvent(QShowEvent *event)
{
    QLabel::showEvent(event); // Call base class implementation
    startMarquee(animation->duration() > 0 ? animation->duration() : 20000); // Start with default if no duration set
}

// Override resizeEvent to restart animation if label size changes
void MarqueeLabel::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event); // Call base class implementation
    // Restart animation to recalculate positions based on new size
    startMarquee(animation->duration() > 0 ? animation->duration() : 20000);
}


void MarqueeLabel::startMarquee(int durationMs)
{
    // Stop any existing animation first
    if (animation->state() == QAbstractAnimation::Running) {
        animation->stop();
    }

    if (text().isEmpty()) {
        qDebug() << "MarqueeLabel: Text is empty, cannot start animation.";
        return;
    }

    // Measure the actual width of the text with current font
    QFontMetrics fm(font());
    int textWidth = fm.horizontalAdvance(text());

    // Get the current width of the MarqueeLabel widget itself
    int labelWidth = this->width();

    qDebug() << "MarqueeLabel: Starting animation...";
    qDebug() << "MarqueeLabel: Text: '" << text() << "'";
    qDebug() << "MarqueeLabel: Calculated textWidth: " << textWidth;
    qDebug() << "MarqueeLabel: Current labelWidth (from this->width()): " << labelWidth;

    // If text is not wider than the label, no need to scroll
    if (textWidth <= labelWidth) {
        qDebug() << "MarqueeLabel: Text fits within label. No scrolling needed. textWidth:" << textWidth << "labelWidth:" << labelWidth;
        // If text fits, just display it centered and don't animate
        setAlignment(Qt::AlignCenter | Qt::AlignVCenter); // Center text
        // Reset position to (0, y()) to ensure it's at the start of the label
        animation->stop(); // Stop any pending animation
        move(0, y()); // Move to start of label's content area
        return;
    }

    // Otherwise, set up animation
    setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Align left for scrolling

    animation->setDuration(durationMs);
    animation->setLoopCount(-1); // Loop indefinitely
    animation->setEasingCurve(QEasingCurve::Linear); // Constant scrolling speed

    // Calculate start and end positions relative to the MarqueeLabel's own top-left corner
    // The Y position remains constant (this->y()) as we are only animating X.
    // Start from the right edge of the label's visible area
    // End when the text is completely off the left edge of the label's visible area
    int startX = labelWidth; // Start X: right edge of the label's content area
    int endX = -textWidth;   // End X: text is completely off the left edge

    animation->setStartValue(QPoint(startX, this->y()));
    animation->setEndValue(QPoint(endX, this->y()));

    // Ensure the animation's target object (this QLabel) is visible
    if (!isVisible()) {
        show(); // Make sure the label is visible to animate
    }

    // Start the animation
    animation->start();
    qDebug() << "MarqueeLabel: Animation started successfully from " << animation->startValue().toPoint() << " to " << animation->endValue().toPoint();
}

void MarqueeLabel::stopMarquee()
{
    if (animation && animation->state() == QAbstractAnimation::Running) {
        animation->stop();
        qDebug() << "MarqueeLabel: Animation stopped.";
    }
}
