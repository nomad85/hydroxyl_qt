#ifndef EXITWINDOW_H
#define EXITWINDOW_H

#include <QDialog>
#include <ui_exitwindow.h>

class ExitWindow : public QDialog, public Ui_ExitWindow
{
    Q_OBJECT
public:
    explicit ExitWindow(QWidget *parent = 0);
    
signals:
    void resizeFinished();
public slots:
    void afterResize();
protected:
    virtual void resizeEvent(QResizeEvent* event);
    virtual void paintEvent(QPaintEvent * event);
private:
    bool isResized;
};

#endif // EXITWINDOW_H
