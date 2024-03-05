#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<char> wheel(N, '?');
    int currentPos = 0;

    for (int i = 0; i < K; i++) {
        int rotation;
        char letter;
        cin >> rotation >> letter;

        rotation %= N;
        currentPos = (currentPos - rotation + N) % N;

        if (wheel[currentPos] != '?' && wheel[currentPos] != letter) {
            cout << "!\n";
            return 0;
        } else {
            wheel[currentPos] = letter;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (wheel[i] != '?' && wheel[i] == wheel[j]) {
                cout << "!\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << wheel[(currentPos + i) % N];
    }
    cout << '\n';

    return 0;
}
