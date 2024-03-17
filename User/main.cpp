#include "userInterface.h"




int main()
{  
    int choice;
  do{
    
    cout << "1. Do you want to Register.";
    cout << "\n2. Do you want to Login." << endl;
    cout << "0. Exit" << endl;
    cin>>choice;
    unique_ptr<UserInteface> registerUser;
    unique_ptr<UserInteface> loginUser;
    switch(choice){
        case 1:
            cout << "Register User" << endl;
            registerUser->registerUser();          
            break;
        case 2:
            cout << "Login User" << endl;
            loginUser->loginUser();
            
            break;
        case 0:
            cout << "Thank you for using" << endl;
            break;
        default:
            cout << "Please enter valid choice";
    }
  }while(choice!=0);
    return 0;
}