# lem-in

## description

Path finding algorithm for arbitrary graphs. <br>
In this project an ant colony is simulated and the goal is to find the most efficient way for n numbers of ants to travel from the entry of the graph to the exit. Each vertex and edge of the graph can only hold one ant at a time.

## usage

for compiling run `make` <br>

	$> ./lem-in < path/to/map

## map example

a map has the following structure:

	number_of_ants
	the_rooms
	the_links

comments are escaped with `#`. The source is marked by `##start` and sink is marked by `##end`. <br>
Here an example:

	$> cat example.map
	3
	##start
	src 2 0
	##end
	snk 1 4
	K 0 1
	O 0 2
	M 0 3
	G 1 1
	H 1 2
	I 1 3
	D 2 1
	E 2 2
	F 2 3
	A 3 1
	B 3 2
	C 3 3
	# links
	src-G
	src-D
	src-A
	M-snk
	I-snk
	F-snk
	G-K
	E-H
	C-F
	K-O
	O-M
	G-H
	H-I
	D-E
	E-F
	A-B
	B-C

## how to read the output

the output will have the following structure  (`-l` option suppresses the input map from being printed to the stdout):

	./lem-in -l < tests/maps/valid_normal_2
	L1-G L2-D
	L1-H L2-E L3-D
	L1-I L2-F L3-E
	L1-snk L2-snk L3-F
	L3-snk

to be read as follows: <br>
L'ant_no'-'current_vertex'. One line represents one step. So in the first step ant `1` moves to room `G` and ant `2` moves to room `D`. In the second step ant `1` continues to room `H`, ant `2` to `E` and ant `3` moves to room `D`. After step 5 all ants have arrived in `snk`.
