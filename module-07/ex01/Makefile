define HEADER

                                ..                                
                              ...                                 
                      ..........................                  
                   ................................               
                     .................................            
                   .....................................          
                  ........................................        
                .............................................     
               ................................................   
              ...............................................     
              ................................................    
              ................................................    
              .................................................   
              ....................................-............   
              ...................--...............+#...........   
              ...................##...............###...........  
             ...................+###.............+###+..........  
                ...............+#####...........-+####-....... .. 
                 ..+##........+##+++--...............-#.......    
                  .####......+#-....--#-......+-.....+#-......    
 ...---           .+####+.....#-.......#+..#.##-++-+-###.....     
 .++++-..+-.........+######...##-+++++-#########..-+####.. .      
 -+++++++..............-++####+#########################-                           _
.+++++++.....................-##############+####+-..-+++-                         | |            __
.++++++-.........................-++#########+-+-++++++++.        _______ __ __  __| | ____      |__| ____   ______
.++++++-...............................++.....-+++++++++-         \_  __ \  |  \/ __ |/ __ \_____|  |/ __ \ /  ___/ 
 .+++++-......................................++++++++++.          |  | \/  |  / /_/ \  ___/_____/  \  ___/ \___ \  
    .-++.....................................++++++++++.           |__|  |____/\____ |\___  >/\__|  |\___  >____  > 
         ..................................#-+++++++++-                             \/    \/ \______|    \/     \/          

=======================================================================================================================
endef
export HEADER

define APP_HEADER

                            __ __ __                                                           __         __        
.----.-----.--------.-----.|__|  |__|.-----.-----.    .----.-----.-----.    .--------.-----.--|  |.--.--.|  |.-----.
|  __|  _  |        |  _  ||  |  |  ||     |  _  |    |  __|  _  |  _  |    |        |  _  |  _  ||  |  ||  ||  -__|
|____|_____|__|__|__|   __||__|__|__||__|__|___  |    |____|   __|   __|    |__|__|__|_____|_____||_____||__||_____|
                    |__|                   |_____|         |__|  |__|                                               

endef
export APP_HEADER

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main \

SRC +=	\


CPPFILES = $(SRC:%=%.cpp)

NAME =	iter

all: $(NAME)

debug: fclean $(CPPFILES)
		@echo "$$APP_HEADER"
		@printf "\t🤖 Compiling $(NAME)...\r"
		@$(CC) -g $(CPPFILES) $(CFLAGS) -o $(NAME)
		@printf "\33[2K"
		@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is compiled ✅"
		@echo "\nThe programm was compiled with debug sanitizer set to address\nDo not forget to use \"leak -atExit -- $(NAME)\" in order to check for potential leaks.\nNote that it won't work with the debug version.\n\nFor better debug, you can use \"lldb $(name) <args>\" after using debug rule.\n\n"

clean:

fclean: clean
		@rm -f $(NAME)
		@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is fully deleted 🗑️"

re: fclean
		@$(MAKE) all --no-print-directory

help:
		@echo "$$HEADER"
		@echo "all							  -	   Build $(NAME)"
		@echo "clean							-	   Clean temporary files"
		@echo "fclean						   -	   Clean the whole build"
		@echo "debug							-	   Runs the program with g3 fsanitize=address"
		@echo "$(NAME)				  -	   Build the $(NAME) with necessary libs"

$(CPPFILES): header

%.o: %.c
		@printf "\t🤖 Compiling $<...\r"
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "\33[2K"

$(NAME): $(CPPFILES) $(BETTERFT_LIB)
		@echo "$$APP_HEADER"
		@printf "\t🤖 Compiling $(NAME)...\r"
		@$(CC) $(CPPFILES) $(CFLAGS) -o $(NAME)
		@printf "\33[2K"
		@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is compiled ✅\n"

header:
		@echo "$$HEADER"

.PHONY = all clean fclean re header help