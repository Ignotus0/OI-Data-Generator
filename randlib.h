#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
#define system_clock chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(system_clock);

ll rand64(){
    return (ll)((rng() * (1llu << 32) | rng()) % (1llu << 63));
}

int randomInt(int l, int r){
    return rand64() % (r - l + 1) + l;
}

int logrithmatic_rng(int l, int r){
    assert(l < r && r <= 31);
    int pw = randomInt(l, r - 1);
    return randomInt((1 << pw), (1 << (pw + 1)) - 1);
}

ll randomLong(ll l, ll r){
    return rand64() % (r - l + 1) + l;
}

vector <int> randomSequence(int n, int l, int r){
    vector <int> a(n);
    for(int i = 0; i < n; ++i) a[i] = randomInt(l, r);
    return a;
}

vector <int> randomPerm(int n){
    vector <int> a(n);
    for(int i = 0; i < n; ++i) a[i] = i + 1;
    shuffle(a.begin(), a.end(), default_random_engine(rng()));
    return a;
}

vector <pair <int, int>> randomPoints(int n, int x_low, int x_high, int y_low, int y_high){
    assert(1ll * (y_high - y_low + 1) * (x_high - x_low + 1) >= n);
    set <pair <int, int>> s;
    vector <pair <int, int>> a(n);
    for(int i = 0; i < n; ++i){
        int x = randomInt(x_low, x_high), y = randomInt(y_low, y_high);
        while(s.find({x, y}) != s.end()) x = randomInt(x_low, x_high), y = randomInt(y_low, y_high);
        a[i] = {x, y};
        s.insert({x, y});
    }
    return a;
}

vector <int> randomTree(int n){
    vector <int> T(n + 1);
    for(int i = 2; i <= n; ++i) T[i] = randomInt(1, i - 1);
    return T;
}

vector <int> Chain(int n){
    vector <int> T(n + 1);
    for(int i = 2; i <= n; ++i) T[i] = i - 1;
    return T;
}

vector <int> Flower(int n){
    vector <int> T(n + 1);
    for(int i = 2; i <= n; ++i) T[i] = 1;
    return T;
}

vector <int> Caterpillar(int n){
    vector <int> T(n + 1);
    if(n <= 8) return randomTree(n);
    int d = randomInt(n / 3, 2 * n / 3);
    for(int i = 2; i <= d; ++i) T[i] = i - 1;
    for(int i = d + 1; i <= n; ++i) T[i] = randomInt(1, i - 1);
    return T;
}

vector <vector <int>> randomConnectedGraph(int n, int m){
    assert(m >= n - 1);
    assert(m <= n * (n - 1) / 2);
    vector <vector <int>> G(n + 1);
    set <pair <int, int>> Edges;
    for(int i = 2, fa; i <= n; ++i){
        fa = randomInt(1, i - 1);
        G[fa].push_back(i);
        Edges.insert({fa, i});
    }
    for(int i = 1; i <= m - n + 1; ++i){
        int u = randomInt(1, n), v = randomInt(1, n);
        if(u > v) swap(u, v);
        while(u == v || Edges.find({u, v}) != Edges.end()){
            u = randomInt(1, n), v = randomInt(1, n);
            if(u > v) swap(u, v);
        }
        G[u].push_back(v);
        Edges.insert({u, v});
    }
    return G;
}

void OutputGraph(int n, int m){
    vector <vector <int>> G = randomConnectedGraph(n, m);
    vector <int> a(n);
    for(int i = 0; i < n; ++i) a[i] = i + 1;
    shuffle(a.begin(), a.end(), default_random_engine(rng()));
    for(int i = 1; i <= n; ++i){
        for(auto p : G[a[i - 1]]){
            int sd = randomInt(0, 1);
            if(sd == 1) printf("%d %d\n", a[i - 1], p);
            else printf("%d %d\n", p, a[i - 1]);
        }
    }
}

void OutputDAG(int n, int m){
    vector <vector <int>> G = randomConnectedGraph(n, m);
    for(int i = 1; i <= n; ++i){
        for(auto p : G[i]){
            printf("%d %d\n", i, p);
        }
    }
}