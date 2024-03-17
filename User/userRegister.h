#ifndef USER_REGISTER_H_
#define USER_REGISTER_H_

#include <random>
#include <regex>
#include <string>
#include "user.h"


/*
Learning:
1. Never store password in plain string in classes. Instead Store a hash of password
Hashing is a one-way cryptographic function that converts the password into a unique, 
fixed-length string. Even if someone steals the hashed password, 
they cannot easily reverse the hash to obtain the original password.
2. Secure Hashing Algorithm: Cryptographically secure hasing algorithm like bcrypt or scrypt. produce a string containing 
alphanumeric characters and symbols. In this case, std::string is a suitable choice.
3. Salting: Salt is a random string prepended to the password before hasing. This adds an extra layer of security. We can stored the salt 
alongside the hashsed password std::string
4. Non Deterministic Algorithm: A algorithm that even for the same input produce different results every time.
*/
class UserRegister: public User{
    private:
        const unsigned long long int userId; //we generate this Id using id generator
        
        //vector<User* > userList; get UserList to verify same user id
    public:
        UserRegister(unsigned long long int userId);
        UserRegister(int userId, string userName, string userEmail);
        void acceptRegisterUser();
        //void displayUser();
        unsigned long long int getUserId() const;
        //void pullUserData(); //to pull registered users data into userList
        bool validateEmail(string email);
            
       
        ~UserRegister();
};


#endif