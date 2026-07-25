#include "Client.hpp"

Client::Client()
{
}

Client::Client(int fd):_fd(fd)
{
}


/////// Setters //////////
void Client::setNickname(const std::string &nick)
{
    _nickname = nick;
}
void Client::setUsername(const std::string &user)
{
    _username = user;
}
void Client::setRealname(const std::string &realname)
{
    _realname = realname;
}
void Client::setHostname(const std::string &hostname)
{
    _hostname = hostname;
}
void Client::setRegistered(bool value)
{
    _registered = value;
}
void Client::setPassAccepted(bool value)
{
    _passAccepted = value;
}
//////////// Getters ///////////

int Client::getFd() const
{
    return _fd;
}

const std::string &Client::getNickname() const
{
    return _nickname;
}
const std::string &Client::getUsername() const
{
    return _username;
}
const std::string &Client::getRealname() const
{
    return _realname;
}
const std::string &Client::getHostname() const
{
    return _hostname;
}

bool Client::isRegistered() const
{
    return _registered;
}
bool Client::passAccepted() const
{
    return _passAccepted;
}

const std::vector<Channel*> &Client::getChannels() const
{
    return _channels;
}

const std::string &Client::getRecvBuffer() const
{
    return _recvBuffer;
}
const std::string &Client::getSendBuffer() const
{
    return _sendBuffer;
}

void Client::joinChannel(Channel &channel)
{
    if (std::find(_channels.begin(), _channels.end(), &channel) == _channels.end())
    {
        channel.addMember(*this);
        this->_channels.push_back(&channel);
        std::cout << _username <<" joined successfully #" << channel.getName() << "\n";
    }
    else
        std::cout << "You already a memeber of #" << channel.getName() << "\n";
}

void Client::leaveChannel(Channel &channel)
{
    std::vector<Channel*>::iterator it = std::find(_channels.begin(), _channels.end(), &channel);
    if (it != _channels.end())
    {
        channel.removeMember(*this);
        this->_channels.erase(it);
        std::cout << _username <<" Removed successfully  from #" << channel.getName() << "\n";
        std::cout << "u still in " << _channels.size() << " channel\n";
    }
    else
        std::cout << "You're not already a memeber of #" << channel.getName() << "\n";
}

Client::~Client()
{
}