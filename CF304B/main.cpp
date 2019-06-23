//
//  main.cpp
//  CF304B
//
//  Created by Kanger He on 2019/6/23.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

class Date {
public:
    int year, month, day;
    Date() {
        year = 1900;
        month = 1;
        day = 1;
    }
    bool prime() {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    void update() {
        int days[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(!prime()) {
            days[2] = 28;
        } else {
            days[2] = 29;
        }
        day++;
        if(day > days[month]) {
            day = 1;
            month++;
        }
        if(month > 12) {
            month = 1;
            year++;
        }
    }
    bool operator == (const Date &b) const {
        return day == b.day && month == b.month && year == b.year;
    }
    bool operator != (const Date &b) const {
        return !(*this == b);
    }
    
    bool operator < (const Date &b) const {
        if(year == b.year) {
            if(month == b.month) {
                return day < b.day;
            }
            return month < b.month;
        }
        return year < b.year;
    }
};

int main(int argc, const char * argv[]) {
    Date a, b;
    
    scanf("%d:%d:%d", &a.year, &a.month, &a.day);
    scanf("%d:%d:%d", &b.year, &b.month, &b.day);
    
    int ans = 0;
    
    while(a != b) {
        ans++;
        if(a < b) {
            a.update();
        } else {
            b.update();
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
