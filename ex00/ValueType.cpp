/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ValueType.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:10:51 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:10:51 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <climits>
#include "Converter.hpp"
#include "ValueType.hpp"


ValueType::ValueType(const ValueType &other): _input(other._input), _type(other._type) {}

ValueType::ValueType(const std::string &input): _input(input) {
	_type = NO_TYPE;
	identify(input);
}

ValueType::~ValueType() {}

ValueType &ValueType::operator=(const ValueType &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

static bool isChar(const std::string &input) {
	return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

static bool isInt(const std::string &input) {
	const size_t pos = input[0] == '+' || input[0] == '-';
	return input.find_first_not_of("0123456789", pos) == std::string::npos;
}

static bool isFloatVal(const std::string &input) {
	return input.find('.') != std::string::npos;
}

static ValType identifyFloat(const std::string &input) {
	const size_t pos = input[0] == '-' || input[0] == '+';
	if (input.compare(pos, 3, "inf") != 0 && input.compare(pos, 3, "nan") != 0)
		throw ValueType::InvalidValueException("Could not identify input!");
	if (pos + 3 == input.length())
		return DOUBLE;
	if (input[input.length() - 1] == 'f')
		return FLOAT;
	throw ValueType::InvalidValueException("Invalid special value!");
}

void ValueType::identify(const std::string &input) {
	if (input.empty())
		throw InvalidValueException("Input is empty!");
	if (isChar(input))
		_type = CHAR;
	else if (isInt(input))
		_type = INT;
	else if (isFloatVal(input))
		_type = input[input.length() - 1] == 'f' ? FLOAT : DOUBLE;
	else
		_type = identifyFloat(input);
}


Converter ValueType::createConverter() const {
	switch (_type) {
		case CHAR:
			return Converter(toChar());
		case INT:
			return Converter(toInt());
		case FLOAT:
			return Converter(toFloat());
		case DOUBLE:
			return Converter(toDouble());
		default:
			throw InvalidValueException("The value type has not yet been initialized, how did this happen?!");
	}
}

char ValueType::toChar() const {
	return _input[1];
}

int ValueType::toInt() const {
	char *end;
	long int parsed = std::strtol(_input.c_str(), &end, 10);

	if (*end != '\0') {
		const std::string err = "Invalid value " + _input;
		throw InvalidValueException(err);
	} else if (parsed > INT_MAX || parsed < INT_MIN) {
		const std::string err = "Value " + _input + " overflows!";
		throw InvalidValueException(err);
	}
	return (int) parsed;
}

float ValueType::toFloat() const {
	char *end;
	float parsed = std::strtof(_input.c_str(), &end);

	if (*end != 'f' || end[1] != '\0') {
		const std::string err = "Invalid value " + _input;
		throw InvalidValueException(err);
	}
	return parsed;
}

double ValueType::toDouble() const {
	char *end;
	double parsed = std::strtod(_input.c_str(), &end);

	if (*end != '\0') {
		const std::string err = "Invalid value " + _input;
		throw InvalidValueException(err);
	}
	return parsed;
}


ValueType::InvalidValueException::InvalidValueException(const std::string &reason): _reason(reason) {}

const char *ValueType::InvalidValueException::what() const throw() {
	return _reason.c_str();
}

ValueType::InvalidValueException::~InvalidValueException() throw() {}

ValueType::InvalidValueException::InvalidValueException(const ValueType::InvalidValueException &other) throw(): _reason(other._reason) {}
