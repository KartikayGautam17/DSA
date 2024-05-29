#include<bits/stdc++.h>

using namespace std;



int main(){
	map<int,int> mp;
	mp.insert({3,4});
	mp[2] = 4;
	for (auto x:mp){
		cout << x.first << " -> " << x.second << endl;
	}
}