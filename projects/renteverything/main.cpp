#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void setup(){
    cout << "Welcome to the RentEverything platform";  
}

class User{

    public:
        //Constructor
        User();
        string first_name;
        string last_name;
        int get_user_id(){ 
            return user_id;
        }
        int get_user_account(){
            return user_account;
        }
        void set_user_id(){
            user_id = rand()%101;
        }
        ~User(){}

    private:
        int user_id;
        const int user_account;
        const int user_pwd;
        const int user_count;

};

const int user_count = 0; //Set total user number to 0

bool checkword(string target, char* filename){
    int offset; 
    string line;
    ifstream Myfile;
    Myfile.open(filename);

    if(Myfile.is_open())
    {
        while (getline( Myfile, line ) )
	    {
            if (line.find( target ) != std::string::npos )
            {
                return true;
            }
	    }
    }
    return false;

}

void rent(){
    string name,line;
    cout << "I want to rent!" << endl;
    cout << "User_id:" << endl;
    cin >>name;
    if (checkword(name,"/Users/haoyangliu/Documents/C++practice/projects/renteverything/account_info.txt")){
        cout<< "You have an account" << endl;
    }else{
        cout << "You don't have an account" << endl;
    }

}

void offer(){
    cout << "I want to offer!" << endl;
}

void sign_up(){
    string name,pwd;
    ofstream output;
    output.open("account_info.txt",std::ios::app);
    cout << "I want to sign up for an account" << endl;
    cout << "Please input your first name and the pwd" << endl;
    if(!output.is_open()){
        cout << "File cannot be properly opened." << endl;
    }
    cin >> name >> pwd;
    output << name << " "<<pwd << endl;
    output.close();
}
int main(){
    setup();
    srand(time(NULL));
    int choice;
    bool quit_system = false;
    do{
        cout << "Please select one of the following options"<< endl;
        cout << "1. I want to rent " << endl;
        cout << "2. I want to offer " << endl;
        cout << "3. Sign up for an account" << endl;
        cout << "What's your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            rent();
            break;
            case 2:
            offer();
            break;
            case 3:
            sign_up();
            case 9:
            quit_system = true;
            default:
            quit_system = true;
        }
    }while(!quit_system);
}