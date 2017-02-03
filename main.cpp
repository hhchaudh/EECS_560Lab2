// EECS560_Lab1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "OpenHashTable.h"

int getChoice();
void menuLoop( OpenHashTable& table );
void insertItem( OpenHashTable& table );
void deleteItem( OpenHashTable& table );
void printTable( OpenHashTable& table );

int main()
{
    unsigned int size;
    int anInteger;
    std::ifstream fileReader("data.txt");
     
    
    if(fileReader.is_open())
    {
        fileReader >> size;

        OpenHashTable myTable = OpenHashTable{ size };

        while(fileReader >> anInteger)
        {
            myTable.insert(anInteger);
        }
        menuLoop( myTable );
        fileReader.close();
    }
    else
    {
        std::cout << "Error reading file\n";
    }
    
    return 0;
}

void menuLoop( OpenHashTable& table )
{
    int choice = 0;

    while( choice != 4 )
    {
        choice = getChoice();

        switch( choice )
        {
        case 1:
            insertItem( table );
            break;
        case 2:
            deleteItem( table );
            break;
        case 3:
            printTable( table );
            break;
        case 4:
            break;
        default:
            std::cout << "Enter a valid choice (1-5)\n";
        }
    }
}

int getChoice()
{
    int choice = 0;

    std::cout   << "..........................................................\n";
    std::cout   << "Please choose one of the folowing commands:\n";
    std::cout   << "1 - insert\n"
                << "2 - delete\n"
                << "3 - print\n"
                << "4 - exit\n"
                << "\n";

    std::cin >> choice;

    return choice;
}

void insertItem( OpenHashTable& table )
{
    std::cout << "Choose a number to be added to the table\n";
    int number;
    std::cin >> number;
    if( !table.insert( number ) )
    {
        std::cout << "Error, could not add " << number << ", value is already in the table.\n";
    }
}

void deleteItem( OpenHashTable& table )
{
    std::cout << "Choose a number to be deleted from the table\n";
    int number;
    std::cin >> number;
    if( !table.deletenode( number ) )
    {
        std::cout << "Error, cannot delete " << number << ", value is not in the table.\n";
    }
}

void printTable( OpenHashTable& table )
{
    if( !table.print() )
    {
        std::cout << "The table is empty\n";
    }
}
