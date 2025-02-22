#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int>& arr, int target){
	int n = arr.size();

	unordered_map<int,int>mp;

	for(int i=0;i<n;i++){
		int compliment =  target-arr[i];
		if(mp.find(compliment)!= mp.end()){
			return {mp[compliment],i};
		}
		
		mp[arr[i]]= i;
	}
	return {};
}
int main(){
	int n;
	cin>>n;

	vector<int>arr(n);

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int target ;
	cin>>target;

	vector<int> res = twosum(arr,target);

	for(int i : res){
		cout<<i<<" ";
	}
	return 0;
}