/*
 * Copyright (c) 2003, 2007-8 Matteo Frigo
 * Copyright (c) 2003, 2007-8 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Jul 12 06:45:48 EDT 2009 */

#include "../../codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 6 -dif -name hb_6 -include hb.h */

/*
 * This function contains 46 FP additions, 32 FP multiplications,
 * (or, 24 additions, 10 multiplications, 22 fused multiply/add),
 * 45 stack variables, 2 constants, and 24 memory accesses
 */
#include "../hb.h"

static void hb_6(float *cr, float *ci, const float *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     INT m;
     for (m = mb, W = W + ((mb - 1) * 10); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 10, MAKE_VOLATILE_STRIDE(rs)) {
	  E TK, TR, TB, TM, TL, TS;
	  {
	       E Td, TN, TO, TJ, Tn, Tk, TC, T3, Tr, T4, T5, T7, T8;
	       {
		    E TH, Tg, Tj, TI, Th, Ti, T1, T2;
		    {
			 E Tb, Tc, Te, Tf;
			 Tb = ci[WS(rs, 5)];
			 Tc = cr[WS(rs, 3)];
			 Te = ci[WS(rs, 3)];
			 Tf = cr[WS(rs, 5)];
			 Th = ci[WS(rs, 4)];
			 Td = Tb - Tc;
			 TN = Tb + Tc;
			 Ti = cr[WS(rs, 4)];
			 TH = Te + Tf;
			 Tg = Te - Tf;
		    }
		    Tj = Th - Ti;
		    TI = Th + Ti;
		    T1 = cr[0];
		    T2 = ci[WS(rs, 2)];
		    TO = TH - TI;
		    TJ = TH + TI;
		    Tn = Tj - Tg;
		    Tk = Tg + Tj;
		    TC = T1 - T2;
		    T3 = T1 + T2;
		    Tr = FNMS(KP500000000, Tk, Td);
		    T4 = cr[WS(rs, 2)];
		    T5 = ci[0];
		    T7 = ci[WS(rs, 1)];
		    T8 = cr[WS(rs, 1)];
	       }
	       {
		    E Tl, Tq, TQ, Ts, Ta, T10, TG;
		    ci[0] = Td + Tk;
		    {
			 E T6, TD, T9, TE, TF;
			 T6 = T4 + T5;
			 TD = T4 - T5;
			 T9 = T7 + T8;
			 TE = T7 - T8;
			 Tl = W[2];
			 Tq = W[3];
			 TQ = TD - TE;
			 TF = TD + TE;
			 Ts = T6 - T9;
			 Ta = T6 + T9;
			 T10 = TC + TF;
			 TG = FNMS(KP500000000, TF, TC);
		    }
		    {
			 E T13, TP, Tz, TZ, Tw, T14, Tv, Ty;
			 {
			      E Tt, T12, T11, Tp, Tm, To, Tu;
			      T13 = TN + TO;
			      TP = FNMS(KP500000000, TO, TN);
			      cr[0] = T3 + Ta;
			      Tm = FNMS(KP500000000, Ta, T3);
			      Tz = FMA(KP866025403, Ts, Tr);
			      Tt = FNMS(KP866025403, Ts, Tr);
			      TZ = W[4];
			      To = FNMS(KP866025403, Tn, Tm);
			      Tw = FMA(KP866025403, Tn, Tm);
			      Tu = Tl * Tt;
			      T12 = W[5];
			      T11 = TZ * T10;
			      Tp = Tl * To;
			      ci[WS(rs, 2)] = FMA(Tq, To, Tu);
			      T14 = T12 * T10;
			      cr[WS(rs, 3)] = FNMS(T12, T13, T11);
			      cr[WS(rs, 2)] = FNMS(Tq, Tt, Tp);
			 }
			 ci[WS(rs, 3)] = FMA(TZ, T13, T14);
			 Tv = W[6];
			 Ty = W[7];
			 {
			      E TX, TT, TW, TV, TY, TU, TA, Tx;
			      TK = FNMS(KP866025403, TJ, TG);
			      TU = FMA(KP866025403, TJ, TG);
			      TA = Tv * Tz;
			      Tx = Tv * Tw;
			      TX = FNMS(KP866025403, TQ, TP);
			      TR = FMA(KP866025403, TQ, TP);
			      ci[WS(rs, 4)] = FMA(Ty, Tw, TA);
			      cr[WS(rs, 4)] = FNMS(Ty, Tz, Tx);
			      TT = W[8];
			      TW = W[9];
			      TB = W[0];
			      TV = TT * TU;
			      TY = TW * TU;
			      TM = W[1];
			      TL = TB * TK;
			      cr[WS(rs, 5)] = FNMS(TW, TX, TV);
			      ci[WS(rs, 5)] = FMA(TT, TX, TY);
			 }
		    }
	       }
	  }
	  cr[WS(rs, 1)] = FNMS(TM, TR, TL);
	  TS = TM * TK;
	  ci[WS(rs, 1)] = FMA(TB, TR, TS);
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 6},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 6, "hb_6", twinstr, &GENUS, {24, 10, 22, 0} };

