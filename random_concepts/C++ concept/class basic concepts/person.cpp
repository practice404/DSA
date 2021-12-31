#include "person.h"

// constructors
Person::Person(const std::string& last_name_param) : last_name{last_name_param}
{
	++person_num;
}
Person::Person(const std::string& last_name_parm, const std::string& first_name_param):
			first_name{first_name_param}, last_name{last_name_parm}
{
	++person_num;
}
Person::Person(const std::string & first_name_param, const std::string & last_name_param, int age_param) : 
			first_name{first_name_param}, last_name{last_name_param}, age{new int(age_param)}
{
	++person_num;
}
// list initializer constructor

Person::Person(std::initializer_list<const char *> list)
{
    assert(list.size() == 2); // putting assertion check on list
	this->first_name = *(list.begin());
	this->last_name = *(list.begin()+1);
	age = new int(0);
    std::cout<<"Initializer list constructior is called"<< std::endl;
	++person_num;
}
// copy constructors

// passing obj by value won't work, since it creates an endless cycle of copying
// passing as const cause we don't want to modify the content of instance

// Person::Person(const Person & source_obj) : 
// 	first_name{source_obj.get_first_name()},
// 	last_name{source_obj.get_last_name()},
// 	age{new int(*(source_obj.get_age()))}
// {
// 	std::cout<<"copy constructor called"<<std::endl;
// }


// copy constructor using constructor delegation
Person::Person(const Person & source_obj) : 
    Person(	
        source_obj.get_first_name(), 
        source_obj.get_last_name(),
        *(source_obj.get_age())
        )
{
    std::cout << "Copy constructor is called"<<std::endl;
}

// move constructor
Person::Person(Person && source) : 
    first_name{source.steal_first_name()},
    last_name{source.steal_last_name()},
    age{source.steal_age()}
{
    ++person_num;
    std::cout<<"Move constructor is called"<<std::endl;
}

// destructors
Person::~Person()
{
    --person_num;
    delete age;
}
// setters
void Person::set_first_name(const std::string & first_name) {this->first_name = first_name;}
void Person::set_last_name(const std::string & last_name) {this->last_name = last_name;}
void Person::set_age(int age) {*(this->age) = age;}
// getters
const std::string Person::get_first_name() const {return this->first_name;}
const std::string Person::get_last_name() const {return this->last_name;}
int * Person::get_age() const {return this->age;}
size_t Person::get_person_num() const {return person_num;}
const std::string Person::steal_first_name() {return this->first_name;}
const std::string Person::steal_last_name() {return this->last_name;}
int * Person::steal_age()
{
    int * new_age = age;
    age = nullptr;
    return new_age;
}

// utility functions
void Person::print_info()
{
    std::cout << "Person object at : " << this 
    <<" [ Last_name : " << last_name 
    << ", First_name :  " << first_name 
    << " ,age : " << *age 
    << " , age address : " << age 
    << " ]" << std::endl;
}

// static member functions
// they can only access static member variables 
std::string Person::get_species(){return species;}
