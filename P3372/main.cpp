//
//  main.cpp
//  P3372
//
//  Created by Helium on 2019/6/24.
//  Copyright © 2019 Helium. All rights reserved.
//

#include<iostream>
#define int long long
using namespace std;

const int MAXN = 1000000 + 5;

int v[MAXN], sum[MAXN], add[MAXN];

void pushup(int k) {
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}

void build(int k, int l, int r) {
    add[k] = 0;
    if(l == r) {
        sum[k] = v[l];
        return;
    }
    
    build(k * 2, l, (l + r) / 2);
    build(k * 2 + 1, (l + r) / 2 + 1, r);
    pushup(k);
}

void f(int k, int l, int r, int p) {
    add[k] += p;
    sum[k] += p * (r - l + 1);
}

void pushdown(int k, int l, int r) {
    int mid = (l + r) / 2;
    f(k * 2, l, mid, add[k]);
    f(k * 2 + 1, mid + 1, r, add[k]);
    add[k] = 0;
}

void modify(int k, int l, int r, int i, int j, int p) {
    if(i <= l && r <= j) {
        f(k, l, r, p);
        return;
    }
    pushdown(k, l, r);
    int mid = (l + r) / 2;
    
    if(i <= mid) {
        modify(k * 2, l, mid, i, j, p);
    }
    if(j > mid) {
        modify(k * 2 + 1, mid + 1, r, i, j, p);
    }
    
    pushup(k);
}

int query(int k, int l, int r, int i, int j) {
    if(i <= l && r <= j) {
        return sum[k];
    }
    pushdown(k, l, r);
    
    int ans = 0, mid = (l + r) / 2;
    
    if(i <= mid) {
        ans += query(k * 2, l, (l + r) / 2, i, j);
    }
    if(j > mid) {
        ans += query(k * 2 + 1, (l + r) / 2 + 1, r, i, j);
    }
    
    return ans;
}

signed main() {
    int n, m;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int c, x, y;
        
        cin >> c >> x >> y;
        
        if(c == 1) {
            int k;
            
            cin >> k;
            
            modify(1, 1, n, x, y, k);
        } else {
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    
    return 0;
}
