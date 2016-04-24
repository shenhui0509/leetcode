#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    int len = s.size();
    vector<string> res;
    if (len <= 10) return res;
    unordered_map<string, int> hasher;
    int i = 0;
    while (i <= len - 10) {
        hasher[s.substr(i, 10)]++;
        i++;
    }
    for (auto iter = hasher.begin(); iter != hasher.end(); ++iter) {
        if (iter->second > 1) {
            res.push_back(iter->first);
        } else {
            continue;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<string> aa = findRepeatedDnaSequences("AAAAACCCCCTTTTTTAAAAACCCCCAAAAACCCCCAAAAA");
    for(auto s : aa){
        cout << s << endl;
    }
    return 0;
}