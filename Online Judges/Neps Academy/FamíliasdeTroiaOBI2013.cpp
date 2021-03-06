#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int>vi;

void dfs_aux(int v) {
    vi[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int u = g[v][i];
        if(!vi[u]) {
            dfs_aux(u);
        }
    }
} 

int dfs() {
    vi.assign((int)g.size(), 0);
    int cont = 0;
    for (int i = 0; i < (int)g.size(); i++)
    {
        if (!vi[i]) {
            dfs_aux(i);
            cont++;
        }
    }
    return cont;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    g.assign(n, vector<int>());
    while(m--) {
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << dfs() << endl;
    return 0;  
}

