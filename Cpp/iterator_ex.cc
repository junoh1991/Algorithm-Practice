#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){
    vector<int> ex{1,2,3,4,5,6,7,8,9};

    for ( auto i : ex){
        cout << i << endl;

    }
}
