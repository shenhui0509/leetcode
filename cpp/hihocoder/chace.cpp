#include <map>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

inline ll gcd(ll x, ll y)
{
    if(y == 0) return x;
    return gcd(y,x%y);
}

int main()
{
    ll n,m;
    cin >> n >> m;
    map<ll,int> mp,np;
    ll cnt = 0, cmt = 0, a = 0;
    ll fn = static_cast<ll>(sqrt(n)) + 1;
    ll fm = static_cast<ll>(sqrt(m)) + 1;
    for(int i = 1; i <= fn; i++)
    {
        if(n%i == 0){
            if(!np[i]){
                np[i] = 1;
                cnt++;
            }
            if(!np[n/i]){
                np[n/i] = 1;
                cnt++;
            }
        }
    }
    for(int i = 1; i <= fm; i++){
        if(m%i == 0){
            if(!mp[i]){
                mp[i] = 1;
                cmt++;
                if(np[i]){
                    ++a;
                }
            }
            if(!mp[m/i]){
                mp[m/i] = 1;
                cmt++;
                if(np[m/i]){
                    ++a;
                }
            }
        }
    }
    ll ans = gcd(cnt*cmt,a);
    cout << cnt*cmt/ans<<" " << a/ans<<endl;
    cout << ceil(2) << endl;
}