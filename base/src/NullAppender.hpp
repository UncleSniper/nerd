#ifndef NERD_BASE_NULLAPPENDER_HPP
#define NERD_BASE_NULLAPPENDER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "Appender.hpp"

namespace nerd {
namespace base {

	template<typename ElementT>
	class NullAppender : public Appender<ElementT> {

	  public:
		NullAppender() {}
		NullAppender(const NullAppender& appender) : Appender<ElementT>(appender) {}

		virtual void append(const ElementT&) {}

	};

}}

#endif /* NERD_BASE_NULLAPPENDER_HPP */
