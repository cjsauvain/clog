NAME = libclog.so

# Directories
INSTALL_PATH = /opt/customlibs
SRCS_DIR = srcs
INC_DIR = inc
OBJS_DIR = obj

# Sources / Header
SRC = 	logInternal.c	\
		logs.c			\
		setLogLevel.c	\
		logFile.c		\

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))

HEADER = $(INC_DIR)/clog.h

# Objects
OBJS = $(subst $(SRCS_DIR)/,,$(SRCS:%.c=$(OBJS_DIR)/%.o))

# Compilation
CC = clang
CFLAGS = -Wall -Wextra -Werror -g -fPIC
SHARED_LIB = -fPIC -shared
INCLUDE = -I $(INC_DIR)

# Rules
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(OBJS) $(SHARED_LIB) -o $(NAME)

install:
	@echo "Installing header to /usr/local/include/..."
	@sudo cp $(HEADER) /usr/local/include/
	@echo "Ensuring install path exists at $(INSTALL_PATH)/..."
	@sudo mkdir -p $(INSTALL_PATH)
	@echo "Copying shared library ($(NAME)) into $(INSTALL_PATH)/..."
	@sudo cp $(NAME) $(INSTALL_PATH)
	@echo "Creating symbolic link /usr/local/lib/$(NAME) -> $(INSTALL_PATH)/$(NAME)..."
	@sudo ln -sf $(INSTALL_PATH)/$(NAME) /usr/local/lib/$(NAME)
	@echo "Updating dynamic linker cache..."
	@sudo ldconfig
	@echo "✅ Installation complete! You can now use clog with -lclog"

uninstall:
	@echo "Removing header from /usr/local/include/..."
	@sudo rm -f /usr/local/include/$(HEADER)
	@echo "Removing shared library from $(INSTALL_PATH)/..."
	@sudo rm -f $(INSTALL_PATH)/$(NAME)
	@echo "Removing symlink from /usr/local/lib/$(NAME)..."
	@sudo rm -f /usr/local/lib/$(NAME)
	@echo "Updating dynamic linker cache..."
	@sudo ldconfig
	@echo "✅ Uninstall complete!"

help:
	@echo "Available targets:"
	@echo "  make            → Compile the shared library"
	@echo "  make install    → Install the header and .so system-wide"
	@#echo "                      ▸ Optionnal: CACHE=true|false (default: false)"
	@#echo "                        - CACHE=true  ->  Registers the lib in ld cache"
	@#echo "                        - CACHE=false ->  You must manually use -L"
	@#echo "                                          and set LD_LIBRARY_PATH to link"
	@echo "  make uninstall  → Remove all installed files"
	@echo "  make clean      → Remove object files"
	@echo "  make fclean     → Remove all built files"
	@echo "  make re         → Clean and rebuild"

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all install uninstall help clean fclean re
