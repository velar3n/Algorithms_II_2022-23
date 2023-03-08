#include <iostream>
#include "setArr.h"

int main(){

    setArr mySetArr;

    mySetArr.insert(12);
    mySetArr.insert(122);
    mySetArr.insert(67);
    mySetArr.insert(67);
    mySetArr.insert(8);
    mySetArr.printSet();

    mySetArr.withdraw(12);
    mySetArr.withdraw(-12);
    mySetArr.withdraw(1);
    mySetArr.printSet();

    std::cout<<mySetArr.getSize()<<std::endl;

    setArr mySecondSet;
    setArr myReceivingSet;
    mySecondSet.insert(8);
    mySecondSet.insert(67);
    mySecondSet.insert(31);
    mySecondSet.insert(1);

    (mySetArr + mySecondSet).printSet();
    (mySetArr * mySecondSet).printSet();
    (mySetArr - mySecondSet).printSet();
    std::cout<<(mySetArr == mySecondSet)<<std::endl;
    std::cout<<(mySetArr == mySetArr)<<std::endl;
    std::cout<<(mySetArr <= mySecondSet)<<std::endl;

    std::cout<<(mySecondSet <= mySetArr)<<std::endl;

    mySetArr.clearSet();
    mySetArr.printSet();

	return 0;
}