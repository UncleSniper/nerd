#ifndef NERD_BASE_API_HPP
#define NERD_BASE_API_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "macros.hpp"

#ifdef NERD_NEEDS_DLLEXPORT
#ifdef BUILDING_NERD_BASE_API
#define NERD_BASE_API __declspec(dllexport)
#else /* !BUILDING_NERD_BASE_API */
#define NERD_BASE_API __declspec(dllimport)
#endif /* BUILDING_NERD_BASE_API */
#else /* !NERD_NEEDS_DLLEXPORT */
#define NERD_BASE_API
#endif

#endif /* NERD_BASE_API_HPP */
