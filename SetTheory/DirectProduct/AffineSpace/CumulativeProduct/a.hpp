// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/972299�i�z�񏉊����A��Ԙa�j
// https://atcoder.jp/contests/agc023/submissions/52375150�i�z�񏉊����A��Ԙa�t�������グ�j
// https://yukicoder.me/submissions/972330�iAbstract�A�z�񏉊����A���ݐϐρj

// ���͈͓͂̔��ŗv��
// (1) M��U�̌Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �Q�ɒl�����z��̗ݐϐς��v�Z����B
// ��������Ԑς���Ԑς̓񕪒T����p���Ȃ��ꍇ�̓��m�C�h�\����id�Ȃǂ̃_�~�[��
// Inverse���߂����̂ł悢�B

// �؍\���ɒ��ۉ�����ꍇ��
// - ���Q�ŕ����ؘa���K�v�Ȃ��AbstractDifferenceSequence
// - ���Q�ŋ�Ԙa���K�v�Ȃ��AbstractReversedDifferenceSequence
// - ���m�C�h�Ōo�H�a���K�v�Ȃ��DepthFirstSearchOnWeightedTree
// ��p����̂ŁA�����ł͔���Q�Ɣz��ɓ����������ݐϐς������B


// M.one()�ɂ�鏉����O(size)�i���m�C�h�\�����g���j
// �z��ɂ�鏉����O(size)�i���Q�\�����g���j

// ��_���O(size)�i���Q�\�����g���j
// ��_�E��ZO(size)�i���Q�\�����g���j
// ��_����ZO(size)�i���Q�\�����g���j

// �E�n�ؕАώ擾O(1)�i���m�C�h�\�����g���j
// ���n�ؕАώ擾O(1)�i���m�C�h�\�����g���j

// �E��Ԑώ擾O(1)�i�Q�\�����g���j
// ����Ԑώ擾O(1)�i�Q�\�����g���j

// �E��Ԑϋt�������グO(size log size)�i���Q�\�����g���j
// ����Ԑϋt�������グO(size log size)�i���Q�\�����g���j

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const U&,const U&)�Ɋւ���M��U�̑S�����Q�\���ł���B
// (3) �e������M.One()��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ���n�ؕАς�u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)�i�S�������m�C�h�\�����g���j
// �E�n�ؕАς�u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)�i�S�������m�C�h�\�����g���j
// ����Ԑς�u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)�i�S�����Q�\�����g���j
// �E��Ԑς�u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)�i�S�����Q�\�����g���j
template <typename U , typename GROUP>
class AbstractCumulativeProduct
{

private:
  GROUP m_M;
  int m_size;
  // ���̔z����i�[�B
  vector<U> m_a;
  // �E��Ԑ�a[0]*...*a[i-1]���i�[�B
  vector<U> m_right;
  // ����Ԑ�a[0]*...*a[i-1]���i�[�B
  vector<U> m_left;

public:
  inline AbstractCumulativeProduct( GROUP M , const int& size = 0 );
  inline AbstractCumulativeProduct( GROUP M , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  // a[i]��u�ɒu���ς���B
  inline void Set( const int& i , U u );
  // a[i]��M.Product(a[i],u)�ɒu���ς���B
  inline void RightMultiply( const int& i , const U& u );
  // a[i]��M.Product(u,a[i])�ɒu���ς���B
  inline void LeftMultiply( const int& i , U u );

  // 0 <= i_final < m_size�̏ꍇ�̂݃T�|�[�g�B
  // �E�n�ؕА�a[0]...a[i_final]��M�Ɋւ��Čv�Z����B
  inline const U& RightInitialSegmentProduct( int i_final );
  // ���n�ؕА�a[i_final]...a[0]��M�Ɋւ��Čv�Z����B
  inline const U& LeftInitialSegmentProduct( int i_final );

  // 0 <= i_start����i_start-1 <= i_final < m_size�̏ꍇ�̂݃T�|�[�g�B
  // �E��Ԑ�a[i_start]...a[i_final]��M�Ɋւ��Čv�Z����B
  inline U RightIntervalProduct( const int& i_start , int i_final );
  // ����Ԑ�a[i_final]...a[i_start]��M�Ɋւ��Čv�Z����B
  inline U LeftIntervalProduct( const int& i_start , int i_final );

  // M�Ɋւ���E��Ԑ�a[i]...a[j]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountRightIntervalProductInverseImage( const U& u );
  // M�Ɋւ��鍶��Ԑ�a[j]...a[i]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountLeftIntervalProductInverseImage( const U& u );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( RightInitialSegmentProduct( i ) , i )��true�ƂȂ�i_start�ȏ��i��
  // ���݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int RightBinarySearch( const F& f );
  // f( LeftInitialSegmentProduct( i ) , i )��true�ƂȂ�i_start�ȏ��i��
  // ���݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int LeftBinarySearch( const F& f );
  // f( RightIntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i��
  // ���݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int RightBinarySearch( const int& i_start , const F& f );
  // f( LeftIntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i��
  // ���݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int LeftBinarySearch( const int& i_start , const F& f );
  // RightInitialSegmentProduct( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N��Ԃ��B
  int RightBinarySearch( const U& u );
  // LeftInitialSegmentProduct( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N��Ԃ��B
  int LeftBinarySearch( const U& u );
  // RightIntervalProduct( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  int RightBinarySearch( const int& i_start , const U& u );
  // LeftIntervalProduct( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  int LeftBinarySearch( const int& i_start , const U& u );
  
};
template <typename GROUP , typename...Args> AbstractCumulativeProduct( GROUP M , Args&&... args ) -> AbstractCumulativeProduct<inner_t<GROUP>,GROUP>;

template <typename U>
class CumulativeSum :
  public AbstractCumulativeProduct<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline CumulativeSum( Args&&... args );

  // a[i]��M.Sum(u,a[i])�ɒu���ς���B
  inline void Add( const int& i , const U& u );

  // �n�ؕИaa[0]+...+a[i_final]���v�Z����B
  inline const U& InitialSegmentSum( int i_final );

  // ��Ԙaa[i_start]+...+a[i_final]���v�Z����B
  inline U IntervalSum( const int& i_start , int i_final );

  // ��Ԙaa[i]+...+a[j]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountIntervalSumInverseImage( const U& u = U() );

  template <typename...Args> int BinarySearch( const Args&... args );

};
template <typename U> CumulativeSum( vector<U> ) -> CumulativeSum<U>;


// ��@�Q�Ɏg�������󋵂Ə�@���m�C�h�Ɏg�������󋵂������x�ł��邽��
// ��Abstract��CumulativeProduct�͒�`����Abstract���g���B