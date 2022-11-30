#include "Converter.hpp"
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>

Converter::Converter(const Converter &other): _type(other._type) {
	_val = other._val;
}

Converter::Converter(char val): _type(CHAR) {
	_val = val;
}

Converter::Converter(int val): _type(INT) {
	_val = val;
}

Converter::Converter(float val): _type(FLOAT) {
	_val = val;
}

Converter::Converter(double val): _type(DOUBLE) {
	_val = val;
}

Converter::~Converter() {}

void Converter::print() const {
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void Converter::printChar() const {
	std::cout << "char: ";

	if (std::isnan(_val) || std::isinf(_val) || _val < CHAR_MIN || _val > CHAR_MAX) {
		std::cout << "impossible\n";
		return;
	}
	char c = (char) _val;
	if (std::isprint(c)) {
		std::cout << '\'' << c << "'\n";
	} else {
		std::cout << "Non displayable\n";
	}
}

void Converter::printInt() const {
	std::cout << "int: ";

	if (std::isnan(_val) || std::isinf(_val) || _val < INT_MIN || _val > INT_MAX) {
		std::cout << "impossible";
	} else {
		std::cout << (int) _val;
	}
	std::cout << '\n';
}

void Converter::printFloat() const {
	std::cout << std::fixed << "float: ";

	if (std::isnan(_val) || std::isinf(_val))
		std::cout << _val << 'f';
	else
		std::cout << (float) _val << 'f';
	std::cout << '\n';
}

void Converter::printDouble() const {
	std::cout << "double: " << std::fixed << _val << '\n';
}