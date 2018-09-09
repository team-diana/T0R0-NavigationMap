#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "config.h"

#include "mqttharbinger.h"

#include "rovershow.h"
#include "imagebutton.h"
#include "autosysdisplay.h"

#include "map2d.h"

#include <QLabel>

#include <QString>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    bool connected;

    MqttHarbinger *m_mqttHarbinger;

    // Custom elements
    RoverShow *rover;
    QLabel *pixlabel;
    AutoSysDisplay *autosysdisplay;
    Map2d *map2d;

};

#endif // MAINWINDOW_H
