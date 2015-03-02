
#ifndef TDVECTOR_HPP_
#define TDVECTOR_HPP_

// =========================================================================
// Includes
// =========================================================================

#include "FFT_Types.hpp"

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

class TdVector
{
    protected:

        // Config
        double  TickLen;
        double  t_beg;
        double  t_end;

        // Resources
        std::vector<double> TD;

        // Internal functions
        virtual double  InterpolateAt( double t_req ) = 0;

    public:

                TdVector( double BeginTime, double BeginOffset, double TickLen, FFT_RealVector *pFFD );
        virtual ~TdVector();

        double  GetBeginTime();
        double  GetEndTime();

        double  InterpolateTD_nom( double t_req );
};


// =========================================================================
// Function declarations
// =========================================================================


#endif
