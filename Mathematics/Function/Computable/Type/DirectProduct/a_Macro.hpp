// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/DirectProduct/a_Macro.hpp

#pragma once

#define PROD( TYPE_NAME , TYPE1 , ... ) using TYPE_NAME = DirectProductTypeOfComputableFunction< TYPE1 , __VA_ARGS__ > 

