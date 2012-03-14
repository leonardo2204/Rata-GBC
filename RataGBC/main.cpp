#include "ratagbc.h"
#include <QtGui/QApplication>
#include <QFileDialog>
#include "dasm.h"
#include "eventos.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RataGBC w;
	dasm dsm;
	eventos ev;
	FILE *file;

	QObject::connect(w.ui.actionAbrir,SIGNAL(triggered()),&ev,SLOT(openROM()));
	file = ev.getROMName();
	cpu *cpp = new cpu(file);
	QObject::connect(cpp,SIGNAL(onEndProcess(UINT32)),&w,SLOT(receivedEndProcess(UINT32)),Qt::BlockingQueuedConnection);
	QObject::connect(w.ui.runBtn,SIGNAL(clicked()),cpp,SLOT(start()));
	QObject::connect(w.ui.stopBtn,SIGNAL(clicked()),&ev,SLOT(btnStopClick()));
	int c = 0;
	rewind(file);
	while(dsm.DAsm(file,w.ui.listWidget,c));
	fclose(file);
	w.show();
	return a.exec();
}
