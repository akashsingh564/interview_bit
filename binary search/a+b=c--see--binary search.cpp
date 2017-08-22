//https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/practice-problems/algorithm/triangular-ranges-2/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <ll> t;
ll l,r,q;

ll gen_tri_num(){
    ll i=1;
    while(1){
        ll tri=((i*(i+1))/2);
        if(tri>1e12)
            break;
        t.push_back(tri);
        i++;
    }
    return 1;
}

ll binary_search(ll low, ll key, int up){
    
    ll l=low;
    ll h=t.size();
    
    /*ll ans=-1;
    while(l<=h){
        ll mid=l+(h-l)/2;
        //cout<<" "<<l<<" "<<h<<" "<<t[mid]<<" "<<key<<endl;
        if(t[mid]<key){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return ans;*/
    
    while(h>l){
        ll mid=l+(h-l)/2;
        if(up){ 
            if(t[mid]>key) 
                h=mid;      
            else 
                l=mid+1;

        } 
        else{
            if(t[mid]<key) 
                l=mid+1;
            else 
                h=mid;
        }
    }
    if(!up) 
        return l;
    return h;
}

int main(){
    gen_tri_num();
    cin>>q;
    while(q--){
        cin>>l>>r;
        ll ans=0;
        for(ll i=0;t[i]<=r;i++){
            ll lower=binary_search(i,l-t[i],0);
            ll upper=binary_search(i,r-t[i],1);
            //cout<<t[i]<<" "<<upper<<" "<<lower<<endl;
            if(lower==-1)
                lower=i;
            if(upper==-1)
                continue;
            ans+=(upper-lower);
        }
        cout<<ans<<endl;
    }
    return 0;
}
