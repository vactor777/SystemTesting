#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H
#include "datetest.h"
#include "users.h"
class BaseUser;
//typedef
using _pBaseUser = std::shared_ptr<BaseUser>;

class ICreateData {
public:
    virtual void setData(std::shared_ptr<DataTest>& data) = 0;
    virtual void createCategory(const std::string& nameCategory) = 0;
    virtual void createTest(const std::string& switchNameCategory, const std::string& nameNewTest) = 0;
    virtual void deleteCategory(const std::string& nameCategory) = 0;
    virtual void deteleTest(const std::string& switchNameCategory, const std::string& nameTest) = 0;
    virtual ~ICreateData() {}
};

class IChangeData {
public:
    virtual void setData(std::shared_ptr<DataTest>& data) = 0;
    virtual void setTestForChange(const std::string& namecategory,const std::string& nametest) = 0;
    virtual void addQusetion(const std::string& description) = 0;
    virtual void addAnsver(const std::string& ansver, int numberQuestion) = 0;
    virtual void deleteQusetion() = 0;
    virtual void addCorreactAnswer(const std::string& correctAnswer, int numberQuestion) = 0;
    virtual void deleteCorreactAnswer() = 0;
    virtual std::string getAlltest() = 0;
    virtual ~IChangeData(){};
};

class IComandUseTest {
public:
    virtual void startTest() = 0;
    virtual ~IComandUseTest(){}
};

class ICreateUsers {
public:
    virtual _pUser createUser(const std::string& login, const std::string& password,
                                                 const std::string& name = "", const std::string& phone = "",
                                                 const std::string& addres = "") = 0;
    virtual ~ICreateUsers(){}
};

class IChangeUser {

public:
    virtual void deleteUser(const std::string& userLogin, _pBaseUser& baseUser) = 0;
    virtual void changeLogin(const std::string& newLogin) = 0;
    virtual void changePassword(const std::string& newPassword) = 0;
    virtual void changeId(ACCESS_ID newId) = 0;
    virtual void setUser(_pUser& user) = 0;
    virtual ~IChangeUser(){}
};


#endif // INTERFACE_H
