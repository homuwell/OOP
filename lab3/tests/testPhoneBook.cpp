#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/PhoneBook.h"
using testing::Eq;

namespace {
    class testPhoneBook : public testing::Test {
    public:
        PhoneBook phone_book;

        testPhoneBook() {
            phone_book;
            phone_book.add_contact("George", "Orwell", WORK, "89991984555");
            phone_book.add_contact("Gumbert", "Gumbert", HOME, "89111111111");
            phone_book.add_contact("Hideo", "Kojima", HOME, "89222222222");
            phone_book.add_contact("Augustin-Louis", "Cauchy", MOBILE, "89333333333");
            phone_book.add_contact("Donald", "Knuth", WORK, "8944444444444");
            phone_book.add_number("Gumbert", "Gumbert", HOME, "89123456789");
            phone_book.add_number("Gumbert", "Gumbert", HOME, "89999999999");
            phone_book.add_number("Gumbert", "Gumbert", WORK, "89666666666");
            phone_book.add_number("Donald", "Knuth", MOBILE, "89000000000");

        }
    };
}
TEST_F(testPhoneBook, changeFullnameTest) {
    std::string newName = "Name: Aldous\nSurname: Orwell\nContacts:\nWork: 89991984555\n\n";
    std::string newSurname = "Name: Aldous\nSurname: Huxley\nContacts:\nWork: 89991984555\n\n";
    std::string newFullName = "Name: Big\nSurname: Boss\nContacts:\nHome: 89222222222\n\n";
    phone_book.change_fullname("George","Orwell","Aldous");
    ASSERT_EQ(phone_book.to_string("Aldous","Orwell"),newName);
    phone_book.change_fullname("Aldous","Orwell","","Huxley");
    ASSERT_EQ(phone_book.to_string("Aldous","Huxley"),newSurname);
    phone_book.change_fullname("Hideo","Kojima","Big","Boss");
    ASSERT_EQ(phone_book.to_string("Big","Boss"),newFullName);
}

TEST_F(testPhoneBook, deleteNumberTest) {
    std::string delNumber = "Name: Donald\nSurname: Knuth\nContacts:\nMobile: 89000000000\n\n";
    phone_book.remove_number("Donald","Knuth","8944444444444");
    ASSERT_EQ(phone_book.to_string("Donald","Knuth"),delNumber);
}

TEST_F(testPhoneBook, ChangeNumberTest) {
std::string newNum = "Name: Augustin-Louis\nSurname: Cauchy\nContacts:\nMobile: 89123654987\n\n";
phone_book.change_number("89333333333",MOBILE,"89123654987");
ASSERT_EQ(phone_book.to_string("Augustin-Louis","Cauchy"),newNum);
}
TEST_F(testPhoneBook, DeleteContactTest) {
    phone_book.remove_contact("Gumbert","Gumbert");
    ASSERT_EQ(phone_book.find("Gumbert"),"");
}
TEST_F(testPhoneBook, FindBySymbolsTest) {
    std::string contacts = "Name: George\nSurname: Orwell\nContacts:\nWork: 89991984555\n\nName: Gumbert\nSurname: Gumbert\n"
                      "Contacts:\nHome: 89111111111\nHome: 89123456789\nHome: 89999999999\n"
                      "Work: 89666666666\n\n";
    ASSERT_EQ(phone_book.find("G"),contacts);
}
TEST_F(testPhoneBook, FindByNumbersTest) {
    std::string contacts = "Name: Gumbert\nSurname: Gumbert\n"
                           "Contacts:\nHome: 89111111111\nHome: 89123456789\nHome: 89999999999\n"
                           "Work: 89666666666\n\nName: Augustin-Louis\nSurname: Cauchy\nContacts:\nMobile: 89333333333\n\n";
    ASSERT_EQ(phone_book.find("3"),contacts);
}

