#include <iostream>

int main()
{
    using namespace std;
    //    int number = 0;
    //    do
    //    {
    //        std::cin >> number;
    //        std::cout << "Squawk! " << number << std::endl;
    //    }
    //    while (number != -1);

    for (int i = 0; i < 10; i++)
    {
        string word;
        cin >> word;
        cout << "Squawk! " << word << endl;
    }
    return 0;
}