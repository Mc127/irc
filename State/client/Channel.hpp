#pragma once

#include "Client.hpp"
#include <iostream>
class Client;

class Channel
{
    private:
        std::string name;

    public:
        Channel();
        Channel(std::string &name);
        ~Channel();
        void add_member(Client &client);
        void remove_member(Client &client);
        std::string getName() const;
};