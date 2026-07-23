#pragma once

#include "Channel.hpp"
#include <iostream>
#include <list>
#include <algorithm>

class Channel;

class Client
{
    private:
        std::string nickname;
        std::string username;
        int socket;
        std::list<Channel*> channels;
        std::string buffer;
        std::string msg;
        bool is_operator;
        //last_active
    public:
        Client();
        void print();
        Client(std::string &n, std::string &u);
        Client(const Client& other);
        Client &operator=(const Client &other);
        ~Client();
        void join_channel(Channel &Channel);
        void leave_channel(Channel &Channel);
        void send_message(std::string message);
        void receive_message();
        void disconnect();
        void isOperator(bool status);
        void update_last_active();
};
