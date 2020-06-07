/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** StoredIngredient
*/

#include "StoredIngredient.hpp"

plazza::StoredIngredient::StoredIngredient(double time)
{
    this->_time = time;
    this->_chrono = plazza::Chrono();
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::Doe, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::Tomato, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::Gruyere, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::Ham, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::Mushrooms, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::Steak, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::Eggplant, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::GoatCheese, 5));
    this->_ingredients.insert(std::pair<plazza::PizzaIngredients, int>(plazza::ChiefLove, 5));
    this->_chrono.startChrono();
}

plazza::StoredIngredient::~StoredIngredient()
{
}

void plazza::StoredIngredient::useIngredient(plazza::PizzaIngredients ingredient)
{
    this->_ingredients.at(ingredient) -= 1;
}

bool plazza::StoredIngredient::isIngredientLeft(plazza::PizzaIngredients ingredient)
{
    return this->_ingredients.at(ingredient) > 0 ? true : false;
}

void plazza::StoredIngredient::addIngredients()
{
    for (std::map<plazza::PizzaIngredients, int>::iterator it = _ingredients.begin(); it != _ingredients.end(); ++it)
        _ingredients.at(it->first) += _ingredients.at(it->first) < 5 ? 1 : 0;
}

void plazza::StoredIngredient::checkIngredientGeneration()
{
    if (this->_chrono.getElapsedTime() >= this->_time) {
        this->addIngredients();
        this->_chrono.resetChrono();
    }
}

void plazza::StoredIngredient::displayIngredient()
{
    std::cout << "------------------" << std::endl;
    for (std::map<plazza::PizzaIngredients, int>::iterator it = _ingredients.begin(); it != _ingredients.end(); ++it)
        std::cout << _ingredients.at(it->first) << " / ";
    std::cout << "\n------------------" << std::endl;
}

bool plazza::StoredIngredient::isRecettePossible(std::vector<plazza::PizzaIngredients> ingredient)
{
    for (std::vector<plazza::PizzaIngredients>::iterator it = ingredient.begin(); it != ingredient.end(); ++it) {
        if (this->isIngredientLeft(*it) == false)
            return false;
    }
    return true;
}
 
void plazza::StoredIngredient::makeRecette(std::vector<plazza::PizzaIngredients> ingredient)
{
    for (std::vector<plazza::PizzaIngredients>::iterator it = ingredient.begin(); it != ingredient.end(); ++it)
            this->useIngredient(*it);
}