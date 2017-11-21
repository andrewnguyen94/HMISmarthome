#ifndef VIEW_3D_WINDOW_H
#define VIEW_3D_WINDOW_H

#include <Qt3DExtras>
#include <QWidget>

class View3DWindow : public QWidget
{
    Q_OBJECT
public:
    explicit View3DWindow(QWidget *parent = nullptr);
    ~View3DWindow();

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseDoubleClickEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    int x_move,y_move,x_press,y_press,x_doubleclick,y_doubleclick,x_release,y_release;

private:
    Qt3DExtras::Qt3DWindow *view;

public slots:

signals:
    void on_MouseMove();
    void on_MouseDoubleClick();
    void on_MousePress();
    void on_MouseRelease();

};

#endif // VIEW_3D_WINDOW_H
