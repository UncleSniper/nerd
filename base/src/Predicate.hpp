#ifndef NERD_BASE_PREDICATE_HPP
#define NERD_BASE_PREDICATE_HPP

#include "Function.hpp"

namespace nerd {
namespace base {

	template<typename ArgT>
	using Predicate = Function<bool, ArgT>;

}}

#endif /* NERD_BASE_PREDICATE_HPP */
