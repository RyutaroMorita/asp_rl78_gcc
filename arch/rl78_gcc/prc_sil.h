/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
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
 *		sil.h�̃v���Z�b�T�ˑ����iRL78G14�p�j
 */

#ifndef TOPPERS_PRC_SIL_H
#define TOPPERS_PRC_SIL_H

#ifndef TOPPERS_MACRO_ONLY

/*
 *  NMI���������ׂĂ̊����݂̋֎~
 */
extern uint16_t TOPPERS_disint(void);
asm(".text \n\t"
"_TOPPERS_disint: \n\t"
"	subw sp,#2 \n\t"
"	bf psw.7,$0f \n\t"
"	di \n\t"
"	onew ax \n\t"
"	br $1f \n\t"
"0:	\n\t"
"	clrw ax \n\t"
"1:	\n\t"
"	movw [sp],ax \n\t"
"	movw 0xffef0,ax \n\t"
"	addw sp,#2 \n\t"
"	ret \n\t"
);

extern void TOPPERS_enaint(bool_t locked);
asm(".text \n\t"
"_TOPPERS_enaint: \n\t"
"	movw ax,[sp+4] \n\t"
"	movw 0xffef0,ax \n\t"
"	cmpw ax,#0 \n\t"
"	bz $0f \n\t"
"	ei \n\t"
"0:	\n\t"
"	ret \n\t"
);

/*
 *  �����ݗD��x�}�X�N�i�����\���j�̌��ݒl�̐ݒ�
 */
Inline void
TOPPERS_set_iipm(uint16_t TOPPERS_iipm)
{
	uint16_t	TOPPERS_sr;

	Asm("move.w %%sr, %0" : "=g"(TOPPERS_sr));
	Asm("move.w %0, %%sr" : : "g"((TOPPERS_sr & ~0x0700U) | TOPPERS_iipm)
							: "memory");
}

/*
 *  �S�����݃��b�N��Ԃ̐���
 */
#define SIL_PRE_LOC      bool_t  TOPPERS_locked
#define SIL_LOC_INT()    ((void)(TOPPERS_locked = TOPPERS_disint()))
#define SIL_UNL_INT()    (TOPPERS_enaint(TOPPERS_locked))

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN_LITTLE				/* ���g���G���f�B�A�� */

/*
 *  �����ݗD��x�̃r�b�g��
 */
#define TBITW_IPRI     2

#endif /* TOPPERS_PRC_SIL_H */
