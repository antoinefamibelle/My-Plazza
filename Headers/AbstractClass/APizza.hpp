/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_

#include <vector>
#include "plazza.hpp"

namespace plazza {
    class APizza {
        public:
            APizza() = default;
            virtual ~APizza() {};
        public: 
            virtual int getCookingTime() const = 0;
            virtual plazza::PizzaSize getPizzaSize() const = 0;
            virtual plazza::PizzaType getPizzaType() const = 0;
            virtual std::vector<plazza::PizzaIngredients> getRecette() const = 0;

        private:
            std::vector<plazza::PizzaIngredients> _recette;
            plazza::PizzaType _type;
            plazza::PizzaSize _size;
            plazza::PizzaTime _time;
            int _multiplier;

        // creer un enum de chaque recette
        //  faire une fonction qui return la recette en focntion du getType()
    };
}

#endif /* !APIZZA_HPP_ */