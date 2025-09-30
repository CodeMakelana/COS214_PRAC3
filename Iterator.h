/**
 * @file Iterator.h
 * @brief Iterator pattern implementations for traversing collections
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include <list>

class Users;

/**
 * @class Iterator
 * @brief Abstract iterator interface for traversing collections
 * @tparam T Type of elements being iterated over
 * Provides standard interface for accessing elements without exposing
 * underlying collection structure.
 */
template <typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    
    /**
     * @brief Moves iterator to first element
     * @return void
     */
    virtual void first() = 0;
    
    /**
     * @brief Moves iterator to next element
     * @return void
     */
    virtual void next() = 0;
    
    /**
     * @brief Checks if iteration is complete
     * @return bool True if no more elements, false otherwise
     */
    virtual bool isDone() = 0;
    
    /**
     * @brief Gets current element
     * @return T Current element in iteration
     */
    virtual T currentItem() = 0;
};

/**
 * @class UsersIterator
 * @brief Concrete iterator for user lists
 * @tparam Users Type of user objects
 * 
 * Iterates over a list of user pointers using STL list iterators.
 */
template <class Users>
class UsersIterator : public Iterator<Users*> {
private:
    typename std::list<Users*>::iterator current;  ///< Current position iterator
    typename std::list<Users*>::iterator end;      ///< End of collection iterator  
    typename std::list<Users*>::iterator begin;    ///< Beginning of collection iterator
public:
    /**
     * @brief Constructs iterator for user list
     * @param usersList List of users to iterate over
     */
    UsersIterator(std::list<Users*>& usersList) {
        begin = usersList.begin();
        end = usersList.end();
        current = begin;
    }
    
    /**
     * @brief Destructor
     */
    ~UsersIterator() {}
    
    /**
     * @brief Moves iterator to first element
     * @return void
     */
    void first() override {
        current = begin;
    }
    
    /**
     * @brief Moves iterator to next element
     * @return void
     */
    void next() override {
        if (!isDone()) {
            ++current;
        }
    }
    
    /**
     * @brief Checks if iteration is complete
     * @return bool True if at end, false otherwise
     */
    bool isDone() override {
        return current == end;
    }
    
    /**
     * @brief Gets current user
     * @return Users* Pointer to current user, nullptr if done
     */
    Users* currentItem() override {
        return isDone() ? nullptr : *current;
    }
};

/**
 * @class ChatHistoryIterator
 * @brief Concrete iterator for chat message history
 * 
 * Iterates over a list of chat message strings using STL list iterators.
 */
class ChatHistoryIterator : public Iterator<std::string*> {
private:
    std::list<std::string>::iterator curr;  ///< Current position iterator
    std::list<std::string>::iterator end;   ///< End of collection iterator
    std::list<std::string>::iterator begin; ///< Beginning of collection iterator
public:
    /**
     * @brief Constructs iterator for chat history
     * @param chatHistoryList List of messages to iterate over
     */
    ChatHistoryIterator(std::list<std::string>& chatHistoryList) {
        begin = chatHistoryList.begin();
        end = chatHistoryList.end();
        curr = begin;
    }
    
    /**
     * @brief Destructor
     */
    ~ChatHistoryIterator() {}
    
    /**
     * @brief Moves iterator to first element
     * @return void
     */
    void first() override {
        curr = begin;
    }
    
    /**
     * @brief Moves iterator to next element
     * @return void
     */
    void next() override {
        if (!isDone()) {
            ++curr;
        }
    }
    
    /**
     * @brief Checks if iteration is complete
     * @return bool True if at end, false otherwise
     */
    bool isDone() override {
        return curr == end;
    }
    
    /**
     * @brief Gets current message
     * @return std::string* Pointer to current message, nullptr if done
     */
    std::string* currentItem() override {
        if (isDone()) {
            return nullptr;
        }
        return &(*curr);
    }
};

#endif //ITERATOR_H