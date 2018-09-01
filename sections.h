//  sections.h: mutual exclusion sections

#ifndef SECTIONS_H
#define SECTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

void think();
void eat();
void sectionInitGlobals(int numPhilosophers);
void sectionRunPhilosopher(int philosopherID, int numRounds);

#ifdef __cplusplus
}
#endif

#endif
