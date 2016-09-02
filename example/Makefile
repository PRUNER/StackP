
include ./Makefile.config

noinst_PROGRAMS= $(mpi_main_PROGRAM)


mpi_main_PROGRAM = mpi-main
mpi_main_SOURCES = mpi-main.c 
mpi_main_OBJECTS = $(mpi_main_SOURCES:%.c=%.o)

lib_LIBRARIES =

#pmpi_1_a_LIBRARY = libpmpi.a
#pmpi_1_so_LIBRARY = libpmpi.so
pmpi_1_SOURCES = pmpi-1.c 
pmpi_1_OBJECTS = $(pmpi_1_SOURCES:%.c=%.o)
pmpi_1_STACKP_OBJECT = libpmpi-1.o	
pmpi_2_SOURCES = pmpi-2.c 
pmpi_2_OBJECTS = $(pmpi_2_SOURCES:%.c=%.o)
pmpi_2_STACKP_OBJECT = libpmpi-2.o
pmpi_3_SOURCES = pmpi-3.c 
pmpi_3_OBJECTS = $(pmpi_3_SOURCES:%.c=%.o)
pmpi_3_STACKP_OBJECT = libpmpi-3.o
pmpi_123_a_LIBRARY  = libpmpi123.a
pmpi_123_so_LIBRARY = $(pmpi_123_a_LIBRARY:%.a=%.so)
pmpi_123_o_LIBRARY  = $(pmpi_123_a_LIBRARY:%.a=%.o)
pmpi_12_a_LIBRARY  = libpmpi12.a
pmpi_12_so_LIBRARY = $(pmpi_12_a_LIBRARY:%.a=%.so)
pmpi_12_o_LIBRARY = $(pmpi_12_a_LIBRARY:%.a=%.o)
pmpi_13_a_LIBRARY  = libpmpi13.a
pmpi_13_so_LIBRARY = $(pmpi_13_a_LIBRARY:%.a=%.so)
pmpi_13_o_LIBRARY = $(pmpi_13_a_LIBRARY:%.a=%.o)
pmpi_23_a_LIBRARY  = libpmpi23.a
pmpi_23_so_LIBRARY = $(pmpi_23_a_LIBRARY:%.a=%.so)
pmpi_23_o_LIBRARY = $(pmpi_23_a_LIBRARY:%.a=%.o)


OBJECTS= \
	$(mpi_main_OBJECTS) \
	$(pmpi_1_OBJECTS) \
	$(pmpi_2_OBJECTS) \
	$(pmpi_3_OBJECTS) 

DEPENDENCIES= \
	$(mpi_main_OBJECTS:%.o=%.d) \
	$(pmpi_1_OBJECTS:%.o=%.d) \
	$(pmpi_2_OBJECTS:%.o=%.d) \
	$(pmpi_3_OBJECTS:%.o=%.d)

OTHERS = \
	$(pmpi_1_STACKP_OBJECT) \
	$(pmpi_2_STACKP_OBJECT) \
	$(pmpi_3_STACKP_OBJECT) \
	$(pmpi_123_a_LIBRARY) \
	$(pmpi_123_so_LIBRARY) \
	$(pmpi_123_o_LIBRARY) \
	$(pmpi_12_a_LIBRARY) \
	$(pmpi_12_so_LIBRARY) \
	$(pmpi_12_o_LIBRARY) \
	$(pmpi_13_a_LIBRARY) \
	$(pmpi_13_so_LIBRARY) \
	$(pmpi_13_o_LIBRARY) \
	$(pmpi_23_a_LIBRARY) \
	$(pmpi_23_so_LIBRARY) \
	$(pmpi_23_o_LIBRARY) 

STACKP=../stack_pmpi

#$@: target name
#$<: first dependent file
#$^: all indemendent files

-include $(DEPENDENCIES)

all: $(noinst_PROGRAMS) a_LIBRARY so_LIBRARY

$(pmpi_1_STACKP_OBJECT): $(pmpi_1_OBJECTS)
	ld -o $@ -r $^

$(pmpi_2_STACKP_OBJECT): $(pmpi_2_OBJECTS)
	ld -o $@ -r $^

$(pmpi_3_STACKP_OBJECT): $(pmpi_3_OBJECTS)
	ld -o $@ -r $^

a_LIBRARY: $(pmpi_1_STACKP_OBJECT) $(pmpi_2_STACKP_OBJECT) $(pmpi_3_STACKP_OBJECT)
	$(STACKP) $(pmpi_123_o_LIBRARY) $(pmpi_1_STACKP_OBJECT) $(pmpi_2_STACKP_OBJECT) $(pmpi_3_STACKP_OBJECT)
	$(STACKP) $(pmpi_12_o_LIBRARY) $(pmpi_1_STACKP_OBJECT) $(pmpi_2_STACKP_OBJECT)
	$(STACKP) $(pmpi_13_o_LIBRARY) $(pmpi_1_STACKP_OBJECT) $(pmpi_3_STACKP_OBJECT)
	$(STACKP) $(pmpi_23_o_LIBRARY) $(pmpi_2_STACKP_OBJECT) $(pmpi_3_STACKP_OBJECT)
	ar cr $(pmpi_123_a_LIBRARY) $(pmpi_123_o_LIBRARY)
	ranlib $(pmpi_123_a_LIBRARY)
	ar cr $(pmpi_12_a_LIBRARY) $(pmpi_12_o_LIBRARY)
	ranlib $(pmpi_12_a_LIBRARY)
	ar cr $(pmpi_13_a_LIBRARY) $(pmpi_13_o_LIBRARY)
	ranlib $(pmpi_13_a_LIBRARY)
	ar cr $(pmpi_23_a_LIBRARY) $(pmpi_23_o_LIBRARY)
	ranlib $(pmpi_23_a_LIBRARY)

so_LIBRARY: a_LIBRARY
	$(CC) $(LDFLAGS) $(LDLIBS) -g -shared -o $(pmpi_123_so_LIBRARY) $(pmpi_123_o_LIBRARY)
	$(CC) $(LDFLAGS) $(LDLIBS) -g -shared -o $(pmpi_12_so_LIBRARY) $(pmpi_12_o_LIBRARY)
	$(CC) $(LDFLAGS) $(LDLIBS) -g -shared -o $(pmpi_13_so_LIBRARY) $(pmpi_13_o_LIBRARY)
	$(CC) $(LDFLAGS) $(LDLIBS) -g -shared -o $(pmpi_23_so_LIBRARY) $(pmpi_23_o_LIBRARY)



$(mpi_main_PROGRAM): $(mpi_main_OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

.SUFFIXES: .c .o
.c.o: 
	$(CC) $(CFLAGS) $(LDFLAGS) -MMD -MP -c $< -o $@

.SUFFIXES: .cpp .o
.cpp.o: 
	$(CC) $(CXXFLAGS) $(LDFLAGS) -MMD -MP -c $< -o $@


.PHONY: clean 
clean:
	-rm -f $(noinst_PROGRAMS) $(OBJECTS) $(DEPENDENCIES) $(OTHERS)

.PHONY: clean_core
cleanc:
	-rm -f *.core
	-rm -f *.btr




