# time-tools!

## Overview

`time-tools` is a temporal library for applications in quantitative finance.
Because its nature is so vital across quant areas alike, it requires that the program 
be unusually rich, productive, general, and robust. 

A main goal is to communicate the programming philosophy developed here to contend with those challenges. 
To introduce some ideas, we will place excessive emphasis in safety, and concern ourselves
with explicitness, clarity and ergonomics. The truth of these briefly stated generalisations will, it
is hoped, be made apparent in the remaining sections. 

The expectation is that constructs contained herein are to be responsible 
for maintaining a valid internal state, which in turn should contribute to the safety of 
programs consuming them downstream. The contracts enforcing these guarantees will be 
covered in detail shortly.

It was also a desire to better understand the idiosyncrasies that make time such a 
complex matter in finance, and so the present work is partly presented as forum for 
those considerations. While the code is written intently to be self-documenting, 
some ideas are formally revisited or expanded.
