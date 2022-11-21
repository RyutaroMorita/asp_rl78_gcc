/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2011 by Embedded and Real-Time Systems Laboratory
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
 */

#include "kernel_impl.h"
#include "target_syssvc.h"
#include <sil.h>
#include "rl78g14.h"


extern void start (void);

const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
	0xef, 0xff, 0xe8, 0x85
};

/* 0xCE�`0xD7��10�o�C�g�̓f�o�b�O���j�^�̈�ł��邽��0xFF�Ŗ��߂Ă������� */
const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

#define VEC          __attribute__ ((section (".vec")))
const void *HardwareVectors[] VEC = {
	// Address 0x0
	start,
	// Secure for Debugging
	(void*)0xFFFF
};

void
usart_early_init()
{
	uint16_t br;

	/* �|�[�g�̐ݒ� */
	PIOR0 &= ~PIOR0_PIOR05;

	// TxD1
	POM0_bit.no2 = 0;
	PMC0_bit.no2 = 0;
	PM0_bit.no2 = 0;
	P0_bit.no2 = 1;
	// RxD1
	PMC0_bit.no3 = 0;
	PM0_bit.no3 = 1;

	/* �N���b�N�̐ݒ� */
	SAU0EN = 1;				// ���̓N���b�N��������
							// �V���A���E�A���C�E���j�b�gm�Ŏg�p����SFR�ւ̃��[�h�^���C�g��
	ST0L = 0x0F;			// �g���K���삹��
	SPS0L = 0x00;			// SPS0L���Z�b�g
	SPS0L |= (
			SPS0_PRS002	|	// CKm0 = 2 MHz
			SPS0_PRS011		// Ckm1 = 8 MHz
			);

#define CKm0_CLOCK	(SYS_CLOCK/16)
#define CKm1_CLOCK	(SYS_CLOCK/4)

	/*
	 *
	 * UART1�̓��j�b�g0�̃`���l��2(TxD1),3(RxD1)
	 *
	 */

	/* TxD1�̐ݒ� */
	ST0L_bit.no2 = 0;		// UART1(�`���l��2)�����~���
	SMR02 = 0x0020;			// SMR02���Z�b�g
	SMR02 |= (
			SMR02_MD020 |	// �o�b�t�@�󂫊��荞��
			SMR02_MD021		// UART���[�h
//			SMR02_MD022
//			SMR02_CKS02		// CKm0 = 2 MHz
			);
	SCR02 = 0x0004;			// SCR02���Z�b�g
	SCR02 |= (
			SCR02_DLS020 |	// 8�r�b�g�E�f�[�^��
			SCR02_DLS021 |
			SCR02_SLC020 |	// �X�g�b�v�r�b�g1
//			SCR02_SLC021
			SCR02_DIR02	|	// LSB�t�@�[�X�g
//			SCR02_PCT020	// �p���e�B�Ȃ�
//			SCR02_PCT021
			SCR02_TXE02		// ���M�݂̂��s��
			);
	SDR02 = 0x0000;			// SDR02���Z�b�g
//	br = (2000000 / (9600 * 2)) - 1;
	br = (CKm0_CLOCK / (BPS_SETTING * 2)) - 1;
	SDR02 |= br << 9;		// 9600bps

	/* RxD1�̐ݒ� */
	ST0L_bit.no3 = 0;		// UART1(�`���l��3)�����~���
	SMR03 = 0x0020;			// ���Z�b�g
	SMR03 |= (
//			SMR03_MD030		// �]���������荞��
			SMR03_MD031	|	// UART���[�h
//			SMR02_MD032
			SMR03_STS03		// RxDq�[�q�̗L���G�b�W(UART��M���ɑI��)
//			SMR03_CKS03		// CKm0 = 2 MHz
			);
	SCR03 = 0x0004;			// SCR03���Z�b�g
	SCR03 |= (
			SCR03_DLS030 |	// 8�r�b�g�E�f�[�^��
			SCR03_DLS031 |
			SCR03_SLC030 |	// �X�g�b�v�r�b�g1
//			SCR03_SLC031
			SCR03_DIR03	|	// LSB�t�@�[�X�g
//			SCR03_EOC03 |	// �G���[���荞��INTSREx�̔�����������(�G���[�������CINTSRx�͔������Ȃ�)
//			SCR03_PCT030	// �p���e�B�Ȃ�
//			SCR03_PCT031
			SCR03_RXE03		// ��M�݂̂��s��
			);
	SDR03 = 0x0000;			// SDR03���Z�b�g
//	br = (2000000 / (9600 * 2)) - 1;
	br = (CKm0_CLOCK / (BPS_SETTING * 2)) - 1;
	SDR03 |= br << 9;		// 9600bps

	/* UART1�ʐM�ҋ@��ԂɑJ�� */
	SO0 |= SO0_SO02;		// �V���A���E�f�[�^�o�͒l���g1�h
	SOE0L_bit.no2 = 1;		// �V���A���ʐM����ɂ��o�͋���
	SS0L_bit.no2 = 1;		// SE02�r�b�g��1���Z�b�g���C�ʐM�ҋ@��ԂɑJ�ڂ���
	SS0L_bit.no3 = 1;		// SE03�r�b�g��1���Z�b�g���C�ʐM�ҋ@��ԂɑJ�ڂ���
}

