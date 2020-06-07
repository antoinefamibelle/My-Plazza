/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "StoredIngredient.hpp"
#include "plazza.hpp"
#include "Pizza.hpp"
#include "Thread.hpp"
#include "Parser.hpp"
#include <iostream>
#include <vector>
#include <thread>

namespace plazza {
    class Cook {
        public:
            Cook();
            ~Cook() {}
        public:
            bool isBusy() const;
            bool isWaiting() const;
            bool isCooking() const;
            void setActualPizza(plazza::Pizza *);
            void setWaitingPizza(plazza::Pizza *);
            void info();
            static void cooking(plazza::Cook *object) {
                std::cout << "Cook: Cooking pizza" << std::endl;
                object->_isCooking = true;
                object->_cookingChrono = new plazza::Chrono();
                object->_cookingChrono->startChrono();
                while (object->_cookingChrono->getElapsedTime() < object->_actualPizza->getCookingTime())
                {
                    //Il wait la cuisson
                }
                std::cout << "Cook: Pizza done" << std::endl;
                object->_isCooked = true;
            }
            void describePizza();
            void setBusy(bool);
            void setWaiting(bool tmp) {this->_isWaiting = tmp;};
            void simulate();
            void setUnCooked();
            bool isCooked() const;
            plazza::Pizza *getActualPizza() const;

        private:
            bool _isCooking;
            bool _isBusy;
            bool _isWaiting;
            bool _isCooked;
            std::thread th;
            plazza::Chrono *_cookingChrono;
            plazza::StoredIngredient *_ingredient;
            plazza::Pizza *_actualPizza;
            plazza::Pizza *_awaitingPizza;

    };
}

#endif /* !COOK_HPP_ */