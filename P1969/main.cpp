//
//  main.cpp
//  P1969
//
//  Created by Kanger He on 2019/6/23.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, ans;
    
    cin >> n >> ans;
    
    int p = ans;
    for(int i = 1; i <= n - 1; i++) {
        int q;
        
        cin >> q;
        if(p < q) {
            ans += (q - p);
        }
        p = q;
    }
    
    cout << ans << endl;
    
    return 0;
}
