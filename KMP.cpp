#include<bits/stdc++.h>
using namespace std;


void constructLPS(vector<int> &lps,string pattern){
	lps[0] = 0;
	int len = 0;
	int index = 1;
	while(index < pattern.size()){
		if(pattern[len] == pattern[index]){
			lps[index] = lps[index-1] + 1;
			index++;
			len++;
		}
		else{
			if(len == 0) {
				lps[index] = 0;
				index++;
			}
			else{
				len = lps[len-1];
			}
		}
	}
}

void KMP(string text,string pattern,vector<int> &lps){
	int i = 0, j = 0;
	int n = text.size();
	int m = pattern.size();
	while(i < n){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		if(j == m){
			cout<<(i - j)<<" ";
			j = lps[j-1];
		}
		else if(i < n && text[i] != pattern[j]){
			if(j == 0) i++;
			else j = lps[j-1];
		}
	}
	
}


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
	string text,pattern;
	cin>>text>>pattern;
	int m = pattern.size();
	vector<int> lps(m);
	constructLPS(lps,pattern);
	KMP(text,pattern,lps);
	return 0;
}