/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  exceptions.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/28/2010 07:32:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__EXCEPTIONS_H__)
#define __EXCEPTIONS_H__

#include <string>
#include <exception>
#include "type_props.h"

// m3g signature
struct incorrect_m3g_signature : public std::exception
{
	virtual char const *what() const throw()
	{
		return "Incorrect M3G file signature";
	}
};

// Stream exceptions
struct file_not_open : public std::exception
{
	file_not_open(char const *fname)
		: file_name("")
	{
		if (fname)
			file_name = std::string(fname);
	}
	virtual ~file_not_open() throw() {}
	virtual char const *what() const throw()
	{
		static std::string reason;
		reason = "Cannot open file: " + file_name;
		return reason.c_str();
	}
	std::string file_name;
};

struct file_read_error : public std::exception
{
	virtual char const *what() const throw()
	{
		return "File read error occured";
	}
};

struct memory_read_out_of_bound : public std::exception
{
	virtual char const *what() const throw()
	{
		return "Read out of bound exception was occured";
	}
};

struct memory_no_data : public std::exception
{
	virtual char const *what() const throw()
	{
		return "Stream has no data";
	}
};

struct memory_data_corrupt : public std::exception
{
	virtual char const *what() const throw()
	{
		return "ZLib data corrupt";
	}
};

// Invalid object type
struct invalid_object_type : public std::exception
{
	int object_type;
	invalid_object_type(int ot)
		: object_type(ot)
	{}
	virtual char const *what() const throw()
	{
		static char reason[8196];
		sprintf(reason, "Invalid object type: %d",
			object_type);
		return reason;
	}
};

// Invalid property value
template<class T>
struct invalid_property_value : public std::exception
{
	std::string object_name;
	std::string property_name;
	T value;

	invalid_property_value(std::string const &on,
		std::string const &pn, T const &v)
		: object_name(on)
		, property_name(pn)
		, value(v)
	{}
	virtual ~invalid_property_value() throw() {}
	virtual char const *what() const throw()
	{
		static std::string reason;
		reason = "Invalid property value: " + object_name + "::" +
			property_name + " = " + type_props<T>::to_string(value);
		return reason.c_str();
	}
};


#endif//__EXCEPTIONS_H__
