#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>&arr){
    for (auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];

    int i = low-1;
    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[high], arr[i+1]);
    return i+1;
}

void quickSortHelper(vector<int>& arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
        
        quickSortHelper(arr, low, pivot-1);
        quickSortHelper(arr, pivot+1, high);
    }
}

void quickSort(vector<int>& arr){
    quickSortHelper(arr, 0, arr.size()-1);
}


int main(){
    vector<int> input {5,2,1,3,4};
    quickSort(input);
    print(input);

}
