#include "SuperBlock.h"

int diskSize = NULL;
int iSize = NULL;
int freeSize = NULL;

//diskSize, iSize, freelist 
SuperBlock::SuperBlock(int ds, int is, int fl){
	this->diskSize = ds;
	this->iSize = is;
	this->freeSize = fl;
}

int getSize(){
	return this->diskSize;
}

int getIsize(){
	return this->iSize;
}

int getFreeList(){
	return this->freeSize;
}
