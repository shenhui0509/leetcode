#include <bits/stdc++.h>
using namespace std;

class Sloution
{
public:
    vector<vector<int>> paliderome_pair(vector<string>& words){
        if(words.size() < 2)   return vector<vector<int>>();
        vector<vector<int>> res;
        map<string, int> word_idx;
        for(unsigned i = 0; i < words.size(); ++i) {
            string key = words[i];
            reverse(key.begin(), key.end());
            word_idx.insert(make_pair(key, i));
        }

        if(word_idx.find("") != word_idx.end()){
            for(int i = 0; i < words.size(); ++i){
                if(word_idx[""]==i) continue;
                res.push_back({word_idx[""], i});
            }

        }

        for(unsigned i = 0; i < words.size(); ++i) {
            for(unsigned j = 0; j < words[i].size(); ++j) {
                string left = words[i].substr(0,j);
                string right = words[j].substr(j);
                if(word_idx.find(left) != word_idx.end() &&
                    is_paliderome(right) &&
                    word_idx[left] != i){
                    res.push_back(vector<int>{word_idx[left],i});
                }
                if(word_idx.find(right) != word_idx.end() &&
                    is_paliderome(left) && 
                    word_idx[right] != i){
                    res.push_back(vector<int>{i,word_idx[right]});
                }
            }
        }
        return res;

    }

    bool is_paliderome(string& s){
        if(s.size() <= 1) return true;
        int i = 0,j=s.size() - 1;
        while(i < j) if(s[i++] != s[j--]) return false;
        return true; 
    }  
};

int main(int argc, char const *argv[])
{
    vector<string> test = {"abc","ba","cba","aaaa","bbbb","acbd","ca",""};
    Sloution sol;
    vector<vector<int>> ans = sol.paliderome_pair(test);
    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    } 
    return 0;
}