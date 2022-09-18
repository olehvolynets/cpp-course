#pragma once

#include "employee.h"

class scientist : public employee
{
private:
    int pubs;

public:
    virtual void getdata() override;
    virtual void putdata() override;
    virtual employee_type get_type() override;
};
