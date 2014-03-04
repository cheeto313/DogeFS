/*
Devan Tatum
Such port. Very iNode.
*/

#ifndef
#define INODE_H

class Inode {
	public:
		Inode();
		~Inode();
		// size of an inode in bytes
		int SIZE = 64; 
		int flags;
		int owner;
		int getFileSize();
		int pointer[13];
	private:
		void setFileSize(int);
};

#endif