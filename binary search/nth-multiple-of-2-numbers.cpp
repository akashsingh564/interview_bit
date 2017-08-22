//https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/practice-problems/algorithm/supertables-3/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t,a,b,k,l;

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll solve(ll x){
    return ((x/a)+(x/b)-(x/l));
}

ll binary_search(){
    ll l=0;
    ll h=1000000000000000000;
    ll ans=-1;
    while(l<=h){
        ll mid=l+(h-l)/2;
        if (solve(mid)<k)
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
        cin>>a>>b>>k;
        l=(a*b)/gcd(a,b);
        cout<<binary_search()<<endl;
    }
    return 0;
}
