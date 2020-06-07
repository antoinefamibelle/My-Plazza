/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <map>
#include <memory>
#include "fstream"
#include "iostream"
#include "plazza.hpp"
#include "Pizza.hpp"
#include "Cook.hpp"
#include "Communication.hpp"
#include "unistd.h"
#include "Chrono.hpp"
#include "StoredIngredient.hpp"
#include "Thread.hpp"
#include "Log.hpp"
#include "Parser.hpp"

namespace plazza {
    class Kitchen {
        public:
            Kitchen();
            Kitchen(int, int, int);
            ~Kitchen() {}
        public:
            bool canBeSend();
            void generateCook();
            bool areBusy();
            bool areWaiting();
            int getNumberOfPizza();
            int getNumberOfCook() {return this->_numberOfCook; };
            int getKitchenNumber() { return this->_kitchenNumber; };
            void manageKitchen();
            void giveOrder();
            void refillStock();
            void giveOrder(plazza::Pizza *);
            void writeInLog(std::string);
            void manageResponse();

        private:
            plazza::Communication *_communication;
            std::vector<std::pair<plazza::Pizza *, bool>> _pizza;
            std::vector<std::pair<plazza::Cook *,std::thread *>> _cooks;
            plazza::StoredIngredient *_ingredient; 
            plazza::Chrono *_chrono;
            plazza::Chrono *_stockChrono;
            plazza::Log _log;
            plazza::Parser _parser;

            //std::ofstream _log("./logs/log.txt");
            //std::ofstream _detailLog("./logs/detailedLog.txt");
            int _numberOfCook;
            int _speedStock;
            int _kitchenNumber;
            bool _isFull;
            bool _isStarted;
            bool _inactive;
    };
}

#endif /* !KITCHEN_HPP_ */