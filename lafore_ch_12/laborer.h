#pragma once

#include "employee.h"


class laborer : public employee
{
    virtual employee_type get_type() override;
};
