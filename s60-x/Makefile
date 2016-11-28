# --------------------------------------------------------------------------------
# Define customizable variables:
# --------------------------------------------------------------------------------
firmware_source_git_repo = https://github.com/VinnyCordeiro/tmk_keyboard.git
firmware_subdir = tmk_keyboard/keyboard/s60-x

# --------------------------------------------------------------------------------
# Define utility variables and functions:
# --------------------------------------------------------------------------------
# Currently only Debian-based Linux is supported:
define mandate_platforms
	@if [ -z "$$(grep 'Ubuntu\|Debian' /etc/lsb-release)" ]; then \
		echo "ERROR: Platform not supported"; \
	fi
endef

define install_linux_package
	@$(mandate_platforms)
	@if [ ! -f $(2) ]; then \
		echo ; \
		echo Note: Installing $(1) which provides $(2); \
		echo ; \
		sudo apt-get install $(1); \
		if [ ! -f $(2) ]; then \
			echo ; \
			echo ERROR: Installing $(1) did not provide $(2) as expected; \
			echo ; \
			exit 1; \
		fi; \
	fi
endef

# --------------------------------------------------------------------------------
# Define rules:
# --------------------------------------------------------------------------------
.PHONY: all
all: build

# Reference the build instructions at https://github.com/VinnyCordeiro/tmk_keyboard/tree/master/keyboard/s60-x
# 
# Use --assume-new=keymap_$(KEYMAP).c below in order to force the
# specified KEYMAP file to be rebuilt each time. Without this, and you
# compile different keymaps and try to load them, the .hex file does
# not get regenerated.
#
.PHONY: build
build: dfu-programmer download-firmware
	./install_local_keymaps.sh $(firmware_subdir)
	make -C $(firmware_subdir) --assume-new=keymap_$(KEYMAP).c KEYMAP=$(KEYMAP) 

.PHONY: load
load: build install_udev_rules
	make -C $(firmware_subdir) KEYMAP=$(KEYMAP) dfu

.PHONY: install_udev_rules
install_udev_rules:
	./install_udev_rules.sh $(firmware_subdir)

.PHONY: clean
clean:
	./install_udev_rules.sh $(firmware_subdir) clean
	./install_local_keymaps.sh $(firmware_subdir) clean
	make -C $(firmware_subdir) KEYMAP=$(KEYMAP) clean

.PHONY: dfu-programmer
dfu-programmer:
	$(call install_linux_package,dfu-programmer,/usr/bin/dfu-programmer)

.PHONY: download-firmware
download-firmware: avr-gcc
	@$(mandate_platforms)
	@if [ ! -d ./tmk_keyboard ]; then \
		echo ; \
		echo Note: Downloading firmware from $(firmware_source_git_repo) ...; \
		echo ; \
		git clone $(firmware_source_git_repo); \
		if [ ! -d ./tmk_keyboard ]; then \
			echo ; \
			echo ERROR: Installing $(firmware_source_git_repo) did not provide ./tmk_keyboard as expected; \
			echo ; \
			exit 1; \
		fi; \
	fi

.PHONY: avr-gcc
avr-gcc: avr-libc 
	$(call install_linux_package,gcc-avr,/usr/bin/avr-gcc)

# The avr-libc provides the /usr/lib/avr/include/stdint.h which is
# needed by avr-gcc whenever its stdint.h is included. Without this
# package, we get this error:
#
#    In file included from keymap_common.h:20:0,
#                     from keymap_standard.c:1:
#    /usr/lib/gcc/avr/4.8.1/include/stdint.h:9:26: fatal error: stdint.h: No such file or directory
#     # include_next <stdint.h>
#                              ^
#    compilation terminated.
#
# "apt-cache --no-all-versions show gcc-avr" indicates that avr-libc is suggested:
#
#    Suggests: task-c-devel, gcc-doc (>= 4:4.8), gcc (>= 4:4.8), avr-libc (>= 1:1.8.0-4)
#
.PHONY: avr-libc
avr-libc:
	$(call install_linux_package,avr-libc,/usr/lib/avr/include/stdint.h)


