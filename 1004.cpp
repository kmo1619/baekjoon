#include <iostream>

//2차원 좌표를 받아주는 구조체
struct point {
    int x;
    int y;
};

int main() {
    int T,PlanetCount,R,len1,len2,Encount;
    // T 테스트케이스
    // PlanetCount 행성개수
    // R 반지름값
    // len1 출발지점과 행성사이 거리
    // len2 도착지점과 행성사이 거리
    // Encount 어린왕자가 거친 행성의 개수

    std::cin >> T; 
    // Testcase갯수 입력

    for (int i = 0; i < T; i++){ // Testcase만큼 반복
        struct point start, end; 
        // 출발지점과 도착지점 좌표를 받아줄 구조체

        std::cin >> start.x >> start.y >> end.x >> end.y; 
        // 출발지점 도착지점 좌표 입력
        std::cin >> PlanetCount; 
        // Planet개수를 받아줌

        Encount = 0; 
        // 초기화

        for (int j = 0; j < PlanetCount; j++){ // PlanetCount만큼 반복
            struct point planet; 
            // 행성의 좌표를 받아줄 구조체
            std::cin >> planet.x >> planet.y >> R; 
            // 행성 좌표와 반지름 입력
            len1 = (start.x-planet.x)*(start.x-planet.x) + (start.y-planet.y)*(start.y-planet.y);
            //출발지점과 행성간 거리 제곱 ( 절댓값을 위함 )
            len2 = (end.x-planet.x)*(end.x-planet.x) + (end.y-planet.y)*(end.y-planet.y);
            //도착지점과 행성간 거리 제곱 ( 절댓값을 위함 )

            if (len1 < R*R != len2 < R*R){ // 문제 조건
                Encount++; // 조건에 부합하면 카운트 증가
            }
        }
        std::cout << Encount << std::endl;
        // 결과 출력
    }
    return 0;// main 함수 종료
}