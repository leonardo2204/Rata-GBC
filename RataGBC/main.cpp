#include "ratagbc.h"
#include <QtGui/QApplication>
#include <QThread>
#include "dasm.h"
#include "eventos.h"
#include "cpu.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RataGBC w;
	QThread thr;
	dasm dsm;
	cpu *cpp = new cpu();
	cpp->moveToThread(&thr);
	QObject::connect(&thr,SIGNAL(started()),cpp,SLOT(cpu_emulates(int)));
	thr.start();
	FILE *file = fopen("Tetris DX.gbc","r");
	int c = 0;
	QObject::connect(cpp,SIGNAL(onEndProcess(UINT32)),&w,SLOT(receivedEndProcess(UINT32)));	
	while(dsm.DAsm(file,w.ui.listWidget,c));
	fclose(file);
	w.show();
	thr.quit();
	thr.wait();
	return a.exec();
}
