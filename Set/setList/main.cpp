#include <iostream>
#include "setList.h"

int main(){

    setList mySetList;

    mySetList.insert(12);
    mySetList.insert(122);
    mySetList.insert(67);
    mySetList.insert(67);
    mySetList.insert(8);
    mySetList.printSet();

    mySetList.withdraw(12);
    mySetList.withdraw(-12);
    mySetList.withdraw(1);
    mySetList.printSet();

    std::cout<<mySetList.getSize()<<std::endl;

    setList mySecondSet;
    setList myReceivingSet;
    mySecondSet.insert(8);
    mySecondSet.insert(67);
    mySecondSet.insert(31);
    mySecondSet.insert(1);

    (mySetList + mySecondSet).printSet();
    (mySetList * mySecondSet).printSet();
    (mySetList - mySecondSet).printSet();
    std::cout<<(mySetList == mySecondSet)<<std::endl;
    std::cout<<(mySetList == mySetList)<<std::endl;
    std::cout<<(mySetList <= mySecondSet)<<std::endl;

    mySetList.withdraw(122);
    std::cout<<(mySecondSet <= mySetList)<<std::endl;

    mySetList.clearSet();
    mySetList.printSet();

	return 0;
}