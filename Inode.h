/*
Devan Tatum
Such port. Very iNode
*/

#ifndef
#define INODE_H

class Inode {
	public:
		// size of an inode in bytes
		int SIZE = 64; 
		int flags;
		int owner;
		int fileSize;
		int pointer[13];
};

#endif