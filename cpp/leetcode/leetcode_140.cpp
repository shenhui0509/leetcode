#include <bits/stdc++.h>
using namespace std;

void dfs(string s, vector<vector<bool>>& seg, int start, int length,
        int depth, vector<string> &result, string cur, unordered_set<string>& dic){
    if(depth == length){
        result.push_back(cur);
        return;
    }
    for(int len = 1; len <= length; len++){
        if(seg[start][len]){
            string tmp = s.substr(start, len);
            if(dic.find(tmp) == dic.end()){
                continue;
            }
            int c = cur.size();
            cur += tmp;
            if(start + len < length){
                cur.append(" ");  
            }
            dfs(s, seg, start+len,length,start+len,result,cur,dic);
            cur.resize(c);
        }
    }

}
vector<string> wordBreak(string s, unordered_set<string>& wordDict){
    vector<string> result;
    if(s.empty() || wordDict.size() == 0)
        return result;
    int length = s.size();
    vector<vector<bool>> seg(length, vector<bool>(length+1, false));
    for(int len = 1; len <= length; len++){
        for(int i = 0; i + len < length + 1; ++i){
            string tmp = s.substr(i,len);
            if(wordDict.find(tmp) != wordDict.end()){
                seg[i][len] = true;
                continue;
            }
            for(int k = 1; k < len; k++){
                if(seg[i][k] && seg[i+k][len-k]){
                    seg[i][len] = true;
                }
            }

        }
    }
    
    if(!seg[0][length]) return result;
    dfs(s,seg,0,length,0,result,string(""),wordDict);
    return result;
}

int main(int argc, char const *argv[])
{
    string test = "ab"/*"catsanddog"*/;
    unordered_set<string> dic = {"a","b"};/* {"cat","cats","and","sand","dog"}*/;
    vector<string> res = wordBreak(test,dic);
    for(auto ss : res)
        cout << ss << endl;
    return 0;
}
