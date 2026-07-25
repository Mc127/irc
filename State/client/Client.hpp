#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Channel.hpp"
#include <iostream>

class Channel;

class Client
{
private:
    // ===== Connection =====
    int _fd;

    // ===== Registration =====
    bool _registered;
    bool _passAccepted;

    // ===== User =====
    std::string _nickname;
    std::string _username;
    std::string _realname;
    std::string _hostname;

    // ===== Network =====
    std::string _recvBuffer;
    std::string _sendBuffer;

    // ===== Joined Channels =====
    std::vector<Channel*> _channels;

public:
    Client();
    Client(int fd);
    Client(const Client &other);
    Client &operator=(const Client &other);
    ~Client();

    //==========================
    // Getters
    //==========================

    int getFd() const;

    const std::string &getNickname() const;
    const std::string &getUsername() const;
    const std::string &getRealname() const;
    const std::string &getHostname() const;

    bool isRegistered() const;
    bool passAccepted() const;

    const std::vector<Channel*> &getChannels() const;

    const std::string &getRecvBuffer() const;
    const std::string &getSendBuffer() const;

    //==========================
    // Setters
    //==========================

    void setNickname(const std::string &nick);
    void setUsername(const std::string &user);
    void setRealname(const std::string &realname);
    void setHostname(const std::string &hostname);

    void setRegistered(bool value);
    void setPassAccepted(bool value);

    //==========================
    // Buffers
    //==========================

    void appendRecvBuffer(const std::string &data);
    void appendSendBuffer(const std::string &data);

    bool getNextCommand(std::string &command);

    void clearSendBuffer();

    //==========================
    // Channels
    //==========================

    void joinChannel(Channel &channel);
    void leaveChannel(Channel &channel);

    bool isInChannel(const std::string &name) const;

    Channel *findChannel(const std::string &name) const;
};