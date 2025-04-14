#include <string>
#include<vector>
#include<iostream>
#include<iomanip>
#pragma once
using namespace std;
class Basic_task {
protected: 
    std::string *name;
    std::string *category;
    bool *completed;
public:
    Basic_task(){};
    Basic_task(string a,string b)
    {
        name =new string(a);
        category =new string(b);
        completed=new bool(false);
    };
    void print(int a)
    {
        string arr[5]={"ANNOYING","Basic need","Critical","Daily routine","Exploring"};
        if(*completed==false)
        {
        cout<<left<<setw(20)<<*name<<" "<<setw(20)<<arr[a-1]<<"[not yet]"<<endl;
        }
        else
        cout<<left<<setw(20)<<*name<<" "<<setw(20)<<arr[a-1]<<"[done]"<<endl;
    }
    virtual ~Basic_task()
    {
        delete name;
        delete category;
        delete completed;
    }
    bool deletecheck(string s1)
    {
        if(*name==s1)
        {
        return 1;
        }
        else return 0;
    }
    bool editcheck(string s1,string s2)
    {
        if(*name==s1)
        {
            *category=s2;
            *name=s1;
            return 1;
        }
        if(*category==s1)
        {
            *category=s2;
            return 1;
        }
        return 0;
    }
    bool boolcheck(string s1,bool n)
    {
        if(*name==s1)
        {
            *completed=n;
            return 1;
        }
        if(*category==s1)
        {
            *completed=n;
            return 1;
        }
        return 0;
    }
    bool com()
    {
        return *completed;
    }
    string na()
    {
        return *name;
    }
    string ca()
    {
        return *category;
    }
};
