


#include "ifftw.h"

/* Currently, mktensor_4d and mktensor_5d are only used in the MPI
   routines, where very complicated transpositions are required.
   Therefore we split them into a separate source file. */

tensor *fftwf_mktensor_4d(INT n0, INT is0, INT os0,
		       INT n1, INT is1, INT os1,
		       INT n2, INT is2, INT os2,
		       INT n3, INT is3, INT os3)
{
     tensor *x =fftwf_mktensor(4);
     x->dims[0].n = n0;
     x->dims[0].is = is0;
     x->dims[0].os = os0;
     x->dims[1].n = n1;
     x->dims[1].is = is1;
     x->dims[1].os = os1;
     x->dims[2].n = n2;
     x->dims[2].is = is2;
     x->dims[2].os = os2;
     x->dims[3].n = n3;
     x->dims[3].is = is3;
     x->dims[3].os = os3;
     return x;
}

tensor *fftwf_mktensor_5d(INT n0, INT is0, INT os0,
		       INT n1, INT is1, INT os1,
		       INT n2, INT is2, INT os2,
		       INT n3, INT is3, INT os3,
		       INT n4, INT is4, INT os4)
{
     tensor *x =fftwf_mktensor(5);
     x->dims[0].n = n0;
     x->dims[0].is = is0;
     x->dims[0].os = os0;
     x->dims[1].n = n1;
     x->dims[1].is = is1;
     x->dims[1].os = os1;
     x->dims[2].n = n2;
     x->dims[2].is = is2;
     x->dims[2].os = os2;
     x->dims[3].n = n3;
     x->dims[3].is = is3;
     x->dims[3].os = os3;
     x->dims[4].n = n4;
     x->dims[4].is = is4;
     x->dims[4].os = os4;
     return x;
}
