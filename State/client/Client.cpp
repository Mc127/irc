#include "Client.hpp"

Client::Client() : nickname(""), username(""), socket(-1), is_operator(false) 
{
}
Client::Client(const Client& other)
{
    this->nickname = other.nickname;
    this->username = other.username;
    this->socket = other.socket;
    this->channels = other.channels;
    this->is_operator = other.is_operator;
}
Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        this->nickname = other.nickname;
        this->username = other.username;
        this->socket = other.socket;
        this->channels = other.channels;
        this->is_operator = other.is_operator;
    }
    return *this;
}

Client::Client(std::string &n, std::string &u)
{
    nickname = n;
    username = u;
}

void Client::join_channel(Channel &channel)
{
    if (std::find(channels.begin(), channels.end(), &channel) == channels.end())
    {
        channel.add_member(*this);
        this->channels.push_back(&channel);
        std::cout << username <<" joined successfully #" << channel.getName() << "\n";
    }
    else
        std::cout << "You already a memeber of #" << channel.getName() << "\n";
}

void Client::leave_channel(Channel &channel)
{
    std::list<Channel*>::iterator it = std::find(channels.begin(), channels.end(), &channel);
    if (it != channels.end())
    {
        channel.remove_member(*this);
        this->channels.erase(it);
        std::cout << username <<" Removed successfully  from #" << channel.getName() << "\n";
        std::cout << "u still in " << channels.size() << " channel\n";
    }
    else
        std::cout << "You're not already a memeber of #" << channel.getName() << "\n";
}

Client::~Client()
{
}