#include <std.h>
#include "../keep.h"

/* This is the Librarian mob present in the black keep library. It cannot be attacked, and serves two purposes. One is for decorative purposes because the room is a library, and the other is to recieve the white spellbook containing the summoning information he asks for from the arch mage chamber on the first floor as part of the areas quest. He will give the player the holy soul, which is a white globe that he says can be used at the pool of life to fully heal. However, if the player reads the clue on the picture frame on the second floor, they can discover a disciple can use it to recieve the red gem for the red arcane orb on the second floor. */

inherit MONSTER;

object ob;
int a;

void init() {
::init();
add_action("give", "give");
add_action("talk", "talk");
}

int give(string str) {
if(present("book", this_player())) {
if(str == "book to librarian" || str == "book to stout librarian") {
if(present("white spellbook", this_player())) {
tell_room(environment(this_object()), "The Librarian spots the white book in your hand before you can do anything. You then kindly give it to him.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "Librarian says in Common: YES! This is the book I've been looking for! Thank you very much for helping me out kind one. As a token of my gratitude, I will give you something i found on the corpse of one of the monsters slain here not too long ago. It is a white globe that carries the power of Lidfino within it. Immerse it in the pool of life and it will restore you to full health and magic.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "The Librarian quickly shelves the white book.");
present("white spellbook", this_player())->remove();
ob = new(ITEM+"holy_soul.c");
ob->move(this_player());
a = 5;
return 1;
}
tell_room(environment(this_object()), "Librarian says in Common: Thank you for the book young one. I already have a copy of that one however, so you may keep it.");
return 1;
}
}
}

int talk(string str) {
if(str == "to librarian" || str == "to stout librarian") {
if(a<1) {
tell_room(environment(this_object()), "Librarian says in Common: Hello young fellow. I am the Librarian of this keep. If you are wondering why i am alive, it is solely because the master needed someone to keep and watch over records. The master? He is a cold one indeed, a being of immense unworldly power from an entirely different realm. He arrived here some time ago with his army of servants and destroyed the powerful clan that once inhabited this structure. He told me once when i inquired that he was here because of the 'secret' to mold the dead and living, and is in the process of mastering it as i speak. He resides on the top level behind an unbreakable door even his own servants cannot bypass, and he rarely emerges. However, he is adept at telepathy and speaks from time to time.");
a++;
return 1;
}
if(a>0 && a<2) {
tell_room(environment(this_object()), "Librarian says in Common: The power to mold the dead and living is truly astonishing. I myself witnessed the master perform his magic on ferocious demons and undead vampires to create the horrible vampiric demons which roam the many halls. He has already managed to combine his own undead warriors with the same demons to create the sickening death soldiers, and he recently trained an army of powerful warlocks the art of summoning these creations. His newest creation however are the shadow knights, a new breed of warrior created from undead energy infused into the bodies of the Paladins of Sacrel. They have not been completely perfected yet, but these new 'Dark Paladins' when finished will give him a great edge over the divine gods.");
a++;
return 1;
}
if(a>1 && a<3) {
tell_room(environment(this_object()), "Librarian says in Common: The master discovered the secret of the keep from one of his followers, a member of the legendary clan that resided here before its conquering, the Demon Master Rancid. Rancid was a spy for Owedquar from the beginning, and using his sly wits was able to secure a spot in the clan ranks. When Rancid discovered the secret that the keep was built at a dimensional nexus where the realms of the dead and living crossed, he immediately reported the info to his diety and abandoned his clan in the heat of war. The keep itself was constructed over several months by a large company of dwarves, hailing from the mountains of Nelfton. It was by pure accident it was contructed in this location however. In anger due to Rancid's betrayal, the clan ordered a bounty, and the legendary master assassin Kyoki impaled a dagger through his back, instantly killing him. However, the damage was already done, and Owedquar began to plan his attack which would eventually lead to the fall of the Shadow-Keepers.");
a++;
return 1;
}
if(a>2 && a<4) {
tell_room(environment(this_object()), "Librarian says in Common: Shortly after Rancid's death, the forces of Owedquar arrived and stormed the keep. The master of this keep, a right hand of the dark god himself, materialized atop the western tower from Owedquar's world thanks to the aid of the great sorcerer Agulz, a secret servant of the evil incarnate. The master entered the keep when most of the members were away at war battling the extremely powerful forces of the warlord Ammon. Upon entering, he seized the power of the nexus and created his first cross of the dead and living, a fiercely potent Necromancer which utilizes both undead and chaos magic. After the Necromancer, the master began to create hordes of hybrids, and when the Shadow-Keepers returned from defeating Ammon in a bloody stand they were helpless to watch their home being destroyed by the undead warriors of Owedquar. They fought valiantly but fell in bloody defeat when the hybrids were unleashed. Only a few members of the clan survived, and none have ever returned.");
a++;
return 1;
}
if(a>3 && a<5) {
tell_room(environment(this_object()), "Librarian says in Common: After the keep's conquering, the master transformed the structure into his lair. Numerous doors and puzzles were erected to halt invaders as well as armies of his creations stationed throughout the keep. Despite his power however, there are a select few rooms that are untouched by it, for they are the grounds where the former clan members worshipped the divine gods devoutly. The gods are aware of the presence of Owedquar's forces here, and exercise their power over those rooms in honor of the fallen that used them. But the power of the master is so great that he has been able to restrict the divine gods to controlling only those rooms. Well my dear friend, that is what i know of the history of this building based on information i have assimilated from spoken word and the books here. I must be busy now, for i misplaced my summoning and teleportation book and i must find it, else i will likely be slain by the first one requesting it. It was a pleasure talking with you, young one.");
a++;
return 1;
}
if(a>4) {
tell_room(environment(this_object()), "Librarian says in Common: I am sorry my young fellow, but i am very busy at this moment. If at all possible can we talk later?");
return 1;
}
}
}

void create() {
::create();
a = 0;
set_name("librarian");
add_money("mithril", 1000);
set("id", ({ "librarian", "stout librarian" }));
set_property("no kill", 1);
set_property("no kill msg", "Librarian says in Common: Please young one, no violence in the library.");
set_short("A stout librarian");
set_long("This short stout man dressed rather nicely is the Librarian of the keep. For some odd reason he was spared when the structure was attacked by Owedquar's forces, most likely for the purpose of keeping records. He seems rather lonely, so maybe you could try to 'talk' to him.");
set("race", "human");
set_gender("male");
set_body_type("humanoid");
set_alignment(0);
set_skill("perception", 5000);
set_property("see invis", 1);
return;
}

void heart_beat() {
::heart_beat();
if(present("white spellbook", this_object())) {
tell_room(environment(this_object()), "Librarian says in Common: YES! This is the book ive been looking for! Thank you very much for helping me out kind one. As a token of my gratitude, i will give you something i found off the corpse of one of the monsters slain here not too long ago. It is a white globe that carries the power of Lidfino within it. Immerse it in the pool of life and it will restore you to full health and magic.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "The Librarian quickly shelves the white book.");
ob = new(ITEM+"holy_soul.c");
ob->move(this_player());
ob->move(environment(this_object()));
present("white spellbook", this_object())->remove();
a = 5;
return;
}
}
