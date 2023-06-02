#include <iostream>
#include <vector>
using namespace std;

int t, n, m, a, b, k, u;
vector<int>graph[1001];
bool visited[1001];
int countt = 0;

void DFS(int x) {
    countt++;
    if (x == k)cout << countt << " ";
    visited[x] = true;
    for (int i : graph[x]) {
        if (!visited[i]) DFS(i);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);



    cin >> n >> m >> t;
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    while (t--) {
        cin >> u >> k;
        DFS(u);
        cout << endl;
        countt = 0;
        for (int i = 0; i <= n; i++) {
            visited[i] = false;
        }
    }

    return 0;

}

