// A bookcase. -TW 03/04/01
#include <move.h>
#include <daemons.h>

inherit "/std/Object";
inherit "/std/locker_logic";

int sitting=0;

void init() {
  ::init();
  add_action("read_func", "peruse");
  return;
}

void create() {
  ::create();
  set_property("no save", 1);
  set_id( ({ "bookcase" }) );
  set_name("bookcase");
  set_short("A tall bookcase");
  set_long("This is a tall and well-stocked book case. Even though you're illiterate, you can still peruse a random title.");
  set_weight(1);
  set_value(0);
  return;
}


int read_func() {
    write("You walk over to the bookcase, grab a random book, and turn to a random page.");
    write("You read:");
    switch(random(3)){
      case 0:
        write("\t\t\t The Book of Aragorn - Chapter 3 ");
        write("\tAragorn drew his steel sword. Blood ran down his brow. His clothing was soaked with water from the hard rain coming down on top of him.\n\t'What have you, sir? What have I done to deserve this treacherous attack?' asked Aragorn to his black-clad assassin, who was coming towards him with a wicked dagger.\n\t'My friend, you have crossed the Guild of the Silver Knife. We do not appreciate you meddling in our affairs,' responded the assassin with a sneer. 'We will now teach you the folly of your actions.'\n\t'It will take more than dirty looks to kill me, fiend. Prepare yourself!' screamed Aragorn. In a moment, steel clashed.");
        break;
      case 1:
        write("\t\t\t A Warrior's Destiny - Chapter 2 ");
        write("\tReally, though, General Edge's career did not truly take off until the infamous goblin border clashes. His command of an elite team of Shadow Corps to quickly eradicate the main goblin camp was a master stroke of strategic genius. _Were it not for this move, the goblins would have gained a major foothold near Daybreak Ridge_.\n\tThe next month after his successful battle, he was summoned before the king, and promoted to lieutenant. He also received knighthood, and a small parcel of land. Edge, though, was not a businessman, and gave charge of it to a friend, Loria, whom he would eventually marry.");
        break;
      case 2:
        write("\t\t\t Broken Lands - Chapter 9 ");
        write("\tThe demonic forces broke through Klatchian defenses after a major battle. Estimates are somewhat sketchy, but over two and a half _million_ people are estimated to have been brutally slaughtered by the demonic host. Feln himself is said to have been responsible for the axe-murders of over 10,000 people. Needless to say, blood ran through the streets in rivers for over a week.\n\tA week later, the Empire's army collapsed completely, enabling the demons to move south to the Kingdom. The Kingdom was in little better shape - most of their men had been at Klatch, and the garrison at Daybreak Ridge was far too little to stop the 100,000 demons left...");
        break;
    }
    return 1;
}


// int register_num() { return 1; }
string query_storage_key() { return "misc"; }

int query_is_locker() { return 1; }
string query_my_file() { return "bookcase"; }

int move(mixed dest) {
  if(query_property("no get") && objectp(dest) && living(dest))
    return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

int restore_locker(string null) {
  return 1;
}

int is_furniture() {return 1;}
