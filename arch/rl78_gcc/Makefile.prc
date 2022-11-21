#
#		Makefileのプロセッサ依存部（RL78G14用）
#

#
#  GNU開発環境のターゲットアーキテクチャの定義
#
GCC_TARGET = rl78-elf

#
#  プロセッサ依存部ディレクトリ名の定義
#
PRCDIR = $(SRCDIR)/arch/$(PRC)_$(TOOL)

#
#  コンパイルオプション
#
INCLUDES := $(INCLUDES) \
		    -I$(SRCDIR)/arch/$(PRC)_$(TOOL)/include_gcc
COPTS := $(COPTS) -mg14 -fsigned-char -falign-functions=16
#LDFLAGS := $(LDFLAGS) -mg14 -fsigned-char -nostartfiles
LDFLAGS := $(LDFLAGS) -nostartfiles

#
#  カーネルに関する定義
#
KERNEL_DIR := $(KERNEL_DIR) $(PRCDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o

#
#  コンフィギュレータ関係の変数の定義
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(PRCDIR)/prc_def.csv

#
#  オフセットファイル生成のための定義
#
OFFSET_TF = $(PRCDIR)/prc_offset.tf
