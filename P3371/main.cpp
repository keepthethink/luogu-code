//
//  main.cpp
//  P3371
//
//  Created by Kanger He on 2019/6/24.
//  Copyright © 2019 Kanger He. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Line {
    int len, dest, next;
};

struct Node {
    int dist, headLine;
    
    bool operator < (const Node& n) const {
        return dist > n.dist;
    }
};

const int MAXN = 10000 + 5;
const int MAXM = 500000 + 5;
const int INF = 2147483647;

Line line[MAXM];
Node node[MAXN];
int n, m;

void addLine(int id, int u, int v, int l) {
    line[id].dest = v;
    line[id].len = l;
    line[id].next = node[u].headLine;
    node[u].headLine = id;
}

void dijkstra(int s) {
    for(int i = 1; i <= n; i++) {
        node[i].dist = INF;
    }
    node[s].dist = 0;
    
    priority_queue<Node> pq;
    
    pq.push(node[s]);
    
    while(!pq.empty()) {
        Node now = pq.top(); pq.pop();
        
        for(int i = now.headLine; i != 0; i = line[i].next) {
            int dest = line[i].dest;
            
            if(node[dest].dist > now.dist + line[i].len) {
                node[dest].dist = now.dist + line[i].len;
                
                pq.push(node[dest]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int s;
    
    cin >> n >> m >> s;
    
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        
        cin >> u >> v >> w;
        
        addLine(i, u, v, w);
    }
    
    dijkstra(s);
    
    for(int i = 1; i <= n; i++) {
        cout << node[i].dist << " ";
    }
    
    return 0;
}
