//
//  main.cpp
//  P1577
//
//  Created by Kanger He on 2019/6/24.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 10000 + 5;

int v[MAXN];
int n, k;

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        double d;
        cin >> d;
        v[i] = d * 100;
    }
}

bool check(int d) {
    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        ans += v[i] / d;
    }
    
    return ans >= k;
}

int cut() {
    int l = 1, r = 10000000;
    
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main(int argc, const char * argv[]) {
    input();
    
    cout << fixed << setprecision(2) << cut() / 100.0 << endl;
    
    return 0;
}
