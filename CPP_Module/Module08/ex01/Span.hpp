#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <stdexcept>
#include <climits>

class Span
{
	private:
		unsigned int	_maxSize;
		std::set<int>	_numbers;

	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span(void);

		void	addNumber(int value);
		template<typename InputIterator>
		void addNumbers(InputIterator first, InputIterator last)
		{
			std::size_t count = std::distance(first, last);
			if (_numbers.size() + count > _maxSize)
				throw std::runtime_error("Not enough space in Span");
			_numbers.insert(first, last);
		}

		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		void	ensureSpanIsValid(void) const;
};

#endif
