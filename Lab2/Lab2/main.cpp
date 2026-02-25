// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NumberList.h"

int main()
{
    NumberList list1;

    list1.Init();

    for (int i = 10; i > 0; i--)
    {
        list1.Add(i * 2);
    }

    list1.Print();
    std::cout << std::endl;
    
    list1.Sort();
    list1.Print();
    return 0;
}

