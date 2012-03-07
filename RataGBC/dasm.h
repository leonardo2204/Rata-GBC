#pragma once

#include <stdio.h>
#include <string.h>
#include "ui_ratagbc.h"

class dasm
{
public:
	dasm(void);
	~dasm(void);
	int DAsm(FILE*,QListWidget *,int&);
};

