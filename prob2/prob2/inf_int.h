#ifndef _INF_INT_H_
#define _INF_INT_H_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>

class inf_int
{
private:
    char* digits;
    unsigned int length;
    bool thesign;   // true if positive , false if negative.
    // ex) 15311111111111111 -> digits="11111111111111351", length=17, thesign=true;
    // ex) -12345555555555 -> digits="55555555554321", length=14, thesign=false
    // you may insert additional private members here.
    void CheckZero(void); //-0인지 체크해서 0으로 만드는 함수, -0이 나올 수 있는 곳에 사용

public:
    inf_int();               // assign 0 as a default value
    inf_int(int);
    inf_int(const char*);
    inf_int(const inf_int&); // copy constructor
    ~inf_int(); // destructor

    inf_int& operator=(const inf_int&); // assignment operator

    friend bool operator==(const inf_int&, const inf_int&);
    friend bool operator!=(const inf_int&, const inf_int&);
    friend bool operator>(const inf_int&, const inf_int&);
    friend bool operator<(const inf_int&, const inf_int&);

    friend inf_int operator+(const inf_int&, const inf_int&);
    friend inf_int operator-(const inf_int&, const inf_int&);
    friend inf_int operator*(const inf_int&, const inf_int&);
    // friend inf_int operator/(const inf_int& , const inf_int&); // not required

    friend std::ostream& operator<<(std::ostream&, const inf_int&);
    // friend istream& operator>>(istream& , inf_int&);    // not required

    void Add(const char num, const unsigned int index);
    void Subtract(const char num, const unsigned int index);
};

#endif