#ifndef METAPHIRE_H
#define METAPHIRE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines.h"

typedef struct JournalEntry
{
	time_t created, edited;
	char *text;
	struct JournalEntry *next;
}
JournalEntry; 

typedef struct Journal
{
	JournalEntry *entries;
	u32 count, capacity;
}
Journal;

i8 journal_init(Journal *j);
i8 journal_free(Journal *j);
i8 journal_save(const Journal * const j, const char * const path);
i8 journal_load(Journal * const j, const char * const path);
i8 journal_entry_add(Journal * const j, const JournalEntry * const je);
i8 journal_entry_remove(Journal * const j, JournalEntry *je);

#endif
