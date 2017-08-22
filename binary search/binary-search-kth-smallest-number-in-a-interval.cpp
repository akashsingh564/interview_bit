//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/description/

#include <bits/stdc++.h>
using namespace std;
 
typedef pair<long long,long long> p;
#define ll long long
 
ll t,n,q,j;
vector <p> a1;
vector <p> a2;
vector <p> a;
ll x,y;
ll arr[105];
 
ll binary_search(ll x){
    ll h=j+2;
    ll l=0;
    ll ans=-1;
    while(l<=h){
        ll mid=l+(h-l)/2;  
        if(arr[mid]>=x){
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
 
int main(){
    cin>>t;
    while(t--){
        cin>>n>>q;
        a1.clear();
        a2.clear();
        a.clear();
        memset(arr,0,sizeof(arr));
        
        //input
        for(ll i=0;i<n;i++){
            cin>>x>>y;
            a1.push_back(make_pair(y,x));
        }
        
        //sorting
        sort(a1.begin(),a1.end());
        for(ll i=0;i<n;i++){
            x=a1[i].second;
            y=a1[i].first;
            a2.push_back(make_pair(x,y));
        }
        sort(a2.begin(),a2.end());
        
        /*for(ll i=0;i<n;i++)
            cout<<a2[i].first<< " " <<a2[i].second<<endl;*/
        
        //merging intervals
        a.push_back(a2[0]);
        ll i=1;
        j=0;
        while(i<n){
            if(a[j].second>=a2[i].first){
                a[j].second=max(a[j].second,a2[i].second);
            }
            else{
                a.push_back(a2[i]);
                j++;
            }
            i++;
        }
        
        //****** print intervals ******
        /*cout<<"Merged"<<endl;
        for(ll i=0;i<=j;i++)
            cout<<a[i].first<< " " <<a[i].second<<endl;*/
            
        //processing, making cumulative sum array
        arr[0]=0;
        for(ll i=1;i<j+2;i++){
            arr[i]=arr[i-1]+(a[i-1].second-a[i-1].first+1);
        }
        
        //quering
        while(q--){
            cin>>x;
            ll index=binary_search(x);
            if(index!=-1)
                cout<<a[index-1].first+(x-arr[index-1])-1<<endl;
            else
                cout<<"-1"<<endl;
        }
    }
    return 0;
}