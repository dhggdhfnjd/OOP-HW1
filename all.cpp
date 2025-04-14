#include"todo1.h"
#include<fstream>
#include<vector>
#include <sstream>
int main()
{
    todo *user=new todo();
    string check,name,cat,username;
    string line;
    int k=0;
    bool sit;
    cout<<"What is your name: ";
    getline(cin,username);
    ifstream file("todo.txt");
    while(getline(file,line))
    {
        istringstream iss(line);
        iss>>check;
        if(check=="add")
        {
            iss>>name>>cat;
            if(user->error(name)==false)
            cout<<"this work is already on the list."<<endl;
            else
            {
                user->add(name,cat);
                k++;
            }
        }
        else if(check=="edit")
        {
            iss>>name>>cat;
            
            if(cat=="0"|| cat=="1")
            {
                if(cat=="0")
                {
                cout<<"After edit ("<<name<<" "<<"not yet)"<<endl;
                user->edit(name,0);
                }
                else
                {
                cout<<"After edit ("<<name<<" "<<"done)"<<endl;
                user->edit(name,1);
                k--;
                }
            }
            else
            {
                cout<<"After edit ("<<name<<" "<<cat<<")"<<endl;
                user->edit(name,cat);
            }
            cout<<endl;
        }
        else if(check=="delete")
        {
            iss>>name;
            cout<<"After delete "<<name<<" "<<endl;
            user->del(name);
            k--;
        }
        else if(check=="view")
        {
            cout<<"Hi "<<username<<" here is your todo list"<<endl;
            user->view(k);
            break;
        }
        else
        continue;
    
    }
    file.close();
    delete user; 
}