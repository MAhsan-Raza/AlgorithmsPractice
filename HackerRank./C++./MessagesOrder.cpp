

class Message {
public: 
    Message(const string& msg, const int seq)
        : mMsg(msg), mSeq(seq) {}
    const string& get_text() {
        return mMsg;
    }

    int get_seq() const {
        return mSeq;
    }

    bool operator < (const Message& msg)
    {
        return this->mSeq < msg.get_seq();
    }

private:
    string mMsg;
    int mSeq;
};

class MessageFactory {
public:
    MessageFactory() : mSeq(0) {}
    Message create_message(const string& text) {
        return Message(text, mSeq++);
    }

private:
    int mSeq;
};

