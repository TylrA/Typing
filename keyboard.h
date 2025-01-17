/*
 *  keyboard.h
 *  Typing
 *
 *  Created by Michael Dickens on 8/7/09.
 *
 * Includes the keyboard struct and the fitness function.
 */

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__
 
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "tools.h"

/*
 * Define all necessary digraphs as used by calcInRoll() in
 * fitness.c.
 *
 * All digraphs refer to the QWERTY locations. For example,
 * DF refers to the two consecutive keys typed by the middle
 * and index fingers on the home row.
 * 
 * Some digraphs are included with others because the 
 * difficulty in typing them was considered roughly equal.
 * Any equivalent digraphs are commented.
 */
#define AS 5  // QW
#define AD 9  // AE ZD ZC QE
#define AF 9  // ZV QR
#define AR 6  // ZF
#define AV 5  // QF
#define AG 6  // QT ZB
#define AT 5  // ZG
#define AB 4  // QG
#define SD 12 // WE
#define XC 9
#define XV 9  // XB
#define SG 8  // WT
#define SF 13 // WR
#define SR 6  // SV WF
#define SB 4  // WG ST
#define CV 10 // CB
#define DF 14 // ER
#define DG 8  // ET
#define DV 10
#define DB 4
#define EF 13
#define EG 6

/* Takes a Keyboard pointer k and an integer index.
 * 
 * WARNING: Both k and index are evaluated multiple times.
 */
#define charAt(k, index) ((index) < ksize ? (k)->layout[index] : (k)->shiftedLayout[index - ksize])
#define setCharAt(k, index, c) ((index) < ksize ? ((k)->layout[index] = (c)) : ((k)->shiftedLayout[index - ksize] = (c)))

void buildShuffledIndices(int indices[], int length);

int initKeyboard(Keyboard *k);
int setLayout(Keyboard *k, char *layout);
int layoutFromFile(FILE *file, Keyboard *k);
void copyKeyboard(Keyboard *k, Keyboard *original);
int swap(Keyboard *k, int loc1, int loc2);
int swapPair(Keyboard *k, int loc1, int loc2);
int printLayoutOnly(Keyboard *k);
int printLayoutRaw(char layout[]);
int printPercentages(Keyboard *k);
int charToPrintable(char *buffer, char c, int changeSpace);

int qwertyPositions(Keyboard *k);
int readLayouts(Keyboard pool[], int length);

int isSwappable(char c);
int isLegalSwap(Keyboard *k, int i, int j);
void shuffleLayout(Keyboard *kbd);

/* Returns the index of c on either the shifted or unshifted layout. */
int locIgnoreShifted(Keyboard *k, char c);

/* Returns the index of c if c is on the unshifted layout, or index + ksize 
 * if c is on the shifted layout.
 */
int locWithShifted(Keyboard *k, char c);

/* To use, set USE_COST_ARRAY to TRUE. */
int allDigraphCosts[KSIZE_MAX][KSIZE_MAX];

int calcFitnessDirect(Keyboard *k);
int scoreDigraphDirect(Keyboard *k, char digraph[], int64_t multiplier);
int calcFitness(Keyboard *k);
int scoreDigraph(Keyboard *k, char digraph[], int64_t multiplier, int allLocs[]);


char shortcutKeys[4];
char seedLayout[KSIZE_MAX]; // Holds every letter and is randomly shuffled. Used to seed the keyboards.
unsigned int seedVal;

int64_t calcShortcuts(Keyboard *k);
int64_t calcQWERTY(Keyboard *k);
int64_t calcBrackets(Keyboard *k);
int64_t calcBracketsGeneric(Keyboard *k, char openChar, char closeChar);
int64_t calcNumbersShifted(Keyboard *k);

int calcFingerWork(Keyboard *k);
int calcInRoll(int loc0, int loc1);
int calcOutRoll(int loc0, int loc1);
int calcSameFinger(int loc0, int loc1);
int calcRowChange(int loc0, int loc1);
int calcHomeJump(int loc0, int loc1);
int calcRingJump(int loc0, int loc1);
int calcToCenter(int loc0, int loc1);
int calcToOutside(int loc0, int loc1);


#endif
