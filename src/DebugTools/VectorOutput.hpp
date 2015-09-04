// ============================================================================
///
/// \file
///
/// \brief  Tools that are helpful for debugging
///
/// \ingroup module_debug_tools
///
// ============================================================================

// ============================================================================
// 
// Copyright 2015 Wolfgang Wallner (wolfgang-wallner AT gmx.at)
// 
// This file is part of libPLN.
// 
// libPLN is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License.com as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// libPLN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License.com for more details.
// 
// You should have received a copy of the GNU General Public License.com
// along with libPLN.  If not, see <http://www.gnu.org/licenses/>.
//
// ============================================================================

#ifndef VECTOROUTPUT_HPP_
#define VECTOROUTPUT_HPP_

// =========================================================================
// Includes
// =========================================================================

#include <vector>
#include <iostream>
#include <complex>

#include "Utils/FFT_Types.hpp"

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

// =========================================================================
// Function declarations
// =========================================================================

/// Print a real vector to the command line, and prefix it with an arbitrary name
///
/// \param Name A human-readable name for the data vector
/// \param v    The data vector that should be printed
void    PrintRealVector( std::string Name, std::vector<double> v );

/// Print a complex vector to the command line, and prefix it with an arbitrary name
///
/// \param Name A human-readable name for the data vector
/// \param v    The data vector that should be printed
void    PrintCompVector( std::string Name, std::vector< std::complex<double> > v );

/// Print a real vector to the command line, and prefix it with an arbitrary name
///
/// \param Name A human-readable name for the data vector
/// \param v    The data vector that should be printed
void    PrintFftRealVector( std::string Name, FFT_RealVector v );

/// Print a complex vector to the command line, and prefix it with an arbitrary name
///
/// \param Name A human-readable name for the data vector
/// \param v    The data vector that should be printed
void    PrintFftCompVector( std::string Name, FFT_ComplexVector v );

#endif
