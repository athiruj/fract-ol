CC				= 		cc
CCFLAGS			=	 	
# -Wall -Wextra -Werror
AR				=		ar -rsc
RM				=		rm -rf

NAME			=		fractol

# ==== Directories ========================================

OBJS_DIR		=		objs/
OBJS_DIRS		=		$(OBJS_DIR) $(GNL_OBJ_DIR) $(ALL_OBJ_DIR)

# ==== Submodule ==========================================

SUBMD_DIR		=		submodule/

SUBMD			=		$(LIBFT) $(GNL) $(MLX) 

# ---- Submodule Libft ------------------------------------

LIBFT			=		$(LIB_DIR)libft.a

LIB_DIR			=		$(SUBMD_DIR)libft/

# ---- Submodule GNL --------------------------------------

GNL_DIR			=		$(SUBMD_DIR)get_next_line/
GNL				=		$(GNL_DIR)get_next_line.a
GNL_OBJ_DIR		=		$(OBJS_DIR)$(GNL_DIR)

GNL_HEADER		=		get_next_line.h
GNL_DIR_HEADER	=		$(GNL_DIR)$(GNL_HEADER)

GNL_FILES		=		get_next_line.c \
						get_next_line_utils.c

GNL_DIR_FILES	=		$(addprefix $(GNL_DIR), $(GNL_FILES))
GNL_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(GNL_DIR_FILES:.c=.o))

# ---- Submodule GNL --------------------------------------

MLX				=		$(MLX_DIR)build/libmlx42.a

MLX_FLAGS		= 		-ldl -lglfw3 -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

MLX_DIR			=		$(SUBMD_DIR)MLX42/

MLX_HEADER		=		$(MLX_DIR)include

# ==== Header =============================================

HEADER_DIR		=	 	include/

# ==== Source ==============================================

SRC_DIR			=		src/
SRC_OBJ_DIR		=		$(OBJS_DIR)$(SRC_DIR)

SRC_FILE		=		fract_ol.c

SRC_DIR_FILES	=		$(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(SRC_DIR_FILES:.c=.o))

# ---- Source Initial -------------------------------------

INIT_DIR		=		$(SRC_DIR)initialize/
INIT_OBJ_DIR	=		$(OBJS_DIR)$(INIT_DIR)

INIT_FILES		=		initialize_fract_ol.c \
						initialize_fractal.c \
						initialize_move.c

INIT_DIR_FILES	=		$(addprefix $(INIT_DIR), $(INIT_FILES))
INIT_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(INIT_DIR_FILES:.c=.o))

# ---- Source hook -------------------------------------

HOOK_DIR		=		$(SRC_DIR)hook/
HOOK_OBJ_DIR	=		$(OBJS_DIR)$(HOOK_DIR)

HOOK_FILES		=		hook.c \
						hook_key.c \
						hook_mouse.c \
						hook_cursor.c \
						hook_resize.c \
						hook_scroll.c

HOOK_DIR_FILES	=		$(addprefix $(HOOK_DIR), $(HOOK_FILES))
HOOK_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(HOOK_DIR_FILES:.c=.o))

# ---- Source fractal ------------------------------------

FRAC_DIR		=		$(SRC_DIR)fractal/
FRAC_OBJ_DIR	=		$(OBJS_DIR)$(FRAC_DIR)

FRAC_FILES		=		mandelbrot.c \
						julia.c

FRAC_DIR_FILES	=		$(addprefix $(FRAC_DIR), $(FRAC_FILES))
FRAC_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(FRAC_DIR_FILES:.c=.o))

# ==== ALL ===============================================

ALL_OBJ_DIR		=		$(SRC_OBJ_DIR) \
						$(INIT_OBJ_DIR) \
						$(HOOK_OBJ_DIR) \
						$(FRAC_OBJ_DIR)

ALL_OBJS		=		$(SRC_OBJ_FILES) \
						$(INIT_OBJ_FILES) \
						$(HOOK_OBJ_FILES) \
						$(FRAC_OBJ_FILES)

all: $(NAME)

$(NAME): $(OBJS_DIRS) $(SUBMD) $(ALL_OBJS) Makefile
	$(CC) $(CCFLAGS) $(ALL_OBJS) $(LIBFT) $(GNL) $(MLX) $(MLX_FLAGS) -I $(HEADER_DIR) -I $(MLX_HEADER) -o $@

$(OBJS_DIRS):
	@mkdir -p $@

$(LIBFT): $(LIB_DIR)
	@make --no-print-directory -C $(LIB_DIR)

$(GNL): $(GNL_OBJ_FILES)
	$(AR) $@ $?

$(GNL_OBJ_DIR)%.o: $(GNL_DIR)%.c $(GNL_DIR_HEADER)
	$(CC) $(CCFLAGS) -I $(GNL_DIR_HEADER) -c $< -o $@

$(MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(SRC_OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) -c $< -o $@

bonus: all

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(MLX_DIR)/build
	$(RM) $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(GNL)
	$(RM) $(NAME)
	

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT: $(NAME) $(ALL_OBJS) $(GNL) $(GNL_OBJ_FILES)