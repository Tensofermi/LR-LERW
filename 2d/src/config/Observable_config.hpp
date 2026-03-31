#pragma once

void Observable::initObservable()  // add addBasicObser() & addCombiObser()
{
	int Vol = pow(para.L, para.D);

    //  Observables               Name           				Description             		 A     +     B  *  Obs 
    addBasicObser(para.i_Len_8        	 , "Len_8"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_16        	 , "Len_16"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_32        	 , "Len_32"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_64        	 , "Len_64"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_128         , "Len_128"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_256         , "Len_256"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_512         , "Len_512"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_1024        , "Len_1024"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_2048        , "Len_2048"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_4096        , "Len_4096"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_8192        , "Len_8192"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_16384       , "Len_16384"       	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len_32768       , "Len_32768"       	, ""    				, 0     , 1.0      					);

	addBasicObser(para.i_Lop_8        	 , "Lop_8"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_16          , "Lop_16"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_32          , "Lop_32"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_64          , "Lop_64"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_128         , "Lop_128"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_256         , "Lop_256"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_512         , "Lop_512"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_1024        , "Lop_1024"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_2048        , "Lop_2048"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_4096        , "Lop_4096"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_8192        , "Lop_8192"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_16384       , "Lop_16384"       	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop_32768       , "Lop_32768"       	, ""    				, 0     , 1.0      					);

    addBasicObser(para.i_Len2_8        	  , "Len2_8"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_16          , "Len2_16"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_32          , "Len2_32"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_64          , "Len2_64"        		, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_128         , "Len2_128"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_256         , "Len2_256"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_512         , "Len2_512"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_1024        , "Len2_1024"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_2048        , "Len2_2048"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_4096        , "Len2_4096"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_8192        , "Len2_8192"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_16384       , "Len2_16384"       	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Len2_32768       , "Len2_32768"       	, ""    				, 0     , 1.0      					);

	addBasicObser(para.i_Lop2_8           , "Lop2_8"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_16          , "Lop2_16"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_32          , "Lop2_32"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_64          , "Lop2_64"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_128         , "Lop2_128"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_256         , "Lop2_256"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_512         , "Lop2_512"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_1024        , "Lop2_1024"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_2048        , "Lop2_2048"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_4096        , "Lop2_4096"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_8192        , "Lop2_8192"        	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_16384       , "Lop2_16384"       	, ""    				, 0     , 1.0      					);
	addBasicObser(para.i_Lop2_32768       , "Lop2_32768"       	, ""    				, 0     , 1.0      					);


    addCombiObser(para.i_LenQ_8        	  , "LenQ_8"        		, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_16          , "LenQ_16"        		, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_32          , "LenQ_32"        		, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_64          , "LenQ_64"        		, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_128         , "LenQ_128"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_256         , "LenQ_256"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_512         , "LenQ_512"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_1024        , "LenQ_1024"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_2048        , "LenQ_2048"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_4096        , "LenQ_4096"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_8192        , "LenQ_8192"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_16384       , "LenQ_16384"       	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LenQ_32768       , "LenQ_32768"       	, ""    				, 0     , 1.0      					);

	addCombiObser(para.i_LopQ_8        	 , "LopQ_8"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_16          , "LopQ_16"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_32          , "LopQ_32"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_64          , "LopQ_64"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_128         , "LopQ_128"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_256         , "LopQ_256"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_512         , "LopQ_512"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_1024        , "LopQ_1024"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_2048        , "LopQ_2048"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_4096        , "LopQ_4096"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_8192        , "LopQ_8192"        	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_16384       , "LopQ_16384"       	, ""    				, 0     , 1.0      					);
	addCombiObser(para.i_LopQ_32768       , "LopQ_32768"       	, ""    				, 0     , 1.0      					);

}

