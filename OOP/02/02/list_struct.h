#pragma once

template <typename type_t>
struct listItem
{
	listItem* Prev;
	listItem* Next;
	type_t data;
};