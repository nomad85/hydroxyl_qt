#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>
#include "Ui_options.h"

class AcceptWindow;

class OptionsWindow : public QWidget, public Ui_OptionsWindow
{
    Q_OBJECT
public:
    explicit OptionsWindow(QWidget *parent = 0);
    
signals:
    void resizeFinished();
public slots:
    void changedTab(int tabIndex);
    void afterResize();
    void acceptProperties();
protected:
    virtual void resizeEvent(QResizeEvent* event);
    virtual void paintEvent(QPaintEvent * event);

//    virtual void changeEvent(QEvent *event);
private:
    QTimer* timer;
    bool isResized;
    AcceptWindow* acceptWindow;
};

#endif // OPTIONSWINDOW_H