void Observable::calCombiObser()  // add Result[]
{
	Result[para.i_LenQ_8] = Ob[para.i_Len_8] * Ob[para.i_Len_8] / Ob[para.i_Len2_8];
	Result[para.i_LenQ_16] = Ob[para.i_Len_16] * Ob[para.i_Len_16] / Ob[para.i_Len2_16];
	Result[para.i_LenQ_32] = Ob[para.i_Len_32] * Ob[para.i_Len_32] / Ob[para.i_Len2_32];
	Result[para.i_LenQ_64] = Ob[para.i_Len_64] * Ob[para.i_Len_64] / Ob[para.i_Len2_64];
	Result[para.i_LenQ_128] = Ob[para.i_Len_128] * Ob[para.i_Len_128] / Ob[para.i_Len2_128];
	Result[para.i_LenQ_256] = Ob[para.i_Len_256] * Ob[para.i_Len_256] / Ob[para.i_Len2_256];
	Result[para.i_LenQ_512] = Ob[para.i_Len_512] * Ob[para.i_Len_512] / Ob[para.i_Len2_512];
	Result[para.i_LenQ_1024] = Ob[para.i_Len_1024] * Ob[para.i_Len_1024] / Ob[para.i_Len2_1024];
	Result[para.i_LenQ_2048] = Ob[para.i_Len_2048] * Ob[para.i_Len_2048] / Ob[para.i_Len2_2048];
	Result[para.i_LenQ_4096] = Ob[para.i_Len_4096] * Ob[para.i_Len_4096] / Ob[para.i_Len2_4096];
	Result[para.i_LenQ_8192] = Ob[para.i_Len_8192] * Ob[para.i_Len_8192] / Ob[para.i_Len2_8192];
	Result[para.i_LenQ_16384] = Ob[para.i_Len_16384] * Ob[para.i_Len_16384] / Ob[para.i_Len2_16384];
	Result[para.i_LenQ_32768] = Ob[para.i_Len_32768] * Ob[para.i_Len_32768] / Ob[para.i_Len2_32768];

	Result[para.i_LopQ_8] = Ob[para.i_Lop_8] * Ob[para.i_Lop_8] / Ob[para.i_Lop2_8];
	Result[para.i_LopQ_16] = Ob[para.i_Lop_16] * Ob[para.i_Lop_16] / Ob[para.i_Lop2_16];
	Result[para.i_LopQ_32] = Ob[para.i_Lop_32] * Ob[para.i_Lop_32] / Ob[para.i_Lop2_32];
	Result[para.i_LopQ_64] = Ob[para.i_Lop_64] * Ob[para.i_Lop_64] / Ob[para.i_Lop2_64];
	Result[para.i_LopQ_128] = Ob[para.i_Lop_128] * Ob[para.i_Lop_128] / Ob[para.i_Lop2_128];
	Result[para.i_LopQ_256] = Ob[para.i_Lop_256] * Ob[para.i_Lop_256] / Ob[para.i_Lop2_256];
	Result[para.i_LopQ_512] = Ob[para.i_Lop_512] * Ob[para.i_Lop_512] / Ob[para.i_Lop2_512];
	Result[para.i_LopQ_1024] = Ob[para.i_Lop_1024] * Ob[para.i_Lop_1024] / Ob[para.i_Lop2_1024];
	Result[para.i_LopQ_2048] = Ob[para.i_Lop_2048] * Ob[para.i_Lop_2048] / Ob[para.i_Lop2_2048];
	Result[para.i_LopQ_4096] = Ob[para.i_Lop_4096] * Ob[para.i_Lop_4096] / Ob[para.i_Lop2_4096];
	Result[para.i_LopQ_8192] = Ob[para.i_Lop_8192] * Ob[para.i_Lop_8192] / Ob[para.i_Lop2_8192];
	Result[para.i_LopQ_16384] = Ob[para.i_Lop_16384] * Ob[para.i_Lop_16384] / Ob[para.i_Lop2_16384];
	Result[para.i_LopQ_32768] = Ob[para.i_Lop_32768] * Ob[para.i_Lop_32768] / Ob[para.i_Lop2_32768];

	
}

