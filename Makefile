all: mdat1 mdat2

OBJS = main.o
INSTR_OBJS = sections1.o sections2.o
MDAT_OBJS = $(INSTR_OBJS:.o=.mdat.o)
MDAT_SRC = $(INSTR_OBJS:.o=.mdat.c)
MDAT_PP = $(INSTR_OBJS:.o=.i)

MDAT_DIR = .
SUDS_DIR = .

LIBS = -L$(MDAT_DIR) -lmdat -lpthread
INCLUDE = -I. -I$(MDAT_DIR)

CPP = gcc -E
CPPFLAGS =
CC = gcc
CFLAGS = -O0 -Wall -g
CXX = g++
CXXFLAGS = -O0 -Wall -g
LD = g++
LDFLAGS =

mdat1: $(OBJS) sections1.mdat.o checker1.o think_eat.o
	$(LD) $(LDFLAGS) -o $@ $(OBJS) sections1.mdat.o checker1.o think_eat.o $(LIBS)

mdat2: $(OBJS) sections2.mdat.o checker2.o think_eat.o
	$(LD) $(LDFLAGS) -o $@ $(OBJS) sections2.mdat.o checker2.o think_eat.o $(LIBS)

$(OBJS): %.o : %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

$(MDAT_OBJS): %.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(MDAT_SRC): %.mdat.c : %.i
	$(SUDS_DIR)/suds -use_func_list suds_file_list.txt -suffix mdat $<

$(MDAT_PP): %.i : %.c $(HDRS)
	$(CPP) $(CPPFLAGS) $< > $@ $(INCLUDE)

checker1.o: checker.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

checker2.o: checker.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -DCHECK_LIMIT -c $< -o $@ $(INCLUDE)

.DELETE_ON_ERROR: $(MDAT_SRC)

clean: 
	rm -f mdat1 mdat2
	rm -f $(OBJS) $(MDAT_OBJS) checker1.o checker2.o think_eat.o *.o
	rm -f $(MDAT_SRC) $(MDAT_PP)
