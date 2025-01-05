#include <std.h>

/* This is one among the several spellbooks located in the arch mage room of the black keep. Inside this book is information pertaining to the arch mages power word magics. This book contains no special use. */ 

inherit OBJECT;

void create() {
::create();
set_name("spellbook");
set("id", ({ "book", "spellbook", "purple book", "purple spellbook" }));
set_short("A purple spellbook");
set_long("You open the purple spellbook and flip a few pages\n\n     A power that is completely unique to the Arch Mage is the ability to alter the physical status of living beings. This is done by speaking single words of power, passed down through countless generations of magi to the worthy. These words are extremely simple, but in order to make them happen to an aggressor, the Arch Mage must have a truly clear mind and built up telekinetic power. One such word a magi can speak is 'Blind', to remove the sight from someone no matter how clear they can see. Another is 'Stun', which requires more mental power but can completely render an enemy paralyzed, unable to move in the slightest way to avoid anything else the Arch Mage is prepared to use against them. It is also a proven fact that the most powerful magi, ones that are tested from decades of their craft and possess the unchallenged power to bend space-time with insane telekinetic energy, to speak the word 'KILL' and age a being to instanteneously perish.");  
set_weight(200);
set_value(50000);
}
