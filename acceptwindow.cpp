#include "acceptwindow.h"

AcceptWindow::AcceptWindow(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    isResized = true;
    connect(this,SIGNAL(resizeFinished()),this,SLOT(afterResize()));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

void AcceptWindow::afterResize()
{
    int textHeight = acceptButton->height();
    QFont font = acceptButton->font();
    font.setPixelSize(textHeight/3);
    setFont(font);
}

void AcceptWindow::resizeEvent(QResizeEvent *event)
{
    isResized = true;
}

void AcceptWindow::paintEvent(QPaintEvent *event)
{
    if (isResized == true) {
        isResized = false;
        emit resizeFinished();
    }
}

