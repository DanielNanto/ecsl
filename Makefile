CC  = gcc
CXX = g++
LD  = g++
TARGET = ecsl

SOURCES = \
	ecsl_file.c \
	ecsl_str.c \
	src/main.c

BUILDIR = build
OBJECTS += $(addprefix $(BUILDIR)/,$(addsuffix .o,$(basename $(SOURCES))))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo " LD " $@
	@$(LD) -o $(TARGET) $(OBJECTS) 

$(BUILDIR)/%.o: %.c
	@echo " CC " $<
	@mkdir -p $(dir $@)
	@$(CC) -o $@ -c $< 

$(BUILDIR)/%.o: %.cpp
	@echo " CC " $@
	@mkdir -p $(dir $@)
	@$(CXX) -o $@ -c $< 

-include $(OBJECTS:.o=.d)

clean:
	rm -f $(OBJECTS) $(OBJECTS:.o=.d) $(TARGET) $(TARGET).exe
	rm -rf build

.PHONY: all clean
