// c:/Users/user/Documents/Programming/Mathematics/Algebra/a.hpp

#pragma once

// - インタフェースをなるべく抽象型で与えて仮想継承する。
//   - 具体的構造が２種類以上あるものはもちろん抽象型を仮想継承する。
//   - VirtualPointedSetのように具体的構造が１種類しかないものも仮想継承のコンストラクタ呼び出しを
//     省略するためになるべく抽象型を用意する。
//   - AbstractDijkstraのように全ての具体的構造が１つの具体的構造の派生である場合は
//     インタフェースを必要としない。
// - コンストラクタはなるべく省略できるようにするが、ポインタはメンバ変数にしない。
//   - VirtualGraphのように具体的構造が２種類以上あるもので全てに共通の定義本体を持つ関数（Edge）が
//     必要な場合は実装が膨れ上がらないように抽象型に関数の定義をし、そのため抽象型にメンバ変数が
//     必要になる場合はコンストラクタを非自明なものにする
//   - 代わりにポインタを抽象型のメンバとして
//     派生クラスのコンストラクタの定義内でアドレスを渡すようにすると、ムーブなどで意図せず
//     ポインタの指すアドレスが意図通りでなくなることに注意する。
// - データ構造に渡すことを想定する。
//   - データ構造の配列や初期化をムーブセマンティクスで処理できるようにするために
//     代数構造もムーブコンストラクタがdeleteされないようにする。
//   - そのために演算に対応する関数オブジェクトは参照ではなく実体としてメンバに持つ。
template <typename U>
class UnderlyingSet
{

public:
  using type = U;

};

template <typename U>
class VirtualPointedSet :
  virtual public UnderlyingSet<U>
{

public:
  virtual const U& Point() const noexcept = 0;
  virtual U& Point() noexcept = 0;
  DECLARATION_OF_CPOINT( Unit );
  DECLARATION_OF_CPOINT( Zero );
  DECLARATION_OF_CPOINT( One );
  DECLARATION_OF_CPOINT( Infty );
  DECLARATION_OF_POINT( init );
  DECLARATION_OF_POINT( root );

};

template <typename U>
class PointedSet :
  virtual public VirtualPointedSet<U>
{

private:
  U m_b_U;

public:
  inline PointedSet( U b_u = U() );
  inline const U& Point() const noexcept;
  inline U& Point() noexcept;

};

template <typename U>
class VirtualNSet :
  virtual public UnderlyingSet<U>
{

public:
  virtual U Transfer( const U& u ) = 0;
  inline U Inverse( const U& u );

};

template <typename U , typename F_U>
class AbstractNSet :
  virtual public VirtualNSet<U>
{

private:
  F_U m_f_U;

public:
  inline AbstractNSet( F_U f_U );
  inline U Transfer( const U& u );

};

template <typename U>
class VirtualMagma :
  virtual public UnderlyingSet<U>
{

public:
  virtual U Product( U u0 , const U& u1 ) = 0;
  inline U Sum( U u0 , const U& u1 );

};

template <typename U = ll>
class AdditiveMagma :
  virtual public VirtualMagma<U>
{

public:
  inline U Product( U u0 , const U& u1 );

};

template <typename U = ll>
class MultiplicativeMagma :
  virtual public VirtualMagma<U>
{

public:
  inline U Product( U u0 , const U& u1 );

};

template <typename U , typename M_U>
class AbstractMagma :
  virtual public VirtualMagma<U>
{

private:
  M_U m_m_U;

public:
  inline AbstractMagma( M_U m_U );
  inline U Product( U u0 , const U& u1 );

};
