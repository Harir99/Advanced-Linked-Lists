all: a4q1a_int a4q1a_char a4q2 a4q1b a4q3

a4q1a_int: a4q1a_int.o create_list.o  remove_smallest_key.o rmSortedNode.o push.o remove_largest_key.o size.o append.o remove_first.o remove_last.o  empty_list.o destroy_list.o free_list.o print_list_all.o print_list_sort.o rmX_nNodeFromList.o
	gcc -Wall -std=c11  -DINT -o a4q1a_int  a4q1a_int.o create_list.o remove_smallest_key.o rmSortedNode.o push.o remove_largest_key.o size.o append.o remove_first.o remove_last.o empty_list.o destroy_list.o free_list.o print_list_all.o print_list_sort.o rmX_nNodeFromList.o

a4q1a_char: a4q1a_char.o create_list.o  remove_smallest_key_char.o rmSortedNodeChar.o push_char.o remove_largest_key_char.o size.o append_char.o remove_first_char.o remove_last_char.o  empty_list.o destroy_list.o free_list.o print_list_char.o print_list_sorted_char.o   rmX_nNodeFromListChar.o
	gcc -Wall -std=c11 -o a4q1a_char  a4q1a_char.o create_list.o remove_smallest_key_char.o rmSortedNodeChar.o push_char.o remove_largest_key_char.o size.o append_char.o remove_first_char.o remove_last_char.o empty_list.o destroy_list.o free_list.o print_list_char.o print_list_sorted_char.o rmX_nNodeFromListChar.o

a4q1b: a4q1b.o print_array.o diffC.o create_list.o  remove_smallest_key.o rmSortedNode.o push.o remove_largest_key.o size.o append.o remove_first.o remove_last.o  empty_list.o destroy_list.o free_list.o print_list_all.o print_list_sort.o rmX_nNodeFromList.o map.o map_reduce.o map_2_array.o map_2_reduce.o reduce.o sum.o  sum_of_sq_diff.o add.o  diff.o square.o  mult.o
	gcc -Wall -std=c11 -DINT -o a4q1b a4q1b.o print_array.o diffC.o create_list.o remove_smallest_key.o rmSortedNode.o push.o remove_largest_key.o size.o append.o remove_first.o remove_last.o  empty_list.o destroy_list.o free_list.o print_list_all.o print_list_sort.o rmX_nNodeFromList.o map.o map_reduce.o map_2_array.o map_2_reduce.o reduce.o sum.o  sum_of_sq_diff.o add.o diff.o square.o  mult.o

a4q2: a4q2.o push.o append.o gcd_xy.o size.o create_list.o empty_list.o print_list_all.o print_list_sort.o  nth.o nth_node.o remove_nth.o rmX_nNodeFromList.o rmSortedNode.o count_up.o count_down.o findNthSortList.o findNthInsList.o destroy_list.o
	gcc -Wall -std=c11 -DINT -o a4q2 a4q2.o  push.o append.o gcd_xy.o size.o create_list.o empty_list.o print_list_all.o print_list_sort.o nth.o nth_node.o remove_nth.o rmX_nNodeFromList.o rmSortedNode.o count_up.o count_down.o findNthSortList.o findNthInsList.o destroy_list.o

a4q3: a4q3.o print_list_sort_fract.o print_list_all_fract.o create_fract.o gcd.o push_fract.o append_fract.o empty_fract.o destroy_fract.o fraction.o print_fract.o simplifyFractGCD.o add_fract.o mult_fract.o sub_fract.o div_fract.o rand_fract.o rfract.o sortFractArray.o filter.o rmX_nNodeFromFract.o rmSortedFract.o
	gcc -Wall -std=c11 -DFRACT -o a4q3 a4q3.o print_list_sort_fract.o print_list_all_fract.o create_fract.o gcd.o push_fract.o append_fract.o empty_fract.o destroy_fract.o fraction.o print_fract.o simplifyFractGCD.o add_fract.o mult_fract.o sub_fract.o div_fract.o rand_fract.o rfract.o sortFractArray.o filter.o rmX_nNodeFromFract.o rmSortedFract.o

print_list_sort_fract.o: print_list_sort_fract.c
	gcc -Wall -c print_list_sort_fract.c

print_list_all_fract.o: print_list_all_fract.c
	gcc -Wall -c print_list_all_fract.c

create_fract.o: create_fract.c
	gcc -Wall -c create_fract.c

push_fract.o: push_fract.c
	gcc -Wall -c push_fract.c

append_fract.o: append_fract.c
	gcc -Wall -c append_fract.c

fraction.o: fraction.c
	gcc -Wall -c fraction.c

print_fract.o: print_fract.c
	gcc -Wall -c print_fract.c

simplifyFractGCD.o: simplifyFractGCD.c
	gcc -Wall -c simplifyFractGCD.c

add_fract.o: add_fract.c
	gcc -Wall -c add_fract.c

mult_fract.o: mult_fract.c
	gcc -Wall -c mult_fract.c

sub_fract.o: sub_fract.c
	gcc -Wall -c sub_fract.c

