#include <iostream>

#include "easyfind.hpp"

#define CONTAINER_TYPE vector
// #define CONTAINER_TYPE list
// #define CONTAINER_TYPE deque

int main(void) {
    std::CONTAINER_TYPE<int> v;

    for (int i = 0; i < 25; i++) {
        v.push_back(i);
    }

    for (std::CONTAINER_TYPE<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    try {
		for (int i = 20; i < 30; i++){
			std::cout << i << ": ";
	        easyfind<std::CONTAINER_TYPE<int> >(v, i);
			std::cout << "Element found in the container" << std::endl;
		}
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}