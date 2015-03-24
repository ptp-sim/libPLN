// =========================================================================
// Includes
// =========================================================================

#include "TdVectorLinear.hpp"

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

double
TdVectorLinear::InterpolateAt( double t_req )
{
    double  t   = t_req - t_beg;

    size_t  idxl = std::floor( t / TickLen );
    size_t  idxr = std::ceil ( t / TickLen );

    double  x  = t - (idxl * TickLen);
    double  dx = TickLen;
    double  dy = (TD[idxr] - TD[idxl]);

    return TD[idxl] + dy / dx * x;
}

TdVectorLinear::TdVectorLinear( double t_beg, double TD_0, double TickLen, FFT_RealVector *pData, size_t ValidLen, TdVecDataType DataType )
    : TdVector( t_beg, TD_0, TickLen, pData, ValidLen, DataType )
{
}

TdVectorLinear::TdVectorLinear( const TdVectorLinear& other )
    : TdVector( other )
{
}

TdVectorLinear::~TdVectorLinear()
{
}

TdVectorLinear&
TdVectorLinear::operator=( const TdVectorLinear& other )
{
    TdVector::operator=( other );

    // By convention, always return *this
    return *this;
}
