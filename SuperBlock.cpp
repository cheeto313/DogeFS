#include "SuperBlock.h"

int diskSize = NULL;
int iSize = NULL;
int freeSize = NULL;

//Takes in a disk size parameter for the superblock
SuperBlock::SuperBlock(int d){
	this->diskSize = d;
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
