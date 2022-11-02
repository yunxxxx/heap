# heap
A simple heap implementation

Command List:
### S
	On reading S, the program stops.
### C n
	On reading C n, the program creates an empty heap with capacity equal ton, and waits for thenext command.
### R
	On reading R, the program reads in the arrayAfrom fileHEAPinput.txt, calls the linear time buildheap algorithm to build the max-heap based onA, and waits for the next command.
### W
	On reading W, the program writes the current heap information to the screen, and waits for thenext command. The output should be in the same format as in the fileHEAPinput.txt, proceededby the heap capacity.
### I f k
	On reading I f k, the program inserts an element withkeyequal tokinto the current heap withthe corresponding flag set tof, and waits for the next command.
### D f
	On reading D f, the program deletes the minimum element from the heap with the correspondingflag  set  tof, and  prints  thekeyfield  of  the  deleted  element  on  the  screen,  it  waits  for  the  nextcommand.
### K f i v
	On readingK f i v, the program increases thekeyof element with indexitovwith the correspond-ing flag set tof.

### HEAPinput.txt:
	The fileHEAPinput.txtis a text file.  The first line of the file contains an integern, which indicatesthe  number  of array elements.   The  nextnlines containnintegers,  one  integer per line. Theseintegers are the key values of thenarray elements, from the first element to thenth element.
