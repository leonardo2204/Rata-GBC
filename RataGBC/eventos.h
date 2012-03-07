#pragma once

#include <QDialog.h>
#include "ui_ratagbc.h"

class eventos : public QObject, public Ui::RataGBCClass
{
	Q_OBJECT
	
public:
	eventos(void);
	~eventos(void);
};

