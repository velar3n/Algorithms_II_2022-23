CC = g++

CFLAGS = -Wall -std=c++11

OBJECTS = setArr.o main.o

HFILES = setArr.h

TARGET = main.out

%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core