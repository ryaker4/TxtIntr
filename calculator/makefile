# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
LDFLAGS = -lboost_program_options

# Имя исполняемого файла
TARGET = calculator

# Исходные файлы
SOURCES = calculator.cpp

# Объектные файлы
OBJECTS = $(SOURCES:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Компиляция исходных файлов в объектные
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJECTS) $(TARGET)

# Пересборка
rebuild: clean all

# Установка (опционально)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Тестовые запуски
test: $(TARGET)
	@echo "Тест 1: 8 операндов (оба значения по умолчанию)"
	./$(TARGET) --operands 1 2 3 4 5 6 7 8
	@echo
	@echo "Тест 2: 9 операндов (только среднее)"
	./$(TARGET) --operation mean --operands 10 20 30 40 50 60 70 80 90
	@echo
	@echo "Тест 3: 10 операндов (только медиана)"
	./$(TARGET) -o median --operands 5.5 6.6 7.7 8.8 9.9 10.1 11.2 12.3 13.4 14.5
	@echo
	@echo "Тест 4: 8 операндов (явное указание both)"
	./$(TARGET) --operation both --operands 1 3 5 7 9 11 13 15
	@echo
	@echo "Тест 5: Вызов справки"
	./$(TARGET) --help

# Отладочная сборка
debug: CXXFLAGS += -g -DDEBUG
debug: rebuild

.PHONY: all clean rebuild install test debug
