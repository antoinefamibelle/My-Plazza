/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Order
*/

#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <vector>
#include <string>
#include <algorithm>


namespace plazza {
    class Order {
        public:
            Order();
            ~Order();

            const std::vector<std::string> getOrder() const;
            void addOrder(std::string, std::string, std::string);
            void delOrder(std::string order);
        protected:
        private:
            std::vector<std::string> _order;
    };
}

#endif /* !ORDER_HPP_ */
