#include "bitonicSort.h"
#include "../../../../include/objects.h"

//Main CAE block (compare and exchange)
GreaterSmaller AscendDescend(Tower &x, Tower &y){
#pragma HLS PIPELINE II=9
#pragma HLS INLINE
    GreaterSmaller s;

    s.greater = (x.tower_et() > y.tower_et()) ? x.tower_et() : y.tower_et();
    s.smaller = (x.tower_et() > y.tower_et()) ? y.tower_et() : x.tower_et();

    return s;
}

void FourinSmallFir(Tower &x0, Tower &x1, Tower &x2, Tower &x3,
					Tower &y0, Tower &y1, Tower &y2, Tower &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res1;
        res1 = AscendDescend(x0, x2);
        y0.data.range(19, 10) = res1.smaller; y2.data.range(19, 10) = res1.greater;

        res1 = AscendDescend(x1, x3);
        y1.data.range(19, 10) = res1.smaller; y3.data.range(19, 10) = res1.greater;
}

void FourinGreatFir(Tower &x0, Tower &x1, Tower &x2, Tower &x3,
					Tower &y0, Tower &y1, Tower &y2, Tower &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res2;
        res2 = AscendDescend(x0, x2);
        y0.data.range(19, 10) = res2.greater; y2.data.range(19, 10) = res2.smaller;

        res2 = AscendDescend(x1, x3);
        y1.data.range(19, 10) = res2.greater; y3.data.range(19, 10) = res2.smaller;
}

void EightinSmallFir(Tower &x0, Tower &x1, Tower &x2, Tower &x3, Tower &x4, Tower &x5,
                Tower &x6, Tower &x7, Tower &y0, Tower &y1, Tower &y2, Tower &y3, Tower &y4, Tower &y5, Tower &y6, Tower &y7){
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res3;
        res3 = AscendDescend(x0, x4);
        y0.data.range(19, 10) = res3.smaller; y4.data.range(19, 10) = res3.greater;

        res3 = AscendDescend(x1, x5);
        y1.data.range(19, 10) = res3.smaller; y5.data.range(19, 10) = res3.greater;

        res3 = AscendDescend(x2, x6);
        y2.data.range(19, 10) = res3.smaller; y6.data.range(19, 10) = res3.greater;

        res3 = AscendDescend(x3, x7);
        y3.data.range(19, 10) = res3.smaller; y7.data.range(19, 10) = res3.greater;

}

void EightinGreatFir(Tower &x8, Tower &x9, Tower &x10, Tower &x11, Tower &x12, Tower &x13,
                Tower &x14, Tower &x15, Tower &y8, Tower &y9, Tower &y10, Tower &y11, Tower &y12, Tower &y13, Tower &y14, Tower &y15){
        #pragma HLS PIPELINE II=9
       	#pragma HLS INLINE
        GreaterSmaller res4;
        res4 = AscendDescend(x8, x12);
        y8.data.range(19, 10) = res4.greater; y12.data.range(19, 10) = res4.smaller;

        res4 = AscendDescend(x9, x13);
        y9.data.range(19, 10) = res4.greater; y13.data.range(19, 10) = res4.smaller;

        res4 = AscendDescend(x10, x14);
        y10.data.range(19, 10) = res4.greater; y14.data.range(19, 10) = res4.smaller;

        res4 = AscendDescend(x11, x15);
        y11.data.range(19, 10) = res4.greater; y15.data.range(19, 10) = res4.smaller;

}

void SixteenSmallFir(Tower &x0, Tower &x1, Tower &x2, Tower &x3, Tower &x4, Tower &x5,
                     Tower &x6, Tower &x7, Tower &x8, Tower &x9, Tower &x10, Tower &x11, Tower &x12,
                     Tower &x13, Tower &x14, Tower &x15, Tower &y0, Tower &y1, Tower &y2, Tower &y3, Tower &y4, Tower &y5, Tower &y6,
                    Tower &y7, Tower &y8, Tower &y9, Tower &y10, Tower &y11, Tower &y12, Tower &y13, Tower &y14, Tower &y15){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res5;

        res5 = AscendDescend(x0, x8);
        y0.data.range(19, 10) = res5.smaller; y8.data.range(19, 10) = res5.greater;

        res5 = AscendDescend(x1, x9);
        y1.data.range(19, 10) = res5.smaller; y9.data.range(19, 10) = res5.greater;

        res5 = AscendDescend(x2, x10);
        y2.data.range(19, 10) = res5.smaller; y10.data.range(19, 10) = res5.greater;

        res5 = AscendDescend(x3, x11);
        y3.data.range(19, 10) = res5.smaller; y11.data.range(19, 10) = res5.greater;

        res5 = AscendDescend(x4, x12);
        y4.data.range(19, 10) = res5.smaller; y12.data.range(19, 10) = res5.greater;

        res5 = AscendDescend(x5, x13);
        y5.data.range(19, 10) = res5.smaller; y13.data.range(19, 10) = res5.greater;

        res5 = AscendDescend(x6, x14);
        y6.data.range(19, 10) = res5.smaller; y14.data.range(19, 10) = res5.greater;

        res5 = AscendDescend(x7, x15);
        y7.data.range(19, 10) = res5.smaller; y15.data.range(19, 10) = res5.greater;
}

