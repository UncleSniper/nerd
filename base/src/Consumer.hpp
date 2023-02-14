#ifndef NERD_BASE_CONSUMER_HPP
#define NERD_BASE_CONSUMER_HPP

#include "Function.hpp"

namespace nerd {
namespace base {

	template<typename ArgT>
	using Consumer = Function<void, ArgT>;

}}

#endif /* NERD_BASE_CONSUMER_HPP */
