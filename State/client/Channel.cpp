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

void Channel::setInviteOnly(bool value)
{
    _inviteOnly = value;
}

void Channel::setTopicRestricted(bool value)
{
    _topicRestricted = value;
}

void Channel::setKey(const std::string &key)
{
    _key = key;
}
void Channel::setLimit(size_t limit)
{
    _limit = limit;
}

void Channel::removeKey()
{
    _key.clear();
}

void Channel::removeLimit()
{
    _limit = 0;
}

void Channel::addMember(Client &client)
{
    ///passkey handling
    // invit only
    // limit
    if (isMember(&client))
        throw std::runtime_error("Error : you already a member of this channel");
    if (inviteOnly())
    {
        
    }
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

bool Channel::empty() const
{
    if (_members.size() == 0 || _invited.size() == 0)
        return true;
    return false;
}

size_t Channel::size() const
{
    if (inviteOnly())
        return _invited.size();
    return _members.size();
}

bool Channel::isMember(Client *client) const
{
    if (std::find(_invited.begin(), _invited.end(), client) != _invited.end())
        return true;
    return false;
}

bool Channel::isOperator(Client *client) const
{
    if (std::find(_operators.begin(), _operators.end(), client) != _operators.end())
        return true;
    return false;
}

bool Channel::isInvited(Client *client) const
{
    if (std::find(_members.begin(), _members.end(), client) != _members.end())
        return true;
    return false;
}

const std::string &Channel::getName() const 
{
    return _name;
}