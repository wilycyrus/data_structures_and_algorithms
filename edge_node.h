// EdgeNode.h
#include <string>

class EdgeNode
{
    public:
        EdgeNode(std::string endpoint, int weight = 1, EdgeNode* next = nullptr);
        ~EdgeNode();
        std::string endpoint_;
        int weight_;
        EdgeNode* next_;
};
