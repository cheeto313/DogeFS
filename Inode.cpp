/*
Devan Tatum
Such implement. Amaze.
*/

#include "Inode.h"

#define BLOCK_SIZE 64

//there needs to be different block classes, all overloaded

Inode::Inode(){
	//these are here as required, but not implemented
	this->flags = 0;
	this->owner = 0;
}

Inode::~Inode(){}

int Inode::getFileSize(){
	return 0 //not implemented
}

void setFileSize(int s){

}