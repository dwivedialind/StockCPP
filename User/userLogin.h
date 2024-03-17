#ifndef USER_LOGIN_H_
#define USER_LOGIN_H_
#endif

#include <cstring>
#include "user.h"

class UserLogin: public User{
    unsigned long long int userId;
    vector<UserLogin *> userList;
    void loadDataFromList(){
        ifstream fin("RegisteredUser.csv");
        
        string data;
        while(getline(fin,data)){
            string userId;
            string s(userId);
            string userName;
            string userEmail;
            stringstream line(data);
            getline(line,userId,',');
            getline(line,userName,',');
            getline(line,userEmail,',');
            int length = userId.length();
            char* buffer(new char[length+1]);
            strcpy(buffer,userId.c_str());
            char *ptr;
            userList.push_back(new UserLogin(strtoull(buffer,&ptr,10),userName,userEmail));
        }
        
        fin.close();
    }
    public:
        UserLogin();
        UserLogin(unsigned long long int userId, string userName, string userEmail);
        void acceptLoginUser();
        unsigned long long int getUserId() const;
        ~UserLogin();
        
};