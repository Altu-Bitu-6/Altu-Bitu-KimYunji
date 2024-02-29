#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkBalance(string sequence) {

    stack<char> bracketStack;

    for(char bracket : sequence) {
        if(bracket == '(' || bracket == '[') {
            bracketStack.push(bracket);
        } else if(bracket == ')' || bracket == ']') {
            if(bracketStack.empty()) return false;
            if(bracket == ')' && bracketStack.top() != '(') return false;
            if(bracket == ']' && bracketStack.top() != '[') return false;
            bracketStack.pop();
        }
    }
    return bracketStack.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string line;

    while(true) {
        getline(cin, line);
        if(line == ".") break;
        if(checkBalance(line)) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
    return 0;
}
