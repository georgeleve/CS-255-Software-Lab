/* Georgios Gerasimos Leventopoulos AM 4152  */
/* Assignment 1  Software Lab   CS 255	     */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* The enum that holds the special cases. */
enum state {
	b, B, d, D, inactive
};
/*This method puts the iso8859-1 characters that we need to translate
   in the array in order to print them later. (Initialize the array) */
void putCharactersInTheArray(char* index[]) {
	/* Low case letters (225-249 in iso8859_7) */
	index[0] = "a";
	index[1] = "v";
	index[2] = "g";
	index[3] = "d";
	index[4] = "e";
	index[5] = "z";
	index[6] = "h";
	index[7] = "8";
	index[8] = "i";
	index[9] = "k";
	index[10] = "l";
	index[11] = "m";
	index[12] = "n";
	index[13] = "ks";
	index[14] = "o";
	index[15] = "p";
	index[16] = "r";
	index[17] = "s"; /* s teliko */
	index[18] = "s";
	index[19] = "t";
	index[20] = "y";
	index[21] = "f";
	index[22] = "x";
	index[23] = "ps";
	index[24] = "w";
	/* Upper case letters. (193-217 in iso8859_7) */
	index[25] = "A";
	index[26] = "V";
	index[27] = "G";
	index[28] = "D";
	index[29] = "E";
	index[30] = "Z";
	index[31] = "H";
	index[32] = "8";
	index[33] = "I";
	index[34] = "K";
	index[35] = "L";
	index[36] = "M";
	index[37] = "N";
	index[38] = "KS";
	index[39] = "O";
	index[40] = "P";
	index[41] = "R";
	index[42] = "S";
	index[43] = "T";
	index[44] = "Y";
	index[45] = "F";
	index[46] = "X";
	index[47] = "PS";
	index[48] = "W";
	/*Upper case letters with accent */
	index[49] = "'A";
	index[50] = "'E";
	index[51] = "'H";
	index[52] = "'I";
	index[53] = "'O";
	index[54] = "'Y";
	index[55] = "'W";
	/*Low case letters with accent */
	index[56] = "a'";
	index[57] = "e'";
	index[58] = "h'";
	index[59] = "i'";
	index[60] = "o'";
	index[61] = "y'";
	index[62] = "w'";
	/*Special low case letetrs */
	index[63] = "i\"";
	index[64] = "y\"";
	index[65] = "y'\"";
	index[66] = "y'\"";
}
/* This function matches the iso8859-7 with iso8859-1 characters
and returns their position in the array we made. */
int matchCharacter(int id) {
	/* Special letter cases : */
	/*Upper case with accent*/
	if (id == 182) return 49; /* "A'" */
	if (id == 184) return 50; /* "E'" */
	if (id == 185) return 51; /* "H'" */
	if (id == 186) return 52; /* "I'" */
	if (id == 188) return 53; /* "O'" */
	if (id == 190) return 54; /* "Y'" */
	if (id == 191) return 55; /* "W'" */
	/*Low case with accent */
	if (id == 220) return 56; /* a' */
	if (id == 221) return 57; /* e' */
	if (id == 222) return 58; /* h' */
	if (id == 223) return 59; /* i' */
	if (id == 252) return 60; /* o' */
	if (id == 253) return 61; /* y' */
	if (id == 254) return 62; /* w' */
	/*Special low case with accent */
	if (id == 250) return 63; /* i me dialitika */
	if (id == 251) return 64; /* y me dialitika */
	if (id == 192) return 65; /* i y me dialitika kai tono*/
	if (id == 224) return 66; /* y me dialitika kai tono */
	/* Common cases */
	/* Low case letters (a-z letters) */
	if (id >= 225 && id <= 249) {
		return id - 225 + 0;
	}
	/* Upper case letters (A-R letters) */
	else if (id >= 193 && id <= 209) {
		return id - 193 + 25;
	}
	/* Upper case letters. (S-W letters) */
	else if (id >= 211 && id <= 217) {
		return id - 211 + 42;
	}
	return -1; /* The letter is the same in both iso and we do not need to translate it. */
}
/* This method prints characters in stdout (In this case we print in the console). */
void print_character(char* letters) {
	while (*letters) {
		putchar(*letters);
		letters++;
	}
}
/*A method that changes the 'currentState' when is needed. */
enum state switchState(enum state currentState, int c) {
	if (c == 236) {      /* GREEK SMALL LETTER mi */
		return b;
	}
	else if (c == 204) { /* GREEK CAPITAL LETTER Mi */
		return B;
	}
	else if (c == 237) { /* GREEK SMALL LETTER ni  */
		return d;
	}
	else if (c == 205) { /* GREEK CAPITAL LETTER Ni */
		return D;
	}
	else {
		return inactive; /* No special case, the state stays as it is. */
	}
}
/* Main function that gets a standard input with iso8859-7 characters(from a text file),
translates it to iso8859-1 characters and writes in standard output (in the console).   */
int main() {
	enum state currentState = inactive;
	char *character;                    /* A pointer that points to the letter that we want to print.*/
	char *index[67];                   /* The array of characters that we are going to use. */
	int temp;                         /* Temporary variable to keep letters number ID.*/
	int c = getchar();               /*The variable that holds the number ID of characters*/
	putCharactersInTheArray(index); /* Initialize array - Store iso8859-1 letters. */
	do {
		/* That means that the character is not in the iso. */
		if (c < 32) {
			continue;
		}
		/* Find the cell of the array that we store the letter and
		store it in variable temp. */
		temp = matchCharacter(c);
		/* If the character is the same in both iso we don't need to change
		something so we take space in memory, we store the integer in *character
		and we print it as it is. (e.g. " " (space) is the same in both iso). */
		if (temp == -1) {
			character = (char*)malloc(sizeof(char));
			*character = c;
		}
		else {
			character = index[temp]; /* We store the letter in character. */
		}
		/*  Print characters or change character variable if we need to, depending on the state. */
		if (currentState == b) {
			if (c != 208 && c != 240) { /* if char is not p or P (greek) */
				print_character("m");
			}
			else {
				character = "b";        /* That means that we read 'm' as a previous letter now we read 'p' or 'P'. */
			}
		}
		else if (currentState == B) {
			if (c != 208 && c != 240) { /* if char is not p or P (greek) */
				print_character("M");
			}
			else {
				character = "B";        /* That means that we read 'M' as a previous letter now we read 'p' or 'P'. */
			}
		}
		else if (currentState == d) {
			if (c != 212 && c != 244) { /* if char is not t or T (greek) */
				print_character("n");
			}
			else {
				character = "d";        /*That means that read 'n' as a previous letter now we read 't' or 'T' . */
			}
		}
		else if (currentState == D) {
			if (c != 212 && c != 244) { /* if char is not t or T (greek) */
				print_character("N");
			}
			else {
				character = "D"; /* That means that read 'N' as a previous letter now we read 't' or 'T' . */
			}
		}

		currentState = inactive; /* Initialize the state to inactive */

		/* We switch state if we need to. Else the state stays as 'inactive'.  
		   We need to switch state if we find m or M or n or N (greek letters) */
		currentState = switchState(currentState, c);

		/*If the current state is inactive (is not in states b, B, d, D) then we print character.*/
		if (currentState == inactive) {
			print_character(character);
		}
	} while ((c = getchar()) != EOF);
	return 0;
}
