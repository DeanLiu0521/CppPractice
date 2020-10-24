#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;


int main(){
    vector<int> data = {1,2,3,4};
    data.push_back(222);
    cout << data.size() << "\t" << data[data.size()-1] << "\n" << "\n";
    for(int i=0;i<data.size();i++){
        cout << data[i] << "\t";
    }
    return 0;
}