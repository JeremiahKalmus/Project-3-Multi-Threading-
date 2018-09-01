#include "mdat.h"

void
spendTime()
{
  // The code here is garbage - just to force the threads to spend
  // a little time in the critical section.  This makes it easier
  // to catch mutual exclusion problems.
  int x, y;
  x = 3;
  y = x * 7;
  x--;
  y++;
  y = y - 1;
}

void
think()
{
  mdat_enter_section("Thinking");
  spendTime();
  mdat_enter_section("DoneThinking");
}

void
eat()
{
  mdat_enter_section("Eating");
  spendTime();
  mdat_enter_section("DoneEating");
}
