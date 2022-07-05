#pragma once
#ifndef BASE_FOR_PROGRAM_H
#define BASE_FOR_PROGRAM_H
#include <map>
#include "createusers.h"
class BaseStatistic;
class _Statistick;

class BaseUser final {
public:
    BaseUser() = default;
    void addUser(const std::string& login, const std::string& password, ACCESS_ID id_AdminOrUser,
                 const std::string& name = "", const std::string& phone = "",
                 const std::string& addres = "");
    void deleteUser(const std::string& userLogin);
    _pUser getUser(const std::string& userLogin);
private:
    std::vector<_pUser> _userBase;
private:
    BaseUser(const BaseUser&) = delete;
    BaseUser& operator=(BaseUser&) = delete;
};

class BaseStatistic final {
public:
    struct _Statistick {
        std::string _testName;
        unsigned int grade;
        _Statistick(const std::string& testName, unsigned grade);
    };
public:
    BaseStatistic() {};
public:
    std::vector<std::shared_ptr<_Statistick>> getStatistic(const std::string& loginUser);
    void setStatistic (const std::string& login, const std::string& testName, unsigned grade);

private:
    std::map<const std::string, std::vector<std::shared_ptr<_Statistick>>> _statistic;//login user, vector whith different test
private:
    BaseStatistic(const BaseStatistic&) = delete;
    BaseStatistic& operator=(BaseStatistic&) = delete;
};

#endif // BASE_FOR_PROGRAM_H
