#pragma once

#include "Movie.h"
#include "Member.h"

extern bool staff_logged_in;

bool LoginToStaffMenu();

void WriteStaffMenu();

Movie * GetNewMovie(std::string title);
