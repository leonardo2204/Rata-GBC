#include "telaGBC.h"


telaGBC::telaGBC(QWidget *parent):
	QGLWidget(parent)
{
	setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
}

void telaGBC::initializeGL()
{
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
}

void telaGBC::resizeGL(int w, int h)
{
	glViewport(0,0,w,h);
}

void telaGBC::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


telaGBC::~telaGBC(void)
{
}
