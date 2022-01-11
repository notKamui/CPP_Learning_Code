#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned int> count_lower(const std::string& s)
{
    auto ret = std::vector<unsigned int>(26);
    for (auto c : s)
        if (c >= 'a' && c <= 'z')
            ret[c - 'a'] += 1;

    return ret;
}

void display_lower_occ(const std::vector<unsigned int>& vec)
{
    for (auto c = 'a'; c <= 'z'; c++)
        std::cout << c << " : " << vec[c - 'a'] << std::endl;
}

int main()
{
    auto cat = std::string();
    auto s   = std::string();
    do
    {
        std::cin >> s;
        display_lower_occ(count_lower(s));
        cat += s;
        std::cout << cat << std::endl;
    }
    while (s != "QUIT");
    return 0;
}