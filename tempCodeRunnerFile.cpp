#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, W;
vector<int> indegree;
vector<int> D;
vector<int> dp;
vector<vector<int>> v;

// T 테스트케이스
// N 건물수
// K 규칙수
// D 각 건물이 지어지는 시간
// X, Y 건물 건설 순서
// W 승리조건

// indegree[]
// - 건물의 위상정렬 배열
// D[]
// - 건물의 건설시간 배열
// dp[i] 
// - i 건물까지 짓는데 걸리는 시간 배열
// v[i][j]
// - 건설 조건에 대한 배열
// - i 건물을 건설 완료해야 j 건물을 건설 가능

void BFS();

int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> K;
        D.resize(N);
        dp.resize(N);
        indegree.resize(N);
        v.resize(K);
        for(int j = 0; j < N; j++){
            cin >> D[j];
        }
        for(int j = 0; j < K; j++){
            int X, Y;
            cin >> X >> Y;
            v[X-1].push_back(Y-1);
            indegree[Y-1]++;
        }
        cin >> W;
        W--;
        // cout << T << endl;
        // cout << N << " " << K << endl;
        // for(int i = 0; i < N; i++){
        //     cout << D[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < v[i].size(); j++){
        //         cout << i << " " << v[i][j] << endl;
        //     }
        // }
        // cout << W << endl;
        BFS();
        cout << dp[W] << endl;
        indegree.clear();
        D.clear();
        dp.clear();
        v.clear();
    }
    return 0;
}
void BFS(){
    queue<int> build;
    for(int i = 0; i < N; i++){
        if(indegree[i] == 0){
            build.push(i);
            dp[i] = D[i];
        }
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