void SixteenGreatFir(Tower &x16, Tower &x17, Tower &x18, Tower &x19, Tower &x20, Tower &x21,
                     Tower &x22, Tower &x23, Tower &x24, Tower &x25, Tower &x26, Tower &x27, Tower &x28,
                     Tower &x29, Tower &x30, Tower &x31, Tower &y16, Tower &y17, Tower &y18, Tower &y19, Tower &y20, Tower &y21, Tower &y22,
                    Tower &y23, Tower &y24, Tower &y25, Tower &y26, Tower &y27, Tower &y28, Tower &y29, Tower &y30, Tower &y31){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res6;

        res6 = AscendDescend(x16, x24);
        y16.data.range(19, 10) = res6.greater; y24.data.range(19, 10) = res6.smaller;

        res6 = AscendDescend(x17, x25);
        y17.data.range(19, 10) = res6.greater; y25.data.range(19, 10) = res6.smaller;

        res6 = AscendDescend(x18, x26);
        y18.data.range(19, 10) = res6.greater; y26.data.range(19, 10) = res6.smaller;

        res6 = AscendDescend(x19, x27);
        y19.data.range(19, 10) = res6.greater; y27.data.range(19, 10) = res6.smaller;

        res6 = AscendDescend(x20, x28);
        y20.data.range(19, 10) = res6.greater; y28.data.range(19, 10) = res6.smaller;

        res6 = AscendDescend(x21, x29);
        y21.data.range(19, 10) = res6.greater; y29.data.range(19, 10) = res6.smaller;

        res6 = AscendDescend(x22, x30);
        y22.data.range(19, 10) = res6.greater; y30.data.range(19, 10) = res6.smaller;

        res6 = AscendDescend(x23, x31);
        y23.data.range(19, 10) = res6.greater; y31.data.range(19, 10) = res6.smaller;
}

void bitonicSort(Tower in[M], Tower out[M]){
#pragma HLS PIPELINE II=9

#pragma HLS ARRAY_PARTITION variable=in
#pragma HLS ARRAY_PARTITION variable=out

GreaterSmaller result;

Tower a[M], b[M], c[M], d[M], e[M], f[M], g[M], h[M], l[M], m[M], n[M], o[M], p[M], q[M];
#pragma HLS ARRAY_PARTITION variable=a
#pragma HLS ARRAY_PARTITION variable=b
#pragma HLS ARRAY_PARTITION variable=c
#pragma HLS ARRAY_PARTITION variable=d
#pragma HLS ARRAY_PARTITION variable=e
#pragma HLS ARRAY_PARTITION variable=f
#pragma HLS ARRAY_PARTITION variable=g
#pragma HLS ARRAY_PARTITION variable=h
#pragma HLS ARRAY_PARTITION variable=l
#pragma HLS ARRAY_PARTITION variable=m
#pragma HLS ARRAY_PARTITION variable=n
#pragma HLS ARRAY_PARTITION variable=o
#pragma HLS ARRAY_PARTITION variable=p
#pragma HLS ARRAY_PARTITION variable=q

//.........................Starting first stage..........................//

for(dloop_t i=0; i<M/4; i++){
    #pragma HLS unroll
    result = AscendDescend(in[4*i], in[4*i+1]);
    a[4*i].data.range(19, 10) = result.smaller; a[4*i+1].data.range(19, 10) = result.greater;
}

for(dloop_t i=0; i<M/4; i++){
    #pragma HLS unroll
    result = AscendDescend(in[4*i+2], in[4*i+3]);
    a[4*i+2].data.range(19, 10) = result.greater; a[4*i+3].data.range(19, 10) = result.smaller;
}

//.........................Starting second stage..........................//

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    FourinSmallFir(a[8*i], a[8*i+1], a[8*i+2], a[8*i+3], b[8*i], b[8*i+1], b[8*i+2], b[8*i+3]);
    FourinGreatFir(a[8*i+4], a[8*i+5], a[8*i+6], a[8*i+7], b[8*i+4], b[8*i+5], b[8*i+6], b[8*i+7]); 
}

