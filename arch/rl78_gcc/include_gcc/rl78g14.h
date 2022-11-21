/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2015 by Embedded and Real-Time Systems Laboratory
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
 *  RL78G14�̃n�[�h�E�F�A�����̒�`
 */

#ifndef RL78G14_H
#define RL78G14_H

#include "iodefine.h"
#include "iodefine_ext.h"

/* OSMC - �T�u�V�X�e���E�N���b�N�������[�h���䃌�W�X�^ */
#define OSMC_WUTMMCK0_Pos	(4U)
#define OSMC_WUTMMCK0_Msk	(0x1UL << OSMC_WUTMMCK0_Pos)
#define OSMC_WUTMMCK0		OSMC_WUTMMCK0_Msk
#define OSMC_RTCLPC_Pos		(7U)
#define OSMC_RTCLPC_Msk		(0x1UL << OSMC_RTCLPC_Pos)
#define OSMC_RTCLPC			OSMC_RTCLPC_Msk

/* ITMC - 12�r�b�g�E�C���^�[�o���E�^�C�}�E�R���g���[���E���W�X�^ */
#define ITMC_ITCMP_Pos		(0U)
#define ITMC_ITCMP_Msk		(0xFFFUL << ITMC_ITCMP_Pos)
#define ITMC_ITCMP			ITMC_ITCMP_Msk
#define ITMC_RINTE_Pos		(15U)
#define ITMC_RINTE_Msk		(0x1UL << ITMC_RINTE_Pos)
#define ITMC_RINTE			ITMC_RINTE_Msk

/* PIOR0 - ����I/O���_�C���N�V�����E���W�X�^0 */
#define PIOR0_PIOR05_Pos	(5U)
#define PIOR0_PIOR05_Msk	(0x1UL << PIOR0_PIOR05_Pos)
#define PIOR0_PIOR05		PIOR0_PIOR05_Msk

/* SPS0 - �V���A���E�N���b�N�I�����W�X�^0 */
#define SPS0_PRS000_Pos		(0U)
#define SPS0_PRS000_Msk		(0x1UL << SPS0_PRS000_Pos)
#define SPS0_PRS000			SPS0_PRS000_Msk
#define SPS0_PRS001_Pos		(1U)
#define SPS0_PRS001_Msk		(0x1UL << SPS0_PRS001_Pos)
#define SPS0_PRS001			SPS0_PRS001_Msk
#define SPS0_PRS002_Pos		(2U)
#define SPS0_PRS002_Msk		(0x1UL << SPS0_PRS002_Pos)
#define SPS0_PRS002			SPS0_PRS002_Msk
#define SPS0_PRS003_Pos		(3U)
#define SPS0_PRS003_Msk		(0x1UL << SPS0_PRS003_Pos)
#define SPS0_PRS003			SPS0_PRS003_Msk
#define SPS0_PRS010_Pos		(4U)
#define SPS0_PRS010_Msk		(0x1UL << SPS0_PRS010_Pos)
#define SPS0_PRS010			SPS0_PRS010_Msk
#define SPS0_PRS011_Pos		(5U)
#define SPS0_PRS011_Msk		(0x1UL << SPS0_PRS011_Pos)
#define SPS0_PRS011			SPS0_PRS011_Msk
#define SPS0_PRS012_Pos		(6U)
#define SPS0_PRS012_Msk		(0x1UL << SPS0_PRS012_Pos)
#define SPS0_PRS012			SPS0_PRS012_Msk
#define SPS0_PRS013_Pos		(7U)
#define SPS0_PRS013_Msk		(0x1UL << SPS0_PRS013_Pos)
#define SPS0_PRS013			SPS0_PRS013_Msk

/* SO0 - �V���A���o�̓��W�X�^0 */
#define SO0_SO02_Pos		(2U)
#define SO0_SO02_Msk		(0x1UL << SO0_SO02_Pos)
#define SO0_SO02			SO0_SO02_Msk

/* SMR02 - �V���A���E���[�h�E���W�X�^02 */
#define SMR02_MD020_Pos		(0U)
#define SMR02_MD020_Msk		(0x1UL << SMR02_MD020_Pos)
#define SMR02_MD020			SMR02_MD020_Msk
#define SMR02_MD021_Pos		(1U)
#define SMR02_MD021_Msk		(0x1UL << SMR02_MD021_Pos)
#define SMR02_MD021			SMR02_MD021_Msk
#define SMR02_MD022_Pos		(2U)
#define SMR02_MD022_Msk		(0x1UL << SMR01_MD012_Pos)
#define SMR02_MD022			SMR02_MD022_Msk
#define SMR02_CKS02_Pos		(15U)
#define SMR02_CKS02_Msk		(0x1UL << SMR02_CKS02_Pos)
#define SMR02_CKS02			SMR02_CKS02_Msk

/* SCR02 - �V���A���ʐM����ݒ背�W�X�^02 */
#define SCR02_DLS020_Pos	(0U)
#define SCR02_DLS020_Msk	(0x1UL << SCR02_DLS020_Pos)
#define SCR02_DLS020		SCR02_DLS020_Msk
#define SCR02_DLS021_Pos	(1U)
#define SCR02_DLS021_Msk	(0x1UL << SCR02_DLS021_Pos)
#define SCR02_DLS021		SCR02_DLS021_Msk
#define SCR02_SLC020_Pos	(4U)
#define SCR02_SLC020_Msk	(0x1UL << SCR02_SLC020_Pos)
#define SCR02_SLC020		SCR02_SLC020_Msk
#define SCR02_SLC021_Pos	(5U)
#define SCR02_SLC021_Msk	(0x1UL << SCR02_SLC021_Pos)
#define SCR02_SLC021		SCR02_SLC021_Msk
#define SCR02_DIR02_Pos		(7U)
#define SCR02_DIR02_Msk		(0x1UL << SCR02_DIR02_Pos)
#define SCR02_DIR02			SCR02_DIR02_Msk
#define SCR02_PCT020_Pos	(8U)
#define SCR02_PCT020_Msk	(0x1UL << SCR02_PCT020_Pos)
#define SCR02_PCT020		SCR02_PCT020_Msk
#define SCR02_PCT021_Pos	(9U)
#define SCR02_PCT021_Msk	(0x1UL << SCR02_PCT021_Pos)
#define SCR02_PCT021		SCR02_PCT021_Msk
#define SCR02_TXE02_Pos		(15U)
#define SCR02_TXE02_Msk		(0x1UL << SCR02_TXE02_Pos)
#define SCR02_TXE02			SCR02_TXE02_Msk

/* SSR02 - �V���A���E�X�e�[�^�X�E���W�X�^02 */
#define SSR02_BFF02_Pos		(5U)
#define SSR02_BFF02_Msk		(0x1UL << SSR02_BFF02_Pos)
#define SSR02_BFF02			SSR02_BFF02_Msk

/* SMR03 - �V���A���E���[�h�E���W�X�^03 */
#define SMR03_MD030_Pos		(0U)
#define SMR03_MD030_Msk		(0x1UL << SMR03_MD030_Pos)
#define SMR03_MD030			SMR03_MD030_Msk
#define SMR03_MD031_Pos		(1U)
#define SMR03_MD031_Msk		(0x1UL << SMR03_MD031_Pos)
#define SMR03_MD031			SMR03_MD031_Msk
#define SMR03_MD032_Pos		(2U)
#define SMR03_MD032_Msk		(0x1UL << SMR03_MD032_Pos)
#define SMR03_MD032			SMR03_MD032_Msk
#define SMR03_STS03_Pos		(8U)
#define SMR03_STS03_Msk		(0x1UL << SMR03_STS03_Pos)
#define SMR03_STS03			SMR03_STS03_Msk
#define SMR03_CKS03_Pos		(15U)
#define SMR03_CKS03_Msk		(0x1UL << SMR03_CKS03_Pos)
#define SMR03_CKS03			SMR03_CKS03_Msk

/* SCR03 - �V���A���ʐM����ݒ背�W�X�^03 */
#define SCR03_DLS030_Pos	(0U)
#define SCR03_DLS030_Msk	(0x1UL << SCR03_DLS030_Pos)
#define SCR03_DLS030		SCR03_DLS030_Msk
#define SCR03_DLS031_Pos	(1U)
#define SCR03_DLS031_Msk	(0x1UL << SCR03_DLS031_Pos)
#define SCR03_DLS031		SCR03_DLS031_Msk
#define SCR03_SLC030_Pos	(4U)
#define SCR03_SLC030_Msk	(0x1UL << SCR03_SLC030_Pos)
#define SCR03_SLC030		SCR03_SLC030_Msk
#define SCR03_SLC031_Pos	(5U)
#define SCR03_SLC031_Msk	(0x1UL << SCR03_SLC031_Pos)
#define SCR03_SLC031		SCR03_SLC031_Msk
#define SCR03_DIR03_Pos		(7U)
#define SCR03_DIR03_Msk		(0x1UL << SCR03_DIR03_Pos)
#define SCR03_DIR03			SCR03_DIR03_Msk
#define SCR03_PCT030_Pos	(8U)
#define SCR03_PCT030_Msk	(0x1UL << SCR03_PCT030_Pos)
#define SCR03_PCT030		SCR03_PCT030_Msk
#define SCR03_PCT031_Pos	(9U)
#define SCR03_PCT031_Msk	(0x1UL << SCR03_PCT031_Pos)
#define SCR03_PCT031		SCR03_PCT031_Msk
#define SCR03_EOC03_Pos		(10U)
#define SCR03_EOC03_Msk		(0x1UL << SCR03_EOC03_Pos)
#define SCR03_EOC03			SCR03_EOC03_Msk
#define SCR03_RXE03_Pos		(14U)
#define SCR03_RXE03_Msk		(0x1UL << SCR03_RXE03_Pos)
#define SCR03_RXE03			SCR03_RXE03_Msk

/* SSR03 - �V���A���E�X�e�[�^�X�E���W�X�^03 */
#define SSR03_BFF03_Pos		(5U)
#define SSR03_BFF03_Msk		(0x1UL << SSR03_BFF03_Pos)
#define SSR03_BFF03			SSR03_BFF03_Msk

/*
 *  �����ݔԍ�
 */
typedef enum
{
	WDTI_IRQn					= 0,		/* �E�H�b�`�h�b�O�E�^�C�}�̃C���^�[�o��												*/
	LVI_IRQn					= 1,		/* �d�����o																			*/
	P0_IRQn						= 2,		/* �[�q���̓G�b�W���o0																*/
	P1_IRQn						= 3,		/* �[�q���̓G�b�W���o1																*/
	P2_IRQn						= 4,		/* �[�q���̓G�b�W���o2																*/
	P3_IRQn						= 5,		/* �[�q���̓G�b�W���o3																*/
	P4_IRQn						= 6,		/* �[�q���̓G�b�W���o4																*/
	P5_IRQn						= 7,		/* �[�q���̓G�b�W���o5																*/
	ST2_CSI20_IIC20_IRQn		= 8,		/* UART2���M�̓]�������C�o�b�t�@�󂫊��荞��										*/
											/* CSI20�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC20�̓]������																	*/
	SR2_CSI21_IIC21_IRQn		= 9,		/* UART2��M�̓]������																*/
											/* CSI21�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC21�̓]������																	*/
	SRE2_TM11H_IRQn				= 10,		/* UART2��M�̒ʐM�G���[����														*/
											/* �^�C�}�E�`���l��11�̃J�E���g�����܂��̓L���v�`������								*/
	ST0_CSI00_IIC00_IRQn		= 13,		/* UART0���M�̓]�������C�o�b�t�@�󂫊��荞��										*/
											/* CSI00�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC00�̓]������																	*/
	SR0_CSI01_IIC01_IRQn		= 14,		/* UART0��M�̓]������																*/
											/* CSI01�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC01�̓]������																	*/
	SRE0_TM01H_IRQn				= 15,		/* UART0��M�̒ʐM�G���[����														*/
											/* �^�C�}�E�`���l��01�̃J�E���g�����܂��̓L���v�`������								*/
	ST1_CSI10_IIC10_IRQn		= 16,		/* UART1���M�̓]�������C�o�b�t�@�󂫊��荞��										*/
											/* CSI10�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC10�̓]������																	*/
	SR1_CSI11_IIC11_IRQn		= 17,		/* UART1��M�̓]������																*/
											/* CSI11�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC11�̓]������																	*/
	SRE1_TM03H_IRQn				= 18,		/* UART1��M�̒ʐM�G���[����														*/
											/* �^�C�}�E�`���l��03�̃J�E���g�����܂��̓L���v�`������								*/
	IICA0_IRQn					= 19,		/* IICA0�ʐM����																	*/
	TM00_IRQn					= 20,		/* �^�C�}�E�`���l��00�̃J�E���g�����܂��̓L���v�`������								*/
	TM01_IRQn					= 21,		/* �^�C�}�E�`���l��01�̃J�E���g�����܂��̓L���v�`������								*/
	TM02_IRQn					= 22,		/* �^�C�}�E�`���l��02�̃J�E���g�����܂��̓L���v�`������								*/
	TM03_IRQn					= 23,		/* �^�C�}�E�`���l��03�̃J�E���g�����܂��̓L���v�`������								*/
	AD_IRQn						= 24,		/* A/D�ϊ��I��																		*/
	RTC_IRQn					= 25,		/* ���A���^�C���E�N���b�N�̒�����M���^�A���[����v���o								*/
	IT_IRQn						= 26,		/* �C���^�[�o���M�����o																*/
	KR_IRQn						= 27,		/* �L�[�E���^�[���M�����o															*/
	ST3_CSI30_IIC30_IRQn		= 28,		/* UART3���M�̓]�������C�o�b�t�@�󂫊��荞��										*/
											/* CSI30�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC30�̓]������																	*/
	SR3_CSI31_IIC31_IRQn		= 29,		/* UART3��M�̓]������																*/
											/* CSI31�̓]�������C�o�b�t�@�󂫊��荞��											*/
											/* IIC31�̓]������																	*/
	TRJ0_IRQn					= 30,		/* �^�C�}RJ���荞��																	*/
	TM10_IRQn					= 31,		/* �^�C�}�E�`���l��10�̃J�E���g�����܂��̓L���v�`������								*/
	TM11_IRQn					= 32,		/* �^�C�}�E�`���l��11�̃J�E���g�����܂��̓L���v�`������								*/
	TM12_IRQn					= 33,		/* �^�C�}�E�`���l��12�̃J�E���g�����܂��̓L���v�`������								*/
	TM13_IRQn					= 34,		/* �^�C�}�E�`���l��13�̃J�E���g�����܂��̓L���v�`������								*/
	P6_IRQn						= 35,		/* �[�q���̓G�b�W���o6																*/
	P7_IRQn						= 36,		/* �[�q���̓G�b�W���o7																*/
	P8_IRQn						= 37,		/* �[�q���̓G�b�W���o8																*/
	P9_IRQn						= 38,		/* �[�q���̓G�b�W���o9																*/
	P10_CMP0_IRQn				= 39,		/* �[�q���̓G�b�W���o10																*/
											/* �R���p���[�^���o0																*/
	P11_CMP1_IRQn				= 40,		/* �[�q���̓G�b�W���o11																*/
											/* �R���p���[�^���o1																*/
	TRD0_IRQn					= 41,		/* �^�C�}RD0�C���v�b�g�L���v�`���C�R���y�A��v�C�I�[�o�t���[�C�A���_�t���[���荞��	*/
	TRD1_IRQn					= 42,		/* �^�C�}RD1�C���v�b�g�L���v�`���C�R���y�A��v�C�I�[�o�t���[�C�A���_�t���[���荞��	*/
	TRG_IRQn					= 43,		/* �^�C�}RG�C���v�b�g�L���v�`���C�R���y�A��v�C�I�[�o�t���[�C�A���_�t���[���荞��	*/
	SRE3_TM13H_IRQn				= 44,		/* UART3��M�̒ʐM�G���[����														*/
											/* �^�C�}�E�`���l��13�̃J�E���g�����܂��̓L���v�`������								*/
	IICA1_IRQn					= 46,		/* IICA1�ʐM����																	*/
	FL_IRQn						= 47,		/* �\��																				*/
} IRQn_Type;

#endif  /* RL78G14_H */
