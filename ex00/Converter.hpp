#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include "ValueType.hpp"

class Converter {
	private:
		Converter();
		Converter &operator=(const Converter &rhs);

		double _val;

		const ValType _type;

		void printChar() const;
		void printInt() const;
		void printFloat() const;
		void printDouble() const;

	public:
		Converter(const Converter& other);
		explicit Converter(char val);
		explicit Converter(int val);
		explicit Converter(float val);
		explicit Converter(double val);
		virtual ~Converter();

		void print() const;
};

#endif
