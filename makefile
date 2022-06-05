COMPILER = g++
TARGET = rps

all: $(TARGET)

$(TARGET) : $(TARGET).cpp
	$(COMPILER) "$(TARGET).cpp" -o $(TARGET)

clean:
	$(RM) *.o *.d $(TARGET)

run:
	./$(TARGET)