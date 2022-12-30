// c:/Users/user/Documents/Programming/Mathematics/Polynomial/IntervalEvaluation/a_Macro.hpp

#pragma once
#define SET_MATRIX_MULTIPOINT_EVALUATION( SAMPLE_NUM_MAX , FINAL_LENGTH , POINT ) \
  point = vector<T>( SAMPLE_NUM_MAX + 1 );				\
									\
  for( uint t = 0 ; t <= SAMPLE_NUM_MAX ; t++ ){			\
									\
    point[t] = POINT;							\
									\
  }									\
									\
  VLArray<VLArray<Polynomial<T> > > pt{};				\
  SetPointTree( point , pt );						\
  vector<T> eval[Y][Y] = {};						\
									\
  for( uint y = 0 ; y < Y ; y++ ){					\
									\
    const vector<Polynomial<T> >& M_ref_y = M_ref[y];			\
    vector<T> ( &eval_y )[Y] = eval[y];					\
									\
    for( uint x = 0 ; x < Y ; x++ ){					\
									\
      SetPointTreeEvaluation( M_ref_y[x] , pt , eval_y[x] );		\
									\
    }									\
									\
  }									\
									\
  vector<Matrix<Y,Y,T> > sample( SAMPLE_NUM_MAX + 1 , Matrix<Y,Y,T>::Zero() ); \
  sample.reserve( FINAL_LENGTH );					\
									\
  for( uint t = 0 ; t <= SAMPLE_NUM_MAX ; t++ ){			\
									\
    vector<vector<T> >& sample_t_ref = sample[t].RefTable();		\
									\
    for( uint y = 0 ; y < Y ; y++ ){					\
									\
      vector<T>& sample_t_ref_y = sample_t_ref[y];			\
      vector<T> ( &eval_y )[Y] = eval[y];				\
									\
      for( uint x = 0 ; x < Y ; x++ ){					\
									\
	sample_t_ref_y[x] = eval_y[x][t];				\
									\
      }									\
									\
    }									\
									\
  }									\


// subinterval_length / interval_length‚ÍT‚É‚¨‚¯‚é¤‚Å‚ ‚é‚±‚Æ‚É’ˆÓB
#define MULTIPLY_SUBPRODUCT_OF_PRECURSIVE_MATRIX( REST_INTERVAL_LENGTH ) \
  vector<Matrix<Y,Y,T> > eval_odd{};					\
  vector<Matrix<Y,Y,T> > eval_even{};					\
  SetIntervalEvaluation( subinterval_num_max , subinterval_length / interval_length , REST_INTERVAL_LENGTH + subinterval_num_max + 1 , sample , eval_odd ); \
  SetIntervalEvaluation( subinterval_num_max , T( subinterval_num_max + 1 ) , REST_INTERVAL_LENGTH , sample , eval_even ); \
									\
  for( uint t = 0 ; t <= subinterval_num_max ; t++ ){			\
									\
    sample[t] = eval_odd[t] * sample[t];				\
									\
  }									\
									\
  for( uint t = 0 ; t < REST_INTERVAL_LENGTH ; t++ ){			\
									\
    sample.push_back( eval_odd[t + subinterval_num_max + 1] * eval_even[t] ); \
									\
  }									\



