
#ifndef exceptions_cpp
#define exceptions_cpp

#include <iostream>

using namespace std;

class OutOfRange{
public:
    OutOfRange(): message ("\033[31m\nIndex is out of range \033[0m") {};
    void printMessage() const {cout << message << endl << endl;};
private:
    const char* message;
};

class Empty{
public:
    Empty(): message ("\033[31m\nCan't work with empty containers \033[0m") {};
    void printMessage() const {cout << message << endl << endl;};
private:
    const char* message;
};

class InvalidSize{
public:
    InvalidSize(): message ("\033[31m\nInvalid size \033[0m") {};
    void printMessage() const {cout << message << endl;};
private:
    const char* message;
};

class EndOfContainer{
public:
    EndOfContainer(): message ("\033[31m\nReached the end of the container \033[0m") {};
    void printMessage() const {cout << message << endl;};
private:
    const char* message;
};

class InvalidOrder{
public:
    InvalidOrder(): message ("\033[31m\nInvalid order of beginning and ending of subsequence\033[0m") {};
    void printMessage() const {cout << message << endl;};
private:
    const char* message;
};

class InvalidInput{
public:
    InvalidInput(): message ("\033[31m\nYou can enter only numbers from the menu\033[0m") {};
    void printMessage() const {cout << message << endl;};
private:
    const char* message;
};

class EmptyPonter{
public:
    EmptyPonter(): message ("\033[31m\nThe pointer is empty\033[0m") {};
    void printMessage() const {cout << message << endl;};
private:
    const char* message;
};

#endif
