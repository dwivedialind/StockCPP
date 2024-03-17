#include "userRegister.h"

UserRegister::UserRegister(unsigned long long int userId):userId(userId){
    cout << this->userId << endl;
}
UserRegister::UserRegister(int userId, string userName, string userEmail): userId(userId){
    setUserEmail(userEmail);
    setUserName(userName);
}

void UserRegister::acceptRegisterUser(){
    cout << "Enter Name: ";
    cin.ignore();
    string name;
    getline(cin,name);
    setUserName(name);
    cout << "Enter Email: ";
    string email;
    getline(cin,email);
    validateEmail(email) ? setUserEmail(email):throw "Email not Valid";
    
}

// void UserRegister::displayUser(){

// }

// void UserRegister::pullUserData(){
//     ifstream fin("RegisteredUser.txt");
//     string data;
//     while(getline(fin,data)){
//         string userId;
//         string userName;
//         string userEmail;

//         stringstream line(data);
//         getline(line,userId,',');
//         getline(line,userName,',');
//         getline(line,userEmail,',');

//         //userList.push_back(new UserRegister(stoi(userId),userName,userEmail));

//     }
     


//     fin.close();
// }

UserRegister::~UserRegister(){
    // for(vector<User*>::iterator it = userList.begin(); it!=userList.end(); it++){
    //     delete *it;
    // }
}

unsigned long long int UserRegister::getUserId() const{
    return this->userId;
}

bool UserRegister::validateEmail(string email){
    //Regex for a valid email address
    const regex emailRegex(R"(^([a-zA-Z0-9_\-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([a-zA-Z0-9\-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$)");

    //check if the email matches the basic structure
    if(!regex_match(email,emailRegex))
        return false;
    if(email.length() > 254)
        return false;
    
    
    
    return true;
}




