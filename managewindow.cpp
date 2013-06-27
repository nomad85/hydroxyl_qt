#include "managewindow.h"
#include "VisibleProperties.h"
#include "optionswindow.h"
#include "exitwindow.h"
#include <QResizeEvent>

ManageWindow::ManageWindow(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    exitWindow = new ExitWindow(this);

    QColor backColor(INDICATOR_GOOD);
    QString backgroundColor = "background-color: "+backColor.name();

    lineStateIndicator->setStyleSheet(backgroundColor);
    matrixStateIndicator->setStyleSheet(backgroundColor);
    tmiStateIndicator->setStyleSheet(backgroundColor);
    spsStateIndicator->setStyleSheet(backgroundColor);
    bspnStateIndicator->setStyleSheet(backgroundColor);
    hddStateIndicator->setStyleSheet(backgroundColor);

    connect(exitButton,SIGNAL(clicked()),this,SLOT(showExitWindow()));
    connect(this,SIGNAL(resizeFinished()),this,SLOT(afterResize()));
    connect(findLayerButton,SIGNAL(clicked()),this,SLOT(afterResize()));
    connect(optionsButton,SIGNAL(clicked()),this,SLOT(showOptions()));
    connect(exitWindow,SIGNAL(accepted()),this,SLOT(close()));

    isResized = true;
    optionsWindow = 0;
}


void ManageWindow::afterResize()
{
    int indicatorHeight = tmiStateIndicator->height();
    QFont font = spcStateIndicator->font();
    font.setPixelSize(indicatorHeight*0.7);

    spcStateIndicator->setFont(font);
    lineStateIndicator->setFont(font);
    matrixStateIndicator->setFont(font);
    tmiStateIndicator->setFont(font);
    spsStateIndicator->setFont(font);
    bspnStateIndicator->setFont(font);
    hddStateIndicator->setFont(font);
    sessionTimeIndicator->setFont(font);
    registeredCountIndicator->setFont(font);
    exitButton->setFont(font);
    optionsButton->setFont(font);
    startStopButton->setFont(font);
    findLayerButton->setFont(font);
    font.setPixelSize(indicatorHeight*0.7*0.8);
    moduleStatusBox->setFont(font);
    registrationStatusBox->setFont(font);

}

void ManageWindow::resizeEvent(QResizeEvent *event)
{
    isResized = true;
}

void ManageWindow::paintEvent(QPaintEvent *event)
{
    if (isResized == true) {
        isResized = false;
        emit resizeFinished();
    }
}

void ManageWindow::showOptions()
{
    if (optionsWindow == 0) {
        optionsWindow = new OptionsWindow(this);
        optionsWindow->setWindowModality(Qt::WindowModal);
    }
    optionsWindow->resize(this->size());
    optionsWindow->show();
}

void ManageWindow::showExitWindow()
{
    QSize curSize = size();
    exitWindow->resize(curSize.width()/2,curSize.height()/2);
    exitWindow->move((curSize.width()-curSize.width()/2)/2,(curSize.height()-curSize.height()/2)/2);
    exitWindow->show();
}