void fftwf_codelet_hb_6 (planner *p) {
     fftwf_khc2hc_register (p, hb_6, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc -compact -variables 4 -pipeline-latency 4 -sign 1 -n 6 -dif -name hb_6 -include hb.h */

/*
 * This function contains 46 FP additions, 28 FP multiplications,
 * (or, 32 additions, 14 multiplications, 14 fused multiply/add),
 * 27 stack variables, 2 constants, and 24 memory accesses
 */
#include "../hb.h"

static void hb_6(float *cr, float *ci, const float *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     INT m;
     for (m = mb, W = W + ((mb - 1) * 10); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 10, MAKE_VOLATILE_STRIDE(rs)) {
	  E T3, Ty, Ta, TO, Tr, TB, Td, TE, Tk, TL, Tn, TH;
	  {
	       E T1, T2, Tb, Tc;
	       T1 = cr[0];
	       T2 = ci[WS(rs, 2)];
	       T3 = T1 + T2;
	       Ty = T1 - T2;
	       {
		    E T6, Tz, T9, TA;
		    {
			 E T4, T5, T7, T8;
			 T4 = cr[WS(rs, 2)];
			 T5 = ci[0];
			 T6 = T4 + T5;
			 Tz = T4 - T5;
			 T7 = ci[WS(rs, 1)];
			 T8 = cr[WS(rs, 1)];
			 T9 = T7 + T8;
			 TA = T7 - T8;
		    }
		    Ta = T6 + T9;
		    TO = KP866025403 * (Tz - TA);
		    Tr = KP866025403 * (T6 - T9);
		    TB = Tz + TA;
	       }
	       Tb = ci[WS(rs, 5)];
	       Tc = cr[WS(rs, 3)];
	       Td = Tb - Tc;
	       TE = Tb + Tc;
	       {
		    E Tg, TG, Tj, TF;
		    {
			 E Te, Tf, Th, Ti;
			 Te = ci[WS(rs, 3)];
			 Tf = cr[WS(rs, 5)];
			 Tg = Te - Tf;
			 TG = Te + Tf;
			 Th = ci[WS(rs, 4)];
			 Ti = cr[WS(rs, 4)];
			 Tj = Th - Ti;
			 TF = Th + Ti;
		    }
		    Tk = Tg + Tj;
		    TL = KP866025403 * (TG + TF);
		    Tn = KP866025403 * (Tj - Tg);
		    TH = TF - TG;
	       }
	  }
	  cr[0] = T3 + Ta;
	  ci[0] = Td + Tk;
	  {
	       E TC, TI, Tx, TD;
	       TC = Ty + TB;
	       TI = TE - TH;
	       Tx = W[4];
	       TD = W[5];
	       cr[WS(rs, 3)] = FNMS(TD, TI, Tx * TC);
	       ci[WS(rs, 3)] = FMA(TD, TC, Tx * TI);
	  }
	  {
	       E To, Tu, Ts, Tw, Tm, Tq;
	       Tm = FNMS(KP500000000, Ta, T3);
	       To = Tm - Tn;
	       Tu = Tm + Tn;
	       Tq = FNMS(KP500000000, Tk, Td);
	       Ts = Tq - Tr;
	       Tw = Tr + Tq;
	       {
		    E Tl, Tp, Tt, Tv;
		    Tl = W[2];
		    Tp = W[3];
		    cr[WS(rs, 2)] = FNMS(Tp, Ts, Tl * To);
		    ci[WS(rs, 2)] = FMA(Tl, Ts, Tp * To);
		    Tt = W[6];
		    Tv = W[7];
		    cr[WS(rs, 4)] = FNMS(Tv, Tw, Tt * Tu);
		    ci[WS(rs, 4)] = FMA(Tt, Tw, Tv * Tu);
	       }
	  }
	  {
	       E TM, TS, TQ, TU, TK, TP;
	       TK = FNMS(KP500000000, TB, Ty);
	       TM = TK - TL;
	       TS = TK + TL;
	       TP = FMA(KP500000000, TH, TE);
	       TQ = TO + TP;
	       TU = TP - TO;
	       {
		    E TJ, TN, TR, TT;
		    TJ = W[0];
		    TN = W[1];
		    cr[WS(rs, 1)] = FNMS(TN, TQ, TJ * TM);
		    ci[WS(rs, 1)] = FMA(TN, TM, TJ * TQ);
		    TR = W[8];
		    TT = W[9];
		    cr[WS(rs, 5)] = FNMS(TT, TU, TR * TS);
		    ci[WS(rs, 5)] = FMA(TT, TS, TR * TU);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 6},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 6, "hb_6", twinstr, &fftwf_rdft_hb_genus, {32, 14, 14, 0} };

void fftwf_codelet_hb_6 (planner *p) {
     fftwf_khc2hc_register (p, hb_6, &desc);
}
#endif				/* HAVE_FMA */
