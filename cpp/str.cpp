#include <bits/stdc++.h>
using namespace std;

void justify(string& s, int max_width)
{
    int remain = max_width - s.size();
    size_t pos = 0;
    if(s.find_first_of(' ') == string::npos){
        s.resize(max_width, ' ');
        return;
    }
    while(remain > 0){
        pos = s.find_first_of(' ', pos);
        if(pos == string::npos)
        {
            pos = 0;
            continue;
        }
        s.insert(pos, " ");
        pos = s.find_first_not_of(' ', pos);
        remain--;
    }
    return;
}

int main(int argc, char const *argv[])
{
    string s = "this is an ";
    justify(s, 16);
    cout << s << endl;
    cout << s.size() << endl;
    return 0;
}