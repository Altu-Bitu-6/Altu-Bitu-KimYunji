#include <iostream>
#include <algorithm>

using namespace std;

// 최대공약수를 구하기
int getGcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // 분자와 분모 계산
    int sumNumerator = A * D + B * C;
    int sumDenominator = B * D;

    // 최대공약수를 찾아서 분자와 분모를 나눔
    int GCD = getGcd(sumNumerator, sumDenominator);
    sumNumerator /= GCD;
    sumDenominator /= GCD;

    cout << sumNumerator << ' ' << sumDenominator << '\n';

    return 0;
}
