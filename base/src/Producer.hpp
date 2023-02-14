#ifndef NERD_BASE_PRODUCER_HPP
#define NERD_BASE_PRODUCER_HPP

#include "Function.hpp"

namespace nerd {
namespace base {

	template<typename ProductT>
	using Producer = Function<ProductT>;

	template<typename ProductT>
	using ProducerInto = Function<void, ProductT&>;

}}

#endif /* NERD_BASE_PRODUCER_HPP */
