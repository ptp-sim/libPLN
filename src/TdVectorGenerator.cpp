
#ifndef TDVECTORGENERATOR_CPP_
#define TDVECTORGENERATOR_CPP_

// =========================================================================
// Includes
// =========================================================================

#include "TdVectorGenerator.hpp"

#include "KwFilterImpResp.hpp"
#include "BmHpFilterImpResp.hpp"
#include "TdVectorLinear.hpp"
#include "TdVectorCubSpline.hpp"

#include <numeric>

// Debug only
#include <iostream>
using namespace std;

#include "VectorOutput.hpp"

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

// =========================================================================
// Function declarations
// =========================================================================

TdVectorGenerator::TdVectorGenerator( size_t TdVecLen, double TickLen, KW_FilterConfig KwConf, HP_FilterConfig HpConf, InterpolationConfig InterpolConf )
    : WhiteNoiseGen( KwConf.Seed, KwConf.Qd )
{
    // Set up filter kernel
    KwFilterImpResp   kw( KwConf.FilterLen, KwConf.alpha );

    switch( HpConf.Type )
    {
        case NO_FILTER:
        {
            H   = FilterKernel( TdVecLen, kw );
            break;
        }

        case BLACKMAN:
        {
            BmHpFilterImpResp bm( HpConf.FilterLen, HpConf.f_c_nom );

            bm.Augment( HpConf.Cnt );

            H   = FilterKernel( TdVecLen, kw, bm );
            break;
        }
    }

    // Set up config
    this->TickLen       = TickLen;
    this->IntpolType    = InterpolConf.Type;

}

void
TdVectorGenerator::ResetToFixPoint( TdFixPoint fp )
{
    // TODO
}

TdVector *
TdVectorGenerator::GetNextVector()
{

    FFT_RealVector    *pw = WhiteNoiseGen.GetVector( H.GetResponseLen(), H.GetMaxDataLen() );

    H.ApplyToSignal( pw );

    // TODO: Handle overlapping FFD part



    TdVector *pTdVec;
    switch( IntpolType )
    {
        case LINEAR_INTERPOLATION:
        {
            pTdVec    = new TdVectorLinear( 0.0, 0.0, TickLen, pw );
            break;
        }
        case CUBIC_SPLINE_INTERPOLATION:
        {
            pTdVec    = new TdVectorCubSpline( 0.0, 0.0, TickLen, pw );
            break;
        }
    }

    // TODO: Handle pw

    return pTdVec;
}

#endif
