#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_


#include<memory>

#include "userLogin.h"

#include "userRegister.h"


class UserInteface{
    private:
        unsigned long long int getTime(){
            char* ptr;
            time_t currentTime = time(nullptr);
            tm* localTime = localtime(&currentTime);
            char buffer[50];
            strftime(buffer,sizeof(buffer),"%y%m%d%H%M%S",localTime);
            return strtoull(buffer,&ptr,10);
        }
        void writetoFile(shared_ptr<UserRegister> u){
            ofstream fout("RegisteredUser.csv",ios::app);
            fout << u->getUserId() << "," << u->getUserName() << "," << u->getUserEmail() << endl;
            fout.close();
        }
    public:
        UserInteface();
        void registerUser();
        void loginUser();
};

#endif