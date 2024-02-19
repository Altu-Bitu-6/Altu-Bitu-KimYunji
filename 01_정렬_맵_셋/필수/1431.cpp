#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& s1, const string& s2){
    if(s1.length() != s2.length())
        return s1.length() < s2.length();

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < s1.length(); i++){
        if(isdigit(s1[i])){
            sum1 += (s1[i] - '0');
        }
        if(isdigit(s2[i])){
            sum2 += (s2[i] - '0');
        }
    }
    if(sum1 != sum2)   
        return sum1<sum2;

    return s1<s2;
}

int main(){
    int n;
    cin >> n;

    vector<string> serials(n);

    for(int i=0; i<n; i++) {
        cin >> serials[i];
    }

    sort(serials.begin(), serials.end(), cmp);

    for(int i=0; i <n; i++) {
        cout << serials[i] << "\n";
    }
    
    return 0;
}
