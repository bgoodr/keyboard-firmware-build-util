.PHONY: all
all: dependencies

.PHONY: dependencies
dependencies: dfu-programmer

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
