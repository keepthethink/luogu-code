//
//  main.cpp
//  P1303
//
//  Created by Kanger He on 2019/6/23.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const int MAXN = 2000 + 5;

int a[MAXN], b[MAXN], c[MAXN * 2];
int aLen, bLen, cLen;
int flag = 0;

void input(void) {
    string s1, s2;
    
    cin >> s1 >> s2;
    
    if(s1[0] == '-') {
        flag++;
        s1 = s1.substr(1, s1.length() - 1);
    }
    
    if(s2[0] == '-') {
        flag++;
        s2 = s2.substr(1, s2.length() - 1);
    }
    flag %= 2;
    
    for(int i = 0; i < s1.length(); i++) {
        a[aLen++] = s1[s1.length() - i - 1] - '0';
    }
    for(int i = 0; i < s2.length(); i++) {
        b[bLen++] = s2[s2.length() - i - 1] - '0';
    }
}

void calc(void) {
    for(int i = 0; i < aLen; i++) {
        for(int j = 0; j < bLen; j++) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    cLen = aLen + bLen - 1;
    if(c[aLen + bLen - 1] != 0) {
        cLen++;
    }
    
    while(cLen > 1 && c[cLen - 1] == 0) {
        cLen--;
    }
}

void output(void) {
    if(flag) {
        cout << "-";
    }
    for(int i = cLen - 1; i >= 0; i--) {
        cout << c[i];
    }
}

int main(int argc, const char * argv[]) {
    input();
    calc();
    output();
    
    return 0;
}
