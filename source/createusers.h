#ifndef CREATEUSERS_H
#define CREATEUSERS_H
#include "interface.h"

class CreateUser : public ICreateUsers
{
public:
    virtual _pUser createUser(const std::string& login, const std::string& password,
                                                 const std::string& name = "", const std::string& phone = "",
                                                 const std::string& addres = "") override;
};
class CreateAdmin : public ICreateUsers
{
public:
    virtual _pUser createUser(const std::string& login = "admin", const std::string& password = "admin",
                                                 const std::string& name = "", const std::string& phone = "",
                                                 const std::string& addres = "") override;
};

#endif // CREATEUSERS_H
