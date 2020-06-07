/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** plazza
*/

#pragma once

namespace plazza {
    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8,
        UNDEFINEDTYPE
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16,
        UNDEFINEDSIZE
    };

    enum PizzaIngredients {
        Doe,
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        ChiefLove,
        UNDEFINEDINGREDIENT
    };

    enum PizzaTime {
        one = 1,
        two = 2,
        three = 3,
        four = 4,
        five = 5,
        six = 6,
        seven = 7,
        eight = 8,
        nine = 9
    };
}
