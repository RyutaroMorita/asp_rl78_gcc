$
$ 		パス2のターゲット依存テンプレート（RTK5RLG140C00000BJ用）
$

$
$  有効な割込み番号，割込みハンドラ番号
$
$INTNO_VALID = { 0,1,...,47 }$
$INHNO_VALID = INTNO_VALID$
$PADDING = { 48,49,...,60 }$

$
$  _kernel_exc_tblにおけるCPU例外の開始位置
$  （RL78は例外ハンドラが一つしかないのでテーブルの最後に一つだけ配置する）
$
$START_EXC = 61$

$
$  有効なCPU例外番号
$
$EXCNO_VALID = { 0 }$

$
$  ATT_ISRで使用できる割込み番号とそれに対応する割込みハンドラ番号
$
$INTNO_ATTISR_VALID = INTNO_VALID$
$INHNO_ATTISR_VALID = INHNO_VALID$

$
$  DEF_INT／DEF_EXCで使用できる割込みハンドラ番号／CPU例外ハンドラ番号
$
$INHNO_DEFINH_VALID = INHNO_VALID$
$EXCNO_DEFEXC_VALID = EXCNO_VALID$

$
$  CFG_INTで使用できる割込み番号と割込み優先度
$
$INTNO_CFGINT_VALID = INTNO_VALID$
$INTPRI_CFGINT_VALID = { -4,-3,...,-1 }$

$
$  標準テンプレートファイルのインクルード
$
$INCLUDE "kernel/kernel.tf"$

/*$NL$
$SPC$*  Target-dependent Definitions (RTK5RLG140C00000BJ)$NL$
$SPC$*/$NL$
$NL$

$
$   CFG_INTのターゲット依存のエラーチェックと_kernel_bitpat_cfgintの生成
$
$bitpat_cfgint = 0$
const uint32_t	_kernel_bitpat_cfgint = UINT32_C($FORMAT("0x%08x", bitpat_cfgint)$);
$NL$

$NL$

$FOREACH inhno INTNO_VALID$
	extern void $FORMAT("__kernel_int_handler_%d(void);", +inhno)$$NL$
	asm(".section .text \n\t"$NL$
	$FORMAT("\"__kernel_int_handler_%d: \\n\\t\"", +inhno)$$NL$
	"	sel rb0 \n\t"$NL$
	"	push bc \n\t"$NL$
	$FORMAT("\"	movw bc, #%d \\n\\t\"", +inhno)$$NL$
	"	br !!_kernel_inthdr_entry \n\t");$NL$
	$NL$
$END$

$FOREACH excno EXCNO_VALID$
	extern void $FORMAT("__kernel_exc_handler_%d(void);", +excno)$$NL$
	asm(".section .text \n\t"$NL$
	$FORMAT("\"__kernel_exc_handler_%d: \\n\\t\"", +excno)$$NL$
	"	sel rb0 \n\t"$NL$
	"	push bc \n\t"$NL$
	$FORMAT("\"	movw bc, #%d \\n\\t\"", +(excno + START_EXC))$$NL$
	"	br !!_kernel_exchdr_entry \n\t");$NL$
	$NL$
$END$

FP _kernel_exc_tbl[] = $NL$
{$NL$
$FOREACH inhno INTNO_VALID$
	$IF LENGTH(INH.INHNO[inhno])$
		$TAB$(FP)($INH.INTHDR[inhno]$),
	$ELSE$
		$TAB$(FP)(_kernel_default_int_handler),
	$END$
	$SPC$$FORMAT("/* %d */", +inhno)$$NL$
$END$
$FOREACH padding PADDING$
	$TAB$(FP)(_kernel_default_int_handler),
	$SPC$/* Padding */$NL$
$END$
$FOREACH excno EXCNO_VALID$
	$IF LENGTH(EXC.EXCNO[excno])$
		$TAB$(FP)($EXC.EXCHDR[excno]$),
	$ELSE$
		$TAB$(FP)(_kernel_default_int_handler),
	$END$
	$SPC$$FORMAT("/* %d */", +excno)$$NL$
$END$
};$NL$

$NL$
asm(".section .vects,\"a\" \n\t"$NL$
$FOREACH inhno INTNO_VALID$
	$FORMAT("\"	.short __kernel_int_handler_%d \\n\\t\"", +inhno)$$NL$
$END$
$FOREACH padding PADDING$
	"	.short 0xFFFF \n\t"$NL$
$END$
$FOREACH excno EXCNO_VALID$
	$FORMAT("\"	.short __kernel_exc_handler_%d \\n\\t\"", +excno)$$NL$
$END$
".section .text \n\t"$NL$
);$NL$
