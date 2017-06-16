#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED

#include "device_properties.hpp"

#include <exception>
#include <sstream>
#include <string>

std::string to_string(std::exception const &e);
std::string to_string(device_type t);

template<class Iterator, typename CharT>
std::string join(Iterator first, Iterator last, CharT const *delim)
{
	std::basic_stringstream<CharT> buf;

	for (auto it = first;;) {
		if (it == last) break;
		buf << *it; it++;
		if (it != last) buf << delim;
	}

	return buf.str();
}

#endif // STRING_HPP_INCLUDED