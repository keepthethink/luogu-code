//
//  main.cpp
//  P1313
//
//  Created by Kanger He on 2019/6/23.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 1000 + 5;
const int MOD = 10007;

long long f[MAXN][MAXN];

int a, b, k, n, m;

void dp() {
    f[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            if(i > 0) {
                f[i][j] = (f[i][j] + f[i - 1][j]  * a) % MOD;
            }
            if(j > 0) {
                f[i][j] = (f[i][j] + f[i][j - 1]  * b) % MOD;
            }
        }
    }
}

int main() {
    cin >> a >> b >> k >> n >> m;
    
    dp();
    
    cout << f[n][m] << endl;
    
    return 0;
}
