#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>

template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it = container.begin();
	typename T::const_iterator end = container.end();

	while (it != end)
	{
		if (*it == value)
			return it;
		++it;
	}
	throw std::runtime_error("Value not found");
}

#endif
