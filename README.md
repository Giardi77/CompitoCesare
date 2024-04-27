### Really simple encryption tool
I am not really proud of this, as it is a really basic and little project.

### How it works

1) insert a key
2) the choose 2 to encrypt or 3 to decript


### The algorithm: a Caesar cipher

The way it works is by shifting characters, base opoun the key we give to the program.
First it applies the key to the whole plain text, let's say we have text to encrypt equal to "THIS IS A TEST" and key "COMPLEXKEY",this is the result.

+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| T | H | I | S |   | I | S |   | A |   | T | E | S | T |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| C | O | M | P | L | E | X | K | E | Y | C | O | M | P | 
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

The first letter is 'T' with matchs with the 'C' of the key, 'T' in the alfabet has value 18 while C has a value of 3, by adding those to value we find the charcter for it to be replaced.
In this case T+C = 21 -> W,then we do it for the rest of the text.

The result will be this.

+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| W | W | V | H | L | N | P | K | F | Y | W | T | E | I |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

To retrieve the original text we apply the key as we did for the plaintext, then instead of adding just subtract.

+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| W | W | V | H | L | N | P | K | F | Y | W | T | E | I |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| C | O | M | P | L | E | X | K | E | Y | C | O | M | P | 
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

W-C = T, W-O = H etc...

+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| T | H | I | S |   | I | S |   | A |   | T | E | S | T |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
