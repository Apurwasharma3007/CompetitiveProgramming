#include<bits/stdc++.h>
using namespace std;
int SuperDigit(string n,int k){
	if(n.length()==1 && k==1){
		return n[0]-'0';
	}
	long long sum=0;
	for(char digit:n){
		sum+=digit-'0';
	}
	sum*=k;
	return SuperDigit(to_string(sum),1);
}
int main(){
	string n;
	int k;
	cin>>n;
	cin>>k;
	cout<<SuperDigit(n,k);
}