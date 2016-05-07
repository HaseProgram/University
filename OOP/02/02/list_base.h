#pragma once

class list_base
{
public:
	virtual size_t length() const = 0;
protected:
	size_t size;
};