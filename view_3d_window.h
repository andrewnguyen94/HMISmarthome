#ifndef VIEW_3D_WINDOW_H
#define VIEW_3D_WINDOW_H

#include <Qt3DExtras>
#include <QMouseEvent>

class View3DWindow : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT
public:
    View3DWindow();
    ~View3DWindow();

protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;


};

#endif // VIEW_3D_WINDOW_H
