#include "MessageManager.hpp"

bool MessageManager::addMessage(std::string str, bool isOwner){
    std::string date = getCurrentTime();
    Message message(str, date, isOwner);

    //Lock mutex before vector edit
    std::lock_guard<std::mutex> lock(messageListMutex);
    this->messageList.push_back(message);
    return true;
}

std::vector<Message> MessageManager::getMessages(){
    //Lock mutex before vector edit
    std::lock_guard<std::mutex> lock(messageListMutex);
    return messageList;
}

void MessageManager::resetList(){
    //Lock mutex before vector edit
    std::lock_guard<std::mutex> lock(messageListMutex);
    messageList.clear();
}

std::string MessageManager::getCurrentTime(){
    // Get current time as time_t
    auto now = std::time(nullptr);

    // Convert to tm structure for local time
    std::tm localTime{};
    localtime_s(&localTime, &now);    
    
    // Create a string stream and format the time
    std::ostringstream timeStream;
    timeStream << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return timeStream.str();
}