//....................Starting third stage..............................//

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    result = AscendDescend(b[8*i], b[8*i+1]);
    c[8*i].data.range(19, 10) = result.smaller; c[8*i+1].data.range(19, 10) = result.greater;
 
    result = AscendDescend(b[8*i+2], b[8*i+3]);
    c[8*i+2].data.range(19, 10) = result.smaller; c[8*i+3].data.range(19, 10) = result.greater;
}

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    result = AscendDescend(b[8*i+4], b[8*i+5]);
    c[8*i+4].data.range(19, 10) = result.greater; c[8*i+5].data.range(19, 10) = result.smaller;

    result = AscendDescend(b[8*i+6], b[8*i+7]);
    c[8*i+6].data.range(19, 10) = result.greater; c[8*i+7].data.range(19, 10) = result.smaller;
}

//.....................Starting fourth stage..............................//

for(dloop_t i=0; i<M/16; i++){
EightinSmallFir(c[16*i+0], c[16*i+1], c[16*i+2], c[16*i+3], c[16*i+4], c[16*i+5], c[16*i+6], c[16*i+7],
                 d[16*i+0], d[16*i+1], d[16*i+2], d[16*i+3], d[16*i+4], d[16*i+5], d[16*i+6], d[16*i+7]);
EightinGreatFir(c[16*i+8], c[16*i+9], c[16*i+10], c[16*i+11], c[16*i+12], c[16*i+13], c[16*i+14], c[16*i+15],
                 d[16*i+8], d[16*i+9], d[16*i+10], d[16*i+11], d[16*i+12], d[16*i+13], d[16*i+14], d[16*i+15]);
}

//.....................Starting fifth stage................................//

for(dloop_t i=0; i<M/16; i++){
    #pragma HLS unroll
        FourinSmallFir(d[16*i], d[16*i+1], d[16*i+2], d[16*i+3], e[16*i], e[16*i+1], e[16*i+2], e[16*i+3]);
        FourinSmallFir(d[16*i+4], d[16*i+5], d[16*i+6], d[16*i+7], e[16*i+4], e[16*i+5], e[16*i+6], e[16*i+7]);
        FourinGreatFir(d[16*i+8], d[16*i+9], d[16*i+10], d[16*i+11], e[16*i+8], e[16*i+9], e[16*i+10], e[16*i+11]);
        FourinGreatFir(d[16*i+12], d[16*i+13], d[16*i+14], d[16*i+15], e[16*i+12], e[16*i+13], e[16*i+14], e[16*i+15]);
}

//.....................Starting sixth stage..............................//

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    result = AscendDescend(e[2*i], e[2*i+1]);
    f[2*i].data.range(19, 10) = result.smaller; f[2*i+1].data.range(19, 10) = result.greater;
}

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    result = AscendDescend(e[2*i+8], e[2*i+9]);
    f[2*i+8].data.range(19, 10) = result.greater; f[2*i+9].data.range(19, 10) = result.smaller;
}

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    result = AscendDescend(e[2*i+16], e[2*i+17]);
    f[2*i+16].data.range(19, 10) = result.smaller; f[2*i+17].data.range(19, 10) = result.greater;
}

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    result = AscendDescend(e[2*i+24], e[2*i+25]);
    f[2*i+24].data.range(19, 10) = result.greater; f[2*i+25].data.range(19, 10) = result.smaller;
}

//.....................Starting seventh stage.............................//

SixteenSmallFir(f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7],
                 f[8], f[9], f[10], f[11], f[12], f[13], f[14], f[15], 
                 g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], 
                 g[9], g[10], g[11], g[12], g[13], g[14], g[15]);
