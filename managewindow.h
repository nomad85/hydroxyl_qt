#ifndef MANAGEWINDOW_H
#define MANAGEWINDOW_H

#include <QWidget>
#include "ui_manage.h"

class OptionsWindow;
class ExitWindow;

class ManageWindow : public QWidget, public Ui_ManageForm
{
    Q_OBJECT
public:
    explicit ManageWindow(QWidget *parent = 0);

signals:
    void resizeFinished();
public slots:
    void afterResize();
    void showOptions();
    void showExitWindow();
protected:
    virtual void resizeEvent(QResizeEvent* event);
    virtual void paintEvent(QPaintEvent * event);
private:
    QTimer* timer;
    bool isResized;
    OptionsWindow *optionsWindow;
    ExitWindow *exitWindow;
};

#endif // MANAGEWINDOW_H
