#include <iostream>
#include <string>

class Person
{
private:
    const std::string _name;
    const std::string _surname;
    unsigned int      _age = 0u;

public:
    Person() = default;

    Person(const std::string& name, const std::string& surname)
        : _name { name }
        , _surname { surname }
    {}

    [[nodiscard]] std::string  get_fullname() const { return _name + " " + _surname; }
    [[nodiscard]] unsigned int get_age() const { return _age; }

    void wait(unsigned int years) { _age += years; }
};

int main()
{
    Person p { "Bruce", "Wayne" };
    p.wait(23);

    std::cout << "Person named '" << p.get_fullname() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}
