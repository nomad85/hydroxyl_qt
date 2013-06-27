#include "exitwindow.h"

ExitWindow::ExitWindow(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    isResized = true;
    connect(this,SIGNAL(resizeFinished()),this,SLOT(afterResize()));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}


void ExitWindow::afterResize()
{
    int textHeight = postActionsLabel->height()/3;
    QFont font = postActionsLabel->font();
    font.setPixelSize(textHeight*0.7);
    setFont(font);
    font.setPixelSize(textHeight*2);
    acceptButton->setFont(font);
    rejectButton->setFont(font);
}

void ExitWindow::resizeEvent(QResizeEvent *event)
{
    isResized = true;
}

void ExitWindow::paintEvent(QPaintEvent *event)
{
    if (isResized == true) {
        isResized = false;
        emit resizeFinished();
    }
}
