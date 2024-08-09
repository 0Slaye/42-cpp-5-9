#include "Span.hpp"

Span::Span(void) : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &reference) : _n(reference._n), _container(reference._container)
{
}

Span::~Span(void)
{
}

Span	&Span::operator=(const Span &reference)
{
	this->_n = reference._n;
	this->_container = reference._container;
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_container.size() < this->_n)
		this->_container.push_back(number);
	else
		throw Span::CapacityException();
}

const char	*Span::CapacityException::what() const throw()
{
	return ("Span already full.");
}

const char	*Span::DistanceException::what() const throw()
{
	return ("Span does not have the required number od items.");
}