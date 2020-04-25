#pragma once

#include <iostream>
#include <vector>
#include <Member.h>

class MemberCollection
{
    Member *members[100];
    int member_count = 0;

public:
    void RegisterMember(Member *member);
    void PrintCurrentMembers();
    bool CheckMemberDetails(std::string username, int password);
    Member * GetMember(std::string username);
    std::string GetMemberPhoneNumber(std::string username);
    bool DoesMemberExist(std::string username);
};