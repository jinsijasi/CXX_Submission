

compiler = g++
NAME	=	sh_ob

All	: shape_main.o shape.so	
	$(compiler)	shape_main.o	-L. -lShape -o $(NAME)

main.o	: shape_main.cpp
	$(compiler) -c shape_main.cpp -o shape_main.o

shape.so	: shape.cpp
	$(compiler)	--shared -fPIC shape.cpp	-o libShape.so




