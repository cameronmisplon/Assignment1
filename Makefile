CC=g++
FLAGS=-std=c++2a
TARGET=TagStructDriver.exe

$(TARGET): TagStruct.o TagStructDriver.o
	$(CC) TagStruct.o TagStructDriver.o -o $(TARGET) $(FLAGS)
TagStruct.o: TagStruct.cpp
	$(CC) -c TagStruct.cpp -o TagStruct.o $(FLAGS)
TagStructDriver.o: TagStructDriver.cpp
	$(CC) -c TagStructDriver.cpp -o $(TARGET) $(FLAGS)
clean:
	rm *.o $(TARGET)
run: $(TARGET)
	chmod 700 $(TARGET)
	./$(TARGET)

