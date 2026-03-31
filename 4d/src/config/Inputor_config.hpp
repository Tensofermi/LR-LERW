#pragma once

void Inputor::initInputor()
{
    setGroup("Model_Parameters");
    addInputor(para.D             ,   "D"               , 		    2                 );
    addInputor(para.sigma         ,   "sigma"           , 		    10000             );
    addInputor(para.L             ,   "L"               , 		    8                 );



}
