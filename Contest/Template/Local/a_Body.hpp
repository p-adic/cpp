// c:/Users/user/Documents/Programming/Contest/Template/Local/a_Body.hpp

#pragma once
#include "a.hpp"

// modeの定義などはAutoCheck/a.hppに記述。
#include "../../AutoCheck/a_Body.hpp"

#include "../../../Utility/Set/a_Body.hpp"
#include "../../../Utility/Tuple/a_Body.hpp"
#include "../../../Utility/Vector/a_Body.hpp"
#include "../../../Utility/Set/Map/a_Body.hpp"
#include "../../../Utility/StdStream/a_Body.hpp"
#include "../../../Utility/String/a_Body.hpp"
#include "../../../Utility/String/ToArray/a_Body.hpp"
#include "../../../Utility/BinarySearch/Debug/a_Body.hpp"
#include "../../../Utility/TwoPointerApproach/Debug/a_Body.hpp"

#include "../../../Mathematics/Algebra/Monoid/Group/Module/a_Body.hpp"
#include "../../../Mathematics/Geometry/Graph/Grid/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a_Body.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a_Body.hpp"

inline void AlertAbort( int n ) { CERR( "abort関数が呼ばれました。assertマクロのメッセージが出力されていない場合はオーバーフローの有無を確認をしてください。" ); }
