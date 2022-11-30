/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:10:58 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:10:58 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <iostream>
#include "Converter.hpp"

void testChar() {
	char c = CHAR_MIN;

	do {
		const Converter conv(c);
		conv.print();
		std::cout << '\n';
	} while (c++ != CHAR_MAX);
}

void testInt(int i) {
	const Converter conv(i);
	conv.print();
	std::cout << '\n';
}

static void	convert(const std::string str) {
	try {
		ValueType type(str);
		Converter conv = type.createConverter();
		conv.print();
	} catch (ValueType::InvalidValueException &err) {
		std::cerr << err.what() << "\n";
	}
}

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cerr << "Add some values to convert!\n";
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		convert(argv[i]);
		if (i + 1 != argc) {
			std::cout << '\n';
		}
	}

	//testChar();
	//testInt(1);
	//testInt(-1);
	//testInt(INT_MIN);
	//testInt(INT_MAX);
	//testInt(55);
}