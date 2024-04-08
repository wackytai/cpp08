#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>
# include <exception>

class Span
{
	private:
		std::vector<int>	_vec;
	public:
		Span();
		Span( unsigned int n );
		Span( Span const &object );
		~Span();
		Span	&operator=( Span const &object );
		int		&operator[]( unsigned int n );
		void	addNumber( int n );
		int		shortestSpan( void );
		int		longestSpan( void );
		void	bulkAddNumbers( int begin, int end );
	class MaxSizeReachedException : public std::exception
	{
		public:
			const char	*what( void ) const throw();
	};
	class NoElementsStoredException : public std::exception
	{
		public:
			const char	*what( void ) const throw();
	};
	class OneElementStoredException : public std::exception
	{
		public:
			const char	*what( void ) const throw();
	};
};

#endif