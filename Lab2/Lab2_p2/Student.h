#pragma once
class Student
{
	char name[20] = "";
	struct note {
		float math, eng, hist;
	}grades;

public:
	bool setName(const char* str);
	const char* getName();
	bool setGrade(float nota, char subj = 'm');
	float getGrade(char subj = 'm');
	float getAvg();
};

int namecmp(Student s1, Student s2);
int mathcmp(Student s1, Student s2);
int engcmp(Student s1, Student s2);
int histcmp(Student s1, Student s2);
int avgcmp(Student s1, Student s2);