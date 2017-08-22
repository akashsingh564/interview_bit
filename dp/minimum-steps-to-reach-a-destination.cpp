//http://www.geeksforgeeks.org/minimum-steps-to-reach-a-destination/

#include <bits/stdc++.h>
using namespace std;

int steps,dest;
int no_of_steps(int dest){
    /*int dp[100005];
    for(int i=0;i<100005;i++)
        dp[i]=INT_MAX;*/
    queue <int> q;
    q.push(0);
    while(1){
        int count=q.size();
        for(int i=0;i<count;i++){
            int top=q.front();
            q.pop();
            //cout<<"popped "<<top<<endl;
            //dp[top]=min(dp[top],steps);
            if(top==dest)
                //return dp[top];
                return steps;
            //cout<<"pushed "<<top+steps+1<<" "<<top-steps-1<<endl;
            q.push(top+steps+1);
            q.push(top-steps-1);
        }
        steps++;
    }
}

int main(){
    cin>>dest;
    int ans=no_of_steps(dest);
    cout<<"Answer: "<<ans<<endl;
    return 0;
}
