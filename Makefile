secret: main.cpp circular_list.cpp circular_list.h
	g++ -g main.cpp circular_list.cpp -o secret

clean:
	rm secret