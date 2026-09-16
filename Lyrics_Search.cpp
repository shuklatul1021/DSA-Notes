#include <bits/stdc++.h>
using namespace std;

const string SummerString = "tanabata";
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int maxScore = -1;
    int answer = 1;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int score = 0;
        size_t pos = s.find(SummerString);
        while (pos != string::npos) {
            score++;
            pos = s.find(SummerString, pos + 1);
        }

        if (score > maxScore) {
            maxScore = score;
            answer = i;
        }
    }

    cout << answer << '\n';
}