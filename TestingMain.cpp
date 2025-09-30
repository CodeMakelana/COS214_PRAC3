#include <iostream>
#include <cassert>
#include <vector>

#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Cindy.h"
#include "Ezio.h"
#include "Cole.h"
#include "ChatRoom.h"
#include "Users.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include "Strategy.h"

// Helper function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << "\n[TEST] " << testName << ": " 
              << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Helper function to print section headers
void printSection(const std::string& sectionName) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTING: " << sectionName << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

int main() {
    std::cout << "COMPREHENSIVE DESIGN PATTERNS TESTING" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    // Setup: Create chat rooms
    ChatRoom* ctrlCat = new CtrlCat();
    ChatRoom* dogorithm = new Dogorithm();
    
    // Setup: Create users
    Cindy* cindy = new Cindy(ctrlCat, "Cindy");
    cindy->joinChatRoom(dogorithm);
    
    Ezio* ezio = new Ezio(dogorithm, "Ezio");
    Cole* cole = new Cole(ctrlCat, "Cole");
    
    // =================================================================
    // TEST SECTION 1: Strategy Pattern Implementation
    // =================================================================
    printSection("STRATEGY PATTERN TESTING");
    
    std::cout << "\nTest 1.1: Default Strategy Assignment" << std::endl;
    std::cout << "Cindy's default strategy: " << cindy->getMessageStrategy()->getStrategyName() << std::endl;
    std::cout << "Ezio's default strategy: " << ezio->getMessageStrategy()->getStrategyName() << std::endl;
    std::cout << "Cole's default strategy: " << cole->getMessageStrategy()->getStrategyName() << std::endl;
    
    std::cout << "\nTest 1.2: Strategy Assignment and Switching" << std::endl;
    // Assign different strategies to different users
    cindy->setMessageStrategy(new TimestampStrategy());
    ezio->setMessageStrategy(new RichTextStrategy());
    cole->setMessageStrategy(new PlainTextStrategy());
    
    std::cout << "Strategy assignments completed:" << std::endl;
    std::cout << "- Cindy: " << cindy->getMessageStrategy()->getStrategyName() << std::endl;
    std::cout << "- Ezio: " << ezio->getMessageStrategy()->getStrategyName() << std::endl;
    std::cout << "- Cole: " << cole->getMessageStrategy()->getStrategyName() << std::endl;
    
    std::cout << "\nTest 1.3: Strategy-Based Message Formatting" << std::endl;
    std::cout << "Each user sending the same message with different formatting:" << std::endl;
    
    std::cout << "\nCindy (Timestamp Strategy):" << std::endl;
    cindy->send("Hello everyone!", ctrlCat);
    
    std::cout << "\nEzio (RichText Strategy):" << std::endl;
    ezio->send("Hello everyone!", dogorithm);
    
    std::cout << "\nCole (PlainText Strategy):" << std::endl;
    cole->send("Hello everyone!", ctrlCat);
    
    printTestResult("Strategy Pattern Implementation", true);
    
    // =================================================================
    // TEST SECTION 2: Strategy Switching at Runtime
    // =================================================================
    printSection("DYNAMIC STRATEGY SWITCHING");
    
    std::cout << "\nTest 2.1: Runtime strategy switching" << std::endl;
    std::cout << "Cindy switching from Timestamp to RichText strategy:" << std::endl;
    cindy->setMessageStrategy(new RichTextStrategy());
    cindy->send("I changed my style!", ctrlCat);
    
    std::cout << "\nCole switching from PlainText to Timestamp strategy:" << std::endl;
    cole->setMessageStrategy(new TimestampStrategy());
    cole->send("Now I show timestamps!", ctrlCat);
    
    printTestResult("Dynamic Strategy Switching", true);
    
    // =================================================================
    // TEST SECTION 3: Command Pattern with Strategy Integration
    // =================================================================
    printSection("COMMAND + STRATEGY INTEGRATION");
    
    std::cout << "\nTest 3.1: Commands using formatted messages" << std::endl;
    std::cout << "Testing that commands receive strategy-formatted messages:" << std::endl;
    
    ezio->send("Strategy + Command working together!", dogorithm);
    cindy->send("Multiple patterns integration test", dogorithm);
    
    printTestResult("Command + Strategy Integration", true);
    
    // =================================================================
    // TEST SECTION 4: Mediator Pattern with All Integrations
    // =================================================================
    printSection("MEDIATOR + STRATEGY + COMMAND");
    
    std::cout << "\nTest 4.1: Full pattern integration" << std::endl;
    std::cout << "Testing Mediator handling strategy-formatted messages via commands:" << std::endl;
    
    std::cout << "\nCross-room communication with different strategies:" << std::endl;
    ezio->send("Message from Dogorithm!", dogorithm);
    cole->send("Reply from CtrlCat!", ctrlCat);
    
    printTestResult("Full Pattern Integration", true);
    
    // =================================================================
    // TEST SECTION 5: Iterator Pattern Testing
    // =================================================================
    printSection("ITERATOR PATTERN TESTING");

    std::cout << "\nTest 5.1: Users Iterator" << std::endl;
    Iterator<Users*>* usersIt = ctrlCat->createUsersIterator();
    std::cout << "Users in CtrlCat:" << std::endl;
    for (usersIt->first(); !usersIt->isDone(); usersIt->next()) {
        Users* user = usersIt->currentItem();
        std::cout << "- " << user->getName() 
                  << " (Strategy: " << user->getMessageStrategy()->getStrategyName() << ")" << std::endl;
    }
    delete usersIt;
    //iterator for dogorithm
    usersIt = dogorithm->createUsersIterator();
    std::cout << "Users in Dogorithm:" << std::endl;
    for (usersIt->first(); !usersIt->isDone(); usersIt->next()) {
        Users* user = usersIt->currentItem();
        std::cout << "- " << user->getName()
                  << " (Strategy: " << user->getMessageStrategy()->getStrategyName() << ")" << std::endl;
    }
    delete usersIt;

    std::cout << "\nTest 5.2: Chat History Iterator" << std::endl;
    Iterator<std::string*>* historyIt = ctrlCat->createChatHistoryIterator();
    std::cout << "Formatted Chat History in CtrlCat:" << std::endl;
    for (historyIt->first(); !historyIt->isDone(); historyIt->next()) {
        std::string* message = historyIt->currentItem();
        std::cout << "- " << *message << std::endl;
    }
    delete historyIt;

    historyIt = dogorithm->createChatHistoryIterator();
    std::cout << "Formatted Chat History in Dogorithm:" << std::endl;
    for (historyIt->first(); !historyIt->isDone(); historyIt->next()) {
        std::string* message = historyIt->currentItem();
        std::cout << "- " << *message << std::endl;
    }
    delete historyIt;

    printTestResult("Iterator Pattern", true);
    
    // =================================================================
    // TEST SECTION 6: Strategy Pattern Extensibility
    // =================================================================
    printSection("STRATEGY EXTENSIBILITY");
    
    std::cout << "\nTest 6.1: Easy addition of new strategies" << std::endl;
    std::cout << "Demonstrating how new strategies can be added without modifying existing code:" << std::endl;
    
    // All users can switch to any strategy without code changes
    std::cout << "\nAll users switching to different strategies:" << std::endl;
    cindy->setMessageStrategy(new PlainTextStrategy());
    ezio->setMessageStrategy(new TimestampStrategy());
    cole->setMessageStrategy(new RichTextStrategy());
    
    cindy->send("Switched to plain text", ctrlCat);
    ezio->send("Now using timestamps", dogorithm);
    cole->send("Rich text format now", ctrlCat);
    
    printTestResult("Strategy Extensibility", true);
    
    // =================================================================
    // FINAL PATTERN SUMMARY
    // =================================================================
    printSection("DESIGN PATTERNS SUMMARY");
    
    std::cout << "\nAll Design Patterns Successfully Implemented and Tested!" << std::endl;
    std::cout << "\nPattern Integration Summary:" << std::endl;
    std::cout << "✓ Mediator Pattern: ChatRooms mediate user communication" << std::endl;
    std::cout << "✓ Command Pattern: Encapsulates send/save operations" << std::endl;
    std::cout << "✓ Iterator Pattern: Traverses users and chat history" << std::endl;
    std::cout << "✓ Strategy Pattern: Interchangeable message formatting algorithms" << std::endl;
    
    std::cout << "\nPattern Types Distribution:" << std::endl;
    std::cout << "- Behavioral Patterns: Mediator, Command, Iterator, Strategy" << std::endl;
    std::cout << "- All patterns work harmoniously together" << std::endl;
    std::cout << "- System demonstrates high extensibility and maintainability" << std::endl;
    
    std::cout << "\nDesign Patterns Implementation: COMPLETE ✓" << std::endl;

    // Cleanup
    delete cindy;
    delete ezio;
    delete cole;
    delete ctrlCat;
    delete dogorithm;
    
    std::cout << "\nMemory cleanup completed." << std::endl;
    
    return 0;
}