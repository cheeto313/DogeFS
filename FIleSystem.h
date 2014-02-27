/*
Devan Tatum
Very port. Much intetface. Amaze FS project.
Such Virtual. Wow.
*/

#ifdef
#define INODE_H

class FileSystem {
	public:
		int formatDisk(int, int); 
		int shutdown();
		int create();
		int open(int);
		int inumber(int);
		int read(int, byte[]);
		int write(int, byte[]);
		int seek(int, int, int); 
		int close(int);
		int delete(int);
};

#endif