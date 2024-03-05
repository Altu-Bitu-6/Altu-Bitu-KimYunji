#include <iostream>
#include <vector>
using namespace std; //기본 틀 그대로 써주기

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
int charToint(char ch){
    return (ch - '0'); //해당 문자열과 0사이의 거리를 return하면 ch가 나타내는 원래의 수가 됨.
}

vector<int> calcPlus(string &a, string &b) {
    int idx_a = a.size() - 1; // 일의 자리 인덱스, 맨 뒤의 자리 수는 길이에 -1한 것
    int idx_b = b.size() - 1; //마찬가지로 길이에 -1한 것
    bool carry = false; //올림수 false면 0이고 true면 1
    vector<int> ans;

    while (idx_a >= 0 && idx_b >= 0) { //뒤의 자릿수부터 덧셈을 할 것.
        int num = charToint(a[idx_a--]) + charToint(b[idx_b--]); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;            // num에 carry 더해주기. (carry는 어차피 1 아니면 0) carry가 true면 더해지는 것
        carry = num / 10;        // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 마지막으로 num의 일의 자리 수를 push(올림을 제외한 값만 스택에 push)
    }

    // a에서 남은 숫자 반영(b는 0인데 a가 아직 0이 아닐 수도 있음)
    while (idx_a >= 0) {
        int num = charToint(a[idx_a--]); //이제 a만 더해주면 됨.

        num += carry; //위와 같은 과정 반복해주기
        carry = num / 10;
        ans.push_back(num % 10);
    }

    // 남은 올림 확인
    if (carry){ //올림 수가 있었는지 이렇게만 조건 해주면
        ans.push_back(1); //carry가 true면 이 명령이 실행됨.
    }

    return ans; //answer 값 반환해주기
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b; //int로 받으면 오버플로우가 발생하므로 string으로 받기
    vector<int> ans;

    //입력
    cin >> a >> b;

    //연산
    if (a.length() < b.length()) {       // 자릿수가 더 긴 것을 앞에 두기
        swap(a, b); //(b의 길이가 더 길다면)swqp해주기
    }

    ans = calcPlus(a, b); //ans라는 문자열을 

    //출력
    while (!ans.empty()) { //vector를 스택인 것처럼 사용하는 방식
        cout << ans.back(); //ans의 back을 출력해주기(해당 벡터의 마지막 원소)
        ans.pop_back(); //
    }
}