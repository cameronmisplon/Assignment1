TagStructDriver.exe: TagStruct.o TagStructDriver.o
	g++ TagStruct.o TagStructDriver.o -o TagStructDriver.exe -std=c++2a
TagStruct.o: TagStruct.cpp
	g++ -c TagStruct.cpp -o TagStruct.o -std=c++2a
TagStructDriver.o: TagStructDriver.cpp
	g++ -c TagStructDriver.cpp -o TagStructDriver.o -std=c++2a
clean:
	rm *.o TagStructDriver.exe
run: TagStructDriver.exe
	chmod 700 TagStructDriver.exe
	./TagStructDriver.exe

