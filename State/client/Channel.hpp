#pragma once

#include <string>
#include <vector>
#include "Client.hpp"
#include <iostream>
#include <map>

class Client;

class Channel
{
private:
    // ===== Basic =====
    std::string _name;
    std::string _topic;

    // ===== Members =====
    std::vector<Client*> _members;
    std::vector<Client*> _operators;
    std::vector<Client*> _invited;

    // Fast lookup
    std::map<std::string, Client*> _membersByNick;
    std::map<int, Client*> _membersByFd;

    // ===== Modes =====
    bool _inviteOnly;
    bool _topicRestricted;

    std::string _key;
    size_t _limit;

public:
    Channel();
    Channel(const std::string &name);
    ~Channel();

    //==========================
    // Basic
    //==========================

    const std::string &getName() const;
    const std::string &getTopic() const;

    bool inviteOnly() const;
    bool topicRestricted() const;

    bool hasKey() const;
    bool hasLimit() const;

    const std::string &getKey() const;
    size_t getLimit() const;

    bool empty() const;
    size_t size() const;

    //==========================
    // Member lists
    //==========================

    const std::vector<Client*> &getMembers() const;
    const std::vector<Client*> &getOperators() const;

    //==========================
    // Searching
    //==========================

    Client *findMember(const std::string &nick) const;
    Client *findMember(int fd) const;

    //==========================
    // Checks
    //==========================

    bool isMember(Client *client) const;
    bool isOperator(Client *client) const;
    bool isInvited(Client *client) const;

    //==========================
    // Member management
    //==========================

    void addMember(Client &client);
    void removeMember(Client &client);

    void addOperator(Client *client);
    void removeOperator(Client *client);

    void addInvited(Client *client);
    void removeInvited(Client *client);

    //==========================
    // Topic
    //==========================

    void setTopic(const std::string &topic);

    //==========================
    // Modes
    //==========================

    void setInviteOnly(bool value);

    void setTopicRestricted(bool value);

    void setKey(const std::string &key);
    void removeKey();

    void setLimit(size_t limit);
    void removeLimit();

    //==========================
    // Communication
    //==========================

    void broadcast(const std::string &message);

};