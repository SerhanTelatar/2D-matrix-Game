# 2D-matrix-Game
Input from file
You will read a text file that contains a 2D matrix of characters structured in rows and columns. In
each row, there are same number of characters and there could be any number of rows. In the
file, only '–' and '#' characters can exist. Figure 1 shows an example of such a sample input file
content with 3 rows and 5 columns (indices are added to the figure as extra information; they are
not part of the file content). Your program should work with all files having structures of any
number of rows and any number of columns.
Figure 1. Sample input file (indices are added for informative reasons; they are not part of the file content)
You should read the content of this file into a vector of vector of char data structure. You
are not allowed to use another structure for this purpose.
We strongly recommend you to read the file line-by-line using getline function, since it reads a
line entirely into a string by automatically stripping off the invisible end-of-line character(s). After
that, you can process the line string as you want. However, if you read by some other means, you
take the risk of processing the invisible end-of-line characters; this might cause inconsistencies
in different operating systems.
There are some input checks that you should perform for the file content.
● Your program should check for consistency in the number of characters in each row. In
other words, all rows must be of the same length.
● Your program should check that the file only contains dashes ‘-‘ and hashes ‘#’. Any other
symbols in a file will make that file invalid.
In case of a problem with the file content, your program must display a generic error message
and quit. See the sample runs for the error message content.
Before reading the file content, you will need to read the file name and open it. There are some
checks to be done with file opening/existence as well, but this is going to be explained in the
"Program Flow" section below.
Input from keyboard
After reading the input file, your program will read multiple queries, each as a string of a specific
structure and encoding to represent an irregular shape. Below are the rules and assumptions of
this encoding scheme.
A valid encoding consists of a sequence of character pairs, optionally separated by one or more
forward slash ‘/’ symbol(s).
● Each character pair is a digit followed by a letter.
○ The digit is a single digit in the range 1 to 9 (inclusive).
○ The letter is either lowercase s or lowercase b.
Interpretation of the encoding:
- Letter s corresponds to * character (star-shaped symbol; a.k.a. asterisk).
- Letter b corresponds to blank character.
- The digit preceding the letter represents the number of consecutive occurrences of that
letter.
- A forward slash represents a line break.
Figure 2. A sample of a string query
Figure 2 shows an example shape encoded as a string. The constructed shape out of this query
will have two stars (2s) in the top row of the shape followed by a single empty cell (1b). Then, we
advance the line (because of the line break ‘/’). On the line below, there will be a single star (1s),
followed by a single empty cell (1b), followed by a single star (1s). Figure 3 shows the shape
visually (Note: the “1s1s1b/1s1b1s” string also represents the same shape of Figure 3). Please
refer to Figure 4 for more examples and their visuals. 
