CXX			= c++
NAME		= inheritance
RM			= rm -rf

CXXFLAGS	= -Wall -Wextra -Werror -MD -MP -std=c++98

SRCS	= utils.cpp A.cpp B.cpp C.cpp Base.cpp main.cpp

OBJS_DIR	= objs
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

all		: $(NAME)

run		: re
		@clear; echo "\nLogs:\n"
		@./${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

test	: re
		@clear; echo "\nLogs:\n"
		@valgrind -s ./${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

$(NAME)	: $(OBJS)
		$(CXX) -o $@ $^

objs/%.o: %.cpp
		@mkdir -p $(dir $@)
		${CXX} ${CXXFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJS_DIR)

fclean	:
		$(RM) $(OBJS_DIR) $(NAME)

re		: fclean all

-include $(DEPS)

.PHONY: all clean fclean re run test
