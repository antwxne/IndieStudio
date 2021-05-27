##
## EPITECH PROJECT, 2020
## Arcade
## File description:
## Arcade Makefile
##

###							    ###
# This file is just a cli manager #
###								###

## Var definition ##
SHELL	=	/bin/sh
RM		=	rm -rf

## Output
BIN			=	indie
BUILD_DIR	=	build

## Rules ##
.PHONY: all
all:
	./build.sh

#
.PHONY: clean
clean:
	@$(RM) $(BUILD_DIR)

# Clean build and binaries
.PHONY: fclean
fclean: clean
	@$(RM) $(BIN)
	# @$(RM) doc/html/
	# @$(RM) doc/latex/

# Generate documentation
# .PHONY: doc
# doc:
# 	doxygen doxygen.conf

# Launch doxygen in google-chrome browser
# .PHONY: doc-chrome
# doc-chrome:
# 	doxygen doxygen.conf
# 	google-chrome ./doc/html/index.html

# Launch doxygen in firefox browser
# .PHONY: doc-firefox
# doc-firefox:
# 	doxygen doxygen.conf
	# firefox ./doc/html/index.html

.PHONY: re
re: fclean all clean