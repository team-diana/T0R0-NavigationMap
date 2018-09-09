#include "mainwindow.h"
#include <QKeyEvent>
#include <QCoreApplication>
#include <QDebug>


// Constructor
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

    //this->setGeometry(0, 0, screen.width(), screen.height());   // -50
    this->setGeometry(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // set black background
    QPalette pal = palette();

    // Set backgroud color
    pal.setColor(QPalette::Background, QColor(14,14,14,255));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // Show Rover Image at the center of the Window
    //QLabel *pixlabel = new QLabel(this);
    //QPixmap pixrover(":/Images/rover_up-230x374.png");
    //pixlabel->setPixmap(pixrover.scaled(ROVIMG_WIDTH, ROVIMG_HEIGHT, Qt::KeepAspectRatio));
    //pixlabel->setGeometry( (this->width() - ROVIMG_WIDTH) /2, (this->height() - ROVIMG_HEIGHT) /2, ROVIMG_WIDTH, ROVIMG_HEIGHT );

    // Show Team D.I.A.N.A. logo at bottom-right
    QLabel *pixlogo = new QLabel(this);
    QPixmap pixmaplogo(":/Images/diana-logo-193x90.png");
    pixlogo->setPixmap(pixmaplogo.scaled(193, 90, Qt::KeepAspectRatio));
    pixlogo->setGeometry( 50, this->height() - 120, 193, 90 );



    m_mqttHarbinger = new MqttHarbinger(this);

    //* Custom elements

    //autosysdisplay = new AutoSysDisplay(this);
    //autosysdisplay->setGeometry(AUTOSYS_DISPLAY_POSX, AUTOSYS_DISPLAY_POSY, AUTOSYS_DISPLAY_WIDTH + 2, AUTOSYS_DISPLAY_HEIGHT + 2);

    //map2d = new Map2d(this);
    //map2d->setGeometry(MAP2D_POSX, MAP2D_POSY, MAP2D_WIDTH, MAP2D_HEIGTH);

    //connect(m_mqttHarbinger, &MqttHarbinger::position_change_event,                       map2d,          &Map2d::addPoint);

    /*Custom elementsq*/
}

MainWindow::~MainWindow(){
}

void MainWindow::keyPressEvent (QKeyEvent *k) {
    switch ( tolower(char(k->key())) ) {
            case 'r':                               // reload
                qDebug("Pressed R");//void keyPressEvent(QKeyEvent *k) Q_DECL_OVERRIDE;
                update();
                break;
            case 'q':                               // quit//void keyPressEvent(QKeyEvent *k) Q_DECL_OVERRIDE;
              qDebug("Pressed Q: Quitting application");
              QCoreApplication::quit();
                break;
        }
}
