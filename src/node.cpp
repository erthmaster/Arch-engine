#include <memory>
#include <sstream>
#include "logging.hpp"
#include "node.hpp"

void Node::mainInit()
{
    for (int i = 0; i < size(); i++)
    {
        nodes[i]->mainInit();
        nodes[i]->init.runAll();
    }
}

void Node::mainUpdate()
{
    this->update.runAll();
    for (int i = 0; i < size(); i++)
    {
        nodes[i]->mainUpdate();
        nodes[i]->update.runAll();
    }
}

int Node::size() const
{
    return nodes.size();
}

Node* Node::getParent() const
{
    return parent;
}

Node* Node::addNode(Node* node)
{
    Log::info("NODE", "Adding '" + node->name + "' to " + name);

    std::unique_ptr<Node> ptr = std::unique_ptr<Node>(node);
    nodes.push_back(std::move(ptr));
    node->parent = this;
    return ptr.get();
}

Node* Node::getNode(int index)
{
    // add log
    return nodes.at(index).get();
}

void Node::removeNode(int index)
{
    if(!index == 0) // add log
    nodes.erase(nodes.begin()+index);
}