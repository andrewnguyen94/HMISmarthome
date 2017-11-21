#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <qopengl.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GlWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GlWidget(QWidget *parent = 0);
    ~GlWidget();

public slots:

private:

protected:

signals:

};

#endif // GLWIDGET_H
