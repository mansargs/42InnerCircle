#ifndef ARRAY_HPP
#define ARRAY_HPP


template<typename T>
class Array {
	private:
		T*		m_arr;
		size_t	m_size;
	public:
		Array() : m_arr(NULL), m_size(0) {}
		Array(unsigned n) : m_arr(NULL), m_size(n) {
			if (m_size == 0)
				return ;
			m_arr = new T[n]();
		}
		Array(const Array& other) : m_arr(NULL), m_size(other.m_size){
			if (m_size == 0)
				return ;
			m_arr = new T[m_size]();
			for (size_t i = 0; i < m_size; ++i)
				m_arr[i] = other.m_arr[i];
		}
		Array& operator=(Array other) {
			std::swap(m_arr, other.m_arr);
			std::swap(m_size, other.m_size);
			return *this;
		}
		~Array() {
			delete[] m_arr;
			m_arr = NULL;
			m_size = 0;
		}
		const T& operator[](unsigned index) const {
			if (index >= m_size)
				throw std::out_of_range("Index out of bounds");
			return m_arr[index];
		}
		T& operator[](unsigned index) {
			return const_cast<T&>(static_cast<const Array&>(*this)[index]);
		}
		size_t size() const {
			return m_size;
		}
};

#endif
