#include <bits/stdc++.h>
using namespace std;

vector<string> table1 = {"", " One"," Two"," Three"," Four"," Five"," Six"," Seven"," Eight"," Nine"};
vector<string> table2 = {" Ten", " Eleven"," Tweleve", " Thirteen"," Fourteen"," Fifteen"," Sixteen"," Seventeen"," Eighteen"," Nineteen"};
vector<string> table3 = {" Twenty"," Thirty"," Forty"," Fifty"," Sixty"," Seventy"," Eighty"," Ninety"};

void trim(string& str){
    if(str.empty()) return;
    str.erase(0,str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' '));
}
string helper(int num)
{
    string ret;
    if(num >= 1000 || num == 0)
        return ret;
    int hundred = num / 100;
    if(hundred != 0)
        ret += table1[hundred] + " Hundred";
    int tens = (num % 100) / 10;
    int ones = (num % 100) % 10;
    if(tens == 1)
        ret += table2[ones];
    else if(tens >= 2){
        ret += table3[tens-2];
        ret += table1[ones];
    } else {
        ret += table1[ones];
    }
    trim(ret);
    return ret;
}

string numberToWords(int num)
{
    string ret;
    if(num == 0){
        return string("Zero");
    }
    int billion = num / 1000000000;
    int million = (num / 1000000) % 1000;
    int thousand = (num / 1000) % 1000;
    int remain = num % 1000;
    if(billion != 0){
        ret += table1[billion] + " Billion ";   
    }

    if(million != 0){
        ret += helper(million) + " Million ";
    }
    if(thousand != 0){
        ret += helper(thousand) + " Thousand ";
    }
    if(remain != 0){
        ret += helper(remain);
    }
    trim(ret);
    return ret;
}
int main(int argc, char const *argv[])
{
    vector<int> tests = {INT_MAX, 0, 123456, 1000100, 413132,1000001,1234567};
    for(int i : tests){
        cout << numberToWords(i) << endl;
    }
    return 0;
}