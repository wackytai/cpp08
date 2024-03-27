#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <limits>

class Span
{
	private:
		int				*_a;
		unsigned int	_maxSize;

	public:
		Span();
		Span( unsigned int n );
		~Span();
		Span( const Span &obj );
		Span	&operator=( const Span &obj );
		void	addNumber( int nb );
		int		shortestSpan();
		int		longestSpan();
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