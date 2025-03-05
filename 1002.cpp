#include <iostream>

int main() {

    int T,x1,x2,y1,y2,r1,r2;
    // T 테스트케이스
    // x1 A의 x좌표
    // x2 B의 x좌표
    // y1 A의 y좌표
    // y2 B의 y좌표
    // r1 A와 주인공이 떨어진 거리
    // r2 B와 주인공이 떨어진 거리

    std::cin >> T; // 테스트케이스 값 입력 받음

    for (int i=0; i<T; i++){// 테스트케이스 만큼 반복
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; 
        // A, B의 좌표, 주인공과의 거리 입력 받음

        int len1 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        // len1 = A와 B사이의 거리^2 = x좌표차이^2 + y좌표차이^2 ( C^2 = A^2 + B^2 )
        // len1이 0일 경우 A와 B는 같은 점에 위치함

        int len2 = (r1+r2)*(r1+r2);
        // len2 = ( A와 주인공 사이의 거리 + B와 주인공 사이의 거리 )^2
        // len1과 비교하여 크면 두군데서 만남
        // len1과 비교하여 작으면 만나지 않음
        // len1과 같다면 한군데에서 만남

        int len3 = (r1-r2)*(r1-r2);
        // len3 = ( A와 주인공 사이의 거리 - B와 주인공 사이의 거리 )^2
        // A와 B가 같은점에 위치하고 len3이 0일 경우 무한한 위치에 위치할 수 있음

        if (len1==0 && len3==0) std::cout << -1; 
        // len1=0 and len3=0일 경우 무한한 경우의 수
        else if (len1<len3 || len1>len2) std::cout << 0; 
        // A와B사이 거리보다 주인공과 A, 주인공과 B사이 거리 합이 더 작을때
        // A와B사이 거리보다 주인공과 A, 주인공과 B사이 거리 차가 더 클때
        else if (len1==len2 || len1==len3) std::cout << 1;
        // A와B사이 거리와 주인공과 A, 주인공과 B사이 거리 합이나 차가 같을때
        else std::cout << 2;
        // 이외 모든 경우

        if (i != T-1){// 마지막 테스트케이스가 아닌경우
            std::cout << std::endl;// 줄바꿈
        }
    }
    
    return 0; //main함수 종료
}