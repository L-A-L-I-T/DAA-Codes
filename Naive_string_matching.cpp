#include<bits/stdc++.h>
using namespace std;

void stringMatch(string &text,string &pattern){
	int n = text.size();
	int m = pattern.size();
	for(int i = 0 ; i <= n-m ; i++){
		bool found = true;
		for(int j = 0 ; j < pattern.size() ; j++){
			if(text[i+j] != pattern[j]){
				found = false;
				break;
			}
		}
		if(found){
			cout<<"Pattern Found at index : "<<i<<"\n";
			return;
		}
	}
	cout<<"Pattern Not Found!";
}


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
	string text,pattern;
	cin>>text>>pattern;
	stringMatch(text,pattern);
	return 0;
}