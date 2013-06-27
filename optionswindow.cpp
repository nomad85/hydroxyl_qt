#include "optionswindow.h"
#include "acceptwindow.h"


OptionsWindow::OptionsWindow(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    isResized = true;
    acceptWindow = new AcceptWindow(this);
    connect(tabOptions,SIGNAL(currentChanged(int)),this,SLOT(changedTab(int)));
    connect(this,SIGNAL(resizeFinished()),this,SLOT(afterResize()));
    connect(acceptWindow,SIGNAL(accepted()),this,SLOT(acceptProperties()));
    connect(acceptWindow,SIGNAL(rejected()),this,SLOT(close()));
}

void OptionsWindow::changedTab(int tabIndex)
{
    if (tabIndex == 2) {
        QSize curSize = size();
        acceptWindow->resize(curSize.width()/2,curSize.height()/2);
        acceptWindow->move((curSize.width()-curSize.width()/2)/2,(curSize.height()-curSize.height()/2)/2);
        acceptWindow->show();
    }
}

void OptionsWindow::afterResize()
{
    int tabCaptionHeight = tabOptions->height()/4;
    QFont font = tabOptions->font();
    font.setPixelSize(tabCaptionHeight*0.5);

    tabOptions->setFont(font);

    QString buttonColor = "color: #ff0000";
    decLineExpositionButton->setStyleSheet(buttonColor);
    decMatrixExpositionButton->setStyleSheet(buttonColor);
    decRegistrationTimeButton->setStyleSheet(buttonColor);

    buttonColor = "color: #00ff00";
    incLineExpositionButton->setStyleSheet(buttonColor);
    incMatrixExpositionButton->setStyleSheet(buttonColor);
    incRegistrationTimeButton->setStyleSheet(buttonColor);

    decLineExpositionButton->setFont(font);
    decMatrixExpositionButton->setFont(font);
    decRegistrationTimeButton->setFont(font);

    incLineExpositionButton->setFont(font);
    incMatrixExpositionButton->setFont(font);
    incRegistrationTimeButton->setFont(font);

    font.setPixelSize(tabCaptionHeight*0.5*0.5);
    ntpServerBox->setFont(font);
    bspnBox->setFont(font);
    lineExpositionBox->setFont(font);
    matrixExpositionBox->setFont(font);
    registrationTimeBox->setFont(font);
}

void OptionsWindow::acceptProperties()
{
    close();
}

void OptionsWindow::resizeEvent(QResizeEvent *event)
{
    isResized = true;
}

void OptionsWindow::paintEvent(QPaintEvent *event)
{
    if (isResized == true) {
        isResized = false;
        emit resizeFinished();
    }
}
