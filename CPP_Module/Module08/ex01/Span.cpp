#include "Span.hpp"

Span::Span(void) : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other)
	: _maxSize(other._maxSize), _numbers(other._numbers)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(void) {}

void Span::addNumber(int value)
{
	if (_numbers.size() == _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.insert(value);
}

void Span::ensureSpanIsValid(void) const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to compute span");
}

int Span::shortestSpan(void) const
{
	int min_diff = INT_MAX;

	ensureSpanIsValid();
	std::set<int>::const_iterator it = _numbers.begin();
	std::set<int>::const_iterator prev = it;
	++it;
	for (; it != _numbers.end(); ++it)
	{
		int diff = *it - *prev;
		if (diff < min_diff)
			min_diff = diff;
		prev = it;
	}
	return min_diff;
}

int Span::longestSpan(void) const
{
	ensureSpanIsValid();
	return *_numbers.rbegin() - *_numbers.begin();
}
