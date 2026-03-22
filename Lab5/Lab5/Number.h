#pragma once
#include <string.h>

class Number
{
    char* val;
    int b;
    int baza10(const char* n, int baza) const;

public:
    Number(const char* value, int base);
    Number(int value);
    ~Number();

    Number(const Number& n);
    Number(Number&& n);

    bool operator>(const Number& n) const;
    bool operator<(const Number& n) const;
    bool operator>=(const Number& n) const;
    bool operator<=(const Number& n) const;
    bool operator==(const Number& n) const;
    bool operator!=(const Number& n) const;

    char operator[](int index) const;

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);

    Number& operator+=(const Number& n);
    Number& operator=(Number&& n);
    Number& operator=(const Number& n);
    Number& operator=(const char* s);
    Number& operator=(int value);

    Number& operator--();
    Number operator--(int);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};