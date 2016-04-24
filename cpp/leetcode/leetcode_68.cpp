#include <bits/stdc++.h>
using namespace std;

void justify(string& s, int max_width){
    if(*s.rbegin() == ' '){
        cout << "wtf" << endl;
        s.pop_back();
    }
    int remain = max_width - s.size();
    if(s.find_first_of(' ') == string::npos){
        s.resize(max_width, ' ');
        return;
    }
    size_t pos = 0;
    while(remain > 0){
        pos = s.find_first_of(' ', pos);
        if(pos == string::npos){
            pos = 0;
            continue;
        }
        s.insert(pos, " ");
        pos = s.find_first_not_of(' ',pos);
        if(pos == string::npos) pos = 0;
        remain--;
    } 
    cout << " ?? " << endl;       
    return;
}

vector<string> fullJustify(vector<string>& word, int max_width)
{
    string line;
    vector<string> result;
    int len = 0;
    int i = 0, n = word.size();
    while(i < n){
        if(line.size() + word[i].size() > max_width){
            justify(line, max_width);
            result.push_back(line);
            line.clear();
            continue;
        } else if(i == n-1){
            line.append(word[i]);
            if(line.size() < max_width)
                line.resize(max_width,' ');
            result.push_back(line);
            break;
        }
        line.append(word[i]);
        if(line.size() < max_width) line.append(" ");
        ++i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<string> ss = {"This","is","an","example","of","text","justification."};
    vector<string> result = fullJustify(ss, 16);
    for(auto s : result){
        cout << s << "---" << s.size() << endl;;
    }
    ss = {"a","b","c","d","e"};
    result = fullJustify(ss,1);
    for(auto s : result){
        cout << s << "---" << s.size() << endl;;
    }   
    return 0;
}

