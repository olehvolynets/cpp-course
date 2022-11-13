#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class String {
private:
    static const int SZ = 80;
    char str[SZ];

public:
    class StringTooLong : public exception {
    public:
        virtual const char* what() const noexcept
        {
            return "Resulting string is too long.";
        }
    };

    String()
    {
        strcpy(str, "");
    }

    String(char s[])
    {
        if (strlen(s) > SZ)
            throw StringTooLong();

        strcpy(str, s);
    }

    void display() const { cout << str; }

    String operator+(String ss) const
    {
        String temp;

        if (strlen(str) + strlen(ss.str) < SZ) {
            strcpy(temp.str, str);
            strcat(temp.str, ss.str);
        } else {
            throw StringTooLong();
        }

        return temp;
    }
};

int main()
{
    try
    {
        String s1("\nMerry Christmas!  ");
        String s2("Happy new year!");
        String s3;
        s1.display();
        s2.display();
        s3.display();
        s3 = s1 + s2;
        s3.display();
        cout << endl;
    }
    catch(String::StringTooLong& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
