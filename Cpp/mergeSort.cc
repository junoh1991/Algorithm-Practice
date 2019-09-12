#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &arr){
	for (auto i : arr){
		cout << i << " ";
	}

	cout << endl;
}

void merge(vector<int>& arr, vector<int>& left, vector<int>& right){
	int i = 0, l = 0, r = 0;

	while (l < left.size() && r < right.size()){
		if (left[l] > right[r]){
			arr[i] = right[r];
			r++;
		}
		else{
			arr[i] = left[l];
			l++;
		}
		i++;
	}

	while(l < left.size()){
		arr[i] = left[l];
		i++;
		l++;
	}

	while(r < right.size()){
		arr[i] = right[r];
		i++;
		r++;
	}

}

void mergeSort(vector<int>& arr){
	if (arr.size() > 1){
		vector<int> left(arr.begin(), arr.begin() + arr.size()/2);
		vector<int> right(arr.begin() + arr.size()/2, arr.begin() + arr.size());
		mergeSort(left);
		mergeSort(right);

		merge(arr, left, right);
	}
}



int main(){
	vector<int> input {5,2,1,3,4};
	mergeSort(input);
	print(input);
	
	input = {1,2,1,2};
	mergeSort(input);
	print(input);
}
