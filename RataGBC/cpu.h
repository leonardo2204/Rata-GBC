#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <QThread>

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

	
	static unsigned short getCpu();
	int cpu_emulate(int);

signals:
	void onEndProcess(UINT32);

protected:
	void run();
	
private:
	static struct Cpu *CPU;
};