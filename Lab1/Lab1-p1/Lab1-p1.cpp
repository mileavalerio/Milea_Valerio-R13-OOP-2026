// Lab1-p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int myatoi(char* nr, int nrc)
{
    int p = 1, rez = 0;;
    for (int i = nrc - 1; i >= 0; i--)
    {
        rez += p * (nr[i] - '0');
        p *= 10;
    }
    return rez;
}

int main()
{
    int s = 0, nrc = 0;
    char nr[10], c;
    FILE* f;

    if (fopen_s(&f, "ini.txt", "r") == 0)
    {
        c = fgetc(f);
        while (c != EOF)
        {
            if (c >= '0' && c <= '9')
            {
                nr[nrc] = c;
                nrc++;
            }
            if (c == '\n')
            {
                s += myatoi(nr, nrc);
                nrc = 0;
            }
            c = fgetc(f);
        }
        s += myatoi(nr, nrc);
        fclose(f);
        printf("%d\n", s);
        return 0;
    }
    printf("Fisierul nu a fost gasit.\n");
    return 1;

}

