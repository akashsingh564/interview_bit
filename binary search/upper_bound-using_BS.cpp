//https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/practice-problems/algorithm/random-generator/description/

#include <bits/stdc++.h>
using namespace std;

//lower / upper bound
/*int searchInsert(vector<int> &A, int target) {
            int n = A.size();
            int start = 0, end = n - 1;
            int mid;
            while(start <= end){
                mid = (start + end) / 2;
                if(target == A[mid]){
                    return mid;
                }
                else if(target < A[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            return start;
            //return end //upper bound 
        }*/

vector <int> a;
vector <int>::iterator up;
int t,n,p,k,x;

int binary_search(int key){
    int l=0;
    int h=n-1;
    int ans=n;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(a[mid]<=key)
            l=mid+1;
        else{
            h=mid-1;
            ans=mid;
        }
    }
    return ans;
}

int solve(){
    int range=2*p;
    for(int i=0;i<n;i++){
        int val=a[i];
        val=val+range;
        //up=upper_bound(a.begin(), a.end(),val);
        ///int idx=up-a.begin();
        int idx=(binary_search(val));
        /*if(idx==-1)
            idx=n;*/
        //cout<<a[i]<<" "<<val<<" "<<idx<<" "<<a[idx]<<endl;
        if(idx-i>=k)
            return 0;
    }
    return 1;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>k>>p;
        a.clear();
        for(int i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        int ans=solve();
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
