#include "Strategy.h"
#include "Users.h"

PlainTextStrategy::PlainTextStrategy() {
    // Simple strategy constructor
}

PlainTextStrategy::~PlainTextStrategy() {
    // Simple strategy destructor
}

string PlainTextStrategy::formatMessage(const string& message, const Users& fromUser) {
    return fromUser.getName() + ": " + message;
}

string PlainTextStrategy::getStrategyName() const {
    return "PlainText";
}


TimestampStrategy::TimestampStrategy() {
    // Timestamp strategy constructor
}

TimestampStrategy::~TimestampStrategy() {
    // Timestamp strategy destructor
}

string TimestampStrategy::formatMessage(const string& message, const Users& fromUser) {
    // Using placeholder timestamp due to library restrictions
    return "[TIMESTAMP] " + fromUser.getName() + ": " + message;
}

string TimestampStrategy::getStrategyName() const {
    return "Timestamp";
}


RichTextStrategy::RichTextStrategy() {
    // Rich text strategy constructor
}

RichTextStrategy::~RichTextStrategy() {
    // Rich text strategy destructor  
}

string RichTextStrategy::formatMessage(const string& message, const Users& fromUser) {
    // Using simple formatting due to library restrictions
    return "**" + fromUser.getName() + "** (online): " + message;
}

string RichTextStrategy::getStrategyName() const {
    return "RichText";
}