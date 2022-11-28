// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "ReferenceCounted.hpp"

namespace nerd {
namespace base {

	ReferenceCounted::ReferenceCounted(const ReferenceCounted&) : refcount(static_cast<MemorySize>(1u)) {}

	ReferenceCounted::ReferenceCounted() : refcount(static_cast<MemorySize>(1u)) {}

	ReferenceCounted::~ReferenceCounted() {}

}}
