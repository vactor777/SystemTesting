#include "base_for_program.h"

void BaseUser::addUser(const std::string& login, const std::string& password, ACCESS_ID id_AdminOrUser,
                       const std::string& name, const std::string& phone, const std::string& addres) {
    //сделать проверку на добавление повторяющихся элементов

    switch (id_AdminOrUser)
    {
    case ACCESS_ID::admin:
    {
        ICreateUsers* creater = new CreateAdmin();

        _userBase.push_back(creater->createUser(login,password, name, phone, addres));
        delete  creater;
        break;
    }
    case ACCESS_ID::user:
    {
        ICreateUsers* creater = new CreateUser();
        _userBase.push_back(creater->createUser(login,password, name, phone, addres));
        delete  creater;
        break;
    }
    }
}

void BaseUser::deleteUser(const std::string& userLogin) {
    for(auto it = _userBase.begin(); it != _userBase.end(); ++it){
        if ((*it)->getLogin() == userLogin)
            _userBase.erase(it);
    }
}

_pUser BaseUser::getUser(const std::string& userLogin) {
   for (auto it = _userBase.begin(); it != _userBase.end(); ++it){
        if((*it)->getLogin() == userLogin) {
            return *it;
        }
    }
   return nullptr;

}

std::vector<std::shared_ptr<BaseStatistic::_Statistick> > BaseStatistic::getStatistic(const std::string& loginUser)
{
    auto it = _statistic.find(loginUser);
    if (it != _statistic.end())
        return it->second;
   else
        throw "statistick not find";
}

void BaseStatistic::setStatistic(const std::string& login, const std::string& testName, unsigned grade) {
    _statistic.emplace(login, std::vector<std::shared_ptr<_Statistick>>());
    auto it = _statistic.find(login);
    it->second.push_back(std::shared_ptr<BaseStatistic::_Statistick>(new _Statistick(testName, grade)));
}

BaseStatistic::_Statistick::_Statistick(const std::string& testName, unsigned grade)
    : _testName(testName), grade(grade) {}
