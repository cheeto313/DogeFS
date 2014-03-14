/*
Devan Tatum
Neil Turnley
Such implement. Amaze.
*/

#include "Inode.h"

#define BLOCK_SIZE 64

//there needs to be different block classes, all overloaded

Inode::Inode(){

	//these are here as required, but not implemented
	this->length = 0;
	this->count = 0;
	this->flag  = 0;
	this->count = 0;

		 for ( int i = 0; i < directSize; i++ ) {
		    	direct[i] = -1;
		    }
	indirect = -1;
  }//Inode::Inode()

Inode::Inode(int iNumber){

	int blockNumber = getBlockNumber(iNumber);
    byte[] data = new byte[Disk.blockSize];

    rawread(blockNumber, data);
    int offset = (iNumber % 16) * 32;

    length = bytes2int(data, offset);
    offset += 4;
    count = bytes2short(data, offset);
    offset += 2;
    flag = bytes2short(data, offset);
    offset += 2;

    for (int i = 0; i < directSize; i++, offset += 2) {
      direct[i] = bytes2short(data, offset);
    }
    indirect = bytes2short(data, offset);
}//Inode::Inode(int iNumber)

 void Inode::toDisk(int iNumber) { // save to disk as the i-th inode
    

    //FIXME: inefficient implementation
    int blockNumber = getBlockNumber(iNumber);

    //read the whole block from the disk
    byte[] data = new byte[Disk.blockSize];
    rawread(blockNumber, data);

    int inode_offset = 0;

    // offset to the correct inode
    int2bytes(length, data, iNumber * iNodeSize + inode_offset);
    inode_offset += 4;
    short2bytes(count, data, iNumber * iNodeSize + inode_offset);
    inode_offset += 2;
    Sshort2bytes(flag, data, iNumber * iNodeSize + inode_offset);
    inode_offset += 2;

	    for (int i = 0; i < directSize; i++, inode_offset += 2) {
	      short2bytes(direct[i], data, iNumber * iNodeSize + inode_offset);
	    }

    short2bytes(indirect, data, iNumber * iNodeSize + inode_offset);

    rawwrite(blockNumber, data);
  }

  short Inode::getIndexBlockNumber() {
    return indirect;
  }

  bool Inode::setIndexBlock(short indexBlockNumber) {
    indirect = indexBlockNumber;
    return true; // FIXME: don't know what to return
  }


  //FIXME: assuming this method is supposed to do an offset inside the direct array
  short Inode::findTargetBlock(int offset) {
    cout("offset in inode: " + offset +"\n");
    if (offset < 0) {
      return -1;
    } else if (offset < directSize) {
     cout("DIRECT DUMP\n");
	      for (int i = 0; i < directSize; i++) {
	        cout("directsize[" + i + "] = " + direct[i] + "\n");

	      }
      return direct[offset];
    }

    //get the index within the indirect block (which is treated like an array)
    int indirect_offset = offset - directSize;
    cout("NOT IN DIRECT, TRY INDIRECT OFFSET " + indirect_offset + "\n");

    //read from that indirect block the short at the indirect_offset
    return bytes2short(readIndirectBlock(), indirect_offset);
  }

  //TODO: more methods, not described in the pdf
  //Does a linear search through the direct blocks looking for an invalid one
  //and then sets that to the given blockNumber. If none is found, moves onto
  //the index. If there is no room in there, returns false. Otherwise true.
  bool Inode::setNextBlockNumber(short blockNumber) {
    cout("SETTING NEXT BLOCK NUMBER " + blockNumber + "\n");
    //Check direct first
    for (int i = 0; i < directSize; i++) {
      if (direct[i] == -1) {
        direct[i] = blockNumber;
        return true;
      }
    }

    	//Check indirect
    short next_indirect_offset = -1;
    byte[] indirect_block = readIndirectBlock();
    
    for (short offset_in_indirect = 0; offset_in_indirect < indirectSize; offset_in_indirect++) {

      //The next free indirect will be -1
      if (bytes2short(indirect_block, offset_in_indirect) <= 0) {
        //write the block number to the byte array
        short2bytes(indirect, indirect_block, offset_in_indirect);

        //write the block back to disk, return success condition on disk
        return rawwrite(indirect, indirect_block) != -1;
      }
    }
    return false;
  }

 Vector<Short> Inode::deallocAllBlocks(int iNumber) {
    Vector blocks_freed = new Vector<Short>();
    //clear the directs
    for (int i = 0; i < directSize; i++) {
      if (direct[i] > 0) {
        blocks_freed.add(direct[i]);
        direct[i] = -1;
      }
    }

    byte[] indirect_block = readIndirectBlock();

    //go through the index block
    for (int i = 0; i < Disk.blockSize / 2; i++) {
      short indirect_value = bytes2short(indirect_block, i);

      //If its a valid block, reset it and add it to the return vector
      if (indirect_value > 0) {
        //write 0 to the index block at this pos to invalidate it
        short2bytes((short)0, indirect_block, i);

        //save it to the return vector
        blocks_freed.add(new Short(indirect_value));
      }
    }

    //Write the now zeroed indirect block back to disk
    rawwrite(indirect, indirect_block);

    toDisk(iNumber);

    return blocks_freed;
  }

  int Inode::getBlockNumber(int iNumber) {
    return 1 + iNumber / 16;
  }

  byte[] Inode::readIndirectBlock() {
    byte[] indirect_block = new byte[Disk.blockSize];

    //read the entire indirect block
    rawread(indirect, indirect_block);

    return indirect_block;
  }
}