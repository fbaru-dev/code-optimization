#
# Makefile for building the Vtune exercises
#
# Copyright (C) 2015, Leibniz Supercomputing Centre,
# Copyright (C) 2015, Vasileios Karakasis
# Copyright (C) 2016, Fabio Baruffa
# 
SUBDIRS = mandelbrot stream 

.PHONY: all clean $(SUBDIRS)
.DEFAULT: all

# Define common variables used by subdirectories
export CC = icc
export CPPFLAGS = -D_GNU_SOURCE
export CFLAGS = -g -Wall -O3 -std=c99 -xHost
export LD = icc
export MKDIR_P = mkdir -p
export RM = /bin/rm

all: $(SUBDIRS)

$(MAKECMDGOALS): $(SUBDIRS)

$(SUBDIRS):
	@echo Making target $(MAKECMDGOALS) in $@ ...
	@$(MAKE) --silent -C $@ $(MAKECMDGOALS)
