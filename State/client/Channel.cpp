#include "Channel.hpp"

Channel::Channel() : _limit(0), _inviteOnly(false), _topicRestricted(false)
{
    _key.clear();
}

Channel::Channel(const std::string &name):_name(name) 
{
}

Channel::~Channel()
{
}

void Channel::setTopic(const std::string &topic)
{
    _topic = topic;
}

void Channel::addMember(Client &client)
{

    std::cout << "From channel added !\n";
}

void Channel::removeMember(Client &client)
{
    std::cout << "From channel Removed !\n";
}

bool Channel::inviteOnly() const
{
    if (_inviteOnly)
        return true;
    return false;
}

bool Channel::topicRestricted() const
{
    if (_topicRestricted)
        return true;
    return false;
}

bool Channel::hasKey() const
{
    if (_key.empty())
        return false;
    return true;
}

bool Channel::hasLimit() const
{
    if (_limit != 0)
        return true;
    return false;
}

const std::string &Channel::getKey() const
{
    if (!hasKey())
    {
        throw "This channel has no key\n";
    }
    return _key;
}

size_t Channel::getLimit() const
{
    if (!hasLimit())
        throw "This channel has no key\n";
    return _limit;
}

const std::string &Channel::getName() const {
    return _name;
}