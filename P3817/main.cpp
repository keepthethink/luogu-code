//
//  main.cpp
//  P3817
//
//  Created by Kanger He on 2019/6/24.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 100000 + 5;

int v[MAXN];

int main(int argc, const char * argv[]) {
    int n, k;
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    long long ans = 0;
    for(int i = 1; i <= n - 1; i++) {
        if(v[i] + v[i + 1] > k) {
            ans += v[i] + v[i + 1] - k;
            v[i + 1] = (k - v[i]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
