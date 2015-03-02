// =========================================================================
// Includes
// =========================================================================

#include "TdVector.hpp"

#include <cassert>
#include <numeric>

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

// =========================================================================
// Global variables
// =========================================================================

// =========================================================================
// Locale function prototypes
// =========================================================================

// =========================================================================
// Function definitions
// =========================================================================

TdVector::TdVector( double BeginTime, double BeginOffset, double TickLen, FFT_RealVector *pFFD )
    : TD( pFFD->size() + 1 )
{
    this->t_beg = BeginTime;
    this->t_end   = BeginTime + TickLen * pFFD->size();
    this->TickLen   = TickLen;

    TD[0] = 0.0L;

    std::partial_sum( pFFD->begin(), pFFD->end(), TD.begin()+1 );
}

TdVector::~TdVector()
{
}

double
TdVector::GetBeginTime()
{
    return t_beg;
}

double
TdVector::GetEndTime()
{
    return t_end;
}

double
TdVector::InterpolateTD_nom( double t_req )
{
    assert( t_req >= t_beg );
    assert( t_req <= t_end );

    return InterpolateAt( t_req );
}
