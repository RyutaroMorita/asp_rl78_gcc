#
#		Makefile�̃v���Z�b�T�ˑ����iRL78G14�p�j
#

#
#  GNU�J�����̃^�[�Q�b�g�A�[�L�e�N�`���̒�`
#
GCC_TARGET = rl78-elf

#
#  �v���Z�b�T�ˑ����f�B���N�g�����̒�`
#
PRCDIR = $(SRCDIR)/arch/$(PRC)_$(TOOL)

#
#  �R���p�C���I�v�V����
#
INCLUDES := $(INCLUDES) \
		    -I$(SRCDIR)/arch/$(PRC)_$(TOOL)/include_gcc
COPTS := $(COPTS) -mg14 -fsigned-char -falign-functions=16
#LDFLAGS := $(LDFLAGS) -mg14 -fsigned-char -nostartfiles
LDFLAGS := $(LDFLAGS) -nostartfiles

#
#  �J�[�l���Ɋւ����`
#
KERNEL_DIR := $(KERNEL_DIR) $(PRCDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o

#
#  �R���t�B�M�����[�^�֌W�̕ϐ��̒�`
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(PRCDIR)/prc_def.csv

#
#  �I�t�Z�b�g�t�@�C�������̂��߂̒�`
#
OFFSET_TF = $(PRCDIR)/prc_offset.tf
