/*
Devan Tatum
Very Disk, such rough port. Wow.
*/

//ADD INCLUDES HERE FOR CUSTOM OBJECTS BELOW
//ELSE EVERYTHING WILL BREAK YO

#ifndef PAGETABLE_H
#define DISK_H

class Disk{
	public:
		Disk();
		~Disk();
		void read(int, byte[]);
		void stop(bool);
	/*	void read(int, SuperBlock);
		void read(int, InodeBlock ;
		void read(int, IndirectBlock);
		void write(int, byte[]);
		void write(int, SuperBlock);
		void write(int, InodeBlock);
		void write(int, IndirectBlock);*/
		//uncomment above when/if the datatypes are create (eg Superblock)
		void stop();

	private:
		bool validate(int);
};

#endif