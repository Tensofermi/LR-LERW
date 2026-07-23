#pragma once

void Inputor::initInputor()
{
    setGroup("Model_Parameters");
    addInputor(para.D             ,   "D"               , 		    2                 );
    addInputor(para.sigma         ,   "sigma"           , 		    10000             );
    addInputor(para.L             ,   "L"               , 		    8                 );

}

void Inputor::validateInputor()
{
    std::ostringstream errors;
    if (para.D != 2) errors << "D must equal 2 for this source tree\\n";
    if (para.L <= 0) errors << "L must be positive\\n";
    if (!(para.sigma > 0.0) || !std::isfinite(para.sigma)) errors << "sigma must be finite and positive\\n";
    if (para.N_Measure == 0 || para.N_Each == 0 || para.N_Total == 0) errors << "sampling counts must be positive\\n";
    if (para.NBlock < 2) errors << "NBlock must be at least 2\\n";
    if (para.MaxNBin < para.NBlock) errors << "MaxNBin must be at least NBlock\\n";
    if (para.NperBin == 0) errors << "NperBin must be positive\\n";
    if (!errors.str().empty()) io.exportInfo(io.ErrorInfo, errors.str());
}
