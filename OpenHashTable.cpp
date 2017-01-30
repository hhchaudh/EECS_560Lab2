#include "OpenHashTable.h"
#include <iostream>

OpenHashTable::OpenHashTable(int aSize): mSIZE(aSize)
{
    mList = new DoubleLinkedList[aSize];
}

OpenHashTable::~OpenHashTable()
{
    if(mList)
    {
        delete [] mList;
    }
}
