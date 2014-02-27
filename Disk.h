/*
Devan Tatum
Very Disk, such rough port. Wow.
*/

//ADD INCLUDES HERE FOR CUSTOM OBJECTS BELOW
//ELSE EVERYTHING WILL BREAK YO

#ifndef
#define DISK_H

class Disk{
	public:
		Disk();
		~Disk();
		void read(int, byte[]);
		void read(int, SuperBlock);
		void read(int, InodeBlock ;
		void read(int, IndirectBlock);
		void write(int, byte[]);
		void write(int, SuperBlock);
		void write(int, InodeBlock);
		void write(int, IndirectBlock);
		void stop();
};

#endif