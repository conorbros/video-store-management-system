#include <iostream>
#include <vector>
#include "MemberCollection.h"

void MemberCollection::RegisterMember(Member *member)
{
    if (this->member_count == 100)
    {
        std::cout << "Could not register new member. Too many members already registered." << std::endl;
        return;
    }

    this->members[this->member_count] = member;
    this->member_count++;
}

void MemberCollection::PrintCurrentMembers()
{
    for (int i = 0; i < this->member_count; i++)
    {
        Member *member = this->members[i];
        std::cout << member->username << std::endl
                  << std::endl;
    }
}

bool MemberCollection::CheckMemberDetails(std::string username, int password)
{
    for (int i = 0; i < this->member_count; i++)
    {
        Member *member = this->members[i];
        if (member->CheckDetails(username, password))
        {
            return true;
        }
    }
    return false;
}

Member *MemberCollection::GetMember(std::string username)
{
    for (int i = 0; i < this->member_count; i++)
    {
        Member *member = this->members[i];
        if (member->username == username)
        {
            return member;
        }
    }
    throw std::invalid_argument("Invalid username");
}

std::string MemberCollection::GetMemberPhoneNumber(std::string username)
{
    return this->GetMember(username)->phone_number;
}

bool MemberCollection::DoesMemberExist(std::string username)
{
    for (int i = 0; i < this->member_count; i++)
    {
        Member *member = this->members[i];
        if (member->username == username)
        {
            return true;
        }
    }
    return false;
}