CXX			= c++
NAME		= PmergeMe
RM			= rm -rf

CXXFLAGS	= -Wall -Wextra -Werror -MD -MP -std=c++98

SRCS	= main.cpp PmergeMe.cpp

OBJS_DIR	= objs
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

all		: $(NAME)

run		: re
		@clear
		@./${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

test	: re
		@clear
		@valgrind -s ./${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

3000	: re
		@clear
		@./${NAME} `shuf -i 1-1000000 -n 3000 | tr "\n" " "`
		@$(RM) $(OBJS_DIR) $(NAME)

10000	: re
		@clear
		@./${NAME} `shuf -i 1-1000000 -n 10000 | tr "\n" " "`
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

.PHONY: all clean fclean re run test 3000 10000
