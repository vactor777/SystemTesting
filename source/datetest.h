#pragma once
#ifndef DATETEST_H
#define DATETEST_H
#include <vector>
#include <map>
#include <memory>
#include <string>
//класс для работы с вопросами из теста
class Questions final {
public:
    explicit Questions(const std::string& description);
    std::string getDescription() const;
    std::string getQuestions() const;
    void addQuestions(const std::string& possibleAnswer);
	void deleteQuestions(int numberQuestion);
    std::string getCorreactAnswer() const;
	void addCorreactAnswer(const std::string& correactAnswer);
	void deleteCorreactAnswer(int numberAnswer);
private:
	std::string _description;
    std::vector<std::string> _testPossibleAnswer;
	std::vector<std::string> _correactAnswer;
private:
	Questions(const Questions&) = delete;
	Questions& operator=(Questions&) = delete;
};
//класс для работы с тестом
class Test final {
public:
    explicit Test(const std::string& nameTest);
    std::string getNameTest();
    void addQuestion(const std::string& descriptionQuestion);
    //void deleteTest(int nu) ---сделать;
    std::string getAllTest();
    std::shared_ptr<Questions>& getQuestionForChange(int numberQuestions);
private:
    std::vector<std::shared_ptr<Questions>> _test;
    std::string _nameTest;
private:
	Test(const Test&) = delete;
	Test& operator=(Test&) = delete;
};

//класс для работы с категориями
class Category final {
public:
    explicit Category(const std::string& nameCategory);
    void createTest(const std::string& testName);
    std::shared_ptr<Test>& getTestForChange(const std::string& testName);
    std::string getTestListFromCategory() const;
    std::string getNameCategory() const;
    void deleteTest(const std::string& nameTest);
private:
    std::map<std::string, std::shared_ptr<Test>> _arrayTest;
    std::string _nameCategory;
private:
	Category(const Category&) = delete;
	Category& operator=(Category&) = delete;
};

class DataTest {
public:
    std::vector<std::shared_ptr<Category>>& getArrayCategory();
    std::string getTest () const;
    DataTest();
    ~DataTest();
private:
    std::vector<std::shared_ptr<Category>> arrayCategory;
    void writeDataFile();
    void readDataFile();
private:
    DataTest(const DataTest&) = delete;
    DataTest& operator=(DataTest&) = delete;
};
#endif//DATETEST_H








