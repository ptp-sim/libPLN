
#ifndef TDVECTORSTORAGE_HPP_
#define TDVECTORSTORAGE_HPP_

// =========================================================================
// Includes
// =========================================================================

#include <set>

#include "TdVector.hpp"
#include "TdFixPoint.hpp"

// =========================================================================
// Defines
// =========================================================================

// =========================================================================
// Type definitions
// =========================================================================

typedef enum
{
    INVALID,
    STARTUP,
    RUNNING,
}
TdVectorStorageState;

// =========================================================================
// Function declarations
// =========================================================================

class TdVectorStorage
{
    private:

        // Config

        // House keeping
        TdVectorStorageState    State;

        // Resources
        std::vector<TdVector *> Storage;
        TdFixPoint              fp;

        // Internal functions
        TdVector    *FindContainingVector( double t );

    public:

        TdVectorStorage();

        void    AddTdVec( TdVector *pTdVec );
        double  GetBeginTime();
        double  GetEndTime();
        void    ResetToFixPoint( TdFixPoint fp );
        double  InterpolateTD_nom( double t_req );
        void    ForgetPast( double t_now );
};

#endif
