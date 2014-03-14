/*
Devan Tatum
Very port. Much interface. Amaze FS project.
Such Virtual. Wow.
*/

#ifdef FILESYSTEM_H
#define FILESYSTEM_H

class FileSystem {
	public:
		FileSystem();
		~FileSystem();
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