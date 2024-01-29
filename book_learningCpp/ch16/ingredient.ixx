// ingredient.ixx
// declare a module named ingredient in the CookingShow namespace
export module CookingShow.ingredient;

import std.core;

export namespace CookingShow
{
    struct ingredient
    {
        std::string name;
        ingredient(const std::string& name) : name(name) {}
    };
}