TARGET = push_swap
TARGET_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_DIR = ./common/
MANDATORY_DIR = ./mandatory/
BONUS_DIR = ./bonus/

RM = rm -rf

INCLUDES = -I$(COMMON_DIR) -I$(MANDATORY_DIR) -I$(BONUS_DIR)

SOURCE = common/clear_functions.c common/indexing.c common/list_management.c \
		common/split_and_convert.c common/str_helpers.c common/Validator_Utils.c \
		mandatory/butterfly.c mandatory/push_swap.c mandatory/stack_operations.c \
		mandatory/stack_sorting.c

OBJ = $(SOURCE:.c=.o)

SOURCE_BONUS = common/clear_functions.c common/indexing.c common/list_management.c \
			   common/split_and_convert.c common/str_helpers.c common/Validator_Utils.c \
			   bonus/get_next_line.c bonus/get_next_line_utils.c bonus/stack_operations.c \
			   bonus/checker.c

BONUS_OBJ = $(SOURCE_BONUS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(TARGET)

bonus: $(TARGET_BONUS)

$(TARGET_BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ) -o $(TARGET_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(TARGET) $(TARGET_BONUS)

re: fclean all

.PHONY: all re clean fclean bonus
