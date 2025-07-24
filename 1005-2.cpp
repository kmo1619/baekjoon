#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, X, Y, W;

// T 테스트케이스
// N 건물수
// K 규칙수
// D 각 건물이 지어지는 시간
// X, Y 건물 건설 순서
// W 승리조건

vector<int> indegree;
vector<int> D;
vector<int> dp;
vector<vector<int>> v;

// indegree[]
// - 건물의 위상 배열
// D[]
// - 건물의 건설시간 배열
// dp[i]
// - i 건물까지 짓는데 걸리는 시간 배열
// v[i][j]
// - 건설 조건에 대한 배열
// - i 건물을 건설 완료해야 j 건물을 건설 가능

void BFS();
// 전방 선언

int main(){
    cin >> T;
    // 테스트케이스 입력받음
    for(int i = 0; i < T; i++){ // 테스트케이스만큼 반복
        cin >> N >> K;
        // 건물수와 규칙수 입력받음
        D.resize(N);
        dp.resize(N);
        indegree.resize(N);
        v.resize(N);
        // 벡터의 초기크기 설정
        for(int j = 0; j < N; j++){ // 건물 수 만큼 반복
            cin >> D[j];
            // 건설시간 입력 받음
        }
        for(int k = 0; k < K; k++){ // 규칙 수 만큼 반복
            cin >> X >> Y;
            // 건설 순서 입력받음
            v[X-1].push_back(Y-1);
            // 선행조건 건물벡터 끝에 후속건물을 요소로 추가
            // 배열이 0부터 시작하므로 -1을 계산
            indegree[Y-1]++;
            // 후속건물의 위상을 1상승
        }
        cin >> W;
        W--;
        // 승리조건건물을 입력받음

        BFS();
        // 너비우선탐색을 진행
        cout << dp[W] << endl;
        // 승리조건 건물을 짓기까지 걸리는 시간을 출력
        indegree.clear();
        D.clear();
        dp.clear();
        v.clear();
        // 배열 초기화
    }
    return 0;
    // main 함수 종료
}
void BFS(){ // 너비우선탐색 알고리즘
    queue<int> build;
    // build 큐 생성
    // 현재 건설 진행중인 건물을 담는 큐
    for(int i = 0; i < N; i++){ // 건물 수 만큼 반복
        if(indegree[i] == 0){ // 만약 건물의 위상이 0이라면 즉 선행조건 건물이 없는 건물이라면
            build.push(i);
            // 건물 i를 build에 추가
            dp[i] = D[i];
            // 건물 i는 선행조건이 없으므로 건선시간이 최종건설시간임
        }
    }
    while(build.empty() == 0){ // build큐가 비어있을때까지 반복
        int curr = build.front();
        // curr = build의 맨앞 요소
        for(int i = 0; i < v[curr].size(); i++){ // curr의 후속건물수 만큼 반복
            int next = v[curr][i];
            // next = curr의 후속건물
            dp[next] = max(dp[next], dp[curr] + D[next]);
            // next의 최종 건설시간은 이미 계산된 값과 이번에 계산되는값중 최대값으로 지정
            indegree[next]--;
            // next의 위상을 1 감소
            if (indegree[next] == 0) { // 만약 next의 위상이 0이라면
                build.push(next);
                // next를 build에 추가
            }
        }
        build.pop();
        // build의 맨앞 요소를 삭제
    }
}