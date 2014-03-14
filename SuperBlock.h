#ifndef
#define DISK_H

class SuperBlock{
	public:		
		SuperBlock();
		~SuperBlock();
		int getSize();		//return number of blocks on fs
		int getIsize();		//return number index blocks
		int getFreeList();	//return first block of the free list
	//private:
};

#endif