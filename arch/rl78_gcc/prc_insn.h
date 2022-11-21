/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
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
 *		�v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`�iRL78G14�p�j
 */

#ifndef	TOPPERS_PRC_INSN_H
#define	TOPPERS_PRC_INSN_H

/*
 *  �X�e�[�^�X���W�X�^�iPSW�j�̌��ݒl�̓Ǐo��
 */
extern uint8_t current_psw(void);
asm(".text \n\t"
"_current_psw: \n\t"
"	mov a,psw \n\t"
"	mov 0xffef0, a \n\t"
"	ret \n\t"
);

/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̐ݒ�
 */
extern void set_psw(uint8_t psw);
asm(".text \n\t"
"_set_psw: \n\t"
"	mov a,[sp+4] \n\t"
"	mov 0xffef0,a \n\t"
"	mov psw,a \n\t"
"	ret \n\t"
);

/*
 *  NMI���������ׂĂ̊����݂̋֎~
 */
Inline void
disint(void)
{
	Asm("di");
}

/*
 *  ���ׂĂ̊����݂̋���
 */
Inline void
enaint(void)
{
	Asm("ei");
}

/*
 *  �x�N�^�x�[�X���W�X�^�iVBR�j�̌��ݒl�̓Ǐo��
 */
Inline void
*current_vbr(void)
{
	void	*vbr;

	Asm("movec.l %%vbr, %0" : "=r"(vbr));
	return(vbr);
}

/*
 *  �x�N�^�x�[�X���W�X�^�iVBR�j�̌��ݒl�̐ݒ�
 */
Inline void
set_vbr(void *vbr)
{
	Asm("movec.l %0, %%vbr" : : "r"(vbr));
}

#endif /* TOPPERS_PRC_INSN_H */
