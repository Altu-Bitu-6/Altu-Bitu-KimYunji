#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    string str, checkstr;
    int count = 0;
    
    // 입력
    cin >> n >> m;

    set<string> s;

    for (int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }

    for (int i = 0; i < m; i++) {
        cin >> checkstr;
        if (s.find(checkstr) != s.end()) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
