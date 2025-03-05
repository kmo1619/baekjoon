#include <iostream>

int main() {
    int T, x, a, b, c;
    // T 테스트케이스
    // x 입력받는 수1
    // a 0의 개수
    // b 1의 개수
    // c 상수를 임시로 저장할 변수

    std::cin >> T; 
    // 테스트케이스 값 입력받음

    for (int i = 0; i < T; i++) {// 테스트케이스 만큼 반복
        std::cin >> x; 
        //상수 입력받음

        a = 1;
        b = 0;
        //x가 0일때 값을 초기값으로 설정

        for (int j = 0; j < x; j++) {//x만큼 반복
            c = a;
            a = b;
            b = a + c;
            //규칙에 따른 계산법
        }
        std::cout << a << " " << b << std::endl;
        //결과 출력
    }

    return 0;// main함수 종료
}
