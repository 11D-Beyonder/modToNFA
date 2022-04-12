#pragma once
#include<string>
class FANode {
private:
    int ID;
	std::string name;
public:
    FANode(std::string name);
    FANode(int ID) {
        this->ID = ID;
    }
    //жидиаЁгкКХ
    bool operator<(const FANode& o)const {
        return ID < o.ID;
    }
public:
    //getter setter
    int getID() const;
    void setID(int ID);

    std::string getName() const;
    void setName(std::string name);

};