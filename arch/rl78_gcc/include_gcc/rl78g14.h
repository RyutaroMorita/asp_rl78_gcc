/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2015 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 *	2022/11/21 Ryutaro Morita
 */

/*
 *  RL78G14のハードウェア資源の定義
 */

#ifndef RL78G14_H
#define RL78G14_H

#include "iodefine.h"
#include "iodefine_ext.h"

/* OSMC - サブシステム・クロック供給モード制御レジスタ */
#define OSMC_WUTMMCK0_Pos	(4U)
#define OSMC_WUTMMCK0_Msk	(0x1UL << OSMC_WUTMMCK0_Pos)
#define OSMC_WUTMMCK0		OSMC_WUTMMCK0_Msk
#define OSMC_RTCLPC_Pos		(7U)
#define OSMC_RTCLPC_Msk		(0x1UL << OSMC_RTCLPC_Pos)
#define OSMC_RTCLPC			OSMC_RTCLPC_Msk

/* ITMC - 12ビット・インターバル・タイマ・コントロール・レジスタ */
#define ITMC_ITCMP_Pos		(0U)
#define ITMC_ITCMP_Msk		(0xFFFUL << ITMC_ITCMP_Pos)
#define ITMC_ITCMP			ITMC_ITCMP_Msk
#define ITMC_RINTE_Pos		(15U)
#define ITMC_RINTE_Msk		(0x1UL << ITMC_RINTE_Pos)
#define ITMC_RINTE			ITMC_RINTE_Msk

/* PIOR0 - 周辺I/Oリダイレクション・レジスタ0 */
#define PIOR0_PIOR05_Pos	(5U)
#define PIOR0_PIOR05_Msk	(0x1UL << PIOR0_PIOR05_Pos)
#define PIOR0_PIOR05		PIOR0_PIOR05_Msk

/* SPS0 - シリアル・クロック選択レジスタ0 */
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

/* SO0 - シリアル出力レジスタ0 */
#define SO0_SO02_Pos		(2U)
#define SO0_SO02_Msk		(0x1UL << SO0_SO02_Pos)
#define SO0_SO02			SO0_SO02_Msk

/* SMR02 - シリアル・モード・レジスタ02 */
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

/* SCR02 - シリアル通信動作設定レジスタ02 */
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

/* SSR02 - シリアル・ステータス・レジスタ02 */
#define SSR02_BFF02_Pos		(5U)
#define SSR02_BFF02_Msk		(0x1UL << SSR02_BFF02_Pos)
#define SSR02_BFF02			SSR02_BFF02_Msk

/* SMR03 - シリアル・モード・レジスタ03 */
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

/* SCR03 - シリアル通信動作設定レジスタ03 */
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

/* SSR03 - シリアル・ステータス・レジスタ03 */
#define SSR03_BFF03_Pos		(5U)
#define SSR03_BFF03_Msk		(0x1UL << SSR03_BFF03_Pos)
#define SSR03_BFF03			SSR03_BFF03_Msk

/*
 *  割込み番号
 */
