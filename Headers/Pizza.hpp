/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** NPizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include "AbstractClass/APizza.hpp"
#include "vector"
#include "memory"

namespace plazza {
    class Pizza : public plazza::APizza {
        public:
            Pizza();
            Pizza(plazza::PizzaType type,plazza::PizzaSize size, int multiplier, int id);
            Pizza(plazza::PizzaType type,plazza::PizzaSize size, int id);
            ~Pizza();
            int getCookingTime() const;
            plazza::PizzaSize getPizzaSize() const;
            plazza::PizzaType getPizzaType() const;
            std::vector<plazza::PizzaIngredients> getRecette() const;
            void setRecette();
            void setTime();
            int getPizzaId() const;

        protected:
            std::vector<plazza::PizzaIngredients> _recette;
            plazza::PizzaType _type;
            plazza::PizzaSize _size;
            plazza::PizzaTime _time;
            int _multiplier;
            int _id;
    };
};

#endif /* !PIZZA_HPP_ */