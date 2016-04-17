.PHONY: all
all: dependencies

.PHONY: dependencies
dependencies: dfu-programmer s60-x-firmware

# Currently only Debian-based Linux is supported:
define mandate_platforms
	@if [ -z "$$(grep 'Ubuntu\|Debian' /etc/lsb-release)" ]; then \
		echo "ERROR: Platform not supported"; \
	fi
endef

.PHONY: dfu-programmer
dfu-programmer:
	@$(mandate_platforms)
	@if [ ! -f /usr/bin/dfu-programmer ]; then \
		echo ; \
		echo Note: Installing dfu-programmer; \
		echo ; \
		sudo apt-get install dfu-programmer; \
	fi


firmware_source_git_repo = https://github.com/VinnyCordeiro/tmk_keyboard.git

.PHONY: s60-x-firmware
s60-x-firmware:
	@$(mandate_platforms)
	@if [ ! -d ./tmk_keyboard ]; then \
		echo ; \
		echo Note: Downloading S60-X firmware from $(firmware_source_git_repo) ...; \
		echo ; \
		git clone $(firmware_source_git_repo); \
	fi
