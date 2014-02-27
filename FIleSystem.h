/*
Devan Tatum
Very port. Much intetface. Amaze FS project.
Such Virtual. Wow.
*/

#ifdef
#define INODE_H

class FileSystem {
	public:
		FileSystem();
		~FileSystem();
		virtual int formatDisk(int, int); 
		virtual int shutdown();
		virtual int create();
		virtual int open(int);
		virtual int inumber(int);
		virtual int read(int, byte[]);
		virtual int write(int, byte[]);
		virtual int seek(int, int, int); 
		virtual int close(int);
		virtual int delete(int);
};

#endif