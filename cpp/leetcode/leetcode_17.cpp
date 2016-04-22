#include <bits/stdc++.h>
using namespace std;



vector<string> letterCombination(string digits)
{
    if(digits.empty()) return vector<string>();
    static const vector<string> table = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ret = {""};
    int d;
    for(int i = 0; i < digits; i++){
        d = digits[i] - '0';
        if(d < 0 || d>9) break;
        const string& candidate = table[d];
        if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0; j < candidate; j++){
            for(int k = 0; k < ret.size(); k++){
                tmp.push_back(ret[k] + candidate[j]);
            }
        }
        ret.swap(tmp);
    }
    return ret;
}
