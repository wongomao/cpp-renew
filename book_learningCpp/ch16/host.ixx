// host.ixx
export module CookingShow.host;

import std.core;
import CookingShow.ingredient;

export namespace CookingShow
{
    struct host
    {
        std::string name;
        host(const std::string& name) : name(name) {}
    };

    void announce_ingredient(const host& h, const ingredient& i)
    {
        std::cout << h.name << ": Let's see what's on the menu today... Ah! ";
        std::cout << i.name << "! Bork Bork Bork!" << std::endl;
    }

    std::vector<ingredient> get_ingredients()
    {
        return {
            ingredient("meatballs"), ingredient("pickled herring"),
            ingredient("lingonberries"), ingredient("cabbage")
            };
    }
}