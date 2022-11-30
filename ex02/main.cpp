/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:10:31 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:10:31 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
	// This enum is here so the compiler knows there's only 3 possible options
	enum Type {
		T_A, T_B, T_C
	};
	Type type = (Type) (rand() % 3);

	Base *b;
	switch (type) {
		case T_A:
			b = new A();
			std::cout << "Generated new A\n";
			break;
		case T_B:
			b = new B();
			std::cout << "Generated new B\n";
			break;
		case T_C:
			b = new C();
			std::cout << "Generated new C\n";
			break;
	}
	return b;
}

void identify(Base *p) {
	A *a = dynamic_cast<A *>(p);
	if (a != NULL) {
		std::cout << "Ptr id'd as type A!\n";
		return;
	}
	B *b = dynamic_cast<B *>(p);
	if (b != NULL) {
		std::cout << "Ptr id'd as type B!\n";
		return;
	}
	C *c = dynamic_cast<C *>(p);
	if (c != NULL) {
		std::cout << "Ptr id'd as type C!\n";
		return;
	}
}

void identify(Base &p) {
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "Ref id'd as type A!\n";
	} catch (std::bad_cast &err) {
		(void) err;
	}
	try {
		(void) dynamic_cast<B &>(p);
		std::cout << "Ref id'd as type B!\n";
	} catch (std::bad_cast &err) {
		(void) err;
	}
	try {
		(void) dynamic_cast<C &>(p);
		std::cout << "Ref id'd as type C!\n";
	} catch (std::bad_cast &err) {
		(void) err;
	}
}

int main() {
	for (int i = 0; i < 25; i++) {
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
}