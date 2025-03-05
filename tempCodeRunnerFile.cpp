#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, W;
vector<int> indegree;
vector<int> D;
vector<int> dp;
vector<vector<int>> v;
void BFS();

int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        int N, T;
        cin >> N >> T;
        D.resize(N + 1);
        dp.resize(N + 1);
        indegree.resize(N + 1);
        v.resize(N + 1);
        for(int j = 0; j < N; j++){
            int time;
            cin >> time;
            D[j] = time;
        }
        for(int j = 0; j < K; j++){
            int X, Y;
            cin >> X >> Y;
            v[X].push_back(Y);
            indegree[Y]++;
        }
        cin >> W;
        BFS();
        cout << dp[W] << endl;
        indegree.clear();
        D.clear();
        dp.clear();
        v.clear();
    }
}
void BFS(){
    queue<int> build;
    for(int i = 0; i <=N; i++){
        if(indegree[i] == 0){
        build.push(i);
        dp[i] = D[i];
        }
        while(build.empty() == 0){
            int curr = build.front();
            build.pop();
            for(int i = 0; i < v[curr].size(); i++){
                int next = v[curr][i];
                if (next > 0){
                    dp[next] = max(dp[next], dp[curr] + D[next]);
                    indegree[next]--;
                    if (indegree[next] == 0) { 
                        build.push(next); 
                    }
                }
            }
        }
    }
}