// c:/Users/user/Documents/Programming/Music/OnMei/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

int OnMei::KanOnToInt( const KanOn& N )
{

  const int Table[8] =
    {

      0 ,
      2 ,
      4 ,
      5 ,
      7 ,
      9 ,
      11 ,
      -1

    };

  const uint& num = N.GetNum();
  
  if( num >= 7 ){

    return Table[7];

  }

  return Table[num];

}

const OnMei& OnMeiTable( const KanOn& N , const HenkaKigou& S )
{

  static const OnMei Table[7][3] =
    {

      { OnMei( Do() , Flat() ) , OnMei( Do() ) , OnMei( Do() , Sharp() ) } ,
      { OnMei( Re() , Flat() ) , OnMei( Re() ) , OnMei( Re() , Sharp() ) } ,
      { OnMei( Mi() , Flat() ) , OnMei( Mi() ) , OnMei( Mi() , Sharp() ) } ,
      { OnMei( Fa() , Flat() ) , OnMei( Fa() ) , OnMei( Fa() , Sharp() ) } ,
      { OnMei( So() , Flat() ) , OnMei( So() ) , OnMei( So() , Sharp() ) } ,
      { OnMei( La() , Flat() ) , OnMei( La() ) , OnMei( La() , Sharp() ) } ,
      { OnMei( Ti() , Flat() ) , OnMei( Ti() ) , OnMei( Ti() , Sharp() ) }

    };

  return Table[N.GetNum()][S.GetNum()+1];
  
}

static const OnMei& OnMeiTable_Sharp( const int& num );
static const OnMei& OnMeiTable_Flat( const int& num );

const OnMei& OnMeiTable( const int& num , const bool& sharp )
{

  if( sharp ){

    return OnMeiTable_Sharp( num );

  }
  
  return OnMeiTable_Flat( num );

}

static const OnMei& OnMeiTable_Sharp( const int& num )
{

  const OnMei* p_Table[12] =
    {

      &OnMeiTable( Do() ) ,
      &OnMeiTable( Do() , Sharp() ) ,
      &OnMeiTable( Re() ) ,
      &OnMeiTable( Re() , Sharp() ) ,
      &OnMeiTable( Mi() ) ,
      &OnMeiTable( Fa() ) ,
      &OnMeiTable( Fa() , Sharp() ) ,
      &OnMeiTable( So() ) ,
      &OnMeiTable( So() , Sharp() ) ,
      &OnMeiTable( La() ) ,
      &OnMeiTable( La() , Sharp() ) ,
      &OnMeiTable( Ti() ) ,

    };

  return *p_Table[num%12];

}

static const OnMei& OnMeiTable_Flat( const int& num )
{

  const OnMei* p_Table[12] =
    {

      &OnMeiTable( Do() ) ,
      &OnMeiTable( Re() , Flat() ) ,
      &OnMeiTable( Re() ) ,
      &OnMeiTable( Mi() , Flat() ) ,
      &OnMeiTable( Mi() ) ,
      &OnMeiTable( Fa() ) ,
      &OnMeiTable( So() , Flat() ) ,
      &OnMeiTable( So() ) ,
      &OnMeiTable( La() , Flat() ) ,
      &OnMeiTable( La() ) ,
      &OnMeiTable( Ti() , Flat() ) ,
      &OnMeiTable( Ti() ) ,

    };

  return *p_Table[num%12];

}
