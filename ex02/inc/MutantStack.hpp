#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<int>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &object);
		~MutantStack();
		MutantStack &operator=(MutantStack const &object);
};

#define MutantStack.tpp

#endif