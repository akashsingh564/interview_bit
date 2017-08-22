//http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int e1=-1,e2=-1,c1=0,c2=0,freq=0;
    for(int i=0;i<n;i++){
        int key=A[i];
        if(e1==key)
            c1++;
        else if(e2==key)
            c2++;
        else if(c1==0){
            e1=key;
            c1++;
        }
        else if(c2==0){
            e2=key;
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    for(int i=0;i<n;i++)
        if(A[i]==e1)
            freq++;
    if(freq>n/3)
        return e1;
    freq=0;
    for(int i=0;i<n;i++)
        if(A[i]==e2)
            freq++;
    if(freq>n/3)
        return e2;
    return -1;
}
