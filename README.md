
# MaryLadder 8 bits Edition V1.0

A pocket-sized 8-bits adder/subtractor PCB with a decimal display


## Features

- A & B inputs as 8 bits numbers with switches and LEDs
- 8 bits adder / subtractor (selection with a switch)
- 7 segments display with 3 digits to see A, B or S (sum) in decimal
- Type-C connector for 5V input
- 4-layers PCB


## How the project works, in a nutshell

I'll say that my project can be divided in two main parts :

* Addition and substraction of two 8-bits numbers (A and B) using switches and LEDs
* Displaying the selected number (A, B or S) in decimal on the 7 segment display 

For the first part, only logic ICs are involved. It begins by selecting each bit of your choice
by switching on or off LEDs on number A and B. These inputs are connected to two 4-bits adders that
are cascaded. Outputs are connected to LEDs of number S (S for sum). With only this configuration,
you can visualize how binary additions work. To choose from addition or substraction, a switch can be activated :
XOR gates are involved in order to create substraction as a two's complement. Here, reading the result is not as easy
as addition, you'll have to think a little bit and even write it down on a piece of paper.

The second part is based on a microcontroller. Another switch can be used to choose which number to display : it triggers
one of the three bus switch to feed a multiplexer. Finally, each bit can be read by the µC. Then, the idea is to match each bit 
with its weight by going through them, one by one. The sum can then be printed in decimal on the 3 7-segment display on the bottom
right corner of the PCB. 
## Assembly and Programming
I'll try to comment on what I've done (or may not have done)
when designing my project.  
### Electronic Design
    
Electronic design has been realized using Altium Designer.
My goal was to get a fully-SMD product at the end. I spent a lot of
time on my schematic in order to make it as clear as possible. On top of that,
I wanted my PCB to fit in the palm of my hand. At this point I understood that
I would have to use 4 layers in my PCB design.  

I tryed to source all of my components from one supplier (Digi-key here)
to place a single order and not be bothered by all kind of fees. 

### Assembly


### Programming
## State of the project

### What's working?

### What is not working (yet)?

### My thoughts on this project

* What could have been done differently
## FAQ

####  How was this project born?

The MaryLadder - 8 bits Edition born in my mind 3 years ago,
when during my electronic engineering studies (at ESEO Angers, in France), 
I had the chance to participate in courses on logic gates. In order to 
make us understand the functioning of basic computers, we had to create
an 8 bits adder on breadboard. Tons of wires and pain for the sole purpose
of displaying a counter from 0 to 9 on a 7 segment display, without cheating
using a microcontroller.

This was my first real experience in electronics, where I discovered a sense of
wonder about these ICs.   

#### What's the purpose of this project?

The realization of this PCB project is important to me.
First of all, because my very own projet, I designed everything from electrical
diagram, to placement, routing and even embedded software.
Through this project, I tried to prove to myself what I was capable of in terms
of PCB design.

But above all, I designed this pocket sized 8 bits adder in order to popularise
how basics calucations are done in a computer. Learning to count in binary isn't
that fun and appealing for someone who has no strong interest in electronics and
IT. I believe that having an object in your hands that allows you to visualize what's
going on is a pretty nice solution. 


