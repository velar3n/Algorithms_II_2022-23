#include <iostream>
#include <vector>
#include "setList.h"

setList::setList() {}

int setList::getSize() {
    return vec.size();
}

void setList::printSet() {
    std::cout<<"{ ";
    for(int i : vec) {
        std::cout<<i<<" ";
    }
    std::cout<<"}"<<std::endl;
}

void setList::insert(int x) {
    if(isInSet(x)) {
        return;
    }
    vec.push_back(x);
}

void setList::withdraw(int x) {
    for(int i=0; i<getSize(); i++) {
        if(x == vec[i]) {
            vec.erase(vec.begin()+i);
            return;
        }
    }
}

bool setList::isInSet(int x) {
    if(getSize() == 0) {
        return false;
    }
    for(int i : vec) {
        if(x == i) {
            return true;
        }
    }
    return false;
}

void setList::clearSet() {
    vec.clear();
}

setList setList::operator+(setList& obj) {
    setList newList;
    for(int i : vec) {
        newList.insert(i);
    }
    for(int i : obj.vec) {
        if(!isInSet(i)) {
            newList.insert(i);
        }
    }
    return newList;
}

setList setList::operator*(setList& obj) {
    setList newList;
    for(int i=0; i<getSize(); i++) {
        if(obj.isInSet(vec[i])) {
            newList.insert(vec[i]);
        }
    }
    return newList;
} 
      
setList setList::operator-(setList& obj) {
    setList newList;
    for(int i=0; i<getSize(); i++) {
        if(!obj.isInSet(vec[i])) {
            newList.insert(vec[i]);
        }
    }
    return newList;
}

bool setList::operator==(setList& obj) {
    if(getSize() != obj.getSize()) {
        return false;
    }
    for(int i=0; i<getSize(); i++) {
        if(!obj.isInSet(vec[i])) {
            return false;
        }
    }
    return true;
}

bool setList::operator<=(setList& obj) {
    if(getSize() < obj.getSize()) {
        return false;
    }
    for(int i=0; i<obj.getSize(); i++) {
        if(!isInSet(obj.vec[i])) {
            return false;
        }
    }
    return true;
}