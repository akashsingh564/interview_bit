#include <bits/stdc++.h>
using namespace std;

string s;
int t;

bool is_palindrome(){
	int l=s.size();
	for(int i=0;i<l/2;i++)
		if(s[i]!=s[l-i-1])
			return false;
	return true;
}

void addition(){
	int carry=1;
	int l=s.size();
	for(int i=l-1;i>=0;i--){
		int sum=(s[i]-'0')+carry;
		s[i]=(char)((sum%10)+'0');
		carry=sum/10;
		if(carry==0)
			return;
	}
	if(carry)
		s=((char)(carry+'0'))+s;
	return;
}

/*void next_palindrome_util(int l, int r){
	if(l>=r)
		return;
	if(s[l]==s[r])
		next_palindrome_util(l+1,r-1);
	else if(s[l]>s[r]){
		s[r]=s[l];
		next_palindrome_util(l+1,r-1);
	}
	else{
		char key=s[l];
		int dif=10-(s[r]-s[l]);
		string mid_res=addition(s.substr(l,r-l+1),dif);
		s=s.substr(0,l)+mid_res+s.substr(r+1,l);
		if(mid_res[0]==key)
			next_palindrome_util(l+1,r-1);
		else
			next_palindrome_util(l,r);
	}
}*/

void next_palindrome(){
	//next_palindrome_util(0,s.size()-1);
	int l=s.size();
	string res=s.substr(0,l/2);
	string t=res;
	reverse(t.begin(),t.end());

	if(l&1)
		res=res+s[l/2]+t;
	else
		res=res+t;

	if(res>s){
		s=res;
		return;
	}

	s=res;

	if(l&1)
		s=s.substr(0,l/2)+s[l/2];
	else
		s=s.substr(0,l/2);

	if(l>1)
		addition();

	if(l&1){
		t=s.substr(0,l/2);
		reverse(t.begin(),t.end());
		s=s+t;
	}
	else{
		t=s;
		reverse(t.begin(),t.end());
		s=s+t;
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>s;
		int ind = 0;
		while(s[ind]=='0')
			ind++;
		if(ind==s.size())
			s="0";
		else
			s.erase(s.begin(),s.begin()+ind);

		if(is_palindrome())
			addition();

		next_palindrome();
		cout<<s<<endl;
		}
	return 0;
}		