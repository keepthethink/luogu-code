//
//  main.cpp
//  P2038
//
//  Created by Kanger He on 2019/6/23.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 200;
const int SIZE = 128;
const int OFFSET = 20;

int space[MAXN][MAXN];
int d, n;

void input(void) {
    cin >> d >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, k;
        
        cin >> x >> y >> k;
        space[x + OFFSET][y + OFFSET] = k;
    }
}

int sum(int x, int y) {
    int res = 0;
    for(int i = x - d; i <= x + d; i++) {
        for(int j = y - d; j <= y + d; j++) {
            res += space[i][j];
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    input();
    
    int ans = 0;
    for(int i = OFFSET; i <= SIZE + OFFSET; i++) {
        for(int j = OFFSET; j <= SIZE + OFFSET; j++) {
            ans = max(ans, sum(i, j));
        }
    }
    
    int cnt = 0;
    for(int i = OFFSET; i <= SIZE + OFFSET; i++) {
        for(int j = OFFSET; j <= SIZE + OFFSET; j++) {
            if(sum(i, j) == ans) {
                cnt++;
            }
        }
    }
    
    cout << cnt << " " << ans << endl;
    
    return 0;
}
