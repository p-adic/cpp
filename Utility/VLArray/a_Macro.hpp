// c:/Users/user/Documents/Programming/Utility/VLArray/a_Macro.hpp

#pragma once
#ifndef AUTO_ITR
  #define AUTO_ITR( ARRAY ) auto itr_ ## ARRAY = ARRAY .begin() , end_ ## ARRAY = ARRAY .end()
  #define FOR_ITR( ARRAY ) for( AUTO_ITR( ARRAY ) , itr = itr_ ## ARRAY ; itr_ ## ARRAY != end_ ## ARRAY ; itr_ ## ARRAY ++ , itr++ )
#endif
