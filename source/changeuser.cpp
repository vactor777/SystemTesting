#include "changeuser.h"

ChangeUser::ChangeUser(_pUser user)
    : _user(user), _friendChangeClass(new UserChange(user)){}

void ChangeUser::deleteUser(const std::string& userLogin, _pBaseUser& baseUser) {

    if(userLogin == _user->getLogin()){
        _user = nullptr;
        _friendChangeClass->~UserChange();
        _friendChangeClass = nullptr;
        baseUser->deleteUser(userLogin);
    }
}

void ChangeUser::changeLogin(const std::string &newLogin) {
    _friendChangeClass->setLogin(newLogin);
}

void ChangeUser::changePassword(const std::string &newPassword) {
    _friendChangeClass->setPassword(newPassword);
}

void ChangeUser::changeId(ACCESS_ID newId) {
    _friendChangeClass->setIdAccess(newId);
}

void ChangeUser::setUser(_pUser& user) {
    _user = user;
    _friendChangeClass->~UserChange();
    _friendChangeClass = std::shared_ptr<UserChange>(new UserChange(user));
}

