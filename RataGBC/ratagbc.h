#ifndef RATAGBC_H
#define RATAGBC_H

#include <QtGui/QMainWindow>
#include "ui_ratagbc.h"
#include "defs.h"
#include "cpu.h"

class RataGBC : public QMainWindow
{
	Q_OBJECT

public:
	RataGBC(QWidget *parent = 0, Qt::WFlags flags = 0);
	~RataGBC();
	Ui::RataGBCClass ui;
	void updateGui();

	public slots:
		void receivedEndProcess(UINT32);
		
};

#endif // RATAGBC_H
