#include "users.h"
//class User
UserBase::UserBase(const std::string& login, const std::string& password, ACCESS_ID id, const std::string& name,
                   const std::string& phone, const std::string& addres)
    : _login(login), _password(password), _id(id), _name(name), _phone(phone), _address(addres) {}

ACCESS_ID UserBase::getID() {
    return _id;
}

std::string UserBase::getLogin() {
    return _login;
}

std::string UserBase::getPassword() {
    return _password;
}

std::string UserBase::getName() {
    return _name;
}

void UserBase::setName(const std::string& newName) {
    _name = newName;
}

std::string UserBase::getAdress() {
    return _address;
}

void UserBase::setAdress(const std::string& newAdress) {
    _address = newAdress;
}

std::string UserBase::getPhone() {
    return _phone;
}

void UserBase::setPhone(const std::string& newPhone) {
    _phone = newPhone;
}
//class Admin
Admin::Admin(const std::string& login, const std::string& password, const std::string& name, const std::string& phone, const std::string& addres)
    : UserBase(login, password, ACCESS_ID::admin, name, phone, addres) {}

//class User
User::User(const std::string& login, const std::string& password, const std::string& name, const std::string& phone, const std::string& addres)
    : UserBase(login, password, ACCESS_ID::user, name, phone, addres) {}

//friend class
UserChange::UserChange(_pUser user) : _user(user){}

void UserChange::setLogin(const std::string& newLogin) {
    _user->_login = newLogin;
}
void UserChange::setPassword(const std::string& newPassword) {
    _user->_password = newPassword;
}

void UserChange::setIdAccess(ACCESS_ID newLogin) {
    _user->_id = newLogin;
}

