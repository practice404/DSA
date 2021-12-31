#ifndef PERSON_H
#define PERSON_H
#include <cassert>
#include <iostream>
#include <string>

class Person
{
	private:
		std::string first_name{};
		std::string last_name{};
		int * age = nullptr;
		inline static size_t person_num{};
	public:
		// constructors
		Person() = delete;
    	Person(const std::string& last_name_param);
		Person(const std::string& last_name_parm, const std::string& first_name_param);
		Person(const std::string & first_name_param, const std::string & last_name_param, int age_param);

		// list initializer constructor

		Person(std::initializer_list<const char *> list);

		// copy constructors
		// Person(const Person & source_obj);


		// copy constructor using constructor delegation
		Person(const Person & source_obj);

		// move constructor
		Person(Person && source);

		// destructors
		~Person();
		// friends function
		friend void show_info(const Person & obj);
		// setters
		void set_first_name(const std::string & first_name);
		void set_last_name(const std::string & last_name);
		void set_age(int age);
		// getters
		const std::string get_first_name()const;
		const std::string get_last_name()const;
		int * get_age()const;
		size_t get_person_num() const;
		const std::string steal_first_name();
		const std::string steal_last_name();
		int * steal_age();

		// utility functions
		void print_info();

		// static members variables
		inline static const std::string species {"Human"};

		// static member functions
		// they can only access static member variables 
		static std::string get_species();


};

#endif