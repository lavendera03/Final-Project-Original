#ifndef AUTHSYSTEM_H
#define AUTHSYSTEM_H

#include "UserProfile.h"

class AuthSystem {
public:
    bool handleLogin(UserProfile& profile);
    bool handleSignup(UserProfile& profile);
};

#endif