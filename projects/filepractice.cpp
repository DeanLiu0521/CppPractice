#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){

    string filename;
    cin >> filename;

    ofstream file (filename.c_str(),ios::app);

    if(!file.is_open()){
        cout << "Failed to open the file." << endl;
    }
    vector<string> contents = {"hi","my","name","is"};

    for (string content : contents ){
        file << content << endl;
    }

    file.close();
    
    string here;
    cout << "Type the name of the file you want to read from: ";
    cin >> here;
    ifstream readfile (here.c_str());
    string line;
    
    
    getline(readfile,line);
    cout << line << endl;
    return 0;
}