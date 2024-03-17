#include "userInterface.h"

UserInteface::UserInteface(){

}
void UserInteface::loginUser(){
    shared_ptr<UserLogin> userLog(new UserLogin());
    try{
       
        userLog->acceptLoginUser();
    }catch(const char *c){
        cout << c << endl;
    }
    
}
void UserInteface::registerUser(){
    
    shared_ptr<UserRegister> userReg(new UserRegister(getTime()));
    try{
        userReg->acceptRegisterUser();
        writetoFile(userReg);
    }catch(const char *c){
        cout << c << endl;
    }
    
}




