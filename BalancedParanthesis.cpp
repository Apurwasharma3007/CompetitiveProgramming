#include<bits/stdc++.h>
using namespace std;

bool check(string s){
	int n=s.size();
	stack<char> st;
	for(int i=0;i<n;i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='[' ||s.empty()){
			st.push(s[i]);
		}
		else{
			if(st.empty()) return false;
			if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')){
				st.pop();
			}
			else{ 
				return false;}
		}
	}
	if(st.empty()){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	string s;
	cin>>s;
	bool ans = check(s);
	if(ans){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
}