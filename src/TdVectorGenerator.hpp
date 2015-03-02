
#ifndef TDVECTORGENERATOR_HPP_
#define TDVECTORGENERATOR_HPP_

// =========================================================================
// Includes
// =========================================================================

#include "Configs.hpp"
#include "TdVector.hpp"
#include "TdFixPoint.hpp"
#include "WhiteNoiseGenerator.hpp"
#include "FilterKernel.hpp"

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

class TdVectorGenerator
{
    private:

        // Config
        double              TickLen;
        InterpolationType   IntpolType;

        // Resources
        WhiteNoiseGenerator     WhiteNoiseGen;
        FilterKernel            H;

    public:

        TdVectorGenerator( size_t TdVecLen, double TickLen, KW_FilterConfig KwConf, HP_FilterConfig HpConf, InterpolationConfig InterpolConf );

        void        ResetToFixPoint( TdFixPoint fp );
        TdVector    *GetNextVector();
};

// =========================================================================
// Function declarations
// =========================================================================

#endif
