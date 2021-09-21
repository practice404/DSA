#include<bits/stdc++.h>
using namespace std;

class Human 
{
    private:
        int num_ears;
        string class_;

    public:
        Human(string class_, int num_ears)
        {
            this->num_ears = num_ears;
            this->class_ = class_;
        }

        void showClass()
        {
            cout<<"Class: "<<this->class_<<endl;
            cout<<"Ears: "<<this->num_ears<<endl;
        }

        void do_something_to_3(char n)
        {
            cout<<"In Human, base class"<<endl;
        }
};

class Person : public Human
{
    private:
        string name;
        int age;
        string gender;

    public:
        // passing arguments to constructor of the super class
        Person(string name, string gender, int age, int num_ears, string class_) : Human(class_, num_ears)
        {
            this->name = name;
            this->age = age;
            this->gender = gender;
        }

        void showData()
        {
            cout<<"Name: "<<this->name<<endl;
            cout<<"Gender: "<<this->gender<<endl;
            cout<<"Age: "<<this->age<<endl;
        //     cout<<"Class: "<<this->class_<<endl; // not work because class_ is private in Human
            showClass();
        }

        // it allow you to overload the base and derived classes's function, 
        //otherwise derived class's functions whill shadow the base's functions having same name
        
        using Human :: do_something_to_3;
        
        void do_something_to_3(int n)
        {
            cout<<"In Person, derived class"<<endl;
        }
};


int main()
{
    Person p = Person("Shubham", "Male", 20, 6, "Homosapians");
    // p.showData();
    p.do_something_to_3('a');
}