CXX=g++ -g

all: fig_2_4 2_3_1 test_binary_search 2_3_7

fig_2_4: fig_2_4.cc merge_sort.cc merge_sort.hh
	$(CXX) $^ -o $@

2_3_1: 2_3_1.cc merge_sort.cc merge_sort.hh
	$(CXX) $^ -o $@

test_binary_search: test_binary_search.cc binary_search.cc binary_search.hh
	$(CXX) $^ -o $@


2_3_7: 2_3_7.cc merge_sort.cc binary_search.cc
	$(CXX) $^ -o $@
