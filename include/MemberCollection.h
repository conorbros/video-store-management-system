#include <iostream>
#include <vector>
#include <Member.h>

class MemberCollection
{
    std::vector<Member> members;

public:
    void RegisterMember(Member);
};