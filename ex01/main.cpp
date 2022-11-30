/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:10:43 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:10:43 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>
#include <cstring>
#include "Data.h"

uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
	Data data = {'a', 'b', 'c', 'd', "efghijk"};
	uintptr_t raw = serialize(&data);
	Data *ptr = deserialize(raw);
	if (&data != ptr)
		std::cerr << "Pointer is different! " << ptr << " vs " << &data << "\n";
	if (std::memcmp(&data, ptr, sizeof(Data)) != 0)
		std::cerr << "Data is different!\n";
}