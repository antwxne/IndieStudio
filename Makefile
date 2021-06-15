##
## EPITECH PROJECT, 2020
## Indie Studio
## File description:
## Indie Studio Makefile
##

###							    ###
# This file is just a cli manager #
###								###

## Var definition ##
SHELL	=	/bin/sh
RM		=	rm -rf

## Output
BIN			=	bomberman
BUILD_DIR	=	build
DOC_DIR 	=	./Documentation

## Rules ##
.PHONY: all
all:
	./build.sh

# Clean build
.PHONY: clean
clean:
	$(RM) $(BUILD_DIR)

.PHONY: doc-clean
doc-clean:
	$(RM) -r $(DOC_DIR)/html/
	$(RM) -r $(DOC_DIR)/latex/
	$(RM) $(DOC_DIR)/refman.pdf

# Clean build and binaries
.PHONY: fclean
fclean: clean doc-clean
	$(RM) $(BIN)

.PHONY: re
re: fclean all

.PHONY: doc
doc:
	doxygen $(DOC_DIR)/Doxyfile

# Generate PDF documentation
.PHONY: doc_pdf
doc-pdf:	doc
	make -C $(DOC_DIR)/latex/
	cp $(DOC_DIR)/latex/refman.pdf $(DOC_DIR)

# Launch doxygen in firefox browser
.PHONY: doc-firefox
doc-firefox:	doc
	firefox $(DOC_DIR)/html/index.html
