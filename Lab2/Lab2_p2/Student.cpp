#include <iostream>
#include <string.h>
#include "Student.h"

bool Student::setName(const char* str)
{
	if (strlen(str) > 20)
		return false;
	strcpy_s(name, str);
	return true;
}

const char* Student::getName()
{
	return name;
}

bool Student::setGrade(float nota, char subj)
{
	if ((nota < 1.0f || nota > 10.0f) || (subj != 'm' && subj != 'e' && subj != 'h'))
		return false;
	if (subj == 'm')
		grades.math = nota;
	else if (subj == 'e')
		grades.eng = nota;
	else grades.hist = nota;
	return true;
}

float Student::getGrade(char subj)
{
	if (subj == 'm')
		return grades.math;
	else if (subj == 'e')
		return grades.eng;
	else return grades.hist;
}

float Student::getAvg()
{
	return (getGrade('m') + getGrade('e') + getGrade('h')) / 3;
}