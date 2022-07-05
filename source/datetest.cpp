#include "datetest.h"
#include <exception>
#include <algorithm>
#include <fstream>
#include <string>
//Class Questions
Questions::Questions(const std::string& description) : _description (description) {}

std::string Questions::getDescription() const {
    return _description + '\n';
}

std::string Questions::getQuestions() const {
    std::string qustions;
    int index = 1;
    for (auto x : _testPossibleAnswer) {
        qustions += std::to_string(index) + ") " + x + '\n';
        index++;
    }
    return qustions;
}

void Questions::addQuestions(const std::string& possibleAnswer) {
    _testPossibleAnswer.push_back(possibleAnswer);
}

void Questions::deleteQuestions(int numberQuestion) {
    if (numberQuestion > _testPossibleAnswer.size() || numberQuestion <= 0)
        throw std::exception();
    _testPossibleAnswer.erase(_testPossibleAnswer.begin() + numberQuestion);
}

std::string Questions::getCorreactAnswer() const {
    std::string answer;
    int index = 1;
    for (auto x : _correactAnswer)
        answer += std::to_string(index) + ") " + x + '\n';
    return answer;
}

void Questions::addCorreactAnswer(const std::string& correactAnswer) {
    _correactAnswer.push_back(correactAnswer);
}

void Questions::deleteCorreactAnswer(int numberAnswer) {
    if (numberAnswer > _testPossibleAnswer.size() || numberAnswer <= 0)
        throw std::exception();
    //???????????? ???????? ?? ???????
    _correactAnswer.erase(_correactAnswer.begin()+numberAnswer);
}

//Class Test
Test::Test(const std::string &nameTest) : _nameTest(nameTest){}

std::string Test::getNameTest() {
    return _nameTest + '\n';
}

void Test::addQuestion(const std::string& descriptionQuestion) {
    _test.push_back(std::shared_ptr<Questions>(new Questions(descriptionQuestion)));
}

std::string Test::getAllTest() {
    std::string temp_str;
    for (auto& ptr: _test){
        temp_str += ptr->getDescription();
        temp_str += ptr->getQuestions();
        temp_str += ptr->getCorreactAnswer();
    }
    return temp_str;
}

std::shared_ptr<Questions>& Test::getQuestionForChange(int numberQuestions) {
    if (numberQuestions >= _test.size())
        throw std::exception();
    else
        return _test[numberQuestions];
}

//Class Category
Category::Category(const std::string& nameCategory) : _nameCategory(nameCategory) {}

void Category::createTest(const std::string& testName) {
    _arrayTest.emplace(testName, std::shared_ptr<Test>(new Test(testName)));
}

std::shared_ptr<Test>& Category::getTestForChange(const std::string& testName) {
    auto it = _arrayTest.find(testName);
    if (it != _arrayTest.end())
        return it->second;
    else
        throw std::exception();
}

std::string Category::getTestListFromCategory() const {
    std::string temp_str = _nameCategory + ":\n";
    for (auto& x: _arrayTest)
        temp_str += x.first + '\n';
    return temp_str;
}

std::string Category::getNameCategory() const {
    return _nameCategory;
}

void Category::deleteTest(const std::string &nameTest) {
    //пересмотерть удаление
   auto it = _arrayTest.find(nameTest);
   if (it != _arrayTest.end())
       _arrayTest.erase(it);
   else
       throw std::exception();
}

//class DataTest
std::vector<std::shared_ptr<Category>>& DataTest::getArrayCategory(){
    return arrayCategory;
}

std::string DataTest::getTest() const {
    std::string temp_str;
    for (auto& x: arrayCategory)
       temp_str += x->getTestListFromCategory();
    return temp_str;
}

DataTest::DataTest() {
 //   readDataFile();
}

DataTest::~DataTest()
{
  //   writeDataFile();
}

/*
 *
 * Сделать запись вектора в бинарник
 *
 *
void DataTest::writeDataFile() {
    std::ofstream file("filebaseBase.dat", std::ios_base::out | std::ios_base::binary);
    if (!(file.is_open())) {
       throw "file is not open";
    }
    else {


        std::cout << "file opne\n";
   //     file.write((char*)& arrayCategory), sizeof (*arrayCategory));
        file.close();
    }

}
void DataTest::readDataFile() {
     std::ifstream infile("filebaseBase.dat", std::ios_base::in | std::ios_base::binary);
    if (!(infile.is_open())) {
       throw "file is not open";
    }
    else {
   //     std::vector<std::unique_ptr<Category>> tmp;
         std::cout << "file opnefff\n";
         while (infile.read((char*)& arrayCategory, sizeof(arrayCategory)));
         infile.close();
    }
}
*/
