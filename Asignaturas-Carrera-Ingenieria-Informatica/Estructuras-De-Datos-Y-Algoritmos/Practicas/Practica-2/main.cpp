#include <iostream>

#include "wardrove.h"
#include "queue.h"
#include "police.h"

int main()
{

    Queue joy_eslava;
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(Persona{"Manuel", "dni-manuel", 0});
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    joy_eslava.push(Persona{"Miguel", "dni-miguel", 0});
    joy_eslava.push(Persona{"Samuel", "dni-samuel", 0});
    joy_eslava.push(Persona{"Raquel", "dni-raquel", 1});

    std::vector<std::string> dnis{"dni-manuel", "dni-raquel", "dni-isabel"};
    auto filtered = police_raid(joy_eslava, dnis);

    std::cout << "Joy Slava, people waiting: " << filtered.size() << std::endl;
    while (!filtered.empty())
    {
        auto person = filtered.front();
        filtered.pop();
        std::cout << person.get_name() << std::endl;
    }

    Wardrobe men;
    Wardrobe women;
    wardrobe(joy_eslava, men, women);

    std::cout << "Wardrobe men:" << std::endl;
    while (!men.empty())
    {
        std::cout << men.top() << std::endl;
        men.pop();
    }

    std::cout << "Wardrobe women:" << std::endl;
    while (!women.empty())
    {
        std::cout << women.top() << std::endl;
        women.pop();
    }

    Persona manuel{"Manuel", "dni-manuel", 0};

    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(manuel);
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});

    Queue friends;
    friends.push(Persona{"Miguel", "dni-miguel", 0});
    friends.push(Persona{"Samuel", "dni-samuel", 0});
    friends.push(Persona{"Raquel", "dni-raquel", 1});

    joy_eslava.sneak_in(manuel, friends);

    std::cout << "Joy Slava, people waiting: " << joy_eslava.size() << std::endl;
    while (!joy_eslava.empty())
    {
        auto person = joy_eslava.front();
        joy_eslava.pop();
        std::cout << person.get_name() << std::endl;
    }
}
