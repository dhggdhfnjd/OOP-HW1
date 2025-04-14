#include"./basic.h"
#include <string>
#include<vector>
#include<algorithm>
#include <random> 

class todo : public Basic_task
{
    public:
    todo(){};
    vector<Basic_task*> todolist;
    void add(string a1,string b1)
    {
        this->todolist.push_back(new Basic_task(a1,b1));
    }
    void viewall()
    {
            for(Basic_task *p:todolist)
        {
            if(p->ca()=="a")
            p->print(1);
            else
            continue;
        }
        for(Basic_task *p:todolist)
        {
            if(p->ca()=="b")
            p->print(2);
            else
            continue;
        }
        for(Basic_task *p:todolist)
        {
            if(p->ca()=="c")
            p->print(3);
            else
            continue;
        }
        for(Basic_task *p:todolist)
        {
            if(p->ca()=="d")
            p->print(4);
            else
            continue;
        }
       
    }
    bool error(string name)
    {
        for(Basic_task *p:todolist)
        {
            if(p->na()==name)
            {
                return false;
                break;
            }
        }
        return true;
    }
    void view(int total)
    {
        int count=0;
        for(Basic_task *p:todolist)
        {
            if(p->com()==0 && p->ca()=="a")
            {
                p->print(1);
                count++;
            }
            else
            continue;
        }
        for(Basic_task *p:todolist)
        {
            if(p->com()==0 && p->ca()=="b")
            {
                p->print(2);
                count++;
            }
            else
            continue;
        }
        for(Basic_task *p:todolist)
        {
            if(p->com()==0 && p->ca()=="c")
            {
                p->print(3);
                count++;
            }
            else
            continue;
        }
        for(Basic_task *p:todolist)
        {
            if(p->com()==0 && p->ca()=="d")
            {
                p->print(4);
                count++;
            }
            else
            continue;
        }
        if(count<total/2)
        {
            cout<<"good job"<<endl<<"you have only"<<count<<" things left"<<endl;
        }
        else
        cout<<"work harder"<<endl<<"you have "<<count<<" things left"<<endl;
    }
    void del(string a1)
    {
        int count;
        for(Basic_task *p:todolist)
        {
            if(p->deletecheck(a1))
            {
                todolist.erase(todolist.begin()+count);
                break;
            }
            count++;
        }
        viewall();
    }
    void edit(string a1,string a2)
    {
        for(Basic_task *p:todolist)
        {
            if(p->editcheck(a1,a2))
            break;
        }
        viewall();
    }
    void edit(string a1,bool a2)
    {
        for(Basic_task *p:todolist)
        {
            if(p->boolcheck(a1,a2))
            break;
        }
        viewall();
    }
   
};