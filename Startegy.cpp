/**
 * @file Strategy.cpp
 * @brief 
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Strategy.h"
#include "Users.h"


PlainTextStrategy::PlainTextStrategy() {
    // Simple strategy constructor
}

PlainTextStrategy::~PlainTextStrategy() {
    // Simple strategy destructor
}

std::string PlainTextStrategy::formatMessage(const std::string& message, const Users& fromUser) {
    return fromUser.getName() + ": " + message;
}

std::string PlainTextStrategy::getStrategyName() const {
    return "PlainText";
}


TimestampStrategy::TimestampStrategy() {
    // Timestamp strategy constructor
}

TimestampStrategy::~TimestampStrategy() {
    // Timestamp strategy destructor
}

std::string TimestampStrategy::formatMessage(const std::string& message, const Users& fromUser) {
    // Using placeholder timestamp due to library restrictions
    return "[TIMESTAMP] " + fromUser.getName() + ": " + message;
}

std::string TimestampStrategy::getStrategyName() const {
    return "Timestamp";
}


RichTextStrategy::RichTextStrategy() {
    // Rich text strategy constructor
}

RichTextStrategy::~RichTextStrategy() {
    // Rich text strategy destructor  
}

std::string RichTextStrategy::formatMessage(const std::string& message, const Users& fromUser) {
    // Using simple formatting due to library restrictions
    return "**" + fromUser.getName() + "** (online): " + message;
}

std::string RichTextStrategy::getStrategyName() const {
    return "RichText";
}