SixteenGreatFir(f[16], f[17], f[18], f[19], f[20], f[21], f[22], f[23],
                 f[24], f[25], f[26], f[27], f[28], f[29], f[30], f[31], 
                 g[16], g[17], g[18], g[19], g[20], g[21], g[22], g[23], g[24], 
                 g[25], g[26], g[27], g[28], g[29], g[30], g[31]);


//.....................Starting eighth stage..............................//

for(dloop_t i=0; i<M/16; i++){
    #pragma HLS unroll
    EightinSmallFir(g[8*i], g[8*i+1], g[8*i+2], g[8*i+3], g[8*i+4], g[8*i+5], g[8*i+6], g[8*i+7],
                 h[8*i], h[8*i+1], h[8*i+2], h[8*i+3], h[8*i+4], h[8*i+5], h[8*i+6], h[8*i+7]);
}

for(dloop_t i=0; i<M/16; i++){
    #pragma HLS unroll
    EightinGreatFir(g[8*i+16], g[8*i+17], g[8*i+18], g[8*i+19], g[8*i+20], g[8*i+21], g[8*i+22], g[8*i+23],
                 h[8*i+16], h[8*i+17], h[8*i+18], h[8*i+19], h[8*i+20], h[8*i+21], h[8*i+22], h[8*i+23]);
}

//.....................Starting ninth stage................................//

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    FourinSmallFir(h[4*i], h[4*i+1], h[4*i+2], h[4*i+3], l[4*i], l[4*i+1], l[4*i+2], l[4*i+3]);
}

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    FourinGreatFir(h[4*i+16], h[4*i+17], h[4*i+18], h[4*i+19], l[4*i+16], l[4*i+17], l[4*i+18], l[4*i+19]);
}

//.....................Starting tenth stage...............................//

for(dloop_t i=0; i<M/4; i++)
{
    #pragma HLS unroll
    result = AscendDescend(l[2*i], l[2*i+1]);
    m[2*i].data.range(19, 10) = result.smaller; m[2*i+1].data.range(19, 10) = result.greater;
}

for(dloop_t i=0; i<M/4; i++){
    #pragma HLS unroll
    result = AscendDescend(l[2*i+16], l[2*i+17]);
    m[2*i+16].data.range(19, 10) = result.greater; m[2*i+17].data.range(19, 10) = result.smaller;
}

//.....................Starting eleventh stage.............................//

for(dloop_t i=0; i<M/2; i++){
    #pragma HLS unroll
    result = AscendDescend(m[i], m[i+16]);
    n[i].data.range(19, 10) = result.smaller; n[i+16].data.range(19, 10) = result.greater;
}

//.....................Starting twelfth stage............................//

for(dloop_t i=0; i<M/16; i++){
    #pragma HLS unroll
    SixteenSmallFir(n[16*i], n[16*i+1], n[16*i+2], n[16*i+3], n[16*i+4], n[16*i+5], n[16*i+6], n[16*i+7],
                 n[16*i+8], n[16*i+9], n[16*i+10], n[16*i+11], n[16*i+12], n[16*i+13], n[16*i+14], n[16*i+15], 
                 o[16*i+0], o[16*i+1], o[16*i+2], o[16*i+3], o[16*i+4], o[16*i+5], o[16*i+6], o[16*i+7], o[16*i+8], 
                 o[16*i+9], o[16*i+10], o[16*i+11], o[16*i+12], o[16*i+13], o[16*i+14], o[16*i+15]);
}

//.....................Starting thirteenth stage..........................//

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS unroll
    EightinSmallFir(o[8*i], o[8*i+1], o[8*i+2], o[8*i+3], o[8*i+4], o[8*i+5], o[8*i+6], o[8*i+7],
                p[8*i], p[8*i+1], p[8*i+2], p[8*i+3], p[8*i+4], p[8*i+5], p[8*i+6], p[8*i+7]);
}

//.....................Starting fourteenth stage............................//

for(dloop_t i=0; i<M/4; i++){
    #pragma HLS unroll
    FourinSmallFir(p[4*i], p[4*i+1], p[4*i+2], p[4*i+3], q[4*i], q[4*i+1], q[4*i+2], q[4*i+3]);
}

//.....................Starting fifteenth stage..............................//

for(dloop_t i=0; i<M/2; i++){
    #pragma HLS unroll
    result = AscendDescend(q[2*i], q[2*i+1]);
    out[2*i].data.range(19, 10) = result.smaller; out[2*i+1].data.range(19, 10) = result.greater;
}

}
