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
 *		�v���Z�b�T�ˑ����W���[�� �A�Z���u�����ꕔ�iRL78G14�p�j
 */

#define	TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* uint_t�^�̒萔�����}�N�� */
#define ULONG_C(val)		(val)		/* ulong_t�^�̒萔�����}�N�� */
#define CAST(type, val)		(val)		/* �^�L���X�g���s���}�N�� */
#include "kernel_impl.h"
#include "offset.h"

; real
; GAS defines r0..r7 as aliases for real registers; we want the saddr
; forms here.
r_0	=	0xffef8
r_1 =	0xffef9
r_2	=	0xffefa
r_3	=	0xffefb
r_4	=	0xffefc
r_5	=	0xffefd
r_6	=	0xffefe
r_7	=	0xffeff
#ifdef __RL78_G10__
; clobberable
r8	=	0xffec8
r9	=	0xffec9
r10	=	0xffeca
r11	=	0xffecb
r12	=	0xffecc
r13	=	0xffecd
r14	=	0xffece
r15	=	0xffecf
; preserved
r16	=	0xffed0
r17	=	0xffed1
r18	=	0xffed2
r19	=	0xffed3
r20	=	0xffed4
r21	=	0xffed5
r22	=	0xffed6
r23	=	0xffed7
#else
; clobberable
r8	=	0xffef0
r9 	=	0xffef1
r10	=	0xffef2
r11	=	0xffef3
r12	=	0xffef4
r13	=	0xffef5
r14	=	0xffef6
r15	=	0xffef7
; preserved
r16	=	0xffee8
r17	=	0xffee9
r18	=	0xffeea
r19	=	0xffeeb
r20	=	0xffeec
r21	=	0xffeed
r22	=	0xffeee
r23	=	0xffeef
#endif

/*
 *  �^�X�N�f�B�X�p�b�`��
 */
	.text
	.globl __kernel_dispatch
__kernel_dispatch:
	/*
	 *  ���̃��[�`���́C�^�X�N�R���e�L�X�g�ECPU���b�N��ԁE�f�B�X�p�b�`
	 *  ����ԁE�i���f����́j�����ݗD��x�}�X�N�S������ԂŌĂяo��
	 *  ���D
	 */
	sel		rb2							/* ���W�X�^��ۑ� */
	push	ax
	push	bc
	push	de
	push	hl
	sel		rb0
	movw	hl, !__kernel_p_runtsk		/* p_runtsk��hl�� */
	movw	ax, sp
	movw	[hl+TCB_msp], ax			/* �^�X�N�X�^�b�N��ۑ� */
	movw	ax, #dispatch_r
	movw	[hl+TCB_pc], ax				/* ���s�ĊJ�Ԓn��ۑ� */
	br		$dispatcher

dispatch_r:
	sel		rb2							/* ���W�X�^�𕜋A */
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	movw	ax, [hl+TCB_texptn]			/* texptn��0�Ȃ烊�^�[�� */
	cmpw	ax, #0
	bz		$dispatch_r_1

	movw	ax,	hl
	addw	ax, #TCB_enatex				/* enatex��false�Ȃ烊�^�[�� */
	movw	hl,	ax
	bf		[hl].TCB_enatex_bit, $dispatch_r_1

	movw	ax, !__kernel_ipmflg
	cmpw	ax, #0						/* ipmflg��true�ł����            */
	skz
	br		!!__kernel_call_texrtn		/*  �^�X�N��O�������[�`���̌ďo�� */

dispatch_r_1:
	ret

/*
 *  �f�B�X�p�b�`���̓���J�n�iprc_support.S�j
 */
	.globl __kernel_start_dispatch
__kernel_start_dispatch:
	/*
	 *  ���̃��[�`���́C�J�[�l���N�����ɁC���ׂĂ̊����݂��֎~�������
	 * �i�����݃��b�N��ԂƓ����j�ŌĂяo�����D�܂��C�����݃��[�h�i��
	 *  �^�X�N�R���e�L�X�g�Ɠ����j�ŌĂяo����邱�Ƃ�z�肵�Ă���D
	 *
	 *  prc_initialize�ŁClock_flag��true�ɁCsaved_iipm��IIPM_ENAALL��
	 *  ���������Ă��邽�߁C�J�[�l���Ǘ��O�̊����݂������邱�ƂŁC
	 *  CPU���b�N��ԁE�i���f����́j�����ݗD��x�}�X�N�S������ԂɂȂ�D
	 *  �܂��Cinitialize_task��disdsp��false�ɏ��������Ă��邽�߁C�f�B
	 *  �X�p�b�`����ԂɂȂ��Ă���D
	 */
;	movw	ax, #0
	clrw	ax
	movw	!__kernel_int_cnt, ax		/* �}�X�^���[�h�� */
	mov		a, psw						/*  �J�[�l���Ǘ��O�̊����݂����� */
	and		a, #0F9h					/* 0x06�̔��] */
	or		a, #IIPM_LOCK
	mov		psw, a
	br		$dispatcher_0

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`
 */
	.globl __kernel_exit_and_dispatch
__kernel_exit_and_dispatch:
	/* �f�B�X�p�b�`���{�́idispatcher�j�� */

/*
 *  �f�B�X�p�b�`���{��
 */
dispatcher:
	/*
	 *  ���̃��[�`���́C�^�X�N�R���e�L�X�g�ECPU���b�N��ԁE�f�B�X�p�b�`
	 *  ����ԁE�i���f����́j�����ݗD��x�}�X�N�S������ԂŌĂяo��
	 *  ���D
	 *
	 *  ���Ȃ킿�C�}�X�^���[�h�Elock_flag��true�Edisdsp��false�Edspflg
	 *  ��true�Esaved_iipm��IIPM_ENAALL�ƂȂ��Ă���D���s�ĊJ�Ԓn�ւ���
	 *  �̏�Ԃ̂܂ܕ��򂷂�D
	 */
#ifdef LOG_DSP_ENTER
	movw	ax, #__kernel_p_runtsk
	movw	[sp], ax
	call	!!_log_dsp_enter

#endif /* LOG_DSP_ENTER */
dispatcher_0:
	movw	hl, !__kernel_p_schedtsk	/* p_schedtsk��p_runtsk�� */
	movw	ax, hl
	movw	!__kernel_p_runtsk, ax		/* p_runtsk��NULL�Ȃ�dispatcher_1�� */
	cmpw	ax, #0
	bz		$dispatcher_1

	movw	ax, [hl+TCB_msp]			/* �^�X�N�X�^�b�N�𕜋A */
	movw	sp, ax
#ifdef LOG_DSP_LEAVE
	movw	ax, #__kernel_p_runtsk
	movw	[sp], ax
	call	!!_log_dsp_leave

#endif /* LOG_DSP_LEAVE */
	movw	ax, [hl+TCB_pc]				/* ���s�ĊJ�Ԓn�֕��� */
	br		ax

dispatcher_1:
	/*
	 *  CPU���b�N��Ԃ��������鏀��������D
	 */
	onew	ax							/* �����݃��[�h�� */
	movw	!__kernel_int_cnt, ax
	movw	ax, !__kernel_istkpt		/* �����ݗp�̃X�^�b�N�֐ؑւ� */
	movw	sp, ax
	mov		a, psw						/* psw��b�ɕۑ� */
	mov		b, a
	clrw	ax
	movw	!__kernel_lock_flag, ax		/* CPU���b�N������Ԃ� */
//#if 0
	mov		a, psw						/* �D��x0�̊����ݏ��������U�� */
	and		a, #0F9h
	mov		x, a
	mov		a, #06h
	or		a, x
	mov		psw, a
//#endif

dispatcher_2:
	/*
	 *  �����݂������C�����݃��[�h�ɐ؂芷���āC�����݂�҂D
	 *
	 *  �����Ŋ����݃��[�h�ɐ؂芷����̂́C�����Ŕ������銄���ݏ�����
	 *  �ǂ̃X�^�b�N���g�����Ƃ������̉����ƁC�����݃n���h�����ł̃^
	 *  �X�N�f�B�X�p�b�`�̖h�~�Ƃ���2�̈Ӗ�������D
	 *
	 *  �v���Z�b�T�������ݑ҂��Ɉڍs�����鏈���ƁC�����݋��Ƃ́C�s��
	 *  ���ɍs�Ȃ��K�v������D�����s���ɍs�Ȃ�Ȃ��ꍇ�C�����݂���
	 *  ��������Ɋ����݂�����C���̒��Ń^�X�N�����s�\��ԂɂȂ��
	 *  ���s���ׂ��^�X�N������ɂ�������炸�v���Z�b�T�������ݑ҂��ɂ�
	 *  ���Ă��܂��D
	 *
	 *  �����ݑ҂��̊Ԃ́Cp_runtsk��NULL�i��0�j�ɐݒ肵�Ȃ���΂Ȃ��
	 *  ���D���̂悤�ɐݒ肵�Ȃ��ƁC�����݃n���h������iget_tid���Ăяo
	 *  �����ۂ̓��삪�d�l�ɍ��v���Ȃ��Ȃ�D
	 */
	ei									/* �����ݑ҂� */
	nop
	di
	nop
	movw	ax, !__kernel_reqflg		/* reqflg��false�Ȃ�dispatcher_2�� */
	cmpw	ax, #0
	bz		$dispatcher_2

	mov		a, b						/* ���̏�Ԃɖ߂� */
	mov		psw, a
	clrw	ax
	movw	!__kernel_reqflg, ax		/* reqflg��false�� */
	/*
	 *  CPU���b�N��Ԃɖ߂��D�����ݑ҂��̊ԂɎ��s���������݃n���h���ɂ�
	 *  ��Csaved_iipm��������������\�������邽�߁C���̒l�ɖ߂��K
	 *  �v������Ddispatcher�����s����鎞�́Csaved_iipm��IIPM_ENAALL
	 *  �ƂȂ��Ă��邽�߁C�����ł�saved_iipm��IIPM_ENAALL�i��0�j�ɖ߂�
	 *  �΂悢�D
	 */
;	movw	ax, #0						/* �}�X�^���[�h�Ɂi�X�^�b�N�؊����j */
	clrw	ax							/* �}�X�^���[�h�Ɂi�X�^�b�N�؊����j */
	movw	!__kernel_int_cnt, ax
	mov		a, #06h
	mov		!__kernel_saved_iipm, a		/* saved_iipm��06h�ɂ��� */
	onew	ax							/* CPU���b�N��Ԃ� */
	movw	!__kernel_lock_flag, ax
	br		$dispatcher_0

/*
 *  �J�[�l���̏I�������̌ďo��
 */
	.globl __kernel_call_exit_kernel
__kernel_call_exit_kernel:
;	movw	ax, #1						/* �����݃��[�h�� */
	onew	ax							/* �����݃��[�h�� */
	movw	!__kernel_int_cnt, ax
	br		!!__kernel_exit_kernel		/* �J�[�l���̏I���������Ă� */

/*
 *  �^�X�N�J�n������
 *
 *  dispatcher����Ăяo����邽�߁CTCB�̃A�h���X��hl�ɓ����Ă���
 */
	.text
	.globl __kernel_start_r
__kernel_start_r:
;	movw	ax, #0						/* CPU���b�N������Ԃ� */
	clrw	ax							/* CPU���b�N������Ԃ� */
	movw	!__kernel_lock_flag, ax
	mov		a, psw
	or		a, #06h
	mov		psw, a
	ei
	movw	ax, [hl+TCB_p_tinib]		/* p_runtsk->p_tinib��hl�� */
	movw	hl, ax
	movw	ax, [hl+TINIB_exinf]		/* exinf���X�^�b�N�ɐς� */
	movw	[sp], ax
	mov		a, psw						/* ext_tsk���X�^�b�N�ɐς� */
;	mov		x, #0
	clrb	x
	push	ax
	movw	ax, #_ext_tsk
	push	ax
	movw	ax, [hl+TINIB_task]			/* �^�X�N�̋N���Ԓn��ax�� */
	br		ax

/*
 *  �����݃G���g���irb0��bc�ɃG���g���ԍ�������j
 */
	.global inthdr_entry
inthdr_entry:
	sel		rb0							/* ���W�X�^��ޔ� */
	push	ax
;	push	bc
	push	de
	push	hl
	sel		rb1
	push	ax
	push	bc
	push	de
	push	hl
;	sel		rb2
;	push	ax
;	push	bc
;	push	de
;	push	hl
	sel		rb0
	mov     a, es
	mov		x, a
	mov		a, cs
	push	ax

	movw	ax, !__kernel_int_cnt		/* �����݃��[�h�� */
	incw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #1						/* ���Z�O��0�łȂ���Α��d������ */
	bnz		$interrupt_from_int

	movw	ax, sp
	movw	!__kernel_int_sp, ax
	movw	ax, !__kernel_istkpt
	movw	sp, ax
	br		$inthdr_entry_0

interrupt_from_int:						/* ���d������ */
	br		$inthdr_entry_0

inthdr_entry_0:
	ei									/* �����݋���(CPU���b�N�������) */
	movw	ax, #__kernel_exc_tbl
	addw	ax, bc
	addw	ax, bc
	movw	de, ax
	movw	ax, [de]
#ifdef LOG_INH_ENTER
	push	ax
	subw	sp, #2						/* �����̊i�[�ꏊ���m�� */
	movw	ax, bc
	movw	[sp], ax
	call	!!__kernel_log_inh_enter	/* log_inh_enter���Ăяo�� */

	addw	sp, #2						/* �X�^�b�N��̈������̂Ă� */
	pop		ax
#endif /* LOG_INH_ENTER */
#ifdef LOG_INH_LEAVE
	push	bc
#endif
;	mov		cs, #0
	call	ax

#ifdef LOG_INH_LEAVE
	pop		bc
	subw	sp, #2						/* �����̊i�[�ꏊ���m�� */
	movw	ax, bc
	movw	[sp], ax
	call	!!_kernel_log_inh_leave		/* log_inh_leave���Ăяo�� */

	addw	sp, #2						/* �X�^�b�N��̈������̂Ă� */
#endif /* LOG_INH_LEAVE */

/*
 *  �����݃n���h���o������
 *
 *  ret_int�́C�����݃n���h������߂�������Ɏ��s���郋�[�`���ŁC
 *  INTHDR_ENTRY�}�N���œW�J���銄���݃n���h���̓��������ŁC�����݃n��
 *  �h������̖߂�Ԓn�ɐݒ肳���D
 */
	.text
	.globl ret_int
ret_int:
	di
	movw	ax, !__kernel_int_cnt		/* �߂�悪�����݃��[�h�Ȃ� */
	decw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #0
	skz
	br		$ret_int_1_d				/*           �����Ƀ��^�[�� */

	/*
	 *  �J�[�l���Ǘ��̊����݂��֎~����D���̎��_�ł́CCPU���b�N��Ԃ�
	 *  �͂Ȃ�Ȃ��ilock_flag��saved_iipm�͍X�V���Ȃ��j�D
	 *
	 *  reqflg���`�F�b�N����O�Ɋ����݂��֎~����̂́Creqflg���`�F�b�N
	 *  ��������Ɋ����݃n���h�����N������C���̒��Ńf�B�X�p�b�`���v��
	 *  ���ꂽ�ꍇ�ɁC�����Ƀf�B�X�p�b�`����Ȃ��Ƃ�����肪�����邽��
	 *  �ł���D
	 */
	mov		a, psw						/* �J�[�l���Ǘ��̊����݂��֎~ */
	and		a, #0F9h					/* 0x06�̔��] */
	or		a, #IIPM_LOCK
	mov		psw, a
	ei
	movw	ax, !__kernel_reqflg		/* reqflg��true�ł����ret_int_2�� */
	cmpw	ax, #0
	skz
	br		$ret_int_2

	movw	ax, !__kernel_int_sp		/* �}�X�^���[�h�Ɂi�X�^�b�N�؊����j */
	movw	sp, ax

ret_int_1:
	/*
	 *  �����ݏ�������̃��^�[���ɂ��CCPU���b�N������ԂɈڍs����悤
	 *  ��������D�����ݗD��x�}�X�N�́CRTE���߂ɂ�茳�̒l�ɖ߂邽�߁C
	 *  lock_flag��false�ɂ��Ă����΂悢�ilock_flag��false�ɂ���̂́C
	 *  CPU���b�N��Ԃ̂܂܊����݃n���h������߂������̑΍�j�D
	 */
;	movw	ax, #0						/* CPU���b�N�����̏��� */
	clrw	ax							/* CPU���b�N�����̏��� */
	movw	!__kernel_lock_flag, ax

	pop		ax							/* ���W�X�^�𕜋A */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	reti

ret_int_1_d:
	br		$ret_int_1

ret_int_2:
	movw	ax, !__kernel_int_sp		/* �}�X�^���[�h�Ɂi�X�^�b�N�؊����j */
	movw	sp, ax

ret_int_3:
	/*
	 *  �����ւ́CCPU��O�n���h���̏o��������������򂵂Ă���D
	 *
	 *  �����ł́C�߂�悪�^�X�N�ł���C�X�^�b�N�́C��O�X�^�b�N�t���[
	 *  ���̏�ɃX�N���b�`���W�X�^�݂̂��ۑ����ꂽ��ԂɂȂ��Ă���D��
	 *  ���C�v���Z�b�T�́C�}�X�^���[�h�E�J�[�l���Ǘ��̊����݂��֎~����
	 *  ��ԂƂȂ��Ă���D
	 */
//	movw	ax, #0
	clrw	ax
	movw	!__kernel_reqflg, ax
	/*
	 *  CPU���b�N��ԂɈڍs���C�����ݗD��x�}�X�N�������ݏ����O�̒l�ɐ�
	 *	�肷��D�J�[�l���Ǘ��̊����݂͂��łɋ֎~���Ă���̂ŁClock_flag
	 *  ��saved_iipm���X�V����Dsaved_iipm�́C�߂��̊����ݗD��x�}�X
	 *  �N�i�̓����\���j�ɐݒ肷��D
	 *
	 *  ���̎��_��CPU���b�N��ԂƂ���̂́Cdispatcher�֕��򂷂鎞�ƁC
	 *  call_texrtn���Ăяo�����ɁCCPU���b�N��ԂɂȂ��Ă���K�v������
	 *  ���߂ł���D
	 */
	movw	ax, [sp+20]					/* �߂���psw��D0�� */
	and		a, #06h						/* IPM�����o����saved_iipm�� */
	mov		!__kernel_saved_iipm, a
;	movw	ax, #1						/* lock_flag��true�� */
	onew	ax							/* lock_flag��true�� */
	movw	!__kernel_lock_flag, ax
	/*
	 *  dspflg��false�ł���ꍇ�ƁCp_runtsk��p_schedtsk�������ꍇ�ɂ́C
	 *  �f�B�X�p�b�`���s��Ȃ��D���̃`�F�b�N���K�v�Ȃ̂́C�^�X�N��O��
	 *  �����[�`���̌ďo�����K�v�ȏꍇ�ɁC�f�B�X�p�b�`���K�v�Ȃ��Ă��C
	 *  reqflg��true�ɂ��邽�߂ł���D
	 */
	movw	hl, !__kernel_p_runtsk		/* p_runtsk��hl�� */
	movw	ax, !__kernel_dspflg		/* dspflg��false�Ȃ�ret_int_4�� */
	cmpw	ax, #0
	bz		$ret_int_4

	movw	ax, !__kernel_p_schedtsk	/* p_runtsk��p_schedtsk�������Ȃ� */
	cmpw	ax, hl
	bz		$ret_int_4					/*                    ret_int_4�� */

	sel		rb2							/* �c��̃��W�X�^��ۑ� */
	push	ax
	push	bc
	push	de
	push	hl
	sel		rb0

	movw	ax, sp						/* �^�X�N�X�^�b�N��ۑ� */
	movw	[hl+TCB_msp], ax
	movw	ax, #ret_int_r				/* ���s�ĊJ�Ԓn��ۑ� */
	movw	[hl+TCB_pc], ax
	br		!!dispatcher

ret_int_r:
	sel		rb2							/* ���W�X�^�𕜋A */
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0

ret_int_4:
	/*
	 *  enatex��true�ŁCtexptn��0�łȂ��Cipmflg��true�ł���΁C�^�X�N
	 *  ��O�������[�`�����Ăяo���D
	 */
	movw	ax, [hl+TCB_texptn]			/* texptn��0�Ȃ�ret_int_5�� */
	cmpw	ax, #0
	bz		$ret_int_5

;	movw	ax, [hl+TCB_enatex]			/* enatex��false�Ȃ�ret_int_5�� */
	movw	ax, hl						/* enatex��false�Ȃ�ret_int_5�� */
	addw	ax, #TCB_enatex
	movw	hl, ax
	bf		[hl].TCB_enatex_bit, $ret_int_5

	movw	ax, !__kernel_ipmflg		/* ipmflg��false�Ȃ�ret_int_5�� */
	cmpw	ax, #0
	bz		$ret_int_5

	call	!!__kernel_call_texrtn		/* �^�X�N��O�������[�`���̌ďo�� */

ret_int_5:
	/*
	 *  �����ݏ�������̃��^�[���ɂ��CCPU���b�N������ԂɈڍs�����
	 *  ����������D�����ݗD��x�}�X�N�́CRTE���߂ɂ�茳�̒l�ɖ߂邽
	 *  �߁Clock_flag��false�ɂ��Ă����΂悢�D
	 */
;	movw	ax, #0						/* CPU���b�N�����̏��� */
	clrw	ax							/* CPU���b�N�����̏��� */
	movw	!__kernel_lock_flag, ax

	pop		ax							/* ���W�X�^�𕜋A */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	reti

/*
 *  CPU��O�n���h���o��������
 *
 *  exchdr_entry�́CCPU��O�������������Ɏ��s���郋�[�`���ŁCEXCHDR_ENTRY
 *  �}�N���œW�J����CPU��O�n���h���̓�����������CCPU��O�n���h���̔Ԓn��
 *  A1�ɁCCPU��O�n���h���ԍ���bc�ɓ���ĕ��򂵂Ă���D
 *
 *  CPU��O�n���h���́C��^�X�N�R���e�L�X�g�Ŏ��s����D���̂��߁CCPU��
 *  �O�n���h�����Ăяo���O�Ɋ����݃��[�h�Ɉڍs���C���^�[�����Ă������
 *  ���̃��[�h�ɖ߂��D���̃��[�h�ɖ߂����߂ɁC�����݃��[�h�Ɉڍs����O
 *  ��SR�������݃X�^�b�N��ɕۑ�����i���^�[�����SR���Q�Ƃ���������
 *  ���C�^�X�N�X�^�b�N��ɕۑ������ꍇ������C�Q�Ƃ���̂��ʓ|�j�D
 */
	.text
	.globl exchdr_entry
exchdr_entry:
	sel		rb0							/* ���W�X�^��ޔ� */
	push	ax
;	push	bc
	push	de
	push	hl
	sel		rb1
	push	ax
	push	bc
	push	de
	push	hl
;	sel		rb2
;	push	ax
;	push	bc
;	push	de
;	push	hl
	sel		rb0
	mov     a, es
	mov		x, a
	mov		a, cs
	push	ax

	movw	ax, [sp + 20]				/* ��O�����O��psw��l�� */
	mov		l, a
	mov		h, #0

	movw	ax, !__kernel_int_cnt		/* �����݃��[�h�� */
	incw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #1						/* ���Z�O��0�łȂ���Α��d������ */
	bnz		$exception_from_int

	movw	ax, sp
	movw	!__kernel_int_sp, ax		/* �X�^�b�N�؊��� */
	movw	ax, !__kernel_istkpt
	movw	sp, ax
	br		$exchdr_entry_0

exception_from_int:						/* ���d������ */
	br		$exchdr_entry_0

exchdr_entry_0:
	ei									/* �����݋���(CPU���b�N�������) */
	movw	ax, #__kernel_exc_tbl
	addw	ax, bc
	addw	ax, bc
	movw	de, ax
	movw	ax, [de]
	movw	de, ax
	mov		a, l
	and		a, #06h
	cmp		a, #INT_IPM(TMIN_INTPRI)	/* IPM��INT_IPM(TMIN_INTPRI) */
	skz									/*    ��菬������΁C�J�[�l�� */
	br		$exchdr_entry_1				/*    �Ǘ���CPU��O�̏����� */

	/*
	 *  �J�[�l���Ǘ��O��CPU��O�n���h���̌ďo��
	 */

	push	hl							/* ��O�����O��psw��ޔ� */
	movw	ax, !__kernel_lock_flag		/* ����lock_flag���X�^�b�N�ɕۑ� */
	push	ax
	subw	sp, #2						/* �����̊i�[�ꏊ���m�� */
	movw	ax, sp
	addw	ax, #4						/* ��O�����O��psw�ƃR���e�L�X�g�̎Q�Ɛ�i���O�ɃX�^�b�N�ɐς܂ꂽ hl �̒l���w���j */
	movw	[sp], ax					/* �����ip_excinf�j��ݒ� */
	call	de							/* CPU��O�n���h�����Ăяo�� */

	addw	sp, #2						/* �X�^�b�N��̈������̂Ă� */
	pop		ax							/* lock_flag�����ɖ߂� */
	movw	!__kernel_lock_flag, ax
	pop		hl							/* ��O�����O��psw�𕜋A */
	mov		a, l
	mov		psw, a						/* psw�����ɖ߂� */
	movw	ax, !__kernel_int_sp		/* �}�X�^���[�h�Ɂi�X�^�b�N�؊����j */
	movw	sp, ax

	pop		ax							/* ���W�X�^�𕜋A */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	retb

	/*
	 *  �J�[�l���Ǘ���CPU��O�n���h���̌ďo��
	 */
exchdr_entry_1:
#ifdef LOG_EXC_LEAVE
	push	bc							/* excno_num���p�����[�^�� */
#endif
	push	hl							/* ��O�����O��psw��ޔ� */
	subw	sp, #2						/* �����̊i�[�ꏊ���m�� */
	movw	ax, sp
	addw	ax, #2						/* ��O�����O��psw�ƃR���e�L�X�g�̎Q�Ɛ�i���O�ɃX�^�b�N�ɐς܂ꂽ hl �̒l���w���j */
	movw	[sp], ax					/* �����ip_excinf�j��ݒ� */
#ifdef LOG_EXC_ENTER
	push	de							/* de��ۑ� */
	push	bc							/* excno_num���p�����[�^�� */
	call	_kernel_log_exc_enter		/* log_exc_enter���Ăяo�� */

	addw	sp, #2						/* �X�^�b�N��̈������̂Ă� */
	pop		de							/* de�𕜋A */
#endif /* LOG_EXC_ENTER */
	call	de							/* CPU��O�n���h�����Ăяo�� */

	addw	sp, #4						/* �X�^�b�N��̈������̂Ă� */
#ifdef LOG_EXC_LEAVE
	call	_kernel_log_exc_leave		/* log_exc_leave���Ăяo�� */

	addw	sp, #2						/* �X�^�b�N��̈������̂Ă� */
#endif /* LOG_EXC_LEAVE */

ret_exc:
	di
	movw	ax, !__kernel_int_cnt		/* �߂�悪�����݃��[�h�Ȃ� */
	decw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #0
	skz
	br		$ret_exc_1_d				/*           �����Ƀ��^�[�� */

	/*
	 *  �J�[�l���Ǘ��̊����݂��֎~���C�}�X�^���[�h�ɖ߂��D���̎��_�ł́C
	 *  CPU���b�N��Ԃɂ͂Ȃ�Ȃ��ilock_flag��saved_iipm�͍X�V���Ȃ��j�D
	 *
	 *  reqflg���`�F�b�N����O�Ɋ����݂��֎~����̂́Creqflg���`�F�b�N
	 *  ��������Ɋ����݃n���h�����N������C���̒��Ńf�B�X�p�b�`���v��
	 *  ���ꂽ�ꍇ�ɁC�����Ƀf�B�X�p�b�`����Ȃ��Ƃ�����肪�����邽��
	 *  �ł���D
	 */
	movw	ax, !__kernel_int_sp		/* �}�X�^���[�h�Ɂi�X�^�b�N�؊����j */
	movw	sp, ax
	mov		a, psw						/* �J�[�l���Ǘ��̊����݂��֎~ */
	and		a, #0F9h					/* 0x06�̔��] */
	or		a, #IIPM_LOCK
	mov		psw, a
	ei
	movw	ax, !__kernel_reqflg		/* reqflg��true�ł����ret_int_3�� */
	cmpw	ax, #0
	skz
	br		!!ret_int_3

ret_exc_1:
	pop		ax							/* ���W�X�^�𕜋A */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	retb

ret_exc_1_d:
	br		$ret_exc_1