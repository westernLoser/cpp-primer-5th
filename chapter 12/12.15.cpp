/*
  author : szz
  date : 2019/07/04
*/
#include<iostream>
#include<memory>
#include<string>

struct destination {
    std::string ip;
};

struct connection {
    destination des;
};

connection connect(destination *des) {
    std::cout << des->ip << " has connected." << std::endl; 
    return {*des};
}

void disconnect(connection con) {
    std::cout << con.des.ip << " has disconnected." << std::endl; 
}

void f(destination &d) {
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection *c) {
        disconnect(*c);
    });
    //use the connect
}

int main() {
    destination des{"10.10.10.10"};
    f(des);
    system("pause");
    return 0;
}