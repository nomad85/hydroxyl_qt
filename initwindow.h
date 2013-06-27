#ifndef INITWINDOW1_H
#define INITWINDOW1_H

#include <QWidget>
#include "ui_init.h"

class QTimer;
class ManageWindow;
class ExitWindow;

class InitWindow : public QWidget, public Ui_InitWindow
{
    Q_OBJECT
public:
    explicit InitWindow(QWidget *parent = 0);
    void setManageWindow(ManageWindow& window) {
        manageWindow = &window;
    }

signals:
    void resizeFinished();
public slots:
    void showWindow();
    void afterResize();
    void updateTimerCaption();
    void showManageWindow();
    void showExitWindow();

protected:
    virtual void resizeEvent(QResizeEvent* event);
    virtual void paintEvent(QPaintEvent *event);
private:
    QTimer* timer;
    ManageWindow* manageWindow;
    bool isResized;
    ExitWindow* exitWindow;
};

#endif // INITWINDOW1_H
