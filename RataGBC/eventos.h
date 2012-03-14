#pragma once

#include <QFileDialog.h>
#include "ui_ratagbc.h"
#include "cpu.h"

class eventos : public QObject, public Ui::RataGBCClass
{
	Q_OBJECT
	
public:
	eventos(void);
	~eventos(void);
	FILE* getROMName();

	public slots:
		void openROM();
		void btnStopClick();
private:
	QFileDialog dialog;
	QStringList lista;
	FILE *file;
	bool btnClicked;
};

