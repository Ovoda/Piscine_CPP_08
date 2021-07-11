#include "Span.hpp"

// Constructors
Span::Span( void ) {}

Span::Span( Span const & src ) {*this = src;}

Span::Span( unsigned int N) : _N(N) {}

Span::Span(std::vector<int>::iterator a, std::vector<int>::iterator b) {
    _v = std::vector<int>(a, b);
    _N = _v.size();
}


// Destructor
Span::~Span() {}

// Operator Overload
Span    &Span::operator=(Span const & rhs) {
    _N = rhs._N;
    _v = std::vector<int>(rhs._v);
    return *this;
}

// Member Functions
void    Span::addNumber(int nb) {
    _v.push_back(nb);
}

int     Span::shortestSpan( void ) {
    std::vector<int>::iterator  it;
    std::vector<int> copy(_v);
    int shortestSpan = -1;

    std::sort(copy.begin(), copy.end());
    for (it = copy.begin() + 1; it != copy.end(); it++) {
        if (shortestSpan == -1 || (*it - *(it - 1)) < shortestSpan)
        {
            shortestSpan = *it - *(it - 1);
            __s_max = *it;
            __s_min = *(it - 1);
        }
    }
    return (shortestSpan);
}

int     Span::longestSpan( void ) {
    __l_max = *(std::max_element(_v.begin(), _v.end()));
    __l_min = *(std::min_element(_v.begin(), _v.end()));
    return (__l_max - __l_min);
}

void    Span::printSpan(void) {
    std::vector<int>::iterator it;
    for (it = _v.begin(); it != _v.end(); it++) {
        if ((*it == __l_min && *it == __s_min) || (*it == __l_max && *it == __s_max))
             std::cout << "\033[1;31m-->";
        else if (*it == __l_min || *it == __l_max)
             std::cout << "\033[1;36m-->";
        else if (*it == __s_min || *it == __s_max)
             std::cout << "\033[1;33m-->";
        std::cout << *it << " ";
        std::cout << "\033[1;0m";
    }
    std::cout << std::endl;
}