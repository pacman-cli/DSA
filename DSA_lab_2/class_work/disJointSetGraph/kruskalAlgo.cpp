#include<iostream>
using namespace std;
int E;     
int V;  
int p[100],rankk[100];

void make_set() {
    for (int i = 0; i < V; i++) {
        p[i] = i;
        rankk[i]=0;
    }
}

int find_set(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x]= find_set(p[x]); //path compression
}

int union_sets(int s1, int s2) {
    int r1, r2;
    r1 = find_set(s1);
    r2 = find_set(s2);
    if (r1 == r2)
        return 0; 
    if (rankk[r1] > rankk[r2]) {
        p[r2] = r1;
    } else {
        p[r1] = r2;
        if (rankk[r1] == rankk[r2]) 
            rankk[r2]++;
    }
    return 1;
}
int main (){
vector<pair<int, pair<int, int>>> graph1; 

    int u, v, w;
    cout << "Enter Number of Vertices: \n";
    cin >> V;
    cout << "Enter Number of Edges: \n";
    cin >> E;
    cout << "Enter the graph: \n";

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph1.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(graph1.begin(), graph1.end());

    cout << "\nSorted Graph according to the Edges:\n";
    for (int i = 0; i < E; i++) {
        cout << graph1[i].second.first << " -- " << graph1[i].second.second << " --> " << graph1[i].first << '\n';
    }
    cout << '\n';
    
    make_set();

    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 0; i < E; i++) {
        u = graph1[i].second.first;
        v = graph1[i].second.second;
        w = graph1[i].first;
        if (union_sets(u, v) != 0) {
            cout << u << " <--> " << v << " --> " << w << '\n';
        }
    }

    return 0;
}