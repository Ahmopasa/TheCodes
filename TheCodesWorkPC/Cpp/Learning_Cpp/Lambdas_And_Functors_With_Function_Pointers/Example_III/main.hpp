#pragma once
#include <iostream>

void print(int x){
    std::cout << "void print(int x) was called. x : " << x << "\n";
}
void print(float x){
    std::cout << "void print(float x) was called. x : " << x << "\n";
}
void print(double x){
    std::cout << "void print(double x) was called. x : " << x << "\n";
}
typedef void(*printITF)(int x);
typedef void(*printFTF)(float x);
typedef void(*printDTF)(double x);