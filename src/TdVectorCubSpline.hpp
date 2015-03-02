
#ifndef TDVECTORCUBSPLINE_HPP_
#define TDVECTORCUBSPLINE_HPP_

// =========================================================================
// Includes
// =========================================================================

#include "TdVector.hpp"
#include "FFT_Types.hpp"

#include "spline.hpp"

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

class TdVectorCubSpline : public TdVector
{
    private:

        // Types
        typedef enum
        {
            UNINITIALIZED,
            INITIALIZED,
        }
        SplineState;

        // Config

        // Housekeeping
        SplineState State;

        // Resources
        tk::spline          s;
        std::vector<double> t;

        // Internal functions
        double  InterpolateAt( double t_req );

    public:

        TdVectorCubSpline( double BeginTime, double BeginOffset, double TickLen, FFT_RealVector *pFFD );
};

// =========================================================================
// Function declarations
// =========================================================================

#endif
