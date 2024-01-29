// CppBookSampleCode.cpp

import CookingShow.host;
import CookingShow.ingredient;
import std.core;

int main()
{
    std::cout << "It's time to play the music, it's time to light the lights!" << std::endl;

    auto ingredients = CookingShow::get_ingredients();
    CookingShow::host h("Swedish Chef");
    for (const auto& i : ingredients)
    {
        CookingShow::announce_ingredient(h, i);
        if (i.name == "meatballs")
        {
            std::cout << "Bork Bork Bork! Meatbally" << std::endl;
        }
    }

    std::cout << std::endl << "Swedish Chef: That's all the time we have for today!" << std::endl;

    return 0;
}