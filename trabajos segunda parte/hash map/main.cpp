#include <iostream>
#include<bits/stdc++.h>
#include "string"
using namespace std;
int max(int a, int b); //maximo valor


int getChar(string str)
{

    // To store the sum of the characters
    // of the given string
    int sum = 0;

    for (int i = 0; i < str.length(); i++) {

        // Add the current character to the sum
        sum += (str[i] - 'a' + 1);
    }



    return sum;

}

void insert2 (string array[],string str2){
    array[getChar(str2)] = str2;

};

int main() {
    string array[10000];

    insert2(array,"sasaasa");

    return 0;
}