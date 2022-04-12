#include "FANode.h"


std::string FANode::getName() const
{
    return name;
}

void FANode::setName(std::string name)
{
    this->name = name;
}


FANode::FANode(std::string name) {
    this->name = name;
}


int FANode::getID() const
{
    return ID;
}

void FANode::setID(int ID)
{
    this->ID = ID;
}


