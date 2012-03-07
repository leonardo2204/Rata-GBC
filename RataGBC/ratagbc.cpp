#include "ratagbc.h"

RataGBC::RataGBC(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{	
	ui.setupUi(this);
	connect(ui.stopBtn,SIGNAL(pressed()),this,SLOT(stopBtnReceive()));
}

RataGBC::~RataGBC()
{
}

void RataGBC::updateGui()
{
	QCoreApplication::processEvents();
	this->show();
}

void RataGBC::receivedEndProcess(UINT32 i){
	this->ui.listWidget->item(i+1)->setSelected(true);
	this->ui.statusBar->showMessage(QString::number(i));
	this->ui.listWidget_2->addItem(QString::number(cpu::getCpu() ,16));

}
