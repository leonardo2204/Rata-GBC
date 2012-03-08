#include "memoria.h"

UINT8 *memoria::mem;
vector<memoria::MemoryRegion*> *memoria::memorias;

memoria::memoria(FILE* s)
{
	mem = new UINT8[0x10000];
	fread(mem,sizeof(UINT8),0x10000,s);

	memorias = new vector<MemoryRegion*>(11);
	memorias->at(0) = (new RAMBankEnable(0x0000,0x1FFF));
	memorias->at(1) = (new ROMBankSelect(0x2000,0x3FFF));
	memorias->at(2) = (new RAMBankEnable(0x4000,0x5FFFF));
	memorias->at(3) = (new RAMROMModeSelect(0x6000,0x7FFF));
	memorias->at(4) = (new VRAM(0x8000,0x9FFF));
	memorias->at(5) = (new SRAM(0xA000,0xBFFF));
	memorias->at(6) = (new RAM(0xC000,0xDFFF));
	memorias->at(7) = (new ERAM(0xE000,0xFDFF));
	memorias->at(8) = (new Sprite(0xFE00,0xFE9F));
	memorias->at(9) = (new IOM(0xFF00,0xFF7F));
	memorias->at(10) = (new HRAM(0xFF80,0xFFF));

}

void memoria::RAMBankEnable::Write(UINT32 address,UINT8 data){
	
}

UINT8 memoria::RAMBankEnable::Read(UINT32 address){
	return mem[address];
}

void memoria::ROMBankSelect::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::ROMBankSelect::Read(UINT32 address){
	return 0;
}

void memoria::RAMBankSelect::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::RAMBankSelect::Read(UINT32 address){
	return 0;
}

void memoria::RAMROMModeSelect::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::RAMROMModeSelect::Read(UINT32 address){
	return 0;
}

void memoria::VRAM::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::VRAM::Read(UINT32 address){
	return 0;
}

void memoria::SRAM::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::SRAM::Read(UINT32 address){
	return 0;
}

void memoria::RAM::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::RAM::Read(UINT32 address){
	return 0;
}

void memoria::ERAM::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::ERAM::Read(UINT32 address){
	return 0;
}

void memoria::Sprite::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::Sprite::Read(UINT32 address){
	return 0;
}

void memoria::IOM::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::IOM::Read(UINT32 address){
	return 0;
}

void memoria::HRAM::Write(UINT32 address,UINT8 data){

}

UINT8 memoria::HRAM::Read(UINT32 address){
	return 0;
}

UINT8 memoria::readByte(UINT32 address){
	vector<MemoryRegion*>::iterator it;
	it = memorias->begin();
	while(it != memorias->end())
	{
		if((address >= (*it)->startAddress) && (address <=  (*it)->endAddress))
			return (*it)->Read(address);
		it++;
	}

	return mem[address];
}

UINT16 memoria::readWord(UINT32 address){
	return (readByte(address)+readByte(address+1));
}

void memoria::writeByte(UINT32 address, UINT8 data){
	vector<MemoryRegion*>::iterator it;
	it = memorias->begin();
	while(it != memorias->end())
	{
		if((address >= (*it)->startAddress) && (address <=  (*it)->endAddress))
			(*it)->Write(address,data);
		it++;
	}

	mem[address] = data;
}

void memoria::writeWord(UINT32 address, UINT16 data){
	writeByte(address,data&255);
	writeByte(address+1,data);
}


memoria::~memoria(void)
{
	delete[] mem;
}
