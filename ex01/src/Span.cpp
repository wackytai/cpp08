#include "../inc/Span.hpp"

Span::Span()
{
	_vec.reserve(0);
}

Span::Span( unsigned int n )
{
	_vec.reserve(n);
}

Span::Span( Span const &object )
{
	*this = object;
}

Span::~Span() {}

Span&	Span::operator=( Span const &object )
{
	_vec = object._vec;
	return *this;
}

void	Span::addNumber( int n )
{
	if (_vec.size() == _vec.capacity())
		throw MaxSizeReachedException();
	_vec.push_back(n);
	//std::cout << "Added " << n << " to the container." << std::endl;
}

int&	Span::operator[]( unsigned int n )
{
	if (n >= _vec.size())
		throw std::out_of_range("Index out of range.");
	return _vec[n];
}

int		Span::shortestSpan( void )
{
	if (_vec.size() == 0)
		throw NoElementsStoredException();
	else if (_vec.size() == 1)
		throw OneElementStoredException();

	std::vector<int>		tmp = _vec;
	int						minSpan = abs(tmp[1] - tmp[0]);

	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		if (abs(tmp[i + 1] - tmp[i]) < minSpan)
			minSpan = abs(tmp[i + 1] - tmp[i]);
	}

	return minSpan;
}

int		Span::longestSpan( void )
{
	if (_vec.size() == 0)
		throw NoElementsStoredException();
	else if (_vec.size() == 1)
		throw OneElementStoredException();

	std::vector<int>	tmp = _vec;

	std::sort(tmp.begin(), tmp.end());
	int	maxSpan = abs(tmp[tmp.size() - 1] - tmp[0]);

	return maxSpan;
}

void	Span::bulkAddNumbers( int begin, int end )
{
	if (_vec.size() == _vec.capacity() || _vec.size() + abs(end - begin) > _vec.capacity())
		throw MaxSizeReachedException();

	int		s = (end >= begin) ? 1 : -1;
	for (int i = begin; i != end + s; i += s)
	{
		_vec.push_back(i);
		if (begin == end)
			break;
	}
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << std::endl;
}

const char *Span::MaxSizeReachedException::what(void) const throw()
{
	return "Container capacity was reached.";
}

const char *Span::NoElementsStoredException::what(void) const throw()
{
	return "There are no elements stored in the container.";
}

const char *Span::OneElementStoredException::what(void) const throw()
{
	return "Container has only one element stored.";
}
