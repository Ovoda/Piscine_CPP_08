#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

class Span {
   public:
    // Constructor(s)
    Span(Span const& src);
    Span(unsigned int N);
    Span(std::vector<int>::iterator a, std::vector<int>::iterator b);

    // Destructor
    ~Span();

	// Operator Overload
    Span& operator=(Span const& rhs);

    // Member function(s)
	void	addNumber(int nb);
	int     longestSpan( void );
	int     shortestSpan( void );
	void	printSpan(void);

   private:
    Span(void);
	unsigned int		_N;
	std::vector<int>	_v;

	// bonus
	int	__l_max;
	int	__l_min;
	int	__s_max;
	int	__s_min;
};

#endif