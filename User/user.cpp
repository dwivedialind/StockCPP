#include "user.h"


User::User(){
    
}
void User::displayUser() const{

}
string User::getUserName() const{
    return userName;
}
string User::getUserEmail() const{
    return userEmail;
}
void User::setUserEmail(string userEmail){
    this->userEmail = userEmail;
}
void User::setUserName(string userName){
    this->userName = userName;
}