.PHONY: all
all: dependencies

.PHONY: dependencies
dependencies: dfu-programmer

.PHONY: dfu-programmer
dfu-programmer:
	@if [ ! -f /usr/bin/dfu-programmer ]; then \
		echo ; \
		echo Note: Installing dfu-programmer; \
		echo ; \
		sudo apt-get install dfu-programmer; \
	fi
