CC                    := gcc
BIN                   := freertos_simulator

BUILD_DIR             := ./build
BUILD_DIR_ABS         := $(abspath $(BUILD_DIR))

KERNEL_DIR            := ../../FreeRTOS/FreeRTOS-Kernel

INCLUDE_DIRS          := -I.
INCLUDE_DIRS          += -I${KERNEL_DIR}/include
INCLUDE_DIRS          += -I${KERNEL_DIR}/portable/ThirdParty/GCC/Posix
INCLUDE_DIRS          += -I${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils

SOURCE_FILES          := main.c main_blinky.c console.c
SOURCE_FILES          += $(wildcard ${KERNEL_DIR}/*.c)

# Memory manager (use malloc() / free() )
SOURCE_FILES          += ${KERNEL_DIR}/portable/MemMang/heap_3.c
# posix port
SOURCE_FILES          += ${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c
SOURCE_FILES          += ${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/port.c


CFLAGS                :=    -ggdb3
LDFLAGS               :=    -ggdb3 -pthread
CPPFLAGS              :=    $(INCLUDE_DIRS) -DBUILD_DIR=\"$(BUILD_DIR_ABS)\"
CPPFLAGS              +=    -D_WINDOWS_

CPPFLAGS              += -DTRACE_ON_ENTER=1
CPPFLAGS              += -DprojCOVERAGE_TEST=1
SANITIZE_LEAK = 1
SANITIZE_ADDRESS = 1

CFLAGS              +=    -O0

CFLAGS              +=   -fsanitize=address -fsanitize=alignment
LDFLAGS             +=   -fsanitize=address -fsanitize=alignment

LDFLAGS             +=   -fsanitize=leak

CPPFLAGS            +=   -DUSER_DEMO=0


vpath %.c $(sort $(dir $(SOURCE_FILES)))

OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCE_FILES:%.c=%.o)))

DEP_FILE = $(OBJ_FILES:%.o=%.d)

${BIN} : $(BUILD_DIR)/$(BIN)

${BUILD_DIR}/${BIN} : ${OBJ_FILES}
	-mkdir -p ${@D}
	$(CC) $^ ${LDFLAGS} -o $@

-include ${DEP_FILE}

${BUILD_DIR}/%.o : %.c Makefile
	@-mkdir -p $(@D)  $(@D)/files
	@echo $<
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -c $< -o $@


.PHONY: clean

clean:
	-rm -rf $(BUILD_DIR) result


GPROF_OPTIONS := --directory-path=$(INCLUDE_DIRS)
profile:
	gprof -a -p --all-lines $(GPROF_OPTIONS) $(BUILD_DIR)/$(BIN) $(BUILD_DIR)/gmon.out > $(BUILD_DIR)/prof_flat.txt
	gprof -a --graph $(GPROF_OPTIONS) $(BUILD_DIR)/$(BIN) $(BUILD_DIR)/gmon.out > $(BUILD_DIR)/prof_call_graph.txt
	gprof2dot $(BUILD_DIR)/prof_call_graph.txt -n0 -e0 | dot -Tpng -o prof_call_graph.png
	gprof2dot $(BUILD_DIR)/prof_flat.txt -n0 -e0 | dot -Tpng -o prof_flat.png

gcov:
	lcov -c -d . -o ${BIN}.info --rc lcov_branch_coverage=1
	genhtml --branch-coverage -o result ${BIN}.info
