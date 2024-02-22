#include <iostream>
#include <tuple> //연산에서 tuple을 사용하기 위해 헤더 추가해주기
#include <cmath> // 절댓값 계산을 위해 필요한 헤더
using namespace std;
//tuple<~> : 처음에 반환되는 자료형, diet라는 함수가 입력받은 6개의 값으로 연산을 진행하므로 파라미터에 전부 정의
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O

    while (d--) { //다이어트 기간인 d일 동안 반복을 해줘야 하기 때문에 while문으로 반복
        // 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a);
        w2 += i - (m2 + a);

        // 일일 기초대사량 변화 (m2만 변화)
        if (abs(i - (m2 + a)) > t) { //체중이 증가한 만큼의 절대값이 역치보다 클 때만 변화가 이루어짐
            // [주의] 음수의 나눗셈에 주의: ⌊−5 / 2⌋를 수행하면 3이 나와야 하지만
            // C++에서 int i = (-5) / 2를 수행할 경우 -2가 나옴
            // => float끼리의 나눗셈으로 수행하고 소숫점 버림
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }
    return {w1, w2, m2}; //tuple이 3개를 반환한다고 했으므로 중괄호로 묶어서 반환
}
int main() {
    //정수형으로 입력받기(다이어트 전 체중, 다이어트 전 일일 에너지 섭취량 및 일일 기초대사량, 다이어트 기간의 일일 에너지 섭취량, 일일 활동대사량)
    int w0, i0, i, a;
    int d, t; // 다이어트 기간,기초 대사량 변화 역치
    int final_weight, final_meta;
    //
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    //연산
    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t); //3개로 반환해야 되기 때문에 tuple로 정의
    int w1 = get<0>(tmp), m1 = i0;          // 기초대사량 변화 고려 X, m1은 변화가 없으므로 i0로
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // 기초대사량 변화 고려 O 

    // 출력
    // 일일 기초 대사량 변화 X
    if (w1 <= 0) {
        // m1은 i0에서 변화하지 않고, i0는 0보다 크므로 기초대사량이 0kcal 이하가 되지 않음
        cout << "Danger Diet\n";
    } else {
        cout << w1 << " " << m1 << "\n"; //일일 기초 대사량 그대로 출력 
    }

    // 일일 기초 대사량 변화 O
    if (w2 <= 0 || m2 <= 0) { // 체중이 0이하일 때나 일일 기초 대사량이 0이하일 때
        cout << "Danger Diet";
    } else {
        cout << w2 << " " << m2 << " "; //예상 체중과 일일 기초 대사량 출력
        // 요요 현상이 발생하는지 확인 필요
        if (m2 < i0) { // i0값이 더 큰 경우 요요 현상 발생
            cout << "YOYO";
        } else {
            cout << "NO"; // 요요 현상이 발생하지 않는 경우 no 출력
        }
    }
    return 0;
}