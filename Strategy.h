#ifndef MESSAGEFORMATTINGSTRATEGY_H
#define MESSAGEFORMATTINGSTRATEGY_H

#include <string>

// Forward declaration
class Users;

/**
 * @brief Abstract strategy interface for message formatting
 * Defines the contract for different message formatting algorithms
 */
class MessageFormattingStrategy {
public:
    virtual ~MessageFormattingStrategy() {}
    
    /**
     * @brief Format a message according to the strategy's algorithm
     * @param message The raw message content
     * @param fromUser The user sending the message
     * @return Formatted message string
     */
    virtual std::string formatMessage(const std::string& message, const Users& fromUser) = 0;
    
    /**
     * @brief Get strategy name for identification
     * @return String identifier for the strategy
     */
    virtual std::string getStrategyName() const = 0;
};

/**
 * @brief Plain text formatting strategy
 * Formats messages as: "Username: message"
 */
class PlainTextStrategy : public MessageFormattingStrategy {
public:
    PlainTextStrategy();
    virtual ~PlainTextStrategy();
    
    std::string formatMessage(const std::string& message, const Users& fromUser) override;
    std::string getStrategyName() const override;
};

/**
 * @brief Timestamp formatting strategy  
 * Formats messages as: "[TIMESTAMP] Username: message"
 * Note: Uses placeholder timestamp due to library restrictions
 */
class TimestampStrategy : public MessageFormattingStrategy {
public:
    TimestampStrategy();
    virtual ~TimestampStrategy();
    
    std::string formatMessage(const std::string& message, const Users& fromUser) override;
    std::string getStrategyName() const override;
};

/**
 * @brief Rich text formatting strategy
 * Formats messages as: "**Username** (online): message"
 * Note: Uses simple formatting due to library restrictions
 */
class RichTextStrategy : public MessageFormattingStrategy {
public:
    RichTextStrategy();
    virtual ~RichTextStrategy();
    
    std::string formatMessage(const std::string& message, const Users& fromUser) override;
    std::string getStrategyName() const override;
};

#endif //MESSAGEFORMATTINGSTRATEGY_H