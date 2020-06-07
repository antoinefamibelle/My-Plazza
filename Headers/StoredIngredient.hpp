/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** StoredIngredient
*/

#ifndef STOREDINGREDIENT_HPP_
#define STOREDINGREDIENT_HPP_

#include <map>
#include <iostream>
#include "Pizza.hpp"
#include "Chrono.hpp"
#include "plazza.hpp"

namespace plazza {
    class StoredIngredient {
        public:
            StoredIngredient(double time);
            ~StoredIngredient();

            void useIngredient(plazza::PizzaIngredients ingredient);
            bool isIngredientLeft(plazza::PizzaIngredients ingredient);
            void displayIngredient();
            void checkIngredientGeneration();
            void addIngredients();
            bool isRecettePossible(std::vector<plazza::PizzaIngredients> ingredient);
            void makeRecette(std::vector<plazza::PizzaIngredients> ingredient);
        protected:
        private:
            int _time;
            std::map<plazza::PizzaIngredients, int> _ingredients;
            plazza::Chrono _chrono;
    };
}

#endif /* !STOREDINGREDIENT_HPP_ */
