# Advent of Code 2024

## Day 4 🎅🏻

**--- Day 4: Ceres Search ---**

"Looks like the Chief's not here. Next!" One of The Historians pulls out a device and pushes the only button on it. After a brief flash, you recognize the interior of the Ceres monitoring station!

As the search for the Chief continues, a small Elf who lives on the station tugs on your shirt; she'd like to know if you could help her with her word search (your puzzle input). She only has to find one word: XMAS.

This word search allows words to be horizontal, vertical, diagonal, written backwards, or even overlapping other words. It's a little unusual, though, as you don't merely need to find one instance of XMAS - you need to find all of them. Here are a few ways XMAS might appear, where irrelevant characters have been replaced with .:

The actual word search will be full of letters instead. For example:

| M | M | M | S | X | X | M | A | S | M |
|---|---|---|---|---|---|---|---|---|---|
| M | S | A | M | X | M | S | M | S | A |
| A | M | X | S | X | M | A | A | M | M |
| M | S | A | M | A | S | M | S | M | X |
| X | M | A | S | A | M | X | A | M | M |
| X | X | A | M | M | X | X | A | M | A |
| S | M | S | M | S | A | S | X | S | S |
| S | A | X | A | M | A | S | A | A | A |
| M | A | M | M | M | X | M | M | M | M |
| M | X | M | X | A | X | M | A | S | X |


In this word search, XMAS occurs a total of 18 times; here's the same word search again, but where letters not involved in any XMAS have been replaced with .:

| . | . | . | . | X | X | M | A | S | . |
|---|---|---|---|---|---|---|---|---|---|
| . | S | A | M | X | M | S | . | . | . |
| . | . | . | S | . | . | A | . | . | . |
| . | . | A | . | A | . | M | S | . | X |
| X | M | A | S | A | M | X | . | M | M |
| X | . | . | . | . | . | X | A | . | A |
| S | . | S | . | S | . | S | . | S | S |
| . | A | . | A | . | A | . | A | . | A |
| . | . | M | . | M | . | M | . | M | M |
| . | X | . | X | . | X | M | A | S | X |

Take a look at the little Elf's word search. How many times does XMAS appear?

<span style="color: orange;">*(ANSWER: 2591)*</span>

![alt text](image.png)

### Second Part

**--- Part Two ---**

The Elf looks quizzically at you. Did you misunderstand the assignment?

Looking for the instructions, you flip over the word search to find that this isn't actually an XMAS puzzle; it's an X-MAS puzzle in which you're supposed to find two MAS in the shape of an X. One way to achieve that is like this:

| M | . | S | 
|---|---|---| 
| . | A | . | 
| M | . | S | 

Irrelevant characters have again been replaced with . in the above diagram. Within the X, each MAS can be written forwards or backwards.

Here's the same example from before, but this time all of the X-MASes have been kept instead:

| . | M | . | S | . | . | . | . | . | . |
|---|---|---|---|---|---|---|---|---|---|
| . | . | A | . | . | M | S | M | S | . |
| . | M | . | S | . | M | A | A | . | . | 
| . | . | A | . | A | S | M | S | M | . | 
| . | M | . | S | . | M | . | . | . | . | 
| . | . | . | . | . | . | . | . | . | . | 
| S | . | S | . | S | . | S | . | S | . | 
| . | A | . | A | . | A | . | A | . | . | 
| M | . | M | . | M | . | M | . | M | . | 
| . | . | . | . | . | . | . | . | . | . | 

In this example, an X-MAS appears 9 times.

Flip the word search from the instructions back over to the word search side and try again. How many times does an X-MAS appear?

<span style="color: orange;">*(ANSWER: 1880)*</span>