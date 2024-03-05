#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    deque<int> dq;

    for(int i = 1; i <= a; i++) {
        dq.push_back(i);
    }

    cout << "<";
    
    while(!dq.empty()) {
        for(int i = 0; i < b - 1; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout << dq.front();
        dq.pop_front();

        if(!dq.empty()) {
            cout << ", ";
        }
    }
    cout << ">" << "\n";

    return 0;
}
