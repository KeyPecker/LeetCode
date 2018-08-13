CXX=clang++
CXXFLAGS=-std=c++11

all: 657 709 771 804 461 617 728

make-bin:
	mkdir -p ./bin

461: 461-HammingDistance.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

617: 617-MergeTwoBinaryTrees.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

657: 657-JudgeRouteCircle.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

709: 709-ToLowerCase.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

728: 728-SelfDividingNumbers.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

771: 771-JewelsAndStones.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

804: 804-UniqueMorseCodeWords.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@

852: 852-PeakIndexInAMountainArray.cpp
	mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $^ -o ./bin/$@
clean:
	rm -rf ./bin