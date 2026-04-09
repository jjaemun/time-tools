# holidays!

## Overview

`holidays` implements the holiday calendar logic, focusing on ingestion-based
workflows. 

algorithmic generation of holidays of a 
larger effort given the wide coverage needed in practice accross different 
markets.

## The contract

Uniqueness and ordering. 


### Internal representation

A number of data structures are suitable for the internal representation 
of holiday dates, considering the intended contract. From those, the ones
worth discussing are `std::set` and `std::vector`.

#### Memory layout.

Briefly, as is widely known, `std::vector` is a contiguous block of memory
that results in

std::vector and std::set differ fundamentally in both memory layout and 
performance characteristics. A std::vector stores elements contiguously, 
resulting in a minimal memory footprint of roughly N * sizeof(T) with only
occasional amortised reallocations as it grows. This makes it highly 
cache-friendly and efficient for traversal and bulk operations. In 
contrast, std::set is typically implemented as a red–black tree, where 
each element is individually allocated and accompanied by multiple 
pointers and bookkeeping data, leading to significantly higher 
memory overhead and poor locality due to pointer chasing. While 
std::set guarantees ordered, unique elements with logarithmic insertions, 
its per-element allocation cost and cache inefficiency often make it slower 
in practice. A useful modern alternative is std::flat_set (introduced in 
C++23), which stores sorted unique elements in a contiguous structure 
(usually backed by a vector), combining the low memory footprint and 
cache efficiency of std::vector with the interface and semantics of a 
set; in many cases, it achieves better real-world performance than both 
std::set and naive vector-based deduplication approaches, especially for 
read-heavy workloads.
