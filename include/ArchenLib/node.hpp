#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "func_container.hpp"

class Node
{
    Node* parent;
    std::vector<std::unique_ptr<Node>> nodes;
    
    void mainInit(void);
    void mainUpdate(void);
    // void mainDestroy(void);

    public:
        std::string name;

        FuncContainer init;
        FuncContainer update;
        FuncContainer destroy;

        Node* getParent() const;
        int size() const;
        // std::string path() const;

        template<typename N>
        N* newNode();
        Node* addNode(Node* node);

        template<typename N>
        N* getNode() const;
        Node* getNode(int index);
        void removeNode(int index);
    
    friend class Engine;
    friend class Node;
};

template<typename N>
N* Node::newNode() 
{
    auto node = std::make_unique<N>();
    nodes.push_back(std::move(node));
    return nodes.back().get();
}

template<typename N>
N* Node::getNode() const
{
    for(int i=0; i < nodes.size(); i++)
    {
        N* derivedNode = dynamic_cast<N*>(nodes.at(i).get());
        if(derivedNode != nullptr)
        {
            return derivedNode;
        }
    }
    return nullptr;
}