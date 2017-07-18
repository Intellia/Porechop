#include "adapter_align.h"
#include <stdio.h>

using namespace std;

int main() {
    char read[] = "CTGTGCTTCGTTCCAGTTACGTATTGCTCGCTTCCGATCTTGTTCTAGATTTTTGCAAAGATGTGTATAAAGAGACAG";
    char adpt[] = "TGTTCTAGNNNNNNNNNNAGATGTGTATAAGAGACAG";
    char *align = adapterAlignment(
        read
        , adpt
        , 3
        , -1
        , -3
        , -1);

    /*
     *
     *  m_readStartPos
        m_readEndPos
        m_adapterStartPos
        m_adapterEndPos
        m_rawScore
        m_alignedRegionPercentIdentity
        m_fullAdapterPercentIdentity

     * */
    fprintf(stderr, "%s\n", align);
    return 0;
}