#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>

template<typename T>
const char	*easyfind( T array, int i )
{
	return (std::binary_search(array.begin(), array.end(), i)) ? "Value not found"; "Value found";
}

#endif