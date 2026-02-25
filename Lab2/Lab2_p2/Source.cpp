#include <iostream>
#include <string.h>
#include "Student.h"

int namecmp(Student s1, Student s2)
{
	if (strcmp(s1.getName(), s2.getName()) > 0)
		return 1;
	else if (strcmp(s1.getName(), s2.getName()) < 0)
		return -1;
	else return 0;
}

int mathcmp(Student s1, Student s2)
{
	if (s1.getGrade('m') > s2.getGrade('m'))
		return 1;
	else if (s1.getGrade('m') < s2.getGrade('m'))
		return -1;
	else return 0;
}

int engcmp(Student s1, Student s2)
{
	if (s1.getGrade('e') > s2.getGrade('e'))
		return 1;
	else if (s1.getGrade('e') < s2.getGrade('e'))
		return -1;
	else return 0;
}

int histcmp(Student s1, Student s2)
{
	if (s1.getGrade('h') > s2.getGrade('h'))
		return 1;
	else if (s1.getGrade('h') < s2.getGrade('h'))
		return -1;
	else return 0;
}

int avgcmp(Student s1, Student s2)
{
	if (s1.getAvg() > s2.getAvg())
		return 1;
	else if (s1.getAvg() < s2.getAvg())
		return -1;
	else return 0;
}