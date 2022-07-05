#include "datacreate.h"
//Class CreateTest
void CreateTest::setData(std::shared_ptr<DataTest>& data) {
    _datatest = data;
}

void CreateTest::createCategory(const std::string& namecategory) {
    _datatest->getArrayCategory().push_back(std::unique_ptr<Category>(new Category(namecategory)));
}

void CreateTest::createTest(const std::string &switchnamecategory, const std::string &namenewtest) {
    for (int i = 0; i < _datatest->getArrayCategory().size(); i++) {
        if (switchnamecategory == _datatest->getArrayCategory()[i]->getNameCategory())
            _datatest->getArrayCategory()[i]->createTest(namenewtest);
    }
}

void CreateTest::deleteCategory(const std::string& namecategory) {
    for (int i = 0; i < _datatest->getArrayCategory().size(); i++) {
        if (namecategory == _datatest->getArrayCategory()[i]->getNameCategory())
            _datatest->getArrayCategory().erase(_datatest->getArrayCategory().begin() + i);
    }
}

void CreateTest::deteleTest(const std::string &switchnamecategory, const std::string &nametest) {
    for (int i = 0; i < _datatest->getArrayCategory().size(); i++)
    {
        if (switchnamecategory == _datatest->getArrayCategory()[i]->getNameCategory()) {
           _datatest->getArrayCategory()[i]->deleteTest(nametest);
        }
    }
}

CreateTest::CreateTest() : _datatest(nullptr) {};

//Class ChangeTest
void ChangeTest::setData(std::shared_ptr<DataTest>& data) {
    _datatest = data;
}

void ChangeTest::setTestForChange(const std::string &namecategory, const std::string &nametest) {
    for (int i = 0; i < _datatest->getArrayCategory().size(); i++){
        if (namecategory == _datatest->getArrayCategory()[i]->getNameCategory()){
           auto it = _datatest->getArrayCategory()[i]->getTestForChange(nametest);
                _test = it;
        }
    }
}

void ChangeTest::addQusetion(const std::string& description) {
    if (_test != nullptr) {
        _test->addQuestion(description);
    }
}

void ChangeTest::addAnsver(const std::string& possibleAnswer, int numberQuestion) {
    if (_test != nullptr)
        _test->getQuestionForChange(numberQuestion)->addQuestions(possibleAnswer);
}

void ChangeTest::addCorreactAnswer(const std::string &correctAnswer, int numberQuestion) {
    if (_test != nullptr)
        _test->getQuestionForChange(numberQuestion)->addCorreactAnswer(correctAnswer);
}

std::string ChangeTest::getAlltest() {
     return _test->getAllTest();
}

ChangeTest::ChangeTest() : _datatest(nullptr), _test (nullptr){}


UseTest::UseTest(std::shared_ptr<DataTest> data) {
    pData = data;
}
