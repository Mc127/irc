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

    Client b(name, Nname);
    b.join_channel(a);
    b.join_channel(c);
    b.leave_channel(a);
    b.join_channel(a);
    b.join_channel(a);
    b.leave_channel(c);
    b.leave_channel(a);
    b.leave_channel(a);


    return 0;
}