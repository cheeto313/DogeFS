/*
Devan Tatum
Neil Turnley
Such port. Very iNode Amaze.
*/

#ifndef
#define INODE_H

using namespace std;

class Inode {
	public:
		Inode();
		Inode(int iNumber);

		void toDisk(int iNumber);
		short getIndexBlockNumber();
		bool setIndexBlock(short indexBlockNumber);
		short findTargetBlock(int offset);
		bool setNextBlockNumber(short blockNumber);
		Vector<Short> deallocAllBlocks(int iNumber);
		int getBlockNumber(int iNumber);
		byte[] readIndirectBlock();


		// size of an inode in bytes
		int SIZE = 64; 
		int flags;
		int owner;
		int pointer[13];

	private:
		int directSize = 11;
		int iNodeSize = 32; 
		int indirectSize = Disk.blockSize / 4; 

		//wow, such constants
		static short UNUSED = 0;
 		static short USED = 1;
	    static short READ = 2;
	   	static short WRITE = 3;
	    static short DELETE = 4;
		void setFileSize(int);
};

#endif