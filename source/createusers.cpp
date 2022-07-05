#include "createusers.h"
_pUser CreateUser::createUser(const std::string& login, const std::string& password,
                                                  const std::string& name, const std::string& phone,
                                                  const std::string& addres) {
    return _pUser(new User(login, password, name, phone, addres));
}

_pUser CreateAdmin::createUser(const std::string& login, const std::string& password,
                                                  const std::string& name, const std::string& phone,
                                                  const std::string& addres) {
    return _pUser(new Admin(login, password, name, phone, addres));
}

