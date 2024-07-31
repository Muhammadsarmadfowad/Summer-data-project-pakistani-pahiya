#ifndef USER_H
#define USER_H
#include<iostream>
#include<cstring>
#include"Log.h"
using namespace std;
const int MAX_USERS = 100;
struct User {
    char username[50];
    char password[50];
};

/////////////////////////////////
class Stack {
private:
    User users[MAX_USERS];
    int top;
public:
	
	///////////////////////////////////////////////
    Stack() : top(-1) {}
    bool isEmpty() const {	LOG_INFO("user.h header file is open for stack isEmpty option ");
        return top == -1;
    }
    
    ////////////////////
    bool isFull() const { LOG_INFO("user.h header file is open for stack isFull option ");
        return top == MAX_USERS - 1;
    }
    
    
    //////////////////
    inline void push(const User &user) {   LOG_INFO("user.h header file is open for stack push option ");
        if (!isFull()) {
            users[++top] = user;
        }
    }
    
    //////////////////////////
    User pop() {      LOG_INFO("user.h header file is open for stack pop option ");
        if (!isEmpty()) {
            return users[top--];
        }
        return User();  // Return a default User if stack is empty
    }
    
    ///////////////////////
    bool findUser(const char* username, const char* password) const {    LOG_INFO("user.h header file is open for stack findUser option ");
        for (int i = 0; i <= top; ++i) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                return true;
            }
        }
        return false;
    }
    
    
    ///////////////////////
    inline void displayUsers() const {  LOG_INFO("user.h header file is open for stack displayUsers option ");
        for (int i = 0; i <= top; ++i) {
            cout << "Username: " << users[i].username << ", Password: " << users[i].password << endl;
        }
    }
};
#endif
