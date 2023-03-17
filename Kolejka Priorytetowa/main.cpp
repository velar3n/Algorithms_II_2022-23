#include <iostream>
#include "priority_queue.h"

int main(){

	PriorityQueue myqueue = PriorityQueue(100);

	myqueue.insert(1);
	myqueue.insert(2);
	myqueue.insert(33);
	myqueue.insert(4);
    myqueue.insert(4);
    myqueue.print();

	std::cout<<myqueue.getRoot()<<std::endl;

	std::cout<<myqueue.popRoot()<<std::endl;
    std::cout<<myqueue.popRoot()<<std::endl;
    std::cout<<myqueue.popRoot()<<std::endl;
    std::cout<<myqueue.popRoot()<<std::endl;
    std::cout<<myqueue.popRoot()<<std::endl;
	std::cout<<myqueue.popRoot()<<std::endl;

	return 0;
}