#include "Channel.hpp"

Channel::Channel() {
}

Channel::Channel(std::string &name) {
    this->name = name;
}

Channel::~Channel() {

}

void Channel::add_member(Client &client)
{
    (void)client;
    std::cout << "From channel added !\n";
}

void Channel::remove_member(Client &client)
{
    (void)client;
    std::cout << "From channel Removed !\n";
}

std::string Channel::getName() const {
    return name;
}