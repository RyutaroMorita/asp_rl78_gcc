/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 *
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 *
 *	2022/11/21 Ryutaro Morita
 */

/*
 *		�^�[�Q�b�g�ˑ����W���[���iRTK5RLG140C00000BJ�p�j
 *
 *  �J�[�l���̃^�[�Q�b�g�ˑ����̃C���N���[�h�t�@�C���Dkernel_impl.h�̃^�[
 *  �Q�b�g�ˑ����̈ʒu�t���ƂȂ�D
 */

#ifndef TOPPERS_TARGET_CONFIG_H
#define TOPPERS_TARGET_CONFIG_H

/*
 *  �^�[�Q�b�g�V�X�e���̃n�[�h�E�F�A�����̒�`
 */
#ifndef __ASSEMBLER__
#include "rl78g14.h"
#endif

/*
 *  �^�[�Q�b�g��`�̃I�u�W�F�N�g����
 */
#define TARGET_INHATR	TA_NONKERNEL	/* �J�[�l���Ǘ��O�̊����� */

/*
 *  �G���[�`�F�b�N���@�̎w��
 */
#define CHECK_STKSZ_ALIGN	4	/* �X�^�b�N�T�C�Y�̃A���C���P�� */
#define CHECK_FUNC_ALIGN	2	/* �֐��̃A���C���P�� */
#define CHECK_FUNC_NONNULL		/* �֐��̔�NULL�`�F�b�N */
#define CHECK_STACK_ALIGN	2	/* �X�^�b�N�̈�̃A���C���P�� */
#define CHECK_STACK_NONNULL		/* �X�^�b�N�̈�̔�NULL�`�F�b�N */
#define CHECK_MPF_ALIGN		2	/* �Œ蒷�������v�[���̈�̃A���C���P�� */
#define CHECK_MPF_NONNULL		/* �Œ蒷�������v�[���̈�̔�NULL�`�F�b�N */
#define CHECK_MB_ALIGN		2	/* �Ǘ��̈�̃A���C���P�� */

/*
 *  �g���[�X���O�Ɋւ���ݒ�
 */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"
#endif /* TOPPERS_ENABLE_TRACE */

/*
 *  ASP�J�[�l�����쎞�̃������}�b�v�Ɗ֘A�����`
 *
 *	00000000 - 0000ffff		ROM���j�^�^�X�^�u���[�N�G���A�i64KB�j
 *	00010000 - 000fffff		�R�[�h�̈�i��1MB�j
 *	00100000 -				�f�[�^�̈�i��3MB�j
 *			 - 003fffff		�f�t�H���g�̔�^�X�N�R���e�L�X�g�p�̃X�^�b�N�̈�
 */

/*
 *  �f�t�H���g�̔�^�X�N�R���e�L�X�g�p�̃X�^�b�N�̈�̒�`
 */
#define DEFAULT_ISTKSZ		0x400U
#define DEFAULT_ISTK		(void *)(0x000FFEDCU - DEFAULT_ISTKSZ)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �v���Z�b�T���ʂ̂��߂̕ϐ��i�}���`�v���Z�b�T�Ή��j
 */
extern uint_t	board_id;		/* �{�[�hID */
extern void		*board_addr;	/* ���[�J���������̐擪�A�h���X */

/*
 *  �����ݔԍ��͈̔͂̔���
 */
#define VALID_INTNO(intno)	(1U <= (intno) && (intno) <= 47U)
#define	VALID_INTNO_CREISR(intno)	VALID_INTNO(intno)
#define VALID_INTNO_DISINT(intno)	VALID_INTNO(intno)
#define VALID_INTNO_CFGINT(intno)	VALID_INTNO(intno)

/*
 *  �����ݑ������ݒ肳��Ă��邩�𔻕ʂ��邽�߂̕ϐ��ikernel_cfg.c�j
 */
extern const uint32_t	bitpat_cfgint;

/*
 *  �����ݗv���֎~�t���O�̃Z�b�g
 *
 *  �����ݑ������ݒ肳��Ă��Ȃ������ݗv�����C���ɑ΂��Ċ����ݗv���֎~
 *  �t���O���Z�b�g���悤�Ƃ����ꍇ�ɂ́Cfalse��Ԃ��D
 */
Inline bool_t
x_disable_int(INTNO intno)
{
	uint_t index;
	index = intno % 16;
	if (intno <= SRE0_TM01H_IRQn) {
		MK0 |= (1 << index);
	} else
	if (intno <= TM10_IRQn) {
		MK1 |= (1 << index);
	} else {
		MK2 |= (1 << index);
	}
	return (true);
}

#define t_disable_int(intno)	x_disable_int(intno)
#define i_disable_int(intno)	x_disable_int(intno)

/*
 *  �����ݗv���֎~�t���O�̃N���A
 *
 *  �����ݑ������ݒ肳��Ă��Ȃ������ݗv�����C���ɑ΂��Ċ����ݗv���֎~
 *  �t���O���N���A���悤�Ƃ����ꍇ�ɂ́Cfalse��Ԃ��D
 */
Inline bool_t
x_enable_int(INTNO intno)
{
	uint_t index;
	index = intno % 16;
	if (intno <= SRE0_TM01H_IRQn) {
		MK0 &= ~(1 << index);
	} else
	if (intno <= TM10_IRQn) {
		MK1 &= ~(1 << index);
	} else {
		MK2 &= ~(1 << index);
	}
	return(true);
}

#define t_enable_int(intno)		x_enable_int(intno)
#define i_enable_int(intno)		x_enable_int(intno)

/*
 *  �����ݗv���̃N���A
 */
Inline void
x_clear_int(INTNO intno)
{
	//
}

#define t_clear_int(intno)		x_clear_int(intno)
#define i_clear_int(intno)		x_clear_int(intno)

/*
 *  �����ݗv���̃`�F�b�N
 */
Inline bool_t
x_probe_int(INTNO intno)
{
	return 0;
}

#define t_probe_int(intno)		x_probe_int(intno)
#define i_probe_int(intno)		x_probe_int(intno)

/*
 *  �����ݗv�����C���̑����̐ݒ�
 */
extern void	x_config_int(INTNO intno, ATR intatr, PRI intpri);

/*
 *  �����݃n���h���̓����ŕK�v��IRC����
 *
 *  �G�b�W�g���K�̏ꍇ�ɂ́C�����ݗv�����N���A����D�G�b�W�g���K�����x
 *  ���g���K�����ݒ�ł���ꍇ���C���݂̐ݒ�l�������ɃN���A���Ă���D
 *  ���x���g���K�̏ꍇ���N���A���������č����x���Ȃ����C�œK���ŏ�����
 *  ���Ƃ����҂��āC�N���A���Ȃ����ƂƂ��Ă���D
 */
Inline void
i_begin_int(INTNO intno)
{
}

/*
 *  �����݃n���h���̏o���ŕK�v��IRC����
 */
Inline void
i_end_int(INTNO intno)
{
}

#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void	target_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���D
 */
extern void	target_exit(void) NoReturn;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �������ԑ҂��̂��߂̒�`�i�{����SIL�̃^�[�Q�b�g�ˑ����j
 */
#define SIL_DLY_TIM1	420
#define SIL_DLY_TIM2	90

/*
 *  �v���Z�b�T�ˑ����W���[���iRL78G14�p�j
 */
#include "rl78_gcc/prc_config.h"

#endif /* TOPPERS_TARGET_CONFIG_H */
