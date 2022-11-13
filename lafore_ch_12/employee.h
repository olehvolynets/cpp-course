#pragma once

class employee
{
protected:
    static const int LEN = 32; // maximum length of last names
    static const int MAXEM = 100; // maximum number of employees

private:
    static int n;
    static employee* arrap[];

    char name[LEN];
    unsigned long number;

public:
    enum employee_type
    {
        t_manager,
        t_scientist,
        t_laborer
    };

    virtual void getdata();
    virtual void putdata();

    virtual employee_type get_type() = 0;

    static void add();
    static void display();
    static void read();
    static void write();
    static void find();
};
