#include "mainwindow.h"
#include "window.h"

#include <qmenubar.h>
#include <qmenu.h>
#include <QMessageBox>

MainWindow::MainWindow(){
    QMenuBar *menuBar = new QMenuBar;
    QMenu *menuFile = menuBar->addMenu(tr("&File"));
    QMenu *menuEdit = menuBar->addMenu("&Edit");
    QMenu *menuTool = menuBar->addMenu("&Tool");

    setMenuBar(menuBar);
    onAddNew();
}

void MainWindow::onAddNew(){
    if(!centralWidget()){
        setCentralWidget(new Window(this));
    }
    else{
        QMessageBox::information(0, tr("Cannot add new window"), tr("Already occupied. Undock first."));
    }
}
