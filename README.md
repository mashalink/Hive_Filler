# filler
An algorithms project from the 42 curriculum. In filler you create a player, whose goal is to put 
more pieces to a board than your enemy does.

## Algorithm
To solve where my player puts the piece given by the filler_vm virtual machine, I create a heatmap. 
In the heatmap the free spots closest to the enemys pieces get the highest value. The value of a free 
spot is decreased the further it is from an enemy piece. In the end, I choose the spot that gets the
highest heat value to be the final spot, where i place the piece.

## Usage

git clone https://github.com/mashalink/filler.git

cd filler

make all

./resources/filler_vm -f resources/maps/map00 -p1 ./mlink.filler -p2 resources/players/superjeannot.filler

	(also you can use maps/map01 or maps/map02)
	(also you caan use players/abanlin.filler , players/carli.filler , players/champely.filler , 
	players/grati.filler or  players/hcao.filler)

## Script

Script to test the program on all maps against all players.

cd resourses

chmod 755 test_filler.sh

./test_filler.sh

You will have the trace_filler file where will be  all results.

Grade 
101 / 100
