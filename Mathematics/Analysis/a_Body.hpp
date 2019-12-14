// Analysis/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/GlobalVariable/a_Body.hpp"

template <> inline const double& pi<double>(){ return *( GLOBAL_CONSTANT( double , pi , 3.14159265358979 ) ); }
template <> inline const float& pi<float>(){ return *( GLOBAL_CONSTANT( float , pi , 3.1415926 ) ); }
