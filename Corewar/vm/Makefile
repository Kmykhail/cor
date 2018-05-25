NAME = ../corewar

# project directories

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

# project source files

SRC =	main.c 					\
		make_cycle.c			\
		init_vizual.c			\
		print_all.c				\
		read_bots.c				\
		free_struct.c			\
		visual.c 				\
		visual_fill_bar.c		\
		visual_fill_charts.c	\
		visual_fill_map.c		\
		visual_window.c			\
		fun_add.c				\
		fun_live.c				\
		fun_sti.c				\
		fun_sti_f.c				\
		fun_sti_s.c				\
		fun_aff.c				\
		fun_lld.c				\
		fun_sub.c				\
		fun_and.c				\
		fun_and_f.c				\
		fun_and_s.c				\
		fun_lldi.c				\
		fun_lldi_f.c			\
		fun_xor.c				\
		fun_xor_f.c				\
		fun_xor_s.c				\
		fun_or.c				\
		fun_or_f.c				\
		fun_or_s.c				\
		fun_fork.c				\
		fun_zjmp.c				\
		fun_ld.c				\
		fun_ldi.c				\
		fun_ldi_f.c				\
		fun_st.c				\
		fun_lfork.c				\
		table_label.c			\
		implement_command.c		\
		process_current.c		\
		unvalid.c				\


OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT = $(LIB_DIR)libft.a
LIBFT_INC := $(LIB_DIR)inc/

# compilation flags

FLAGS := -Wall -Werror -Wextra

# header flags

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lncurses

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		@ gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		@ make -C $(LIB_DIR)

clean:
		@ rm -f $(OBJ)
		@ make clean -C $(LIB_DIR)

fclean: clean
		@ rm -f $(NAME)
		@ make fclean -C $(LIB_DIR)
		@ rm -rf $(OBJ_DIR)

re: fclean all

# special stuff

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
