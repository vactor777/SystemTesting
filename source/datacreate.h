#pragma once
#ifndef DATACREATE_H
#define DATACREATE_H

#include "interface.h"

class CreateTest : public ICreateData {
public:
    virtual void setData(std::shared_ptr<DataTest>& data) override;
    virtual void createCategory(const std::string& nameCategory) override;
    virtual void createTest(const std::string& switchNameCategory, const std::string& nameNewTest) override;
    virtual void deleteCategory(const std::string& nameCategory) override;
    virtual void deteleTest(const std::string& switchNameCategory, const std::string& nameTest) override;
    virtual ~CreateTest() {}

private:
    std::shared_ptr<DataTest> _datatest;
public:
    CreateTest();
private:
	CreateTest(const CreateTest&) = delete;
	CreateTest& operator=(CreateTest&) = delete;
};

class ChangeTest : public IChangeData {
public:
    virtual void setData(std::shared_ptr<DataTest>& data) override;
    virtual void setTestForChange(const std::string& nameCategory,const std::string& nameTest) override;
    virtual void addQusetion(const std::string& description) override;
    virtual void addAnsver(const std::string& possibleAnswer, int numberQuestion) override;
    virtual void deleteQusetion() override {};
    virtual void addCorreactAnswer(const std::string& correctAnswer, int numberQuestion) override;
    virtual void deleteCorreactAnswer() override {};
    virtual std::string getAlltest()override;
private:
    std::shared_ptr<DataTest> _datatest;
    std::shared_ptr<Test> _test;
private:
    ChangeTest(const ChangeTest&) = delete;
    ChangeTest& operator=(ChangeTest&) = delete;
public:
    ChangeTest();
};

class UseTest : public IComandUseTest {
public:
    UseTest (std::shared_ptr<DataTest>);
    virtual void startTest() override {}; //для console UI
private:
    std::shared_ptr<DataTest> pData;
private:
    UseTest(const UseTest&) = delete;
    UseTest& operator=(UseTest&) = delete;
};
#endif//DATACREATE_H
