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
        bool find_by_num(const std::string &number);
        Person() = default;
        Person(std::string name, std::string surname) : full_name_(name,surname) {};
        Person(std::string name, std::string surname, NumTypes type, const std::string& number);
        std::string get_name() const;
        std::string get_surname() const;
        std::pair<NumTypes,std::string>* find(const std::string &num);
        std::string print();
        void set_name(std::string name);
        void set_surname(std::string surname);
        void add_num(NumTypes type, const std::string& number);
        void remove_num(const std::string &num);
    };
    std::vector<Person> persons_;
    Person* find(const std::string &name,const std:: string &surname);
    static std::string is_valid_num(std::string num);
    static bool is_valid_fullname(const std::string &name,const std:: string &surname);
public:
    std::string to_string(const std::string &name,const std:: string &surname);

    void print_to_console(const std::string &name,const std:: string &surname);
    void add_contact(const std::string& name, const std:: string& surname, NumTypes type,const std::string& number);
    void add_contact(const std::string& name, const std:: string& surname);
    void add_number(const std::string &name , const std::string &surname,NumTypes type, const std::string& number);
    std::string find_full_name(const std::string &name);
    std::string find_num(const std::string &num);
    void change_fullname(const std::string &name,const std::string &surname, const std::string& new_name = "", const std::string& new_surname = "");
    void change_number(const std::string &old_num, NumTypes type, const std::string& new_num);
    void remove_number(const std::string& name, const std::string& surname, const std::string& number);
    void remove_contact(const std::string &name,const std::string &surname);
    std::string find(const std::string &str);

};


#endif //OOP_PHONEBOOK_H
