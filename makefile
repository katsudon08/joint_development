CC = gcc
PGNAME = exe
OBJS =  main.o sort_menu.o input.o search.o country_sort.o medallist.o data_access.o data_structure.o

$(PGNAME):$(OBJS)
	$(CC) -o $@ $^ -g
.c.o:
	$(CC) -c -o $@ $<

clean:
	rm -f $(PGNAME) $(OBJS)