#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include <list>
using namespace std;

class Users;

//Iterator class
template <typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual void first () = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual T currentItem() = 0;
};

//UsersIterator class
class Users;

template <class Users>
class UsersIterator : public Iterator<Users*> {
    private:
    typename list<Users*>::iterator current;
    typename list<Users*>::iterator end;
    typename list<Users*>::iterator begin;

    public:
    UsersIterator(list<Users*>& usersList)
    {
        begin = usersList.begin();
        end = usersList.end();
        current = begin;
    }

    ~UsersIterator() {
        // No dynamic memory to clean up
    }
    void first() override {
        current = begin;
    }
    void next() override
    {
        if(!isDone())
        {
            ++current;
        }
    }
    bool isDone() override {
        return current == end;
    }
    Users* currentItem() override {
        return isDone() ? nullptr : *current;
    }
};

//ChatHistoryIterator class
class ChatHistoryIterator : public Iterator<string*> {
private:
    list<string>::iterator curr;
    list<string>::iterator end;
    list<string>::iterator begin;
public:
    ChatHistoryIterator(list<string>& chatHistoryList) {
        begin = chatHistoryList.begin();
        end = chatHistoryList.end();
        curr = begin;
    }
    ~ChatHistoryIterator() {
        // No dynamic memory to clean up
    }
    void first() override {
        curr = begin;
    }
    void next() override {
        if (!isDone()) {
            ++curr;
        }
    }
    bool isDone() override {
        return curr == end;
    }
    string* currentItem() override {
        if (isDone()) {
            return nullptr;
        }
        return &(*curr);
    }
};

#endif //ITERATOR_H