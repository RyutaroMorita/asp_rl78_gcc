/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
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
 *		�J�[�l���Ή��̃X�^�[�g�A�b�v���W���[���iRL78G14�p�j
 */

#define	TOPPERS_MACRO_ONLY
#include "kernel_impl.h"

    .list
	.globl _start
    .short _start

	.global __rl78_fini
__rl78_fini:
		br $__rl78_fini

	.text
_start:
	/*
	 *  �v���Z�b�T���[�h�ƃX�^�b�N�|�C���^�̏�����
	 */
;	mov		es, #0
;	movw	de, #__kernel_istkpt
;	movw	ax, es:[de]
	movw	ax, #0FEDCh
	movw	sp, ax

	/*
	 *  hardware_init_hook�̌ďo���i0�łȂ��ꍇ�j
	 *
	 *  �^�[�Q�b�g�n�[�h�E�F�A�Ɉˑ����ĕK�v�ȏ���������������ꍇ�́C
	 *  hardware_init_hook�Ƃ����֐���p�ӂ���D
	 */
	movw	ax, #hardware_init_hook
	cmpw	ax, #0
	skz
	call	ax

	/*
	 *  data�Z�N�V�����̏������iROM���Ή��j
	 */
	movw	de, #__idata_start
	movw	hl, #__data_start
0:
	movw	ax, #__idata_end
	cmpw	ax, de
	bz		$1f
	mov		es, #0
	movw	ax, es:[de]
	mov		es, #0Fh
	movw	es:[hl], ax
	movw	ax, de
	addw	ax, #2
	movw	de, ax
	movw	ax, hl
	addw	ax, #2
	movw	hl, ax
	br		$0b

1:

	/*
	 *  bss�Z�N�V�����̃N���A
	 */
	movw	hl, #__bss_start
2:
	movw	ax, #__bss_end
	cmpw	ax, hl
	bz		$3f
;	movw	ax, #0
	clrw	ax
	mov		es, #0Fh
	movw	es:[hl], ax
	movw	ax, hl
	addw	ax, #2
	movw	hl, ax
	br		$2b

3:

	/*
	 *  software_init_hook�̌ďo���i0�łȂ��ꍇ�j
	 *
	 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�����������
	 *  ����ꍇ�́Csoftware_init_hook�Ƃ����֐���p�ӂ���΂悢�D
	 */
	movw	ax, #software_init_hook
	cmpw	ax, #0
	skz
	call	ax

	/*
	 *  �J�[�l�����N������D
	 */
	br		!!_sta_ker