// ---------------------------------------------
// This function prints the Monte Carlo results.
// ---------------------------------------------
std::string Observable::printOutput(bool Flag)
{
	std::string str = "";
	ZZ0 = NBin * NperBin + IBin;

	str += "==============================================================================\n";
	str += l_jf("D = " + toStr(para.D), 22) + "\n";
	str += l_jf("sigma = " + toStr(para.sigma), 22) + l_jf("L = " + toStr(para.L), 22) + "\n";
	str += l_jf("N_Therm = " + toStr(para.N_Therm), 22) + l_jf("N_Total = " + toStr(para.N_Total), 22) + l_jf("Seed = " + toStr(para.Seed), 22) + "\n";
	str += l_jf("N_Measure = " + toStr(para.N_Measure), 22) + l_jf("N_Each = " + toStr(para.N_Each), 22) + l_jf("NBlock = " + toStr(para.NBlock), 22) + "\n";
	str += "==============================================================================\n";

	if(Flag)
	{
		double time_ratio = MCStep / (double)para.N_Each / (double)para.N_Total;

		if(NBin >= NBlock)
		{
			ZZ = (NBin / NBlock) * NBlock * NperBin;
			//--------------------------------------------------//
			//------------ obtain average and error ------------//
			//--------------------------------------------------//
			calAveErr();	
			//--------------------------------------------------//
			//------------ obtain average and error ------------//
			//--------------------------------------------------//
			str += "Average: ZZ = " + toStr(ZZ0) + " , MCStep = " + toStr(MCStep0) + " , Status = " + dou2str(100.0 * time_ratio, 2) + "%" + "\n";
			str += printAverage();
		}
		else
		{
			str += "    The samples are too few!!!\n";
		}
		str += "Simulation Time: " + ck.tick() + " , Total: " + ck.exportTime() + " , " + ck.exportNow() + "\n";

		//---------------------------------------------------------------
		//------------------ Estimate Time ------------------------------
		//---------------------------------------------------------------
		str += "==============================================================================\n";
		double total_time_estimate = fromStr<double>(ck.exportTime_sec()) / time_ratio;
		double remaining_time_estimate = total_time_estimate - fromStr<double>(ck.exportTime_sec());
		
		str += "Estimated Total Time     = " + ck.formTime(total_time_estimate) + " \t= " + dou2str(total_time_estimate, 2) + " s\n";
		str += "Estimated Remaining Time = " + ck.formTime(remaining_time_estimate) + " \t= " + dou2str(remaining_time_estimate, 2) + " s\n";
		//---------------------------------------------------------------
		//------------------ Estimate Time ------------------------------
		//---------------------------------------------------------------
	}
	else
	{	
		double time_ratio = MCStep / (double)para.N_Each / (double)para.N_Therm;
		str += "Current: ZZ0 = " + toStr(ZZ0) + " , MCStep0 = " + toStr(MCStep0) + " , Status = " + dou2str(100.0 * time_ratio, 2) + "%" + "\n";
		str += printCurrent();
		str += "Therm Time: " + ck.tick() + " , Total: " + ck.exportTime() + " , " + ck.exportNow() + "\n";
		
		//---------------------------------------------------------------
		//------------------ Estimate Time ------------------------------
		//---------------------------------------------------------------
		str += "==============================================================================\n";
		double total_time_estimate = fromStr<double>(ck.exportTime_sec()) / time_ratio;
		double remaining_time_estimate = total_time_estimate - fromStr<double>(ck.exportTime_sec());
		
		str += "Estimated Thermalizing Time  = " + ck.formTime(total_time_estimate) + "\t= " + dou2str(total_time_estimate, 2) + " s\n";
		str += "Estimated Remaining Time     = " + ck.formTime(remaining_time_estimate) + "\t= " + dou2str(remaining_time_estimate, 2) + " s\n";
		//---------------------------------------------------------------
		//------------------ Estimate Time ------------------------------
		//---------------------------------------------------------------
	}
	
	str += "==============================================================================\n";

	return str;
}