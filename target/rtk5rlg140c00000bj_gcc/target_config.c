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
 *		ターゲット依存モジュール（RTK5RLG140C00000BJ用）
 */

#include "kernel_impl.h"
#include "target_syssvc.h"
#include <sil.h>
#include "rl78g14.h"


extern void start (void);

const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
	0xef, 0xff, 0xe8, 0x85
};

/* 0xCE～0xD7の10バイトはデバッグモニタ領域であるため0xFFで埋めておくこと */
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

	/* ポートの設定 */
	PIOR0 &= ~PIOR0_PIOR05;

	// TxD1
	POM0_bit.no2 = 0;
	PMC0_bit.no2 = 0;
	PM0_bit.no2 = 0;
	P0_bit.no2 = 1;
	// RxD1
	PMC0_bit.no3 = 0;
	PM0_bit.no3 = 1;

	/* クロックの設定 */
	SAU0EN = 1;				// 入力クロック供給許可
							// シリアル・アレイ・ユニットmで使用するSFRへのリード／ライト可
	ST0L = 0x0F;			// トリガ動作せず
	SPS0L = 0x00;			// SPS0Lリセット
	SPS0L |= (
			SPS0_PRS002	|	// CKm0 = 2 MHz
			SPS0_PRS011		// Ckm1 = 8 MHz
			);

#define CKm0_CLOCK	(SYS_CLOCK/16)
#define CKm1_CLOCK	(SYS_CLOCK/4)

	/*
	 *
	 * UART1はユニット0のチャネル2(TxD1),3(RxD1)
	 *
	 */

	/* TxD1の設定 */
	ST0L_bit.no2 = 0;		// UART1(チャネル2)動作停止状態
	SMR02 = 0x0020;			// SMR02リセット
	SMR02 |= (
			SMR02_MD020 |	// バッファ空き割り込み
			SMR02_MD021		// UARTモード
//			SMR02_MD022
//			SMR02_CKS02		// CKm0 = 2 MHz
			);
	SCR02 = 0x0004;			// SCR02リセット
	SCR02 |= (
			SCR02_DLS020 |	// 8ビット・データ長
			SCR02_DLS021 |
			SCR02_SLC020 |	// ストップビット1
//			SCR02_SLC021
			SCR02_DIR02	|	// LSBファースト
//			SCR02_PCT020	// パリティなし
//			SCR02_PCT021
			SCR02_TXE02		// 送信のみを行う
			);
	SDR02 = 0x0000;			// SDR02リセット
//	br = (2000000 / (9600 * 2)) - 1;
	br = (CKm0_CLOCK / (BPS_SETTING * 2)) - 1;
	SDR02 |= br << 9;		// 9600bps

	/* RxD1の設定 */
	ST0L_bit.no3 = 0;		// UART1(チャネル3)動作停止状態
	SMR03 = 0x0020;			// リセット
	SMR03 |= (
//			SMR03_MD030		// 転送完了割り込み
			SMR03_MD031	|	// UARTモード
//			SMR02_MD032
			SMR03_STS03		// RxDq端子の有効エッジ(UART受信時に選択)
//			SMR03_CKS03		// CKm0 = 2 MHz
			);
	SCR03 = 0x0004;			// SCR03リセット
	SCR03 |= (
			SCR03_DLS030 |	// 8ビット・データ長
			SCR03_DLS031 |
			SCR03_SLC030 |	// ストップビット1
//			SCR03_SLC031
			SCR03_DIR03	|	// LSBファースト
//			SCR03_EOC03 |	// エラー割り込みINTSRExの発生を許可する(エラー発生時，INTSRxは発生しない)
//			SCR03_PCT030	// パリティなし
//			SCR03_PCT031
			SCR03_RXE03		// 受信のみを行う
			);
	SDR03 = 0x0000;			// SDR03リセット
//	br = (2000000 / (9600 * 2)) - 1;
	br = (CKm0_CLOCK / (BPS_SETTING * 2)) - 1;
	SDR03 |= br << 9;		// 9600bps

	/* UART1通信待機状態に遷移 */
	SO0 |= SO0_SO02;		// シリアル・データ出力値が“1”
	SOE0L_bit.no2 = 1;		// シリアル通信動作による出力許可
	SS0L_bit.no2 = 1;		// SE02ビットに1をセットし，通信待機状態に遷移する
	SS0L_bit.no3 = 1;		// SE03ビットに1をセットし，通信待機状態に遷移する
}

/*
 *  ターゲット依存の初期化
 */
//uint16_t psw;
void
target_initialize(void)
{
	/*
	 *  プロセッサ依存の初期化
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
 *  ターゲット依存の終了処理
 */
void
target_exit(void)
{
	/*
	 *  プロセッサ依存の終了処理
	 */
	prc_terminate();
	while(1);
}

/*
 *  システムログの低レベル出力のための文字出力
 */
void
target_fput_log(char c)
{
	if (c == '\n') {
		TXD1 = '\r';
		while (SSR02 & SSR02_BFF02);	// 送信ポーリング
	}
	TXD1 = c;
	while (SSR02 & SSR02_BFF02);	// 送信ポーリング
}

/*
 *  割込み要求ラインの属性の設定
 *
 *  ASPカーネルでの利用を想定して，パラメータエラーはアサーションでチェッ
 *  クしている．cfg_intサービスコールを設ける場合には，エラーを返すよう
 *  にすべきであろう．
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	uint8_t	pri;
	uint_t index;

	assert(VALID_INTNO_CFGINT(intno));
	assert(TMIN_INTPRI <= intpri && intpri <= TMAX_INTPRI);

	/*
	 *  一旦割込みを禁止する
	 */
	(void)x_disable_int(intno);

	/*
	 *  割込み優先度をセット
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
	 *  割込み要求マスク解除(必要な場合)
	 */
	if ((intatr & TA_ENAINT) != 0U) {
		(void) x_enable_int(intno);
	}
}
