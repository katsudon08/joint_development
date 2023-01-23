CC = gcc
PGNAME = exe
OBJS =  data_access.c data_structure.c input.c main.c medallist.c search.c #country_sort.o medallist.o

$(PGNAME):$(OBJS)
	$(CC) -o $@ $^ -g
.c.o:
	$(CC) -c -o $@ $<

data_access.o:DATA.h
input.o search.o medallist.o:DAO.h
main.o:PROGRAM_JOINT.h

clean:
	rm -f $(PGNAME) $(OBJS)