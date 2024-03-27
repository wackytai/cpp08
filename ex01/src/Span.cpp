#include "../inc/Span.hpp"

Span::Span() : _maxSize( 0 )
{
	_a = new int[_maxSize];
}

Span::Span( unsigned int n ) : _maxSize( n )
{
	_a = new int[_maxSize];
}

Span::~Span()
{
	if (_a != nullptr)
		delete[] _a;
}

Span::Span( const Span &obj )
{
	*this = obj;
}

Span	Span&::operator=( const Span &obj )
{
	if (this != &obj)
	{
		if (_a != nullptr)
			delete[] _a;
	}
	for (int i = obj._a.begin(); i < obj._a.end(); i++)
		_a[i] = obj._a[i];
	return *this;
}

void	Span::addNumber( int nb )
{
	if ( _a.end() == _maxSize )
		throw MaxSizeReachedException();
	if ( _a == nullptr )
		_a[1] = nb;
	else
		_a[(_.end() + 1)] = nb;	
}

int		Span::shortestSpan()
{
	if ( _a == nullptr )
		throw NoElementsStoredException();
	else if ( _a.begin() == _a.end() )
		throw OneElementStoredException();
	int	diff = _a.end() - _a.begin();
	std::sort(_a.begin(), _a.end());
	//implement adjacent difference here
	return diff;
}

int		Span::longestSpan()
{
	if ( _a == nullptr )
		throw NoElementsStoredException();
	else if ( _a.begin() == _a.end() )
		throw OneElementStoredException();
	int	diff = 0;
	std::sort(_a.begin(), _a.end());
	//implement adjacent difference here
	return diff;
}

const char *Span::MaxSizeReachedException::what(void) const throw()
{
	return "Container storage is full.";
}

const char *Span::NoElementsStoredException::what(void) const throw()
{
	return "There are no elements stored in the container.";
}

const char *Span::OneElementStoredException::what(void) const throw()
{
	return "Container has only one element stored.";
}
