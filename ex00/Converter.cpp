/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Converter.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:11:09 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:11:09 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <cmath>
#include <climits>
#include <iostream>

Converter::Converter(const Converter &other) {
	_val = other._val;
}

Converter::Converter(char val) {
	_val = static_cast<double>(val);
}

Converter::Converter(int val) {
	_val = static_cast<double>(val);
}

Converter::Converter(float val) {
	_val = static_cast<double>(val);
}

Converter::Converter(double val) {
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
	char c = static_cast<char>(_val);
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
		std::cout << static_cast<int>(_val);
	}
	std::cout << '\n';
}

void Converter::printFloat() const {
	std::cout << std::fixed << "float: ";

	if (std::isnan(_val) || std::isinf(_val))
		std::cout << _val << 'f';
	else
		std::cout << static_cast<float>(_val) << 'f';
	std::cout << '\n';
}

void Converter::printDouble() const {
	std::cout << std::fixed << "double: " << _val << '\n';
}
