CMP = g++
MAIN = project
CLASS = bird
CLASS1 = pipe
EXEC = run

$(EXEC): $(MAIN).o $(CLASS).o $(CLASS1).o
	$(CMP) $(MAIN).o $(CLASS).o $(CLASS1).o gfx.o -L/opt/X11/lib/ -o $(EXEC) -std=c++11

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).h $(CLASS).cpp
	$(CMP) -c $(CLASS).cpp

$(CLASS1).o: $(CLASS1).h $(CLASS1).cpp
	$(CMP) -c $(CLASS1).cpp
