#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &v,int low,int high){
	int i = low;
	int j = high;
	int pivot = v[low];
	while (i < j){
		while (v[i] <= pivot && i < high){
			i++;
		}
		while (v[j] > pivot && j > low){
			j--;
		}
		if (i < j) swap(v[i],v[j]);
	}
	swap(v[low],v[j]);
	return j;
}

void quicksort(vector<int> &v,int low,int high){
	if (low >= high){
		return;
	}
	int pivot_index = partition(v,low,high);
	quicksort(v,low,pivot_index-1);
	quicksort(v,pivot_index+1,high);
}

int main(){
	long long n;
	cin >> n;
	vector<int> v1;
	for (int i = 0;i<n;i++){
		long long temp;
		cin >> temp;
		v1.push_back(temp);
	}
	quicksort(v1,0,n-1);
	for (auto x:v1){
		cout << x << endl;
	}
}