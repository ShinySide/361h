log=@echo [$(shell date "+%Y-%m-%d %H:%M:%S")]

KERNEL_CONFIG?=coreprimeve3g-dt_defconfig
CROSS_C= /opt/toolchains/arm-eabi-4.7/bin/arm-eabi- 
CUR_PATH=`pwd`
ARCH=arm

.PHONY:help
help:
	$(hide)echo "======================================="
	$(hide)echo "= This file wraps the build of kernel and modules"
	$(hide)echo "= make kernel: only make the kernel."
	$(hide)echo "= make mali: only make mali."
	$(hide)echo "= make clean: clean the kernel and mali"
	$(hide)echo "======================================="

all: kernel mali

.PHONY: kernel
kernel:
	$(log) "making kernel [$(KERNEL_CONFIG)]..."

	@cd common && \
	make CROSS_COMPILE=$(CROSS_C) $(KERNEL_CONFIG) && \
	make -j8 CROSS_COMPILE=$(CROSS_C) all
	$(log) "kernel [$(KERNEL_CONFIG)] done"

.PHONY: modules
modules:
	$(log) "making modules [$(KERNEL_CONFIG)]..."

	@cd common && \
	make CROSS_COMPILE=$(CROSS_C) $(KERNEL_CONFIG) && \
	make CROSS_COMPILE=$(CROSS_C) modules
	$(log) "modules [$(KERNEL_CONFIG)] done"

.PHONY: mali
mali:
	$(log) "making mali..."
	@cd common && \
	make $(KERNEL_CONFIG) && \
	make -C ../mali \
			MALI_PLATFORM=sc8830 \
			DFS_MAX_FREQ=384000 DFS_MIN_FREQ=104000 \
			CROSS_COMPILE=$(CROSS_C) \
			KDIR=$(CUR_PATH)
	$(log) "mali done"

clean:
	@cd common && \
	make CROSS_COMPILE=$(CROSS_C) clean
	$(log) "Kernel cleaned."


