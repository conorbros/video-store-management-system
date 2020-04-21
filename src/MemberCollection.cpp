#include <iostream>
#include <vector>
#include <MemberCollection.h>

void MemberCollection::RegisterMember(Member member)
{
    this->members.push_back(member);
}