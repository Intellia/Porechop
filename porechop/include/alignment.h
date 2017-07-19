
#ifndef ALIGNMENT_H
#define ALIGNMENT_H


#include <string>
#include <seqan/basic.h>
#include <seqan/align.h>

using namespace seqan;

namespace seqan {

struct NAsMatchMatrix {};

#define M 2
#define X -2

template <>
struct ScoringMatrixData_<int, Dna5, NAsMatchMatrix>
{
    enum
    {
        VALUE_SIZE = ValueSize<Dna5>::VALUE,
        TAB_SIZE = VALUE_SIZE * VALUE_SIZE
    };

    static inline int const * getData()
    {
        static int const _data[TAB_SIZE] =
            { /*A  C  G  T  N*/
                M, X, X, X, M, /* A */
                X, M, X, X, M, /* C */
                X, X, M, X, M, /* G */
                X, X, X, M, M, /* T */
                X, X, X, X, M  /* N */
            };
        return _data;
    }
};

#undef M
#undef X

}

class ScoredAlignment {
public:
    ScoredAlignment(Align<Dna5String, ArrayGaps> & alignment,
                    int readLength, int adapterLength, int score);
    std::string getString();

    int m_readLength;
    int m_adapterLength;
    int m_readStartPos;
    int m_readEndPos;
    int m_adapterStartPos;
    int m_adapterEndPos;
    int m_rawScore;
    double m_alignedRegionPercentIdentity;
    double m_fullAdapterPercentIdentity;
    std::string m_umi;
};

#endif // ALIGNMENT_H
