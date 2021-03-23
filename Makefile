TagDriver.exe: TagStruct.o TagDriver.o
	g++ TagStruct.o TagDriver.o -o TagDriver.exe -std=c++2a
TagStruct.o: TagStruct.cpp
	g++ -c TagStruct.cpp -o TagStruct.o -std=c++2a
TagDriver.o: TagDriver.cpp
	g++ -c TagDriver.cpp -o TagDriver.o -std=c++2a
clean:
	rm *.o TagDriver.exe
run: TagDriver.exe
	chmod 700 TagDriver.exe
	./TagDriver.exe

