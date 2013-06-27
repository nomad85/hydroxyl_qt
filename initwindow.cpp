#include "initwindow.h"
#include "VisibleProperties.h"
#include <QTimer>
#include <QTime>
#include "managewindow.h"
#include "exitwindow.h"

InitWindow::InitWindow(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    updateTimerCaption();
    timer = new QTimer(this);
    timer->start(1000);
    manageWindow = 0;
    exitWindow = new ExitWindow(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(updateTimerCaption()));
    connect(this,SIGNAL(resizeFinished()),this,SLOT(afterResize()));
    connect(testButton,SIGNAL(clicked()),this,SLOT(showWindow()));
    connect(exitButton,SIGNAL(clicked()),this,SLOT(showExitWindow()));
    connect(manageButton,SIGNAL(clicked()),this,SLOT(showManageWindow()));
    connect(exitWindow,SIGNAL(accepted()),this,SLOT(close()));

    QColor backColor(INDICATOR_UNDEFINED);
    QString backroundColor = "background-color: "+backColor.name();

    lineStatusLabel->setStyleSheet(backroundColor);
    matrixStatusLabel->setStyleSheet(backroundColor);
    spcStateLabel->setStyleSheet(backroundColor);
    spsStatusLabel->setStyleSheet(backroundColor);
    bspnStatusLabel->setStyleSheet(backroundColor);
    tmiStatusLabel->setStyleSheet(backroundColor);
    isResized = true;
}


void InitWindow::showWindow()
{
//    spsStatusLabel->setStyleSheet(lineStatusLabel->styleSheet());
}

void InitWindow::afterResize()
{
    int tmiHeight = tmiStatusLabel->height();
    QFont font = tmiStatusLabel->font();
    font.setPixelSize(tmiHeight*0.7);
    tmiStatusLabel->setFont(font);
    spcStateLabel->setFont(font);
    lineStatusLabel->setFont(font);
    matrixStatusLabel->setFont(font);
    spsStatusLabel->setFont(font);
    bspnStatusLabel->setFont(font);
    spcCaptionLabel->setFont(font);
    lineCaptionLabel->setFont(font);
    matrixCaptionLabel->setFont(font);
    tmiCaptionLabel->setFont(font);
    spsCaptionLabel->setFont(font);
    bspnCaptionLabel->setFont(font);
    timerLabel->setFont(font);
    testButton->setFont(font);
    manageButton->setFont(font);
    exitButton->setFont(font);
    font.setPixelSize(tmiHeight*0.7*0.8);
    logGroupBox->setFont(font);
    font.setPixelSize(tmiHeight*0.7*0.8*0.7);
    textLog->setFont(font);
}

void InitWindow::updateTimerCaption()
{
    QTime curTime = QTime::currentTime();
    timerLabel->setText(curTime.toString("hh:mm:ss"));
}

void InitWindow::showManageWindow()
{
    manageWindow->showFullScreen();
    close();
}

void InitWindow::showExitWindow()
{
    QSize curSize = size();
    exitWindow->resize(curSize.width()/2,curSize.height()/2);
    exitWindow->move((curSize.width()-curSize.width()/2)/2,(curSize.height()-curSize.height()/2)/2);
    exitWindow->show();
}


void InitWindow::resizeEvent(QResizeEvent *event)
{
    isResized = true;
}

void InitWindow::paintEvent(QPaintEvent *event)
{
    if (isResized == true) {
        isResized = false;
        emit resizeFinished();
    }
}

