
# MaryLadder 8 bits Edition V1.0

A pocket-sized 8-bits adder/subtractor PCB with a decimal display


## Features

- A & B inputs as 8 bits numbers with switches and LEDs
- 8 bits adder / subtractor (selection with a switch)
- 7 segments display with 3 digits to see A, B or S (sum) in decimal
- Type-C connector for 5V input
- 4-layers PCB (manufactured by PCBWay)


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
with its weight by going through them, one by one. The sum can then be printed in decimal on the three 7-segment display on the bottom
right corner of the PCB. 
## Assembly and Programming
I'll try to comment on what I've done (or may not have done)
when designing my project.  

/!\ WARNING /!\\

The MaryLadder 8 bits Edition V1.0 is still in development for now. I would not recommend
for now to try to replicate it, as I'm at the software phase, some hardware decisions will perhaps
be taken for future version. 

### Electronic Design
    
Electronic design has been realized using Altium Designer.
My goal was to get a fully-SMD product at the end. I spent a lot of
time on my schematic in order to make it as clear as possible. On top of that,
I wanted my PCB to fit in the palm of my hand. At this point I understood that
I would have to use 4 layers in my PCB design.  

I tried to source all of my components from one supplier (Digi-key here)
to place a single order and not be bothered by all kind of fees.

I'll be honest, this first version can be considered as a prototype, I haven't used a breadboard
as my components are SMD type.

For now, only one component should not be used as I did : the BCD decoder for 7 segment display.
I figured out a bit too late that the CD4511 has active outputs high : my configuration with common anode displays
requires low outputs. In order to keep my PCB as it is for now, I found another encoder with active outputs low (SN74LS47DR).
I would have been much more convenient not to choose common anode display at the beginning. I'll probably change this for a future
version.

The use of a voltage regulator isn't mandatory here, that's why I did not solder it at the end (and jump wire VCC and 5V).
I thought it might be useful if in case of using a power supply instead of the type C connector for testing.
In the end, the use of 2 resistors to trigger the Power Delivery Protocol worked fine and I'm pleased with it (quite nice to
power the MaryLadder on the go with a power bank for demonstrations).

### Assembly

Again for the first time, I tried to solder my components with a hot air gun and some solder paste.
It worked flawlessly and I'm very proud of the result. You should be careful not to apply too much heat
to the switches (use Capton tape if you are patient enough). 

### Programming

Programming the ATTINY 84 is quite easy using an Arduino Uno as an ISP programmer.
Here is the video I used upload my code to the µC : https://www.youtube.com/watch?v=TUlzOD9T3nI&list=PL-zNNA1g7OGG9XTFuZwNNf66KeijzKQph&index=2
(huge thank you to Levi Janssen for his video). I used Dupont wire to upload my code, you'll find
labels to recognize each pin.

Code isn't finished yet and may leads to different hardware decisions for a future version (having more GPIOs for instance).
## State of the project

### What's working?
Logical operations are working great. You can already add two 8-bits numbers and see
the result. I think that adding the weight of the bits below the leds was a good idea to
help visualize what's going on. It was for sure the easiest part of this project. Substracting
was a bit trickier, but I was very glad to see it working fine, resulting in a signed result in some cases.


### What is not working (yet)?
On the other side, the challenge was to display my numbers in decimal for the general public to understand.
At this point, I can display a number on my display but it's reversed (segments that should light on are off and vice versa).
I had a good laugh by noticing it at the first time. As mentioned before, my new reference for the BCD decoder should fix it.

I can also access all the inputs of the multiplexer using the microcontroller : I still have to improve my code 
so that it continuously checks what goes into it. I still want to post my project for the PCBWay PCB design contest even if 
I'm a bit short of time. I will obviously continue the project to get it finished as soon as possible!
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
First of all, because it is my very own projet, I designed everything from electrical
diagram, to placement, routing and even embedded software.
Through this project, I tried to prove to myself what I was capable of in terms
of PCB design.

But above all, I designed this pocket sized 8 bits adder in order to popularise
how basics calucations are done in a computer. Learning to count in binary isn't
that fun and appealing for someone who has no strong interest in electronics and
IT. I believe that having an object in your hands that allows you to visualize what's
going on is a pretty nice solution. 


