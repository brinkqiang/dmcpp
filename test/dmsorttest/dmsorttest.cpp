#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <algorithm>

class player
{
public:
    player(int nLevel, int nAge)
        : m_nLevel(nLevel), m_nAge(nAge)
    {

    }

    int get_level()
    {
        return m_nLevel;
    }

    int get_age()
    {
        return m_nAge;
    }

    int m_nLevel;
    int m_nAge;
};

int main()
{
    std::vector<player*> vecPlayer;

    vecPlayer.push_back(new player(2, 2));
    vecPlayer.push_back(new player(2, 3));

    vecPlayer.push_back(new player(3, 5));
    vecPlayer.push_back(new player(3, 6));

    vecPlayer.push_back(new player(1, 2));
    vecPlayer.push_back(new player(1, 3));

    std::sort(vecPlayer.begin(), vecPlayer.end(), [](player* p1, player* p2)
    {
        return (p1->get_level() < p2->get_level()) ||
               (p1->get_level() == p2->get_level() && p1->get_age() > p2->get_age());
    });

    std::sort(vecPlayer.begin(), vecPlayer.end(), [](player* p1, player* p2)
    {
        return (p1->get_level() > p2->get_level()) ||
               (p1->get_level() == p2->get_level() && p1->get_age() > p2->get_age());
    });
    return 0;
}