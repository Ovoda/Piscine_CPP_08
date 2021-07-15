#include <iostream>

#include "Span.hpp"

#define SIZE 10

int randomNumber(void) { return (std::rand() % SIZE); }

std::vector<int> createRandomVector(unsigned int size) {
    std::vector<int> vector(size);
    std::srand(std::time(0));
    std::generate(vector.begin(), vector.end(), randomNumber);
    return (vector);
}

int main(void) {
    std::vector<int> vector = createRandomVector(SIZE);
    Span span(vector.begin(), vector.end());

    std::cout << std::endl;
    std::cout << "shortest span : " << span.shortestSpan() << std::endl;
    std::cout << "longest span  : " << span.longestSpan() << std::endl;
    std::cout << std::endl << "Span :	 ";
    span.printSpan();
    return (0);
}