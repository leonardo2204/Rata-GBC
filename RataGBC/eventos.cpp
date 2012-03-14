#include "eventos.h"
#include <QMessageBox>


eventos::eventos(void)
{
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("Game Boy Color ROM (*.gbc)"));
	dialog.setDirectory(QDir::home());
	btnClicked = false;
}


eventos::~eventos(void)
{
}

void eventos::openROM()
{
	if(dialog.exec())
		lista = dialog.selectedFiles();
}

void eventos::btnStopClick()
{
	if(!btnClicked){
	cpu::setIME();
	btnClicked = true;
	}
}

FILE* eventos::getROMName()
{
	if(lista.isEmpty())
		openROM();
	file = fopen(lista[0].toLatin1(),"r");
		return file;
}