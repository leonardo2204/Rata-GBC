#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <QThread>
#include <qwaitcondition.h>
#include <qmutex.h>
#include "memoria.h"
#include "registradores.h"

class cpu : public QThread
{
	Q_OBJECT
public:
	cpu(void);
	cpu(FILE*);
	~cpu(void);

	typedef union {
		unsigned short w;

		struct {
			unsigned char l;
			unsigned char h;
		} b;
	} cpuReg;

	typedef struct Cpu {
		cpuReg AF;
		cpuReg BC;
		cpuReg DE;
		cpuReg HL;
		unsigned short SP;
		unsigned short PC;
		int IME;
		int IMA;
		int halt,lcdc,div,tim;
		int time;
	}Cpu;

	
	static struct Cpu *getCpu();
	int cpu_emulate(int);
	static void setIME();

signals:
	void onEndProcess(UINT32);

protected:
	void run();
	
private:
	static struct Cpu *CPU;
	QMutex mt;
	QWaitCondition wt;
};