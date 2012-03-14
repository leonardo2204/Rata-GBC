#include "ratagbc.h"

RataGBC::RataGBC(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{	
	ui.setupUi(this);
}

RataGBC::~RataGBC()
{
}

void RataGBC::receivedEndProcess(UINT32 i){
	this->ui.listWidget->item(i+1)->setSelected(true);
	this->ui.statusBar->showMessage(QString::number(i));
	this->ui.listWidget_2->clear();
	this->ui.listWidget_2->addItem("AF = "+ QString::number(cpu::getCpu()->AF.w ,16));
	this->ui.listWidget_2->addItem("BC = "+QString::number(cpu::getCpu()->BC.w ,16));
	this->ui.listWidget_2->addItem("DE = "+QString::number(cpu::getCpu()->DE.w ,16));
	this->ui.listWidget_2->addItem("HL = "+QString::number(cpu::getCpu()->HL.w ,16));
	this->ui.listWidget_2->addItem("PC = "+QString::number(cpu::getCpu()->PC ,16));
	this->ui.listWidget_2->addItem("SP = "+QString::number(cpu::getCpu()->SP ,16));
	this->ui.listWidget->scrollToItem(this->ui.listWidget->item(i+1));
}
