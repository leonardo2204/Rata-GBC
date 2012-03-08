#pragma once

#include <QGLWidget>

class telaGBC : public QGLWidget
{
	Q_OBJECT
public:
	telaGBC(QWidget *parent = 0);
	~telaGBC(void);
protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
};

