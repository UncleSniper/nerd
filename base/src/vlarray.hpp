#ifndef NERD_BASE_VLARRAY_HPP
#define NERD_BASE_VLARRAY_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#ifdef __GNUC__

#include "DestroyArray.hpp"
#define NERD_VLARRAY_DEFINE(elementType, name, elementCount) \
	elementType* name = static_cast<elementType*>(__builtin_alloca(static_cast<size_t>(elementCount) \
			* sizeof(elementType))); \
	::nerd::base::DestroyArray<elementType> _ ## name ## _destroyer(name); \
	_ ## name ## _destroyer.extend(static_cast< ::nerd::base::MemorySize>(elementCount));
#define NERD_VLARRAY_ACCESS(name) name

#else /* unknown compiler */

#include "DeleteArray.hpp"
#define NERD_VLARRAY_DEFINE(elementType, name, elementCount) \
	::nerd::base::DeleteArray<elementType> name(new elementType[static_cast<size_t>(elementCount)]);
#define NERD_VLARRAY_ACCESS(name) (*name)

#endif /* compiler differences */

#endif /* NERD_BASE_VLARRAY_HPP */
