/**
 * @file Strategy.cpp
 * @brief Implementation file of message formatting strategies
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Strategy.h"
#include "Users.h"

/**
 * @brief Constructs a new PlainTextStrategy object
 */
PlainTextStrategy::PlainTextStrategy() {
    // Simple strategy constructor
}

/**
 * @brief Destroys the PlainTextStrategy object
 */
PlainTextStrategy::~PlainTextStrategy() {
    // Simple strategy destructor
}

/**
 * @brief Formats message as plain text
 * @param message The raw message content
 * @param fromUser The user sending the message
 * @return std::string Formatted message "Username: message"
 */
std::string PlainTextStrategy::formatMessage(const std::string& message, const Users& fromUser) {
    return fromUser.getName() + ": " + message;
}

/**
 * @brief Gets the strategy name
 * @return std::string "PlainText"
 */
std::string PlainTextStrategy::getStrategyName() const {
    return "PlainText";
}

/**
 * @brief Constructs a new TimestampStrategy object
 */
TimestampStrategy::TimestampStrategy() {
    // Timestamp strategy constructor
}

/**
 * @brief Destroys the TimestampStrategy object
 */
TimestampStrategy::~TimestampStrategy() {
    // Timestamp strategy destructor
}

/**
 * @brief Formats message with timestamp prefix
 * @param message The raw message content
 * @param fromUser The user sending the message
 * @return std::string Formatted message "[TIMESTAMP] Username: message"
 * @note Uses placeholder timestamp due to library restrictions
 */
std::string TimestampStrategy::formatMessage(const std::string& message, const Users& fromUser) {
    // Using placeholder timestamp due to library restrictions
    return "[TIMESTAMP] " + fromUser.getName() + ": " + message;
}

/**
 * @brief Gets the strategy name
 * @return std::string "Timestamp"
 */
std::string TimestampStrategy::getStrategyName() const {
    return "Timestamp";
}

/**
 * @brief Constructs a new RichTextStrategy object
 */
RichTextStrategy::RichTextStrategy() {
    // Rich text strategy constructor
}

/**
 * @brief Destroys the RichTextStrategy object
 */
RichTextStrategy::~RichTextStrategy() {
    // Rich text strategy destructor  
}

/**
 * @brief Formats message with rich text styling
 * @param message The raw message content
 * @param fromUser The user sending the message
 * @return std::string Formatted message "**Username** (online): message"
 * @note Uses simple formatting due to library restrictions
 */
std::string RichTextStrategy::formatMessage(const std::string& message, const Users& fromUser) {
    // Using simple formatting due to library restrictions
    return "**" + fromUser.getName() + "** (online): " + message;
}

/**
 * @brief Gets the strategy name
 * @return std::string "RichText"
 */
std::string RichTextStrategy::getStrategyName() const {
    return "RichText";
}