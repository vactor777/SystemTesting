#include <iostream>
#include "datacreate.h"
#include "datetest.h"
#include "programbegin.h"
#include <memory>
#include <algorithm>
#include <vector>
#include <fstream>
#include "users.h"
#include "createusers.h"
#include "changeuser.h"
#include "base_for_program.h"

using namespace std;
int main(){

    /*
    //основной класс DataTest
    std::unique_ptr<CreateTest> p(new CreateTest());
    std::shared_ptr<DataTest> data(new DataTest());
    p->setData(data);
    p->createCategory("Algebra");
    p->createCategory("Fizika");
    p->createCategory("Geometry");
    p->createTest("Algebra", "test for 10 class");
    p->createTest("Algebra", "test for 11 class");
    p->createTest("Fizika", "test for 10 class");

//    data->getTest();

    IChangeData* p2 = new ChangeTest();
    p2->setData(data);
    p2->setTestForChange("Algebra", "test for 10 class");
    p2->addQusetion("How are you");

    p2->addAnsver("mike", 0);
    p2->addAnsver("fil", 0);
    p2->addAnsver("bob", 0);
    p2->addCorreactAnswer("mike", 0);

    p2->addQusetion("My friend");
    p2->addAnsver("daq", 1);
    p2->addAnsver("faq", 1);
    p2->addAnsver("lap", 1);
    p2->addCorreactAnswer("lap", 1);
  //  data->getTest();
    cout << p2->getAlltest();

    p2->setTestForChange("Algebra", "test for 11 class");

    p2->addQusetion("How are fizika");

    p2->addAnsver("viktor", 0);
    p2->addAnsver("andre", 0);
    p2->addAnsver("peter", 0);
    p2->addCorreactAnswer("viktor", 0);

    cout << p2->getAlltest();

    ICreateUsers* creater = new CreateAdmin();
   // delete creater;
    //creater = new CreateUser();
    auto user(creater->createUser("admin", "123"));
   // delete  creater;
    UserChange ch(user);


   ch.setLogin("makaka");
    ACCESS_ID id = user->getID();
    switch (id) {
        case ACCESS_ID::admin:
          cout << user->getLogin();
        break;
        case ACCESS_ID::user:
          cout << "its user\n";
        break;
}
 //  ch.setLogin("makaka");
 */
/*
    std::shared_ptr<BaseUser> base(new BaseUser());
    base->addUser("1AllVi", "111", ACCESS_ID::user);
    base->addUser("2BllVi", "222", ACCESS_ID::user);
    base->addUser("3CllVi", "222", ACCESS_ID::user);
    base->addUser("4DllVi", "222", ACCESS_ID::user);

    std::shared_ptr<IChangeUser> us (new ChangeUser(base->getUser("1AllVi")));
        us->changePassword("818181");

    map<string, std::vector<int>*> mp;

    auto i = mp.insert(pair<string, std::vector<int>*>("a", new vector<int>));
    auto it = mp.find("a");
    it->second->push_back(1);
    //mp["a"] =



  //  delete us;

    delete p2;
    //p->
   */

    shared_ptr<BaseStatistic> p(new BaseStatistic());
    p->setStatistic("vik", "algebra", 10);
    p->setStatistic("vik", "algebrafor9", 7);
    p->setStatistic("vik", "algebra10", 9);
    p->setStatistic("vik", "algebra11", 11);
    p->setStatistic("as", "all", 12);
    auto f = p->getStatistic("as");
    for(auto& x: f){
        cout << x->_testName << ":";
        cout << x->grade;
    }
    cout << endl;
    auto v = p->getStatistic("vik");
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Test name: " << v[i]->_testName
             << " grade: " << v[i]->grade << endl;
    }

    return 0;
}
