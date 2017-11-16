#include "view_3d_window.h"
#include "qwidget.h"

View3DWindow::~View3DWindow(){

}

void View3DWindow::mouseMoveEvent(QMouseEvent *ev)
{

    QWidget::mouseMoveEvent(ev);
}

void View3DWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    QWidget::mouseDoubleClickEvent(ev);
}

void View3DWindow::mousePressEvent(QMouseEvent *ev)
{
    QWidget::mousePressEvent(ev);
}

void View3DWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    QWidget::mouseReleaseEvent(ev);
}
