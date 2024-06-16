#include <string>

enum CommandType {
    CONNECT,
    LIST,
    CD,
    GET,
    PUT,
    CACHE,
    HELP,
    EXIT,
};


struct Command {
    CommandType type;
    std::string filepath;
    // maybe add more attributes as needed
};
