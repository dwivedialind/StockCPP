#ifndef USER_H_
#define USER_H_

#include<memory>
#include<iostream>
#include <fstream>
#include<vector>
#include<sstream>
using namespace std;

class User{
    private:

        string userName;
        string userEmail;
        string hashedPassword;

    public:
        User();
        

        virtual void displayUser() const;

	    string getUserName() const;
        void setUserName(string userName);
		string getUserEmail() const; 
		void setUserEmail(string userEmail);    
			
};

#endif