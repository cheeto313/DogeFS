#ifndef	SUPERBLOCK_H
#define SUPERBLOCK_H

class SuperBlock{
	public:		
		SuperBlock(int, int, int);
		~SuperBlock();
		int getSize();		//return number of blocks on fs
		int getIsize();		//return number index blocks
		int getFreeList();	//return first block of the free list
	private:
		int diskSize;
		int iSize;
		int freeList;
};

#endif
