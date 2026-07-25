#include "Client.hpp"
#include "Channel.hpp"

int main()
{
    std::string _name("1337");
    Channel a(_name);
    _name = "ai";
    Channel c(_name);

    std::string name("kimo");
    std::string Nname("kimo1");

    Client b;
    b.setNickname(Nname);
    b.setUsername(name);
    b.joinChannel(a);
    b.joinChannel(c);
    b.leaveChannel(a);
    b.joinChannel(a);
    b.joinChannel(a);
    b.leaveChannel(c);
    b.leaveChannel(a);
    b.leaveChannel(a);


    return 0;
}