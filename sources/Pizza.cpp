/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Pizza
*/

#include "Pizza.hpp"

plazza::Pizza::Pizza()
{
}

plazza::Pizza::~Pizza()
{
}

plazza::Pizza::Pizza(plazza::PizzaType type,plazza::PizzaSize size, int multiplier, int id)
{
    this->_type = type;
    this->_multiplier = multiplier;
    this->_size = size;
    this->setTime();
    this->_recette = this->getRecette();
    this->_id = id;
}

plazza::Pizza::Pizza(plazza::PizzaType type,plazza::PizzaSize size, int id)
{
    this->_type = type;
    this->_size = size;
    this->setTime();
    this->_recette = this->getRecette();
    this->_id = id;
}

void plazza::Pizza::setTime()
{
    if (this->getPizzaType() == plazza::PizzaType::Margarita)
        this->_time = plazza::PizzaTime::one;
    else if (this->getPizzaType() == plazza::PizzaType::Fantasia)
        this->_time = plazza::PizzaTime::four;
    else
        this->_time = plazza::PizzaTime::two;
}

plazza::PizzaSize plazza::Pizza::getPizzaSize() const
{
    return this->_size;
}

plazza::PizzaType plazza::Pizza::getPizzaType() const
{
    return this->_type;
}

int plazza::Pizza::getCookingTime() const
{
    if (this->_multiplier != 0) {
        return this->_type * this->_multiplier;
    }
    return this->_time;
}

void plazza::Pizza::setRecette()
{
    this->_recette.push_back(plazza::PizzaIngredients::Doe);
    this->_recette.push_back(plazza::PizzaIngredients::Tomato);
    if (this->getPizzaType() == plazza::PizzaType::Margarita)
        this->_recette.push_back(plazza::PizzaIngredients::Gruyere);
    else if (this->getPizzaType() == plazza::PizzaType::Fantasia) {
        this->_recette.push_back(plazza::PizzaIngredients::Eggplant);
        this->_recette.push_back(plazza::PizzaIngredients::ChiefLove);
    }
    else if (this->getPizzaType() == plazza::PizzaType::Americana) {
        this->_recette.push_back(plazza::PizzaIngredients::Gruyere);
        this->_recette.push_back(plazza::PizzaIngredients::Steak);
    }
    else if (this->getPizzaType() == plazza::PizzaType::Regina) {
        this->_recette.push_back(plazza::PizzaIngredients::Gruyere);
        this->_recette.push_back(plazza::PizzaIngredients::Ham);
        this->_recette.push_back(plazza::PizzaIngredients::Mushrooms);
    }
}

std::vector<plazza::PizzaIngredients> plazza::Pizza::getRecette() const
{
    return this->_recette;
}

int plazza::Pizza::getPizzaId() const
{
    return this->_id;
}