//! Haaris Chaudhry
//! OpenHashTable.h
//! This file describes the functions and members to be used in the OpenHashTable class

#ifndef OPEN_HASH_TABLE_H
#define OPEN_HASH_TABLE_H

#include "DoubleLinkedList.h"

class OpenHashTable
{
public:
    /**
    * Constructor
    * @return An empty OpenHashTable with
    */
    OpenHashTable(int aSize);

    /**
    * Destructor
    * @return An empty OpenHashTable
    */
    ~OpenHashTable();

private:
    const int mSIZE;
    DoubleLinkedList* mList;

};
#endif // !OPEN_HASH_TABLE_H
