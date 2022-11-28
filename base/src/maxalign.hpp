#ifndef NERD_BASE_MAXALIGN_HPP
#define NERD_BASE_MAXALIGN_HPP

#include <cstddef>

namespace nerd {
namespace base {

	const std::size_t maxAlign = alignof(std::max_align_t);

}}

#endif /* NERD_BASE_MAXALIGN_HPP */
