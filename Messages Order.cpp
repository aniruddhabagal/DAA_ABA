#include <chrono>

class Message {
    string msg;
    chrono::time_point<chrono::high_resolution_clock> sent_at;
public: 
    Message(string msg): msg(msg) { sent_at = chrono::high_resolution_clock::now(); }
    const string& get_text() {
        return msg;
    }

    friend bool operator <(Message& left, Message& right) {
        return left.sent_at < right.sent_at;
    }
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text);
    }
};



