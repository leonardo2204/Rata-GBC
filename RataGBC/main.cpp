#include "ratagbc.h"
#include <QtGui/QApplication>
#include "dasm.h"
#include "eventos.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RataGBC w;
	dasm dsm;
	FILE *file = fopen("Tetris DX.gbc","r");
	cpu *cpp = new cpu(file);
	QObject::connect(cpp,SIGNAL(onEndProcess(UINT32)),&w,SLOT(receivedEndProcess(UINT32)),Qt::BlockingQueuedConnection);
	cpp->start();
	int c = 0;
	rewind(file);
	while(dsm.DAsm(file,w.ui.listWidget,c));

	fclose(file);
	w.show();
	return a.exec();
}
