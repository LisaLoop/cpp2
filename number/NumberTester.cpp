#include "Number.h"
#include <iostream>
using namespace std;

class Other 
{
    private:
        int x;

    public:
        Other(int n) {
            this->x = n;
        }
};

class Person {
    private:
        string name;
        int age;
    public:
        Person(string name, int age)
        {
            this->name = name;
            this->age = age;
        };

        string operator+(Person other)
        {
            return this->name + " & " + other.name;
        };

        bool operator<(Person other)
        {
            return this->age < other.age;
        };

        friend ostream &operator<<(ostream &out, Person person)
        {
            out << person.name;
            out << "(" << person.age << ")";
            return out;
        };
};

int main() {
    Number x(5);
    Other y(6);
    Person bob("Bob", 32);
    Person doug("Doug", 30);

    string names = bob + doug;
    bool isYounger = bob < doug; // false

    std::cout << names << endl;
    std::cout << x << endl;
    std::cout << bob << std::endl;

    return 0;
}
