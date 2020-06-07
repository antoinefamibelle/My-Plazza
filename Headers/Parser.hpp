/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include <stdbool.h>
#include "Pizza.hpp"
#include "Order.hpp"

namespace plazza {
    class Parser {
        public:
            Parser() {};
            ~Parser() {}
            plazza::Pizza *pack(std::string strToPack);
            std::string unpack(Pizza *PizzaClass);

            int parserLoop();
            PizzaSize getPackSize(std::string Size);
            PizzaType getPackName(std::string Name);
            bool IsPossibleToPack(std::string);
            Order getOrderClass() {return(this->_Send);};
        protected:
        private:
            void getEndOfOrder();
            void addOrderNamesOfPizzas();
            void addOrderSizeOfPizzas();
            void addOrderNumberOfPizzas();
            void checkEndOfOrderError();
            void getUserCommand();
        private:
            std::vector<std::string> _orderInput;
        private:
            std::vector<std::string> _pizzasNames;
            std::vector<std::string> _pizzasSize;
            std::vector<std::string> _pizzasNumber;
        private:
            std::string	_pizzasInfo[9] = {"regina", "fantasia", "margarita", "americana", "S", "M", "L", "XL", "XXL"};
        private:
            bool _Errors[3];
        private:
            int _Ret;
            bool _endOfCommand;
            Order _Send;
            std::vector<std::string>::iterator _actualWord;
    };
}

#endif /* !PARSER_HPP_ */