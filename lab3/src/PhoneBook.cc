

#include "../include/PhoneBook.h"

#include <utility>


std::string PhoneBook::find_full_name(std::string name) {
    std::string result;
    for (auto i: persons_) {
        if (i.get_name().find(name) != std::string::npos || i.get_surname().find(name) != std::string::npos) {
            result += i.print();
        }
    }
    return result;
}


void PhoneBook::add_contact(std::string name, std::string surname, NumTypes type, std::string number) {

    if (is_valid_fullname(name,surname) && is_valid_num(number) != "") {
        PhoneBook::Person *elem = find(name,surname);
        if (elem == nullptr) {
            Person person{name,surname,type,number};
            persons_.push_back(person);
        } else {
            auto num = elem->find(number);
            if (num == nullptr) {
                elem->add_num(type,number);
            } else {
                num->first = type;
                num->second = number;
            }
        }
    } else {
        throw std::invalid_argument("Wrong fullname or number format");
    }
}

void PhoneBook::print_to_console(std::string name , std::string surname) {
    auto contact = find(name,surname);
    if (contact != nullptr) {
        std::cout << contact->print();
    }
}

void PhoneBook::add_number(std::string name , std::string surname,NumTypes type, std::string number) {
    add_contact(name,surname,type,number);
}

PhoneBook::Person* PhoneBook::find(std::string name, std::string surname) {
    for(auto i = 0; i < persons_.size();i++) {
        if (persons_[i].get_name() == name && persons_[i].get_surname() == surname) {
            return &persons_[i];
        }
    }
    return nullptr;
}

void PhoneBook::add_contact(std::string name, std::string surname) {
    if (is_valid_fullname(name,surname)) {
        if (find(name,surname) == nullptr) {
            Person person{name,surname};
            persons_.push_back(person);
        }
    } else {
        throw std::invalid_argument("Name and surname can't contain numbers");
    }
}

void PhoneBook::change_fullname(std::string name, std::string surname, std::string new_name, std::string new_surname) {
    if(is_valid_fullname(name,surname) && is_valid_fullname(new_name,new_surname)) {
        auto elem = find(name,surname);
        if (elem == nullptr) throw std::invalid_argument("Can't find user with this fullname");
        if (new_name == "" && new_surname == "") {
            return;
        } else if (new_surname == "") {
            find(new_name,surname) == nullptr ? elem->set_name(new_name) : throw std::invalid_argument("Can't change name, user with this fullname already exist");
        } else if (new_name == "") {
            find(name,new_surname) == nullptr ? elem->set_surname(new_surname) : throw std::invalid_argument("Can't change surname, user with this fullname already exist");
        }
        else {
            find(new_name,new_surname) == nullptr ? elem->set_surname(new_surname), elem->set_name(new_name)
                                                  : throw std::invalid_argument("Can't change name and surname, user with this fullname already exist");
        }
    } else {
        throw std::invalid_argument("Names and Surnames can't contain numbers");
    }

}

std::string PhoneBook::is_valid_num(std::string num) {
    if (num.find('+') != std::string::npos) {
        num = "8" + num.erase(0,2);
    }
    if (num.find_first_not_of("0123456789") != std::string::npos) {
        return "";
    }
    return num;
}

bool PhoneBook::is_valid_fullname(std::string name, std::string surname) {
    if (name.find_first_of("0123456789") != std::string::npos  || surname.find_first_of("0123456789") != std::string::npos) {
        return false;
    }
    return true;
}

void PhoneBook::remove_number(std::string name, std::string surname, std::string number) {
    if (is_valid_fullname(name,surname) && is_valid_num(number) != "") {
        auto elem = find(name,surname);
        elem != nullptr ? elem->remove_num(number) : throw std::invalid_argument("Can't find element with this fullname");
    } else {
        throw std::invalid_argument("Invalid input format");
    }
}

void PhoneBook::remove_contact(std::string name, std::string surname) {
    if (is_valid_fullname(name, surname)) {
        persons_.erase(std::remove_if(persons_.begin(), persons_.end(),
                                      [&](auto &element) { return element.get_name() == name && element.get_surname() == surname; }), persons_.end()
        );
    } else {
        throw std::invalid_argument("Invalid input format");
    }
}

std::string PhoneBook::find_num(std::string num) {
    std::string result;
    for (auto i: persons_) {
        if (i.find_by_num(num)) {
            result += i.print();
        }
    }
    return result;
}

std::string PhoneBook::find(std::string str) {
   std::string result;
   if (str.find_first_of("0123456789") != std::string::npos) {
       result = find_num(str);
   }
   else {
       result = find_full_name(str);
   }
   return result;

}

void PhoneBook::change_number(std::string old_num, NumTypes type, std::string new_num) {
    if ( old_num == new_num || old_num == "" || new_num == "") {
        return;
    }
    if (is_valid_num(old_num) != "" || is_valid_num(new_num) != "") {
        for (auto i = 0; i < persons_.size();i++) {
            auto ptr = persons_[i].find(old_num);
            if (ptr != nullptr) {
                ptr->first = type;
                ptr->second = new_num;
            }
        }
    }
}

std::string PhoneBook::to_string(std::string name, std::string surname) {
    auto elem = find(name,surname);
    if (elem == nullptr) {
        throw std::invalid_argument("Contact with that Fullname didn't exist");
    } else {
        return elem->print();
    }
}


std::string PhoneBook::Person::get_name() const {
    return this->full_name_.first;
}

std::string PhoneBook::Person::get_surname() const {
    return this->full_name_.second;
}

std::pair<NumTypes,std::string>* PhoneBook::Person::find(std::string number) {
    for(auto i = 0; i < contacts_.size();i++) {
        if (contacts_[i].second == number) {
            return &contacts_[i];
        }
    }
    return nullptr;

}

std::string PhoneBook::Person::print() {
    std::stringstream full_info;
    full_info << "Name: " << this->full_name_.first << std::endl;
    if (this->full_name_.second != "") {
        full_info << "Surname: " << this->full_name_.second << std::endl;
    }
    full_info << "Contacts:" << std::endl;
    for(auto i: contacts_) {
        switch (i.first) {
            case MOBILE:
                full_info << "Mobile: " << i.second << std::endl;
                break;
            case HOME:
                full_info << "Home: " << i.second <<  std::endl;
                break;
            case WORK:
                full_info << "Work: " << i.second << std::endl;
                break;
        }
    }
    full_info << std::endl;
    return full_info.str();


}

PhoneBook::Person::Person(std::string name, std::string surname, NumTypes type, std::string number) {
    this->full_name_.first = std::move(name);
    this->full_name_.second = std::move(surname);
    this->contacts_.push_back(std::make_pair(type,number));
}

void PhoneBook::Person::add_num(NumTypes type, std::string number) {
    this->contacts_.push_back(std::make_pair(type,number));
}

void PhoneBook::Person::remove_num(std::string number) {
    contacts_.erase(std::remove_if(contacts_.begin(), contacts_.end(),
                                   [&](auto &element) { return element.second == number; }), contacts_.end()
    );

}

void PhoneBook::Person::set_name(std::string name) {
    full_name_.first = name;
}

void PhoneBook::Person::set_surname(std::string surname) {
    full_name_.second = surname;
}

bool PhoneBook::Person::find_by_num(std::string number) {
    for(auto i: contacts_) {
        if (i.second.find_first_of(number) != std::string::npos ) {
            return true;
        }
    }
    return false;
}

