#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    // Constructors
    MutantStack(void) {}
    MutantStack(MutantStack const& src) { *this = src; }

    // Destructors
    ~MutantStack() {}

    // Operator Overload
    MutantStack& operator=(MutantStack const& rhs) {
        static_cast<std::stack<T> >(*this) = static_cast<std::stack<T> >(rhs);
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

    iterator begin(void) { return std::stack<T>::c.begin(); }
    iterator end(void) { return std::stack<T>::c.end(); }
};

#endif