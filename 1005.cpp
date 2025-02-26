#include <iostream>

int main() {
    int T;//테스트 케이스 개수 T
    int N, K;//건물개수 N, 규칙개수 K
    int W;//승리 목표 건물 번호 W
    std::cin >> T; //테스트 케이스 입력 받음
    for (int i = 0; i < T; i++) {//T만큼 반복

        int TotalTime = 0;
        //총 소요시간

        std::cin >> N >> K;
        //N과 K값을 입력 받음

        int NodeStatus[1000];
        //건물의 상태를 나타낼 NodeStatus배열 생성.
        //노드값에 해당하는 건물이 건설대기중일때는 조건수 N
        //해당 건물이 건설중인때는 0
        //해당 건물이 건설 완료되면 -1의 값을 가지는 리스트

        int Time[1000];
        //남은 건설시간을 나타낼 Time배열 생성
        //노드값에 해당하는 건물의 남은시간을 저장.

        int Request[100000][2];
        //동적할당 2차원 배열 생성

        for (int i = 0; i < N; i++) {//Time배열에 각 건물의 건설시간 할당
            int t;
            std::cin >> t;
            Time[i] = t;
            NodeStatus[i] = 0;//NodeStatus 초기화
        }

        for (int i = 0; i < K; i++) {//Requset배열에 조건배열[2]를 할당
            int r1, r2;
            std::cin >> r1 >> r2;
            Request[i][0] = r1-1;
            Request[i][1] = r2-1;
            NodeStatus[r2-1] = NodeStatus[r2-1] + 1;//NodeStatus 조건개수 추가
        }

        std::cin >> W;
        //승리 목표 건물 번호 W 입력 받음
        
        while (NodeStatus[W - 1] != -1) {

            int BuildTime = 100000;
            for (int i = 0; i < N; i++) {//건물수만큼 반복
                if (NodeStatus[i] == 0 && Time[i] < BuildTime) {//만약 건물이 건설중이고, 건설시간이 다른 건설시간보다 작다면
                    BuildTime = Time[i];//건설시간중 최소값 구하기
                }
            }

            for (int i = 0; i < N; i++) {//건물수만큼 반복
                if (NodeStatus[i] == 0) {//만약 건설중이라면
                    Time[i] = Time[i] - BuildTime;//건설시간중 최소값을 빼라
                }
            }
            for (int i = 0; i < N; i++) {
                if (Time[i] == 0) {//만약 남은 건설시간이 0이 되면
                    NodeStatus[i] = -1;//건설상태를 건설완료로 변경해라
                    for (int j = 0; j < K; j++) {//조건개수만큼 반복
                        if (Request[j][0] == i) {//만약 건설 완료된 건물이 선행조건인 경우가 있다면
                            NodeStatus[Request[j][1]]--;//선행조건에 해당되는 건물의 조건수--
                            Request[j][0] = -1;
                        }
                    }
                }
            }
            TotalTime = TotalTime + BuildTime;
        }

        std::cout << TotalTime << std::endl;
    }

}