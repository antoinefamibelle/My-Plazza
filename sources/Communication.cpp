/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Communication
*/

#include "Communication.hpp"

plazza::Communication::Communication()
{
    this->key = ftok("progfile", 65);
    this->message_id = msgget(key, 0666 | IPC_CREAT);
}

plazza::Communication::~Communication()
{
    msgctl(message_id, IPC_RMID, nullptr);
}

void plazza::Communication::closeCommunication()
{
    msgctl(message_id, IPC_RMID, nullptr);
}

void plazza::Communication::sendCommunication(const char *text, int id)
{
    this->_id = id;
    strcpy(this->message.mesg_text, text);
    this->message.mesg_type = id;
    msgsnd(this->message_id, &this->message, sizeof(this->message), 0);
}

std::string plazza::Communication::receiveCommunication(int id)
{
    this->_id = id;
    msgrcv(this->message_id, &this->message, sizeof(this->message), this->_id, 0);
    return std::string(this->message.mesg_text);
}