//
//  main.cpp
//  P1071
//
//  Created by Kanger He on 2019/6/23.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, char> dict;

bool make() {
    string s1, s2;
    
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++) {
        if(dict.find(s1[i]) != dict.end() && dict[s1[i]] != s2[i]) {
            return false;
        }
        dict[s1[i]] = s2[i];
    }
    return true;
}

bool check() {
    for(int i = 'A'; i <= 'Z'; i++) {
        if(dict.find((char)i) == dict.end()) {
            return false;
        }
    }
    
    for(int i = 'A'; i <= 'Z'; i++) {
        for(int j = 'A'; j <= 'Z'; j++) {
            if(i != j && dict[i] == dict[j]) {
                return false;
            }
        }
    }
    
    return true;
}

string encrypt(string s) {
    for(int i = 0; i < s.length(); i++) {
        s[i] = dict[s[i]];
    }
    return s;
}

int main(int argc, const char * argv[]) {
    if(make() && check()) {
        string s;
        
        cin >> s;
        cout << encrypt(s) << endl;
    } else {
        cout << "Failed" << endl;
    }
    
    return 0;
}
