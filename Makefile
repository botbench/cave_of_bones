# Copyright 2020 Xander Soldaat <xander@botbench.com>
#
# This Makefile makes it easy to compile a project with x88dk.
# Ensure Z88DK_HOME is set for your installation.

# Change this to the name of the project you want to build.
# This will create a .COM 
PROJECT=skelcave

# Set the path to your z88dk home folder
Z88DK_HOME=/usr/local/share/z88dk

Z88DK_BIN=$(Z88DK_HOME)/bin
CC=$(Z88DK_BIN)/zcc

# This is currently configred to work on the RC2014 based RC126 board, running CP/M 3.x
# Refer to the z88dk documentation to change to suit your own system
CFLAGS=+rc2014 -subtype=cpm -mz180 -vn -create-app -Iinclude -SO3 -clib=new --lstcwd

all: $(PROJECT)

$(PROJECT): build/$(PROJECT).lst
	@echo -n Building $@: 
	@$(CC) $(CFLAGS) @$< -o build/$(PROJECT)
	@cp build/$(PROJECT).bin build/$(PROJECT).com
	@echo "\t\tdone."

build/$(PROJECT).lst:
	@echo -n Creating $@:
	@test -d build || mkdir build
	@ls -c1 src/*.c > $@
	@echo "\tdone."

clean:
	@echo -n Cleaning build files: 
	@rm -f build/* 
	@echo "\t\tdone."

distclean: 
	@echo -n Cleaning build/ \& zcc_opt.def: 
	@rm -rf build/ zcc_opt.def
	@echo "\tdone."

.PHONY: build/$(PROJECT).lst
