#include <string>
#include <iostream> 
class User{
    private:
        static int user_count;
        std::string status = "Gold";
    
    public:
        std::string Firstname;
        std::string Lastname;
        static int get_user_count(){
            return user_count;
        }
        std::string get_status(){
            return status;
        }
        void set_status(std::string status){
            this->status = status;
        }

        friend std::ostream& operator << (std::ostream& output, const User user);
        friend std::istream& operator >> (std::istream& input, User& user);
        

};