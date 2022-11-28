#ifndef NERD_BASE_MINIMUMAPPENDER_HPP
#define NERD_BASE_MINIMUMAPPENDER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "Appender.hpp"
#include "IntegerBounds.hpp"

namespace nerd {
namespace base {

	template<
		typename IntegerT,
		IntegerT NegativeInfinity = IntegerBounds<IntegerT>::MIN
	>
	class MinimumAppender : public Appender<IntegerT> {

	  private:
		IntegerT minimum;
		bool hasMinimum;

	  public:
		MinimumAppender() : minimum(static_cast<IntegerT>(0)), hasMinimum(false) {}

		MinimumAppender(const MinimumAppender& appender)
				: Appender<IntegerT>(appender), minimum(appender.minimum), hasMinimum(appender.hasMinimum) {}

		IntegerT getMinimum() const {
			return hasMinimum ? minimum : NegativeInfinity;
		}

		virtual void append(const IntegerT& current) {
			if(!hasMinimum || current < minimum) {
				minimum = current;
				hasMinimum = true;
			}
		}

	};

}}

#endif /* NERD_BASE_MINIMUMAPPENDER_HPP */
