#ifndef ACCEPTWINDOW_H
#define ACCEPTWINDOW_H

#include <QDialog>
#include "ui_acceptParams.h"

class AcceptWindow : public QDialog, public Ui_AcceptWindow
{
    Q_OBJECT
public:
    explicit AcceptWindow(QWidget *parent = 0);
    
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

#endif // ACCEPTWINDOW_H
