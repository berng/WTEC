CC = gcc 
CFLAGS = # -DWINDOWS
LDFLAGS = -lm
all: GetWTEC

GetWTEC: GetWTEC.cpp
	$(CC) GetWTEC.cpp -o GetWTEC $(CFLAGS) $(LDFLAGS)
clean:
	rm -f GetWTEC
