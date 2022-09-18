#pragma once

#include "employee.h"

class manager : public employee
{
private:
    char title[LEN];
    double dues;

public:
    virtual void getdata() override;
    virtual void putdata() override;
    virtual employee_type get_type() override;
};
