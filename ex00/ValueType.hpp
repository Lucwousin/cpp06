/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ValueType.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:10:48 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:10:48 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUETYPE_HPP
# define VALUETYPE_HPP
# include <string>

typedef enum ValType {
	NO_TYPE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	ValType;

class Converter;
class ValueType {
	public:
		ValueType(const ValueType &other);
		explicit ValueType(const std::string &input);
		virtual ~ValueType();
		ValueType &operator=(const ValueType &rhs);

		void identify(const std::string &input);
		Converter createConverter() const;

		class InvalidValueException: public std::exception {
			private:
				const std::string _reason;
			public:
				InvalidValueException(const InvalidValueException &other) throw();
				explicit InvalidValueException(const std::string &reason);
				~InvalidValueException() throw();
				const char *what() const throw();
		};

	private:
		ValueType(); // Not implemented

		const std::string &_input;
		ValType _type;

		char toChar() const;
		int toInt() const;
		float toFloat() const;
		double toDouble() const;
};

#endif
