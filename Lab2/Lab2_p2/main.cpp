// Lab2_p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"

int main()
{
    Student s1, s2;
    s1.setName("Ion"); s2.setName("Andrei");

    s1.setGrade(5.6f, 'm'); s1.setGrade(6.5f, 'e'); s1.setGrade(8.0f, 'h');
    s2.setGrade(9.2f,'m'); s2.setGrade(4.5f, 'e'); s2.setGrade(8.05f, 'h');

    std::cout << s1.getName() << " are nota " << s1.getGrade('m')<<" la matematica."<<std::endl;
    std::cout << "Media studentului " << s2.getName() << " este " << s2.getAvg() << "." << std::endl;
    std::cout << mathcmp(s1, s2) << " " << engcmp(s1, s2) << " " << histcmp(s1, s2) << " " << namecmp(s1, s2) << std::endl;
    return 0;
}


