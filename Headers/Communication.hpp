/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Communication
*/

#pragma once

#include "iostream"
#include <string>
#include <vector>
#include <memory>

#include <cstring>
#include "unistd.h"
#include <stdlib.h>

#include <sys/ipc.h> 
#include <sys/msg.h> 

namespace plazza {

    typedef struct message_t {
        long mesg_type; 
        char mesg_text[100]; 
    } message_s;

    class Communication {
        public:
            Communication();
            ~Communication();

            void closeCommunication();
            void sendCommunication(const char *, int);
            std::string receiveCommunication(int);

        protected:
            key_t key;
            int message_id;
            message_t message;
            int _id;
        private:
    };
}