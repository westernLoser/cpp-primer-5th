/*
  author : szz
  date : 2019/07/10
*/
#ifndef C_13_34_H
#define C_13_34_H

#include<string>
#include<set>

class Folder;
class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = ""): contents(str) { }
    Message(const Message&);
    Message(Message&&);
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder*);
    void removeFolder(Folder*);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_folders(const Message&);
    void remove_from_folders();
    void move_Folders(Message*);
};


class Folder {
    friend class Message;
    friend void swap(Folder &lhs, Folder &rhs);
public:
    Folder() { }
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void addMsg(Message*);
    void removeMsg(Message*);
private:
    std::set<Message*> msgs;
    void add_to_msgs(const Folder&);
    void remove_from_msgs();
};

void Folder::addMsg(Message *m) {
    msgs.insert(m);
}

void Folder::removeMsg(Message *m) {
    msgs.erase(m);
}

void Folder::add_to_msgs(const Folder &f) {
    for (auto m : f.msgs) {
        m->addFolder(this);
    }
}

void Folder::remove_from_msgs() {
    for (auto m : msgs) {
        m->removeFolder(this);
    }
}

Folder::Folder(const Folder &f): msgs(f.msgs) {
    add_to_msgs(f);
}

Folder& Folder::operator=(const Folder &f) {
    remove_from_msgs();
    msgs = f.msgs;
    add_to_msgs(f);
    return *this;
}

Folder::~Folder() {
    remove_from_msgs();
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    lhs.remove_from_msgs();
    rhs.remove_from_msgs();
    swap(lhs.msgs, rhs.msgs);
    for (auto m : lhs.msgs) {
        m->addFolder(&lhs);
    }
    for (auto m : rhs.msgs) {
        m->addFolder(&rhs);
    }
}

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::removeFolder(Folder *f) {
    folders.erase(f);
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.removeMsg(this);
}

void Message::add_to_folders(const Message &m) {
    for (auto f : m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_folders() {
    for (auto f : folders) {
        f->removeMsg(this);
    }
}

void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->removeMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(const Message &m): contents(m.contents), folders(m.folders) {
    add_to_folders(m);
}

Message::Message(Message &&m): contents(std::move(m.contents)) {
    move_Folders(&m);
}

Message& Message::operator=(const Message &rhs) {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

Message::~Message() {
    remove_from_folders();
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f : lhs.folders) {
        f->removeMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->removeMsg(&rhs);
    }
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto f : lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->addMsg(&rhs);
    }
}



#endif