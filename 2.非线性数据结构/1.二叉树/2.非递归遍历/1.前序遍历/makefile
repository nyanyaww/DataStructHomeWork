CC = gcc

all1:compile run clean
    
all2:compile1 run1

compile:
	$(CC) main.c -o main

compile1:
	$(CC) main_version1.c -o main_v1
run1:
	./main_v1

run:
	./main
clean:
	rm main

.PHONY:all compile run clean