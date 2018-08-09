CXX=clang++
CXXFLAGS=-std=c++11

all: 657

make-bin:
	mkdir -p ./bin

657: 657-JudgeRouteCircle.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

709: 709-ToLowerCase.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

771: 771-JewelsAndStones.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

804: 804-UniqueMorseCodeWords.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

clean:
	rm -rf ./bin