#include <bits/stdc++.h>
using namespace std;

void trim(string &s){
    if(s.empty())
        return;
    s.erase(0,s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ')+1);
}

using std::swap;

void reverse_word(string &s)
{
    if(s.empty())
        return;
    trim(s);
    if(s.empty())
        return;
    string::size_type slow = 0, fast = 0;
    while(true){
        while(slow < s.size() && s[slow] != ' ') slow++;
        if(slow >= s.size()) break;
        fast = slow;
        while(fast < s.size() && s[fast] == ' ') fast++;
        slow++;
        if(slow == fast) continue;
        while(fast < s.size() && s[fast] != ' ') swap(s[slow++], s[fast++]);
        if(fast >= s.size()) break;
        while(fast < s.size() && s[fast] == ' ') fast++;
    }
    if(slow < s.size())
        s.erase(slow);
    slow = 0; fast = 0;
    while(fast < s.size() && slow < s.size()){
        while(fast < s.size() && s[fast] != ' ') fast++;
        if (fast - slow >= 2)
        {   auto j = fast - 1;
            while (slow < j) swap(s[slow++], s[j--]);
            if (fast >= s.size())
                break;
        }
        fast++;
        slow = fast;
    }
    slow = 0; fast = s.size() - 1;
    while(slow < fast)
        swap(s[slow++],s[fast--]);
    trim(s);
    return;
}

int main(void)
{
    freopen("in","r",stdin);
    char buf[1024];
    gets(buf);
    string s(buf);
    cout << s << endl;
    reverse_word(s);
    cout << s << endl;
    fclose(stdin);
    return 0;
}