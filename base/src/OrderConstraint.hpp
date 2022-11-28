#ifndef NERD_BASE_ORDERCONSTRAINT_HPP
#define NERD_BASE_ORDERCONSTRAINT_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "api.hpp"

namespace nerd {
namespace base {

	enum NERD_BASE_API OrderConstraint {
		OC_LESS,
		OC_LESS_EQUAL,
		OC_GREATER,
		OC_GREATER_EQUAL,
		OC_EQUAL,
		OC_UNEQUAL
	};

}}

#endif /* NERD_BASE_ORDERCONSTRAINT_HPP */
