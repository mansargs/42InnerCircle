#ifndef DATA_HPP
# define DATA_HPP

class Data {
	protected:
		int x;
		double y;
	public:
		Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();
};

#endif
