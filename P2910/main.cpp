//
//  main.cpp
//  P2910
//
//  Created by Helium on 2019/6/24.
//  Copyright © 2019 Helium. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 100 + 5;
const int MAXM = 10000 + 5;

int edge[MAXN][MAXN], a[MAXM];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> edge[i][j];
        }
    }
}

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(edge[i][k] + edge[k][j] < edge[i][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }
}

void calcAns() {
    int ans = 0;
    for(int i = 1; i < m; i++) {
        ans += edge[a[i]][a[i + 1]];
    }
    cout << ans << endl;
}

int main(int argc, const char * argv[]) {
    input();
    floyd();
    calcAns();
    
    return 0;
}
