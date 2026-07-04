# Настройки компиляции
CXX = g++
CXXFLAGS = -std=c++20 -Os -Wall -Wextra -static -s -fno-exceptions -fno-rtti
TARGET = init
SRC = src/freenit.cpp

# Пути установки
INSTALL_DIR = /sbin

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Команда для установки в системную папку
install: $(TARGET)
	@echo "Установка в $(INSTALL_DIR)..."
	sudo cp $(TARGET) $(INSTALL_DIR)/init
	sudo chmod +x $(INSTALL_DIR)/init
	@echo "Успешно установлено!"

# Команда для удаления (если нужно почистить систему)
uninstall:
	sudo rm -f $(INSTALL_DIR)/init
	@echo "Удалено из $(INSTALL_DIR)."

clean:
	rm -f $(TARGET)

.PHONY: all install uninstall clean
