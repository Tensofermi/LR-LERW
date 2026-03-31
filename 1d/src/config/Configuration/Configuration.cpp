#include "Configuration.hpp"

Configuration::Configuration(Clock& _ck, IOControl& _io, RandomNumGen& _rn, Parameter& _para, Observable& _obs, Histogram& _his) 
: ck(_ck), io(_io), rn(_rn), para(_para), obs(_obs), his(_his), 
visited_bit((2.0 * (para.L + 1) + 1))
{
    initialConf();  // for site spin 
    initialMeas();  // for k-space and cluster measurement
    initialObsr();  // for basic observables
}

void Configuration::initialConf()
{
    //--- Initialize Basic Parameters
    Dim = para.D;
    L_max = para.L;  // Maximum length of the random walk
    Sigma = para.sigma;

}

void Configuration::initialMeas()
{


}

void Configuration::initialObsr()
{

}

#include "../Measurement_config.hpp"

bool Configuration::measureOrNot()
{
    return true;
}

void Configuration::writeCnf()
{
    
}

void Configuration::checkCnf()
{

}
