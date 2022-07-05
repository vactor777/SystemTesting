#pragma once
#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <memory>

class UserBase;
//typedef
using _pUser = std::shared_ptr<UserBase>;

enum class ACCESS_ID { user, admin};

//Abstract class
class UserBase
{
private:
    std::string _login;
    std::string _password;
    std::string _name;
    std::string _phone;
    std::string _address;
    ACCESS_ID _id;
    friend class UserChange;
protected:
    UserBase(const std::string& login, const std::string& password, ACCESS_ID id,
         const std::string& name = "", const std::string& phone = "", const std::string& addres = "");
public:
     virtual ~UserBase() {std::cout << "destruct base\n";};
     ACCESS_ID getID();
     std::string getLogin();
     std::string getPassword();
     std::string getName();
     void setName(const std::string& newName);
     std::string getAdress();
     void setAdress(const std::string& newAdress);
     std::string getPhone();
     void setPhone(const std::string& newPhone);
};

class Admin : public UserBase {
public:
    Admin(const std::string& login = "admin", const std::string& password = "admin",
         const std::string& name = "", const std::string& phone = "", const std::string& addres = "");
private:
    Admin(const Admin&) = delete;
    Admin& operator=(Admin&) = delete;

};

class User : public UserBase {
public:
     ~User() {std::cout << "destruct baseDerived\n";}
    User(const std::string& login, const std::string& password,
         const std::string& name = "", const std::string& phone = "", const std::string& addres = "");
private:
    User(const User&) = delete;
    User& operator=(User&) = delete;
};

//Friend class
class UserChange {
private:
    _pUser _user;
public:
    UserChange(_pUser user);
    void setLogin(const std::string& newLogin);
    void setPassword(const std::string& newPassword);
    void setIdAccess(ACCESS_ID newLogin);
private:
    UserChange(const UserChange&) = delete;
    UserChange& operator= (UserChange&) = delete;
};

#endif // USERS_H