typedef enum
{
	WDTI_IRQn					= 0,		/* ウォッチドッグ・タイマのインターバル												*/
	LVI_IRQn					= 1,		/* 電圧検出																			*/
	P0_IRQn						= 2,		/* 端子入力エッジ検出0																*/
	P1_IRQn						= 3,		/* 端子入力エッジ検出1																*/
	P2_IRQn						= 4,		/* 端子入力エッジ検出2																*/
	P3_IRQn						= 5,		/* 端子入力エッジ検出3																*/
	P4_IRQn						= 6,		/* 端子入力エッジ検出4																*/
	P5_IRQn						= 7,		/* 端子入力エッジ検出5																*/
	ST2_CSI20_IIC20_IRQn		= 8,		/* UART2送信の転送完了，バッファ空き割り込み										*/
											/* CSI20の転送完了，バッファ空き割り込み											*/
											/* IIC20の転送完了																	*/
	SR2_CSI21_IIC21_IRQn		= 9,		/* UART2受信の転送完了																*/
											/* CSI21の転送完了，バッファ空き割り込み											*/
											/* IIC21の転送完了																	*/
	SRE2_TM11H_IRQn				= 10,		/* UART2受信の通信エラー発生														*/
											/* タイマ・チャネル11のカウント完了またはキャプチャ完了								*/
	ST0_CSI00_IIC00_IRQn		= 13,		/* UART0送信の転送完了，バッファ空き割り込み										*/
											/* CSI00の転送完了，バッファ空き割り込み											*/
											/* IIC00の転送完了																	*/
	SR0_CSI01_IIC01_IRQn		= 14,		/* UART0受信の転送完了																*/
											/* CSI01の転送完了，バッファ空き割り込み											*/
											/* IIC01の転送完了																	*/
	SRE0_TM01H_IRQn				= 15,		/* UART0受信の通信エラー発生														*/
											/* タイマ・チャネル01のカウント完了またはキャプチャ完了								*/
	ST1_CSI10_IIC10_IRQn		= 16,		/* UART1送信の転送完了，バッファ空き割り込み										*/
											/* CSI10の転送完了，バッファ空き割り込み											*/
											/* IIC10の転送完了																	*/
	SR1_CSI11_IIC11_IRQn		= 17,		/* UART1受信の転送完了																*/
											/* CSI11の転送完了，バッファ空き割り込み											*/
											/* IIC11の転送完了																	*/
	SRE1_TM03H_IRQn				= 18,		/* UART1受信の通信エラー発生														*/
											/* タイマ・チャネル03のカウント完了またはキャプチャ完了								*/
	IICA0_IRQn					= 19,		/* IICA0通信完了																	*/
	TM00_IRQn					= 20,		/* タイマ・チャネル00のカウント完了またはキャプチャ完了								*/
	TM01_IRQn					= 21,		/* タイマ・チャネル01のカウント完了またはキャプチャ完了								*/
	TM02_IRQn					= 22,		/* タイマ・チャネル02のカウント完了またはキャプチャ完了								*/
	TM03_IRQn					= 23,		/* タイマ・チャネル03のカウント完了またはキャプチャ完了								*/
	AD_IRQn						= 24,		/* A/D変換終了																		*/
	RTC_IRQn					= 25,		/* リアルタイム・クロックの定周期信号／アラーム一致検出								*/
	IT_IRQn						= 26,		/* インターバル信号検出																*/
	KR_IRQn						= 27,		/* キー・リターン信号検出															*/
	ST3_CSI30_IIC30_IRQn		= 28,		/* UART3送信の転送完了，バッファ空き割り込み										*/
											/* CSI30の転送完了，バッファ空き割り込み											*/
											/* IIC30の転送完了																	*/
	SR3_CSI31_IIC31_IRQn		= 29,		/* UART3受信の転送完了																*/
											/* CSI31の転送完了，バッファ空き割り込み											*/
											/* IIC31の転送完了																	*/
	TRJ0_IRQn					= 30,		/* タイマRJ割り込み																	*/
	TM10_IRQn					= 31,		/* タイマ・チャネル10のカウント完了またはキャプチャ完了								*/
	TM11_IRQn					= 32,		/* タイマ・チャネル11のカウント完了またはキャプチャ完了								*/
	TM12_IRQn					= 33,		/* タイマ・チャネル12のカウント完了またはキャプチャ完了								*/
	TM13_IRQn					= 34,		/* タイマ・チャネル13のカウント完了またはキャプチャ完了								*/
	P6_IRQn						= 35,		/* 端子入力エッジ検出6																*/
	P7_IRQn						= 36,		/* 端子入力エッジ検出7																*/
	P8_IRQn						= 37,		/* 端子入力エッジ検出8																*/
	P9_IRQn						= 38,		/* 端子入力エッジ検出9																*/
	P10_CMP0_IRQn				= 39,		/* 端子入力エッジ検出10																*/
											/* コンパレータ検出0																*/
	P11_CMP1_IRQn				= 40,		/* 端子入力エッジ検出11																*/
											/* コンパレータ検出1																*/
	TRD0_IRQn					= 41,		/* タイマRD0インプットキャプチャ，コンペア一致，オーバフロー，アンダフロー割り込み	*/
	TRD1_IRQn					= 42,		/* タイマRD1インプットキャプチャ，コンペア一致，オーバフロー，アンダフロー割り込み	*/
	TRG_IRQn					= 43,		/* タイマRGインプットキャプチャ，コンペア一致，オーバフロー，アンダフロー割り込み	*/
	SRE3_TM13H_IRQn				= 44,		/* UART3受信の通信エラー発生														*/
											/* タイマ・チャネル13のカウント完了またはキャプチャ完了								*/
	IICA1_IRQn					= 46,		/* IICA1通信完了																	*/
	FL_IRQn						= 47,		/* 予約																				*/
} IRQn_Type;

#endif  /* RL78G14_H */
