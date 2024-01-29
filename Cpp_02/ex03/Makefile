CXX			= c++
NAME		= bsp
RM			= rm -rf

CXXFLAGS	= -Wall -Wextra -Werror -MD -MP -std=c++98

SRCS	= Fixed.cpp main.cpp Point.cpp bsp.cpp

OBJS_DIR	= objs
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

all		: $(NAME)

$(NAME)	: ${OBJS}
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

.PHONY: all clean fclean re
