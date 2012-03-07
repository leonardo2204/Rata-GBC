#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "defs.h"

using namespace std;

class memoria
{
public:
	memoria(void);
	memoria(FILE*);
	~memoria(void);


	struct MemoryRegion abstract{
		virtual UINT8 Read(UINT32 address) = 0;
		virtual void Write(UINT32 address, UINT8 data) = 0;
		const UINT32 startAddress, endAddress;
	protected:
		MemoryRegion(UINT32 start, UINT32 end): startAddress(start), endAddress(end) {}
	};

	struct RAMBankEnable : MemoryRegion {
		RAMBankEnable(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct ROMBankSelect : MemoryRegion {
		ROMBankSelect(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct RAMBankSelect : MemoryRegion {
		RAMBankSelect(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct RAMROMModeSelect : MemoryRegion {
		RAMROMModeSelect(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct VRAM : MemoryRegion {
		VRAM(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct SRAM : MemoryRegion {
		SRAM(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};


	struct RAM : MemoryRegion {
		RAM(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct ERAM : MemoryRegion {
		ERAM(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct Sprite : MemoryRegion {
		Sprite(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct IOM : MemoryRegion {
		IOM(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	struct HRAM : MemoryRegion {
		HRAM(UINT32 start, UINT32 end) : MemoryRegion(start,end) {}
		virtual UINT8 Read(UINT32 address);
		virtual void Write(UINT32 address,UINT8 data);
	};

	static void writeByte(UINT32, UINT8);
	static UINT8 readByte(UINT32);

	static void writeWord(UINT32, UINT16);
	static UINT16 readWord(UINT32);

private:
	static vector<MemoryRegion*> *memorias;
	static UINT8 * mem;
	
};

