IDIR = include
ODIR = obj
SDIR = src
BDIR = bin

CC = gcc
CFLAGS = -g -Wall -std=c99 -I $(IDIR)
LFLAGS = -lm

_PROG = sac_a_dos
PROG = $(patsubst %,$(BDIR)/%,$(_PROG))

_DEP = global.h objects.h rec.h dp_rec.h array.h dp_array.h lst.h lst_elm.h
DEP = $(patsubst %,$(IDIR)/%,$(_DEP))

_OBJ = main.o objects.o rec.o dp_rec.o array.o dp_array.o lst.o lst_elm.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: run dirs clean delete

run : $(PROG)
	./$(PROG)

dirs:
	@mkdir -p $(BDIR)
	@mkdir -p $(ODIR)


$(PROG): $(OBJ)
	$(CC) $(LFLAGS) -o $@ $^


$(ODIR)/%.o: $(SDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) -c -o $@ $<


clean :
	rm -rf $(ODIR)/*.o

delete : clean
	rm -rf $(BDIR)/*.bin
	rm -f $(PROG)