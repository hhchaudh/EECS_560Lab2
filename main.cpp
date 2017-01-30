// EECS560_Lab1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "OpenHashTable.h"

int getChoice();
void menuLoop(DoubleLinkedList& list);
void insertItem(DoubleLinkedList& list);
void deleteItem(DoubleLinkedList& list);
void reverseList(DoubleLinkedList& list);
void printList(DoubleLinkedList& list);

int main()
{
    OpenHashTable myList = OpenHashTable{10};
    
    // std::ifstream fileReader("data.txt");
    // DoubleLinkedList myList = DoubleLinkedList{};
    // int anInteger;
    //
    // if(fileReader.is_open())
    // {
    //     while(fileReader >> anInteger)
    //     {
    //         myList.insert(anInteger);
    //     }
    //
    //     fileReader.close();
    // }
    // else
    // {
    //     std::cout << "Error reading file\n";
    // }
    //
    // menuLoop(myList);
    //
    // return 0;
}

void menuLoop(DoubleLinkedList& list)
{
    int choice = 0;

    while(choice != 5)
    {
        choice = getChoice();

        switch(choice)
        {
            case 1:
                insertItem(list);
                break;
            case 2:
                deleteItem(list);
                break;
            case 3:
                reverseList(list);
                break;
            case 4:
                printList(list);
                break;
            case 5:
                break;
            default:
                std::cout << "Enter a valid choice (1-5)\n";
        }
    }
}

int getChoice()
{
    int choice = 0;

    std::cout << "..........................................................\n";
    std::cout << "Please choose one of the folowing commands:\n";
    std::cout << "1 - insert\n"
              << "2 - delete\n"
              << "3 - reverse\n"
              << "4 - print\n"
              << "5 - exit\n"
              << "\n";

    std::cin >> choice;

    return choice;
}

void insertItem(DoubleLinkedList& list)
{
    std::cout << "Choose a number to be added to the list\n";
    int number;
    std::cin >> number;
    if(!list.insert(number))
    {
        std::cout << "Error, could not add " << number << ", value is already in the list.\n";
    }
}

void deleteItem(DoubleLinkedList& list)
{
    std::cout << "Choose a number to be deleted from the list\n";
    int number;
    std::cin >> number;
    if(!list.remove(number))
    {
        std::cout << "Error, cannot delete " << number << ", value is not in the list.\n";
    }
}

void reverseList(DoubleLinkedList& list)
{
    list.reverse();
}

void printList(DoubleLinkedList& list)
{
    if(!list.print())
    {
        std::cout << "The list is empty\n";
    }
    else
    {
        std::cout << std::endl;
    }
}
