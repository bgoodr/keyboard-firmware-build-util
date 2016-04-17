.PHONY: all
all: dependencies

.PHONY: dependencies
dependencies: dfu-programmer

.PHONY: dfu-programmer
dfu-programmer:
	@if [ -z "$$(grep 'Ubuntu\|Debian' /etc/lsb-release)" ]; then \
		echo "ERROR: Platform not supported"; \
	fi
	@if [ ! -f /usr/bin/dfu-programmer ]; then \
		echo ; \
		echo Note: Installing dfu-programmer; \
		echo ; \
		sudo apt-get install dfu-programmer; \
	fi
