#include <bits/stdc++.h>
using namespace std;
vector<int> dp(string input, map<string, vector<int>>&mem)
{
    vector<int> result;
    int len = input.size();
    for(int i = 0; i < len; i++){
        char cur = input[i];
        if(cur == '+' || cur == '-' || cur == '*'){
            vector<int> r1,r2;
            string s1 = input.substr(0,i);
            if(mem.find(s1) != mem.end())
                r1 = mem[s1];
            else 
                r1 = dp(s1,mem);

            s1 = input.substr(i+1);
            if(mem.find(s1) != mem.end())
                r2 = mem[s1];
            else 
                r2 = dp(s1,mem);

            for(auto n1: r1){
                for(auto n2 : r2){
                    if(cur == '+')
                        result.push_back(n1+n2);
                    else if(cur == '-')
                        result.push_back(n1-n2);
                    else   
                        result.push_back(n1*n2);
                }
            }
        }
    }
    if(result.empty())
        result.push_back(atoi(input.c_str()));
    mem[input] = result;
    return result;
}
vector<int> diffways_to_compute(string input)
{
    map<string, vector<int>> mem;
    vector<int> result = dp(input, mem);
    return result;
}



int main(int argc, char const *argv[])
{
    string input("1+2+3-4+5");
    vector<int> res = diffways_to_compute(input);
    for(auto nums : res){
        cout << nums << endl;
    }
    return 0;
}