/*
 *  �^�[�Q�b�g�ˑ��̏�����
 */
//uint16_t psw;
void
target_initialize(void)
{
	/*
	 *  �v���Z�b�T�ˑ��̏�����
	 */
	prc_initialize();

	/*
	psw = current_psw();
	psw |= 0x80;
	set_psw(psw);
	*/

	usart_early_init();
}

/*
 *  �^�[�Q�b�g�ˑ��̏I������
 */
void
target_exit(void)
{
	/*
	 *  �v���Z�b�T�ˑ��̏I������
	 */
	prc_terminate();
	while(1);
}

/*
 *  �V�X�e�����O�̒჌�x���o�͂̂��߂̕����o��
 */
void
target_fput_log(char c)
{
	if (c == '\n') {
		TXD1 = '\r';
		while (SSR02 & SSR02_BFF02);	// ���M�|�[�����O
	}
	TXD1 = c;
	while (SSR02 & SSR02_BFF02);	// ���M�|�[�����O
}

/*
 *  �����ݗv�����C���̑����̐ݒ�
 *
 *  ASP�J�[�l���ł̗��p��z�肵�āC�p�����[�^�G���[�̓A�T�[�V�����Ń`�F�b
 *  �N���Ă���Dcfg_int�T�[�r�X�R�[����݂���ꍇ�ɂ́C�G���[��Ԃ��悤
 *  �ɂ��ׂ��ł��낤�D
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	uint8_t	pri;
	uint_t index;

	assert(VALID_INTNO_CFGINT(intno));
	assert(TMIN_INTPRI <= intpri && intpri <= TMAX_INTPRI);

	/*
	 *  ��U�����݂��֎~����
	 */
	(void)x_disable_int(intno);

	/*
	 *  �����ݗD��x���Z�b�g
	 */
	pri = (uint8_t)((1 << TBITW_IPRI) + intpri);
	index = intno % 16;
	if (intno <= SRE0_TM01H_IRQn) {
		PR10 &= ~(1 << index);
		PR00 &= ~(1 << index);
		if (pri & 0x2)
			PR10 |= (1 << index);
		if (pri & 0x1)
			PR00 |= (1 << index);
	} else
	if (intno <= TM10_IRQn) {
		PR11 &= ~(1 << index);
		PR01 &= ~(1 << index);
		if (pri & 0x2)
			PR11 |= (1 << index);
		if (pri & 0x1)
			PR01 |= (1 << index);
	} else {
		PR12 &= ~(1 << index);
		PR02 &= ~(1 << index);
		if (pri & 0x2)
			PR12 |= (1 << index);
		if (pri & 0x1)
			PR02 |= (1 << index);
	}

	/*
	 *  �����ݗv���}�X�N����(�K�v�ȏꍇ)
	 */
	if ((intatr & TA_ENAINT) != 0U) {
		(void) x_enable_int(intno);
	}
}
