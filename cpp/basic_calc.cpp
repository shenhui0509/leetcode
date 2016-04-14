#include <bits/stdc++.h>
#include <string>
using namespace std;

string to_string(int num){
    string res;
    res.reserve(30);
    if(num < 0){
        res.push_back("-")
    }
    while(num){
        char c = num%10 + '0';
        res.push_back(c);
        num/=10;
    }
    res.shrink_to_fit();
    string r(res.rbegin(), res.rend());
    return r;
}

int stoi(string s){
    int res = 0;
    if(s[0] == '-'){
        for(size_t i = 1; i < s.size(); i++){
            res *= 10;
            res += s[i] - '0';
        }
        return -res;        
    }
    if(s[0] == '+'){
        for(size_t i = 1; i < s.size(); i++){
            res *= 10;
            res += s[i] - '0';
        }
        return res;
    }
    for(size_t i = 0; i < s.size(); i++){
        res*=10;
        res+=s[i] - '0';
    }
    return res;

}

int calculate(string s)
{
    stack<string> stk;
    size_t i = 0;
    while(i < s.size()){
        if(s[i] == ' '){
            i++;
            continue;
        }
        if(s[i] == '(' || s[i] == '+' || s[i] == '-'){
            stk.push(s.substr(i,1));
            i++;
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9'){
            size_t len = 1;
            while((i + len) < s.size() && s[i+len] != ')' && s[i+len] != '+' && s[i+len] != '-') len++;
            string num = s.substr(i, len);
            size_t pos = 0;
            while((pos = num.find_first_of(pos,' ')) != string::npos){
                size_t j = 1;
                while(pos + j < num.size() && num[pos+j] == ' ') j++;
                num.erase(pos,j);
            }
            num.erase(num.find_last_not_of(' ') + 1);
            stk.push(num);
            i+=len;
        }
        if(s[i] == ')'){
            while(stk.top() != "("){
                int num1 = stoi(stk.top());
                stk.pop();
                string op = stk.top();
                stk.pop();
                if(op == "("){
                    stk.push(to_string(num1));
                    break;
                }
                int num2 = stoi(stk.top());
                stk.pop();
                int result;
                cout << num1 << " " << num2 << endl;
                if(op == "+") result = num1 + num2;
                else/* if(op == "-")*/ result = num2 - num1;
                cout << result << endl;
                stk.push(to_string(result));
                // cout << result << endl;
            }
            i++;
            continue;
        }
    }
    cout << stk.size() << endl;
    int result = 0;
    while(!stk.empty()){
        string num = stk.top();
        cout << num << endl;
        stk.pop();
        if(stk.empty()){
            result += stoi(num);
            break;
        }
        string sign = stk.top();
        cout << sign << endl;
        stk.pop();
        result += stoi(sign + num);
        cout << result << endl;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    // cout << calculate("1+(2+3)") << endl;
    // cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    //cout << calculate("  2-1 + 2") << endl;
    cout << calculate("2-(5-6)") << endl;
    return 0;
}