#include <iostream>
#include <string>
#include <stdexcept>

class Member
{
    std::string first_name;
    std::string last_name;
    std::string username;
    std::string phone_number;
    int password;

public:
    Member(std::string, std::string, std::string, int);
};