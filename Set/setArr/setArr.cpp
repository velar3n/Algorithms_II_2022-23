#include <iostream>
#include "setArr.h"

setArr::setArr() {
    size = 0;
    table = new bool[universeSize];
    for(int i=0; i<universeSize; i++) {
        table[i] = false;
    }
}

bool setArr::checkRangeCorrectness(int x) {
    if((x > universeSize) || (x < 1)) {
        return false;
    }
    return true;
}


void setArr::insert(int x) {
    if(!checkRangeCorrectness(x)) {
        std::cout<<"Number "<<x<<" not in range"<<std::endl;
        return;
    }
    table[x-1] = true;
    size++;
    return;
}
		
void setArr::withdraw(int x) {
    if(!checkRangeCorrectness(x)) {
        std::cout<<"Number "<<x<<" not in range"<<std::endl;
        return;
    }
    table[x-1] = false;
    size--;
    return;
}
		
bool setArr::isInSet(int i) {
    if(!checkRangeCorrectness(i)) {
        std::cout<<"Number "<<i<<" not in range"<<std::endl;
        return false;
    }
    if(table[i-1] == true) {
        return true;
    }
    return false;
}

int setArr::getSize() {
    return size;
}
		
void setArr::clearSet() {
    for(int i=0; i<universeSize; i++) {
        table[i] = false;
    }
    size = 0;
}

void setArr::printSet() {
    std::cout<<"{ ";
    for(int i=0; i<universeSize; i++) {
        if(table[i] == true) {
            std::cout<<i+1<< " ";
        }
    }
    std::cout<<"}"<<std::endl;
}

setArr setArr::operator +(setArr& object) {
    setArr newSet;
    for(int i=0; i<universeSize; i++) {
        if(object.isInSet(i+1) || isInSet(i+1)) {
            newSet.table[i] = true;
        }
    }
    return newSet;
}

setArr setArr::operator *(setArr& object) {
    setArr newSet;
    for(int i=0; i<universeSize; i++) {
        if(object.isInSet(i+1) && isInSet(i+1)) {
            newSet.table[i] = true;
        }
    }
    return newSet;
}

setArr setArr::operator -(setArr& object) {
    setArr newSet;
    for(int i=0; i<universeSize; i++) {
        if(isInSet(i+1)) {
            if(!object.isInSet(i+1)) {
                newSet.table[i] = true;
            }
        }
    }
    return newSet;
}
		
bool setArr::operator ==(setArr& object) {
    if(getSize() != object.getSize()) {
        return false;
    }
    for(int i=0; i<universeSize; i++) {
        if(object.isInSet(i+1) != isInSet(i+1)) {
            return false;
        }
    }
    return true;
}

bool setArr::operator <=(setArr& object) {
    if(getSize() < object.getSize()) {
        return false;
    }
    for(int i=0; i<universeSize; i++) {
        if(object.isInSet(i+1)) {
            if(!isInSet(i+1)) {
                return false;
            }
        }
    }
    return true;
}


