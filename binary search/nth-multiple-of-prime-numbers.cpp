//https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/practice-problems/algorithm/glowing-bulbs/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t,k;
string s;
vector <ll> p;

ll solve(ll a){
    ll res=0;
    ll limit=pow(2,p.size());
    for(ll i=1;i<limit;i++){
        int bits=0;
        ll pro=1;
        for(ll j=0;j<p.size();j++){
            if ((i>>j)&1){
                pro*=p[j];
                bits++;
            }
        }
        if(bits%2)
            res+=a/pro;
        else
            res-=a/pro;
    }
    return res;
}

ll binary_search(){
    ll l=1;
    ll h=1000000000000000000;
    ll ans=-1;
    while(l<=h){
        ll mid=l+(h-l)/2;
        if(solve(mid)<k)
            l=mid+1;
        else{
            ans=mid;
            h=mid-1;
        }
    }
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>s;
        cin>>k;
        p.clear();
        for(int i=0;s[i];i++)
            if(s[i]=='1')
                p.push_back(i+1);
        cout<<binary_search()<<endl;
    }
    return 0;
}
