#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <deque>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <vector>

class NotFound : public std::exception {
   public:
    const char* what() const throw() {
        return ("Element not found in the container");
    }
} not_found_exception;

template <typename T>
void easyfind(T & t, int i) {
    typename T::iterator it;
    it = std::find(t.begin(), t.end(), i);
    if (it == t.end()) throw not_found_exception;
}

#endif