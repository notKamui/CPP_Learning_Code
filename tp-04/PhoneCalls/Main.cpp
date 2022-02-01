#include "HomePhone.h"
#include "MobilePhone.h"
#include "Person.h"
#include "Phone.h"

int main()
{
    Person paul { "Paul", 3 };
    MobilePhone mobile_phone { paul };

    return 0;
}
