#include <iostream>
#include <Member.h>

Member::Member(std::string first, std::string last, std::string phone, int pass)
{
    first_name = first;
    last_name = last;
    username = last + first;
    phone_number = phone;
    password = pass;
}