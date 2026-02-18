// Lab1-p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100] = "", cuvinte[20][30];
    int nrcuv = 0;
    scanf("%[^\n]", s); //citeste tot pana la enter
    char* p, aux[30]="";
    p = strtok(s, " ");
    while (p)
    {
        strcpy(cuvinte[nrcuv], p);
        nrcuv++;
        p = strtok(NULL, " ");
    }
    for (int i = 0; i < nrcuv - 1; i++)
        for (int j = i + 1; j < nrcuv; j++)
        {
            int len1 = strlen(cuvinte[i]);
            int len2 = strlen(cuvinte[j]);

            if (len2 > len1 || (len2 == len1 && strcmp(cuvinte[i], cuvinte[j]) > 0))
            {
                strcpy(aux, cuvinte[i]);
                strcpy(cuvinte[i], cuvinte[j]);
                strcpy(cuvinte[j], aux);
            }
        }
    for (int i = 0; i < nrcuv; i++)
        printf("%s\n", cuvinte[i]);
    return 0;
}


