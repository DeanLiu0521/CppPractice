#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ofstream Myfile("filename.txt");

    Myfile << "Files can be tricky, but it is fun enough ";

    Myfile.close();

    string mystring;

    ifstream Myreadfile("filename.txt");

    while(getline(Myreadfile,mystring)){
        cout << mystring;
    }
    Myreadfile.close();
}