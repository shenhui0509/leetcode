#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses_stack(string s)
{
    int len = s.size(), longest = 0;
    stack<int> st;
    for(int i = 0; i < len; i++){
        if(s[i] == '(') st.push(i);
        else {
            if(!st.empty()){
                if(s[st.top()] == '(') st.pop();
                else st.push(i);               
            } else {
                st.push(i);
            }
        }
    }
    if(st.empty()) longest = len;
    else {
        int a = len, b = 0;
        while(!st.empty()){
            b = st.top(); st.pop();
            longest = max(longest, a - b - 1);
            a = b;
        }
        longest = max(longest,a);
    }
    return longest;
}

int longestValidParentheses_dp(string s)
{
    int len = s.size();
    if(len <= 1) return 0;
    int cur_max = 0;
    vector<int> dp(len,0);
    for(int i = 1; i < len; i++){
        if(s[i] == ')'){
            if(s[i-1] == '('){
                dp[i] = (i-2) >= 0 ? (dp[i-2] + 2) : 2;
                cur_max = max(cur_max, dp[i]);
            } else {
                if(i - dp[i-1] - 1 >= 0 && s[i-dp[i-1] - 1] == '('){
                    dp[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0) ? dp[i-dp[i-1]-2] : 0);
                    cur_max = max(cur_max,dp[i]);
                }
            }
        }
    }
    return cur_max;
}

int main(int argc, char const *argv[])
{
    clock_t t;
    string test = "(((((((((((((((((((((((((((((((((()))))))))))))))())()()()()()()()()()()())))))))))()()())())))))))))))))))))))))()()()()()()()()()()";
    t = clock();
    for(int i = 0; i < 1000;i++)
        cout<<longestValidParentheses_stack(test);
    printf("%ld\n", clock() - t);
    t = clock();
    printf("%ld\n", clock() - t);
    return 0;
}