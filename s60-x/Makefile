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
		@if [ ! -f $(2) ]; then \
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
.PHONY: build
build: dfu-programmer s60-x-firmware
	make -C tmk_keyboard/keyboard/s60-x KEYMAP=$(KEYMAP) 

.PHONY: dfu-programmer
dfu-programmer:
	$(call install_linux_package,dfu-programmer,/usr/bin/dfu-programmer)

firmware_source_git_repo = https://github.com/VinnyCordeiro/tmk_keyboard.git
.PHONY: s60-x-firmware
s60-x-firmware: avr-gcc
	@$(mandate_platforms)
	@if [ ! -d ./tmk_keyboard ]; then \
		echo ; \
		echo Note: Downloading S60-X firmware from $(firmware_source_git_repo) ...; \
		echo ; \
		git clone $(firmware_source_git_repo); \
		@if [ ! -d ./tmk_keyboard ]; then \
			echo ; \
			echo ERROR: Installing $(firmware_source_git_repo) did not provide ./tmk_keyboard as expected; \
			echo ; \
			exit 1; \
		fi; \
	fi

.PHONY: avr-gcc
avr-gcc: libc6-dev
	$(call install_linux_package,gcc-avr,/usr/bin/avr-gcc)

.PHONY:
libc6-dev:
	$(call install_linux_package,libc6-dev,/usr/include/stdint.h)

