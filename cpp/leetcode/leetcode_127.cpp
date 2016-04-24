#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordlist){
    unordered_set<string>head, tail, *phead, *ptail;
    head.insert(beginWord);
    tail.insert(endWord);
    int dist = 2;
    while(!head.empty() && !tail.empty()){
        if(head.size() < tail.size()){
            phead = &head;
            ptail = &tail;
        } else {
            phead = &tail;
            ptail = &head;
        }
        unordered_set<string> tmp;
        for(auto iter = phead->begin(); iter != phead->end(); ++iter){
            string word = *iter;
            wordlist.erase(word);
            for(int p = 0; p < static_cast<int>(word.length()); p++){
                char letter = word[p];
                for(int k = 0; k < 26; k++){
                    word[p] = 'a' + k;
                    if(ptail->find(word) != ptail->end())
                        return dist;
                    if(wordlist.find(word) != wordlist.end()){
                        tmp.insert(word);
                        word.erase(word);
                    }
                }
                word[p] = letter;
            }
        }
        dist++;
        swap(*phead, tmp);
    }
    return 0;
}