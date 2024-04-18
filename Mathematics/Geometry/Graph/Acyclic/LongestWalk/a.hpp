// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/LongestWalk/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/972197�iGetLongestWalk�j

// ���͈͓͂̔��ŗv��
// (1) G����Edge:T->(T \times U)^{< \omega}�������H�������Ȃ��L���O���t�ł���B
// (2) M��operator<(const U&,const U&)�Ɋւ���U�̏������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// G�̍Œ�������O(|V_G|+|E_G|)�Ōv�Z����B
template <typename ACYCLIC_GRAPH , typename MONOID> pair<inner_t<MONOID>,list<inner_t<ACYCLIC_GRAPH>>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M );
// G���L���؂̏ꍇ��DepthFirstSearchOnTree::Depth�̍ő�l�ŗǂ��B