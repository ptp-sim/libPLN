
#ifndef FILTERKERNEL_HPP_
#define FILTERKERNEL_HPP_

// =========================================================================
// Includes
// =========================================================================

#include <FilterImpResp.hpp>
#include <complex>
#include <vector>


// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

class FilterKernel
{
    private:

        // Config

        // Resources
        FFT_ComplexVector   H;

    protected:

        FilterKernel() {};

    public:

        FilterKernel( size_t MaxDataLen, FilterImpResp &h );
        FilterKernel( size_t MaxDataLen, FilterImpResp &h1, FilterImpResp &h2 );
};

// =========================================================================
// Function declarations
// =========================================================================


#endif
