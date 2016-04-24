#include <bits/stdc++.h>
using namespace std;

vector<int> find_substring(string s, vector<string>& words)
{
    vector<int> result;
    if(words.empty()) return result;
    unordered_map<string, int> count;
    for(auto word : words){
        if(count.find(word) != count.end()){
            count[word]++;
            continue;
        } else {
            count.insert(make_pair(word,1));
        }
    }
    int n = words.size(), m = words[0].size();
    size_t pos;
    for(pos = 0; pos + m * n <= s.size(); pos++ ){
        string sub = s.substr(pos, m * n);
        unordered_map<string, int> cnt;
        bool flag = true;
        for(int i = 0; i < m*n; i+=m){
            string word = sub.substr(i,m);
            if(count.find(word) != count.end()){
                cnt[word]++;
                if(cnt[word] > count[word]){
                    flag = false;
                    break;
                } else {
                    continue;
                }
            } else {
                flag = false;
                break;
            }
        }
        if(flag) result.push_back(pos);
        else continue;
    }
    return result;
}



int main(int argc, char const *argv[])
{
    string s = "abababab";
    vector<string> dic = {"ab","ab"};
    vector<int> res = find_substring(s,dic);
    for(auto r : res){
        cout << r << " " ;
    } 
    cout << endl;
    return 0;
}