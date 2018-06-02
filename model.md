## GRAM Overview
The graph read alignment / map (GRAM) format is a tab-delimited text file format
for describing alignments of sequences to graphs, particularly string or
variation graphs in the GFA format. A GRAM file contains the following elements:

- Header lines defined by an 'H' at the first character in the line.
- Alignment records defined by a line that begins with 'A'

Column 0 is always a single character in [AH]. The second, third, fourth and fifth
columns (indices 1-4) comprise a BED record of a read relative to a path in the graph:  
    - Column 1: path name
    - Column 2: left-most position on the path
    - Column 3: right-most position on the path
    - Column 4: the read's name or identifier

Columns 1, 2, and 3 are optional and may be omitted by placing a '\*' as a placeholder,
indicating that either the read has no position on any path or that path-relative
position information was not generated.

Column 5 contains the sequence that was aligned. It may be omitted, replaced with the '\*'
placeholder, and stored in an external FASTA file or discarded.

Column 6 contains the quality scores of the sequence. This may be omitted and substituted
with'\*'.

Column 7 is a GFA-style ordered path (a comma-separated list of nodes and orientations)
describing where the read maps to the graph.

Column 8 is a comma-separated list of CS tag strings (or overlaps) that detail how a read
aligns to each of the nodes in its ordered path.

Columns 9 and above describe SAM-style tags in the 'tagName:tagType:tagValue' format.
GRAM supports tag names of up to 4 (8-bit) characters, which may be described in the header lines.
All columns are tab-delimited, so avoid placing tabs in the TAG keys or values.

### TAG Types:
Z: a string
A: a character
i: a (32-bit) signed integer
I: a (64-bit) signed integer
f: a (32-bit) signed float
F: a (64-bit) signed float




## Features

- Sequences may be kept in an external FASTA file (useful for long reads).
- GRAM does not strictly enforce an order, though it is encouraged to put header lines
before alignment lines.
- When a reference path is defined, a GRAM record contains a valid BED record in columns 1-4.
These columns can also be used for indexing with TABIX

A minimal GRAM record is simply a sequence identifier which refers to an external FASTA file:  

`A	*	*	*	r16054_1	*	*	*	*`

A valid BED record, with a single additional column prepended and 4 additional columns appended
is a valid GRAM record:

`A	1	100010	100160	r6540_2	*	*	*	*`

## Reserved Tags
 - RG:Z read group
 - SM:Z sample
 - SC:i number of softclipped bases
 - MQ:i mapping quality
 - FQ:Z FASTA/Q file containing read sequence (not required for omitting sequence)
