#include "edge_node.h"

using namespace std;

EdgeNode::EdgeNode(string endpoint, int weight, EdgeNode* next)
:endpoint_(endpoint), weight_(weight), next_(next)
{}

EdgeNode::~EdgeNode()
{}
