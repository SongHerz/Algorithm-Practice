CXX=g++ -g

all: fig_2_4 2_3_1 test_binary_search

fig_2_4: fig_2_4.cc merge_sort.cc merge_sort.hh
	$(CXX) $^ -o $@

2_3_1: 2_3_1.cc merge_sort.cc merge_sort.hh
	$(CXX) $^ -o $@

test_binary_search: test_binary_search.cc binary_search.cc binary_search.hh
	$(CXX) $^ -o $@
