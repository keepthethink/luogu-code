//
//  main.cpp
//  P1563
//
//  Created by Helium on 2019/6/22.
//  Copyright © 2019 Helium. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;

const int MAXN = 1000000 + 5;

int fx[MAXN];
string name[MAXN];
int n, m, ans = 0;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> fx[i] >> name[i];
    }
}

void calc() {
    for(int i = 0; i < m; i++) {
        int com, num;
        cin >> com >> num;
        
        if(com == fx[ans]) {
            ans = (ans + n - num) % n;
        } else {
            ans = (ans + num) % n;
        }
    }
}

void output() {
    cout << name[ans] << endl;
}

int main() {
    input();
    calc();
    output();
    
    return 0;
}
