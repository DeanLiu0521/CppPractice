#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

void save_score(int count){
    ifstream rf ("bestscore.txt");
    ofstream wf ("bestscore.txt");
    if(!rf.is_open()){cout << "File failed to open"; return;}
    int bestscore;
    rf >> bestscore;
    rf.close();
    if(!wf.is_open()){cout << "File failed to open"; return;}
    if (count < bestscore){
        wf << count;
    } else{
        wf << bestscore;
    }
    wf.close();
}
void print_guesses(vector<int> myvec){
    for(int i=0;i<myvec.size();i++){
        cout << myvec[i] << "\t";
    }
    cout << endl;
}
void play_game(){

    int guess;
    vector<int> guesses;
    cout << "You are in the game" << endl;
    int random = rand()%100 + 1;
    cout << "The random number is: " << random << endl;

    cout << "Input your guess" << endl;
    while(true){
        cin >> guess;
        guesses.push_back(guess);

        if (guess == random) {cout << "You win" << endl; break;}
        else if(guess < random) {cout << "Too low" << endl;}
        else {cout << "Too high" << endl;}
    }

    print_guesses(guesses);
    save_score(guesses.size());
}
int main(){
    int choice;
    srand(time(NULL));

    do{
        cout << "Please select one of the following options" << endl;
        cout << "1. Play Game" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                play_game();
                break;
            case 0:
                cout << "You chose to quit" << endl;
                return 0;
    }
    }while(choice != 0);

}