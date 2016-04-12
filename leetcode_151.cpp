#include <bits/stdc++.h>
using namespace std;

void trim(string& s)
{
    if(s.empty()){
        return;
    }
    s.erase(0,s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ')+1);
}

void swap(char &a, char &b){
    a ^= b;
    b ^= a;
    a ^= b;
}
void reverse_word(string &s)
{
    trim(s);
    if(s.empty()) return;
    cout << s << endl;
    string::size_type slow = 0;
    string::size_type fast = 0;
    while(true){
        while(slow < s.size() && s[slow] != ' ') slow++;
        //cout << slow << endl;
        if(slow == s.size()) break;
        while(fast < s.size() && s[fast] == ' ') fast++;
        //cout << fast << endl;
        slow++;
        if(fast == s.size()) break;
        while(fast < s.size() && s[fast] != ' ') s[slow++] = s[fast++];
        if(fast == s.size()) break;
        else{
            s[slow+1] = ' ';
            slow++;
        }
        //cout << fast << endl;
        while(fast < s.size() && s[fast] == ' ') fast++;
        if(fast == s.size()) break;
        //cout << fast << endl;
        //slow = fast;
    } // erase the duplicate fasts
    s.erase(slow);
    cout << s << endl;
    slow = 0; fast = 0;
    string::size_type j;
    while(slow < s.size() && fast < s.size()){
        while(fast < s.size() && s[fast] != ' ') fast++;
        j = fast - 1;
        while(slow < j) swap(s[slow++],s[j--]);
        fast++;
        slow = fast;
    }
    // reverse(s.begin(), s.end());
    return;
}

int main(void)
{   
    freopen("in","r",stdin);
    string ss = "  asdasd    sdadqwweq      dfq rqrwer rqw qrqwere   qweqwr   rqwer ";
    reverse_word(ss);
    //trim(ss);
    cout << ss << endl;
    fclose(stdin);
    return 0;
}