#include "view_3d_window.h"
#include "qwidget.h"

View3DWindow::View3DWindow(QWidget *parent) :
    QWidget(parent)
{

}

View3DWindow::~View3DWindow(){

}

void View3DWindow::mouseMoveEvent(QMouseEvent *ev)
{
    this->x_move = ev->x();
    this->y_move = ev->y();
    emit on_MouseMove();
}

void View3DWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    this->x_doubleclick = ev->x();
    this->y_doubleclick = ev->y();
    emit on_MouseDoubleClick();
}

void View3DWindow::mousePressEvent(QMouseEvent *ev)
{
    this->x_press = ev->x();
    this->y_press = ev->y();
    emit on_MousePress();
}

void View3DWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    this->x_release = ev->x();
    this->y_release = ev->y();
    emit on_MouseRelease();
}
