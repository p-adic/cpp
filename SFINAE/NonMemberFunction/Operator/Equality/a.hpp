// Equality/a.hpp

#pragma once

#include "../a.hpp"

THREE_WAYS_SFINAE_NON_MEMBER_OPERATOR_ALIAS( Equal , == , bool );

THREE_WAYS_SFINAE_NON_MEMBER_OPERATOR( Equal );
