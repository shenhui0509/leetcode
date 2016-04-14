#include <bits/stdc++.h>
using namespace std;




int calculate_fuck(string s)
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
                    cout << " pop ( and push " << num1 << endl;
                    stk.push(to_string(num1));
                    break;
                }
                int num2 = stoi(stk.top());
                stk.pop();
                int result;
                cout << num1 << " " << num2 << endl;
                if(op == "+") result = num1 + num2;
                else/* if(op == "-")*/ result = num2 - num1;
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
        stk.pop();
        if(sign == "-" && num[0] == '-'){
            num.erase(num.begin());
            result += stoi(num);
            continue;
        }
        result += stoi(sign + num);
    }
    return result;
}

int calculate(string s){
    int res = 0;
    int sign = 1, num = 0;
    stack<int> nums, signs;
    for(char c:s){
        if(isdigit(c)){
            num = num * 10 + c - '0';
        } else {
            res += sign * num;
            num = 0;
            if(c == '+') sign = 1;
            if(c == '-') sign = -1;
            if(c == '('){
                nums.push(res);
                signs.push(sign);
                res = 0;
                sign = 1;
            }
            if(c == ')' && signs.size()){
                res = signs.top() * res + nums.top();
                signs.pop();nums.pop();
            }
        }
    }
    res += sign * num;
    return res;
}

int main(int argc, char const *argv[])
{
    // cout << calculate("1+(2+3)") << endl;
    // cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    //cout << calculate("  2-1 + 2") << endl;
    cout << calculate("2-(5-6)+(1)") << endl;
    return 0;
}