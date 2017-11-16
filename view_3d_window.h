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

private:
    Qt3DExtras::Qt3DWindow *view;

public slots:

protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseDoubleClickEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;


};

#endif // VIEW_3D_WINDOW_H