div_fract.o: div_fract.c
	gcc -Wall -c div_fract.c

rand_fract.o: rand_fract.c
	gcc -Wall -c rand_fract.c

rfract.o: rfract.c
	gcc -Wall -c rfract.c

sortFractArray.o: sortFractArray.c
	gcc -Wall -c sortFractArray.c

filter.o:filter.c
	gcc -Wall -c filter.c

rmX_nNodeFromFract.o: rmX_nNodeFromFract.c
	gcc -Wall -c rmX_nNodeFromFract.c

rmSortedFract.o: rmSortedFract.c
	gcc -Wall -c rmSortedFract.c

create_list.o:create_list.c
	gcc -Wall -c create_list.c

gcd.o: gcd.c
	gcc -Wall -c gcd.c

diffC.o: diffC.c
	gcc -Wall -c diffC.c

print_array.o: print_array.c
	gcc -Wall -c print_array.c

append.o:append.c
	gcc -Wall -c append.c

remove_smallest_key.o:remove_smallest_key.c
	gcc -Wall -c remove_smallest_key.c

rmSortedNode.o:rmSortedNode.c
	gcc -Wall -c rmSortedNode.c

empty_list.o:empty_list.c
	gcc -Wall -c empty_list.c

destroy_list.o:destroy_list.c
	gcc -Wall -c destroy_list.c

empty_fract.o:empty_fract.c
	gcc -Wall -c empty_fract.c

destroy_fract.o:destroy_fract.c
	gcc -Wall -c destroy_fract.c

push.o:push.c
	gcc -Wall -c push.c

remove_largest_key.o:remove_largest_key.c
	gcc -Wall -c remove_largest_key.c

size.o:size.c
	gcc -Wall -c size.c

remove_after.o:remove_after.c
	gcc -Wall -c remove_after.c

remove_last.o:remove_last.c
	gcc -Wall -c remove_last.c

free_list.o:free_list.c
	gcc -Wall -c free_list.c

read_file.o:read_file.c
	gcc -Wall -c read_file.c

print_list_all.o:print_list_all.c
	gcc -Wall -c print_list_all.c

print_list_sort.o:print_list_sort.c
	gcc -Wall -c print_list_sort.c

rmX_nNodeFromList.o:rmX_nNodeFromList.c
	gcc -Wall -c rmX_nNodeFromList.c

rmX_nNodeFromListChar.o:rmX_nNodeFromListChar.c
	gcc -Wall -c rmX_nNodeFromListChar.c

append_char.o:append_char.c
	gcc -Wall -c append_char.c

remove_smallest_key_char.o:remove_smallest_key_char.c
	gcc -Wall -c remove_smallest_key_char.c

push_char.o:push_char.c
	gcc -Wall -c push_char.c

remove_largest_key_char.o:remove_largest_key_char.c
	gcc -Wall -c remove_largest_key_char.c

remove_first_char.o:remove_first_char.c
	gcc -Wall -c remove_first_char.c

remove_last_char.o:remove_last_char.c
	gcc -Wall -c remove_last_char.c

print_list_char.o:print_list_char.c
	gcc -Wall -c print_list_char.c

print_list_sorted_char.o:print_list_sorted_char.c
	gcc -Wall -c print_list_sorted_char.c

rmSortedNodeChar.o: rmSortedNodeChar.c
		gcc -Wall -c rmSortedNodeChar.c

map.o: map.c
	gcc -Wall -c map.c

map_reduce.o: map_reduce.c
	gcc -Wall -c map_reduce.c

map_2_array.o: map_2_array.c
	gcc -Wall -c map_2_array.c

map_2_reduce.o: map_2_reduce.c
	gcc -Wall -c map_2_reduce.c

reduce.o: reduce.c
	gcc -Wall -c reduce.c

sum_of_sq_diff.o: sum_of_sq_diff.c
	gcc -Wall -c sum_of_sq_diff.c

sum.o: sum.c
	gcc -Wall -c sum.c

add.o: add.c
	gcc -Wall -c add.c


diff.o: diff.c
	gcc -Wall -c diff.c

square.o: square.c
	gcc -Wall -c square.c

nth.o: nth.c
	gcc -Wall -c nth.c

remove_nth.o: remove_nth.c
	gcc -Wall -c remove_nth.c

nth_node.o: nth_node.c
	gcc -Wall -c nth_node.c

mult.o: mult.c
	gcc -Wall -c mult.c

count_up.o: count_up.c
	gcc -Wall -c count_up.c

count_down.o: count_down.c
	gcc -Wall -c count_down.c

findNthSortList.o: findNthSortList.c
	gcc -Wall -c findNthSortList.c

findNthInsList.o: findNthInsList.c
	gcc -Wall -c findNthInsList.c

gcd_xy.o: gcd_xy.c
	gcc -Wall -c gcd_xy.c

clean:
	rm -rf *.o
	rm -rf a4q1a_int
	rm -rf a4q1a_char
	rm -rf a4q2
	rm -rf a4q1b
	rm -rf a4q3
