#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool usernameExists(const string& username){
    ifstream file("users.txt");
    string storedUsername, storedpassword;

    while (file>>storedUsername>> storedpassword){
        if(storedUsername == username){
            return true;
        }
    }
    return false;
}

void registerUser(){
    string username, password;

    cout<<"Register\n";
    cout<<"Enter username:";
    cin>> username;

    if(usernameExists(username)){
      cout<<"Error: Username already exists.\n";
      return;
    }

    cout<<"Enter password:";
    cin>> password;

    ofstream file("users.txt", ios::app);//apped mode
    file<<username<<""<<password<<endl;

    cout<<"Registration successful!\n";
}

void loginUser(){
    string username, password;
    string storedUsername, storedpassword;

    cout<<"Login\n";
    cout<<"Enter username:";
    cin>> username;
    cout<<"Enter password:";
    cin>> password;

    ifstream file("users.txt");

    while(file>>storedUsername>> storedpassword){
        if(storedUsername == username && storedpassword == password){
            cout<<"Login successful!\n";
            return;
        }
    }

    cout<<"Error: Invalid username or password.\n";
}

int main() {
    int choice;
    do {
        cout<<"n\1. Register\n2. Login\n3. Exit\nChoose an option:";
        cin>> choice;

        switch(choice) {
            case 1:
               registerUser();
               break;
            case 2:
               loginUser();
               break;
            case 3:
              cout<<"Goodbye!\n";
              break;
            default:
              cout<<"Invalid option.\n";
        }
    } while(choice !=3);

    return 0;
}