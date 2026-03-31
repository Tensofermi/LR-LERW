#pragma once

struct Parameter
{
    // Simulation Parameters
    int Seed;
    unsigned long N_Measure;
    unsigned long N_Each;
    unsigned long N_Therm;
    unsigned long N_Total;
    unsigned long NBlock;
    unsigned long MaxNBin;
    unsigned long NperBin;

    // Model Parameters
    int D, L;
    double sigma;

    // Observable label
    int i_Len_8, i_Len2_8, i_LenQ_8;
    int i_Len_16, i_Len2_16, i_LenQ_16;
    int i_Len_32, i_Len2_32, i_LenQ_32;
    int i_Len_64, i_Len2_64, i_LenQ_64;
    int i_Len_128, i_Len2_128, i_LenQ_128;
    int i_Len_256, i_Len2_256, i_LenQ_256;
    int i_Len_512, i_Len2_512, i_LenQ_512;
    int i_Len_1024, i_Len2_1024, i_LenQ_1024;
    int i_Len_2048, i_Len2_2048, i_LenQ_2048;
    int i_Len_4096, i_Len2_4096, i_LenQ_4096;
    int i_Len_8192, i_Len2_8192, i_LenQ_8192;
    int i_Len_16384, i_Len2_16384, i_LenQ_16384;
    int i_Len_32768, i_Len2_32768, i_LenQ_32768;

    int i_Lop_8, i_Lop2_8, i_LopQ_8;
    int i_Lop_16, i_Lop2_16, i_LopQ_16;
    int i_Lop_32, i_Lop2_32, i_LopQ_32;
    int i_Lop_64, i_Lop2_64, i_LopQ_64;
    int i_Lop_128, i_Lop2_128, i_LopQ_128;
    int i_Lop_256, i_Lop2_256, i_LopQ_256;
    int i_Lop_512, i_Lop2_512, i_LopQ_512;
    int i_Lop_1024, i_Lop2_1024, i_LopQ_1024;
    int i_Lop_2048, i_Lop2_2048, i_LopQ_2048;
    int i_Lop_4096, i_Lop2_4096, i_LopQ_4096;
    int i_Lop_8192, i_Lop2_8192, i_LopQ_8192;
    int i_Lop_16384, i_Lop2_16384, i_LopQ_16384;
    int i_Lop_32768, i_Lop2_32768, i_LopQ_32768;

    // Distribution label

};