// 
// Copyright 2015 Wolfgang Wallner (wolfgang-wallner AT gmx.at)
// 
// This file is part of libPLN.
// 
// libPLN is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// libPLN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with libPLN.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef TDVECGEN_GENERICTDVECGEN_HPP_
#define TDVECGEN_GENERICTDVECGEN_HPP_

// =========================================================================
// Includes
// =========================================================================

#include "TdEst/TdEstConfig.hpp"
#include "TdVecGen/TdVecGen.hpp"

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

class GenericTdVecGen : public TdVecGen
{
    private:

        // Config

        // Resources

        // Internal functions
        void        SetUpKwHpConvFilter( KW_FilterConfig KwConf, HP_FilterConfig HpConf, size_t TdVecLen );

    public:

        // Constructors/Destructor
        GenericTdVecGen( size_t TdVecLen, double TickLen, KW_FilterConfig KwConf, HP_FilterConfig HpConf, InterpolationConfig InterpolConf );
        GenericTdVecGen( const GenericTdVecGen& other );
        ~GenericTdVecGen();

        GenericTdVecGen*    Clone() const;  // Virtual constructor (copying)

        // Operators
        GenericTdVecGen&    operator=( const GenericTdVecGen& other );

        // API
        TdVector    *GetNextVector();
};

// =========================================================================
// Function declarations
// =========================================================================

#endif
