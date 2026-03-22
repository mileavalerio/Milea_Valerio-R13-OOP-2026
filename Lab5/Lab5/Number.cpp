#include "Number.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>

Number::Number(const char* value, int base) {
    this->b = base;
    this->val = new char[strlen(value) + 1];
    strcpy_s(this->val, strlen(value) + 1, value);
}

Number::Number(int value) {
    this->b = 10;
    char temp[20];
    sprintf_s(temp, "%d", value);
    this->val = new char[strlen(temp) + 1];
    strcpy_s(this->val, strlen(temp) + 1, temp);
}

Number::~Number() {
    delete[] val;
}

Number::Number(const Number& n) {
    this->b = n.b;
    this->val = new char[strlen(n.val) + 1];
    strcpy_s(this->val, strlen(n.val) + 1, n.val);
}

Number::Number(Number&& n) {
    this->val = n.val;
    this->b = n.b;
    n.val = nullptr;
    n.b = 0;
}

int Number::baza10(const char* n, int baza) const {
    int rez = 0;
    int p = 1;
    int len = (int)strlen(n);
    for (int i = len - 1; i >= 0; i--) {
        int c = 0;
        if (n[i] >= '0' && n[i] <= '9') c = n[i] - '0';
        else if (n[i] >= 'A' && n[i] <= 'F') c = n[i] - 'A' + 10;
        else if (n[i] >= 'a' && n[i] <= 'f') c = n[i] - 'a' + 10;
        rez += c * p;
        p *= baza;
    }
    return rez;
}

bool Number::operator>(const Number& n) const { return baza10(this->val, this->b) > n.baza10(n.val, n.b); }
bool Number::operator<(const Number& n) const { return baza10(this->val, this->b) < n.baza10(n.val, n.b); }
bool Number::operator>=(const Number& n) const { return baza10(this->val, this->b) >= n.baza10(n.val, n.b); }
bool Number::operator<=(const Number& n) const { return baza10(this->val, this->b) <= n.baza10(n.val, n.b); }
bool Number::operator==(const Number& n) const { return baza10(this->val, this->b) == n.baza10(n.val, n.b); }
bool Number::operator!=(const Number& n) const { return baza10(this->val, this->b) != n.baza10(n.val, n.b); }

char Number::operator[](int index) const { return this->val[index]; }

Number& Number::operator=(Number&& n) {
    if (this != &n) {
        delete[] this->val;
        this->val = n.val;
        this->b = n.b;
        n.val = nullptr;
        n.b = 0;
    }
    return *this;
}

Number& Number::operator=(const Number& n) {
    if (this != &n) {
        delete[] this->val;
        this->b = n.b;
        this->val = new char[strlen(n.val) + 1];
        strcpy_s(this->val, strlen(n.val) + 1, n.val);
    }
    return *this;
}

Number& Number::operator=(const char* s) {
    delete[] this->val;
    this->val = new char[strlen(s) + 1];
    strcpy_s(this->val, strlen(s) + 1, s);
    return *this;
}

Number& Number::operator=(int value) {
    Number temp(value);
    temp.SwitchBase(this->b);
    *this = std::move(temp);
    return *this;
}

void Number::SwitchBase(int newBase) {
    if (this->b == newBase) return;
    int n10 = baza10(this->val, this->b);
    char buf[100];
    int k = 0;
    if (n10 == 0) buf[k++] = '0';
    else {
        while (n10 > 0) {
            int r = n10 % newBase;
            buf[k++] = (r < 10) ? (r + '0') : (r - 10 + 'A');
            n10 /= newBase;
        }
    }
    buf[k] = '\0';
    for (int i = 0; i < k / 2; i++) std::swap(buf[i], buf[k - i - 1]);
    delete[] this->val;
    this->val = new char[k + 1];
    strcpy_s(this->val, k + 1, buf);
    this->b = newBase;
}

Number operator+(const Number& n1, const Number& n2) {
    int res10 = n1.baza10(n1.val, n1.b) + n2.baza10(n2.val, n2.b);
    int maxB = (n1.b > n2.b) ? n1.b : n2.b;
    Number res(res10);
    res.SwitchBase(maxB);
    return res;
}

Number operator-(const Number& n1, const Number& n2) {
    int res10 = n1.baza10(n1.val, n1.b) - n2.baza10(n2.val, n2.b);
    int maxB = (n1.b > n2.b) ? n1.b : n2.b;
    Number res(res10);
    res.SwitchBase(maxB);
    return res;
}

Number& Number::operator+=(const Number& n) {
    *this = *this + n;
    return *this;
}

Number& Number::operator--() {
    memmove(this->val, this->val + 1, strlen(this->val));
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    this->val[strlen(this->val) - 1] = '\0';
    return temp;
}

void Number::Print() const { printf("%s\n", this->val); }
int Number::GetDigitsCount() const { return (int)strlen(this->val); }
int Number::GetBase() const { return this->b; }