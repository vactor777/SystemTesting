#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include "base_for_program.h"

class ChangeUser : public IChangeUser {
public:
    virtual void deleteUser(const std::string& userLogin,  _pBaseUser& baseUser) override ;
    virtual void changeLogin(const std::string& newLogin) override;
    virtual void changePassword(const std::string& newPassword) override;
    virtual void changeId(ACCESS_ID newId) override;
    virtual void setUser(_pUser& user) override;
public:
    ChangeUser(_pUser user);
private:
    _pUser _user;
private:
    ChangeUser(const ChangeUser&) = delete;
    ChangeUser& operator=(ChangeUser&) = delete;
    std::shared_ptr<UserChange> _friendChangeClass;
};

#endif // CHANGEUSER_H
