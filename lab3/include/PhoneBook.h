#ifndef OOP_PHONEBOOK_H
#define OOP_PHONEBOOK_H
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using number = std::vector<std::string>;
using FullName = std::pair<std::string,std::string>;
enum NumTypes{WORK, HOME, MOBILE};
using Numbers = std::vector<std::pair<NumTypes,std::string>>;
class PhoneBook {
    class Person {
        FullName full_name_;
        Numbers contacts_;
    public:
        bool find_by_num(std::string number);
        Person() = default;
        Person(std::string name, std::string surname) : full_name_(name,surname) {};
        Person(std::string name, std::string surname, NumTypes type, std::string number);
        std::string get_name() const;
        std::string get_surname() const;
        std::pair<NumTypes,std::string>* find(std::string number);
        std::string print();
        void set_name(std::string name);
        void set_surname(std::string surname);
        void add_num(NumTypes type, std::string number);
        void remove_num(std::string number);
    };
    std::vector<Person> persons_;
    Person* find(std::string name, std::string surname);
    std::string is_valid_num(std::string num);
    bool is_valid_fullname(std::string name, std::string surname);
public:
    std::string to_string(std::string name, std:: string surname);
    void print_to_console(std::string name , std::string surname);
    void add_contact(std::string name, std::string surname, NumTypes type, std::string number);
    void add_contact(std::string name, std::string surname);
    void add_number(std::string name , std::string surname,NumTypes type, std::string number);
    std::string find_full_name(std::string name);
    std::string find_num(std::string num);
    void change_fullname(std::string name, std::string surname, std::string new_name = "", std::string new_surname = "");
    void change_number(std::string old_num, NumTypes type, std::string new_num);
    void remove_number(std::string name, std::string surname, std::string number);
    void remove_contact(std::string name, std::string surname);
    std::string find(std::string str);

};


#endif //OOP_PHONEBOOK_H
