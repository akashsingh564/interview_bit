vector<int> Solution::flip(string A) {
    vector <int> a;
    for(int i=0;A[i];i++){
        if(A[i]=='1')
            a.push_back(-1);
        else
            a.push_back(1);
    }
    int max_here=0;
    int max_so_far=0;
    int start=1;
    int rs=1;
    int end=0;
    for(int i=0;i<a.size();i++){
        max_here+=a[i];
        if(max_here>max_so_far){
            max_so_far=max_here;
            rs=start;
            end=i+1;
        }
        if(max_here<0){
            max_here=0;
            start=i+2;
        }
    }
    vector <int> res;
    if(rs<=end){
        res.push_back(rs);
        res.push_back(end);
    }
    return res;
}
