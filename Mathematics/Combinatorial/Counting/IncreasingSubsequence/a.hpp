// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/IncreasingSubsequence/a.hpp

#pragma once
#include "a_macro.hpp"

// T��bool operator<(const T&,const T&)�Ɋւ��đS�����ł���ꍇ�ɂ̂݃T�|�[�g�B

// O(size log size)��a�̘A���Ƃ͌���Ȃ����P������������𐔂��グ��B
template <typename T , int size_max> ll CountStrictlyIncreasingSubsequence( const T ( &a )[size_max] , const int& size );
template <typename T , int size_max> ll CountNonStrictlyIncreasingSubsequence( const T ( &a )[size_max] , const int& size );
template <typename T , int size_max> ll CountStrictlyIncreasingSubsequence( const T ( &a )[size_max] , const int& size , const ll& mod );
template <typename T , int size_max> ll CountNonStrictlyIncreasingSubsequence( const T ( &a )[size_max] , const int& size , const ll& mod );


// ���͈͓͂̔���
// (1) bool operator<=(const T&,const T&)���������S�����ł���B
// (2) a�̐�����infty�ł���C�ӂ̍�t�ɑ΂�t <= f(t)��true�ł���B
// (3) a�̔C�ӂ̐���t�ɑ΂�t <= infty && t!=infty��true�ł���B
// �����������ꍇ�ɂ̂݃T�|�[�g�B

// O(size log size)��a�̘A���Ƃ͌���Ȃ���󕔕���ł����ĔC�ӂ̗אڂQ����s,t�ɑ΂�
// f(s) <= t�ł�����̂̒����̍ő�l��Ԃ��B
template <typename T , T f(const T&) , int size_max> int LongestIncreasingSubsequence( const T ( &a )[size_max] , const int& size , const T& infty );
