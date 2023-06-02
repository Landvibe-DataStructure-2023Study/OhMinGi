#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n, m, a, b, k, u;
vector<int>graph[1001];
bool visited[1001];
int countt = 0;


void bfs(int a) {
    queue<int> q;
    q.push(a);    

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (visited [front])continue;
        visited [front] = true;
        countt++;
        if (front==k)cout << countt << " ";
        for (int i : graph[front]) {
            if (!visited[i]) q.push(i);
        }
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
        bfs(u);
        cout << endl;
        countt = 0;
        for (int i = 0; i <= n; i++) {
            visited[i] = false;
        }
    }

    return 0;

}



