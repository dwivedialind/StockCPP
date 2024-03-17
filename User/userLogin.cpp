#include "userLogin.h"

UserLogin::UserLogin(){

}

UserLogin::UserLogin(unsigned long long int userId, string userName, string userEmail){
    this->userId = userId;
    setUserEmail(userEmail);
    setUserName(userName);
}
void UserLogin::acceptLoginUser(){
    loadDataFromList();
    cout << "Enter your id: ";
    unsigned long long int uid;
    cin >> uid;
    for(int i = 0; i < userList.size(); i++){
        if(userList[i]->getUserId()==uid){
            cout << "User Logged In" << endl;
            return;
        }
    }
    throw "Invalid Username";
}
unsigned long long int UserLogin::getUserId() const{
    return userId;
}

UserLogin::~UserLogin(){
    for(vector<UserLogin*>::iterator it = userList.begin(); it != userList.end(); it++){
        delete *it;
    }
}