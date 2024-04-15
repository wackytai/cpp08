#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack<T> const &object);
		~MutantStack();
		MutantStack<T> &operator=(MutantStack<T> const &object);
		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();
};

#define MutantStack.tpp

#endif